
#define LOG_TAG "dinhnamTestLed"

#include <vendor/dinhnamuet/led/1.0/ILed.h>
#include <utils/Log.h>
#include <cstdlib>

using ::vendor::dinhnamuet::led::V1_0::ILed;

int main(int argc, char *argv[])
{
    int32_t index, value;
    ::android::sp<ILed> led;
    ALOGI("%s starting ...!", __FILE__);
    if (argc < 3) {
        ALOGE("Please Use: ./testLedHidl + <LED Index> + <Expected Value>");
        return 1;
    }
    led = ILed::getService();
    if (led == nullptr) {
        ALOGE("Cannot get Service %s!", ILed::descriptor);
        return 1;
    }
    index = std::atoi(argv[1]);
    value = std::atoi(argv[2]);
    led->setLed(index, value);
    ALOGI("Set LED %d to value %d", index, value);
    value = led->getLed(index);
    if (value < 0) {
        ALOGE("Failed to get LED %d", index);
        return 1;
    }
    ALOGI("LED %d state: %d", index, value);
    return 0;
}
