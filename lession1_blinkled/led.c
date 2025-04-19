#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/mod_devicetable.h>
#include <linux/gpio/consumer.h>
#include <linux/kobject.h>
#include <linux/device.h>
#include <linux/mutex.h>
#include <linux/sysfs.h>
#include <linux/of.h>
#include <linux/slab.h>

struct led_manager {
    struct list_head list;
};

struct demo_led {
    struct mutex lock;
    struct gpio_desc *gpio;
    struct device_attribute d_attr;
    struct list_head list;
};

static const struct of_device_id led_match_id[] = {
    { .compatible = "gpio-leds", },
    { }
};
MODULE_DEVICE_TABLE(of, led_match_id);

ssize_t led_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    ssize_t ret;
    struct demo_led *led = container_of(attr, struct demo_led, d_attr);
    ret = mutex_lock_interruptible(&led->lock);
    if (unlikely(ret < 0))
        return ret;
    ret = scnprintf(buf, PAGE_SIZE, "%d\n", gpiod_get_value(led->gpio));
    mutex_unlock(&led->lock);
    dev_info(dev, "%s, %d!\n", __func__, __LINE__);
    return ret;
}
ssize_t led_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
    int val;
    ssize_t ret;
    struct demo_led *led = container_of(attr, struct demo_led, d_attr);
    ret = mutex_lock_interruptible(&led->lock);
    if (unlikely(ret < 0))
        return ret;
    sscanf(buf, "%d", &val);
    gpiod_set_value(led->gpio, val);
    mutex_unlock(&led->lock);
    dev_info(dev, "%s, %d!\n", __func__, __LINE__);
    return count;
}

static int led_probe(struct platform_device *pdev)
{
    int ret = 0;
    struct device *dev;
    struct demo_led *led, *pos;
    struct device_node *np;
    struct device_node *child;
    struct led_manager *led_list;

    dev = &pdev->dev;
    np = dev->of_node;

    if (unlikely(!device_get_child_node_count(dev))) {
        dev_err(dev, "There is no LED found!\n");
        return -ENODEV;
    }

    led_list = devm_kzalloc(dev, sizeof(*led_list), GFP_KERNEL);
    if (unlikely(!led_list)) {
        dev_err(dev, "Cannot Create LEDs Chain!\n");
        return -ENOMEM;
    }
    INIT_LIST_HEAD(&led_list->list);
    dev_set_drvdata(dev, led_list);
    for_each_child_of_node(np, child) {
        led = devm_kzalloc(dev, sizeof(*led), GFP_KERNEL);
        if (unlikely(!led)) {
            dev_err(dev, "Cannot alloc LED memory!\n");
            ret = -ENOMEM;
            goto alloc_error;
        }
        led->gpio = fwnode_gpiod_get_index(&child->fwnode, NULL, 0, GPIOD_OUT_LOW, NULL);
        if (unlikely(!led->gpio)) {
            dev_err(dev, "Cannot get the LED!\n");
            ret = -ENODEV;
            goto find_gpio_err;
        }
        if (unlikely(of_property_read_string(child, "label", &led->d_attr.attr.name)))
            led->d_attr.attr.name = "NoName";
        led->d_attr.attr.mode = 0666;
        led->d_attr.show = led_show;
        led->d_attr.store = led_store;
        ret = device_create_file(dev, &led->d_attr);
        if (unlikely(ret)) {
            dev_err(dev, "Sysfs create failure!\n");
            goto sysfs_err;
        }
        INIT_LIST_HEAD(&led->list);
        list_add_tail(&led->list, &led_list->list);
        mutex_init(&led->lock);
        dev_info(dev, "Added LED %s at GPIO %d!\n", led->d_attr.attr.name, desc_to_gpio(led->gpio));
    }
    dev_info(dev, "%s, %d: Demo LED Init Successfully!\n", __func__, __LINE__);
    return ret;

sysfs_err:
    gpiod_put(led->gpio);
find_gpio_err:
    devm_kfree(dev, led);
alloc_error:
    list_for_each_entry_safe(led, pos, &led_list->list, list) {
        list_del(&led->list);
        device_remove_file(dev, &led->d_attr);
        gpiod_put(led->gpio);
        mutex_destroy(&led->lock);
        devm_kfree(dev, led);
    }
    devm_kfree(dev, led_list);
    return ret;
}

static int led_remove(struct platform_device *pdev)
{
    struct led_manager *led_list;
    struct demo_led *led, *pos;
    struct device *dev = &pdev->dev;
    led_list = dev_get_drvdata(dev);
    list_for_each_entry_safe(led, pos, &led_list->list, list) {
        dev_info(dev, "Remove LED %s at GPIO %d!\n", led->d_attr.attr.name, desc_to_gpio(led->gpio));
        list_del(&led->list);
        device_remove_file(dev, &led->d_attr);
        gpiod_put(led->gpio);
        mutex_destroy(&led->lock);
    }
    dev_info(dev, "%s, %d: Demo LED Stop Running!\n", __func__, __LINE__);
    return 0;
}

static struct platform_driver led_driver = {
    .probe = led_probe,
    .remove = led_remove,
    .driver = {
        .name = "ledtest",
        .owner = THIS_MODULE,
        .of_match_table = of_match_ptr(led_match_id),
    },
};
module_platform_driver(led_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DinhNam <dinhnamuet@gmail.com>");
MODULE_DESCRIPTION("LED Driver Test");
