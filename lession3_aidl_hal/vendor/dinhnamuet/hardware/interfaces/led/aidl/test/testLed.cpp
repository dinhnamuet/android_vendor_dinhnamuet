#define LOG_TAG "testLedAidl"

#include <utils/Log.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include <aidl/vendor/dinhnamuet/hardware/led/ILedAidl.h>

using ::aidl::vendor::dinhnamuet::hardware::led::ILedAidl;

#define INSTANCE_NAME "/default"

int main(int argc, char *argv[])
{
    if (argc < 3) {
        ALOGE("Usage: %s <index> <value>!", argv[0]);
        return -1;
    }
    int8_t index = atoi(argv[1]);
    int8_t value = atoi(argv[2]);
    std::shared_ptr<ILedAidl> led = ILedAidl::fromBinder(
        ndk::SpAIBinder(AServiceManager_waitForService((std::string() + ILedAidl::descriptor + INSTANCE_NAME).c_str()))
    );
    if (led == nullptr) {
        ALOGE("Failed to get an instance of %s", ILedAidl::descriptor);
        return -1;
    }
    led->setLed(index, value);
    ALOGI("Set led %d to %d", index, value);
    led->getLed(index, &value);
    ALOGI("Get led %d value: %d", index, value);
    return 0;
}
