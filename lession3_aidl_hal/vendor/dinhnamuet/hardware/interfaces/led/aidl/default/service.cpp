#define LOG_TAG "dinhnamuetAidl"

#include <utils/Log.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include <binder/IServiceManager.h>
#include <aidl/vendor/dinhnamuet/hardware/led/ILedAidl.h>

#include "LedAidl.h"

#define INSTANCE_NAME "/default"

using ::aidl::vendor::dinhnamuet::hardware::led::ILedAidl;
using ::aidl::vendor::dinhnamuet::hardware::led::LedAidl;

int main(int , char *[])
{
    ALOGI("Start %s", __FILE__);
    std::string insName = std::string() + ILedAidl::descriptor + INSTANCE_NAME;
    ABinderProcess_setThreadPoolMaxThreadCount(1);
    ABinderProcess_startThreadPool();
    std::shared_ptr<ILedAidl> led = ndk::SharedRefBase::make<LedAidl>();
    if (led == nullptr) {
        ALOGI("Failed to create an instance of %s", ILedAidl::descriptor);
        return 1;
    }
    binder_exception_t status = AServiceManager_addService(led->asBinder().get(), insName.c_str());
    if (status != STATUS_OK) {
        ALOGI("Service %s couldn't register!", led->descriptor);
        return 1;
    }
    ALOGI("an instance of %s registered successfully!", led->descriptor);

    ABinderProcess_joinThreadPool();
    return 0;
}
