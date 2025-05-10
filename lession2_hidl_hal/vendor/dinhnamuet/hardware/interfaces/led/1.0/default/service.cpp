
#define LOG_TAG "dinhnamuetLED"

#include <hidl/HidlTransportSupport.h>
#include "utils/Log.h"

#include "Led.h"

using ::vendor::dinhnamuet::led::V1_0::ILed;
using ::vendor::dinhnamuet::led::implementation::Led;

int main(int , char *[])
{
    ALOGI("Start %s", __FILE__);
    ::android::hardware::configureRpcThreadpool(1, true);

    ::android::sp<ILed> led = new Led;
    ::android::status_t status = led->registerAsService();
    if (status != ::android::OK) {
        ALOGI("%s: Service couldn't register!", __func__);
        return 1;
    }
    ALOGI("an instance of %s registered successfully!", led->descriptor);

    ::android::hardware::joinRpcThreadpool();
    return 0;
}
