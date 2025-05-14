#define LOG_TAG "dinhnamuetAidl"

#include "LedAidl.h"
#include <utils/Log.h>
#include <fstream>

#define USR_LED "/sys/devices/platform/leds/user"
#define STATUS_LED "/sys/devices/platform/leds/status"

static const std::string ledList[] = {
    USR_LED,
    STATUS_LED,
};

namespace aidl {
namespace vendor {
namespace dinhnamuet {
namespace hardware {
namespace led {
    ndk::ScopedAStatus LedAidl::setLed(int8_t in_index, int8_t in_value)
    {
        std::ofstream ledFile(ledList[in_index]);
        if (!ledFile.is_open()) {
            ALOGE("Failed to open %s", ledList[in_index].c_str());
            return ::ndk::ScopedAStatus::fromServiceSpecificErrorWithMessage(-1, "setLed failed to open file");
        }
        ledFile << in_value;
        if (ledFile.fail()) {
            ALOGE("Failed to write to %s", ledList[in_index].c_str());
            return ::ndk::ScopedAStatus::fromServiceSpecificErrorWithMessage(-1, "setLed failed to write to file");
        }
        ledFile.close();
        ALOGI("HAL: setLed %s to %d", ledList[in_index].c_str(), in_value);
        return ::ndk::ScopedAStatus::ok();
    }
    ndk::ScopedAStatus LedAidl::getLed(int8_t in_index, int8_t* _aidl_return)
    {
        std::ifstream ledFile(ledList[in_index]);
        if (!ledFile.is_open()) {
            ALOGE("Failed to open %s", ledList[in_index].c_str());
            return ::ndk::ScopedAStatus::fromServiceSpecificErrorWithMessage(-1, "getLed failed to open file");
        }
        std::string line;
        std::getline(ledFile, line);
        ledFile.close();
        *_aidl_return = std::stoi(line);
        ALOGI("HAL: getLed %s = %d", ledList[in_index].c_str(), *_aidl_return);
        return ::ndk::ScopedAStatus::ok();
    }
}  // namespace led
}  // namespace hardware
}  // namespace dinhnamuet
}  // namespace vendor
}  // namespace aidl
