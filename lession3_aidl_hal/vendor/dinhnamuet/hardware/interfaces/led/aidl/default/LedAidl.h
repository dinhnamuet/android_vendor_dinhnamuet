#pragma once

#include <aidl/vendor/dinhnamuet/hardware/led/ILedAidl.h>
#include <aidl/vendor/dinhnamuet/hardware/led/BnLedAidl.h>

namespace aidl {
namespace vendor {
namespace dinhnamuet {
namespace hardware {
namespace led {
class LedAidl : public BnLedAidl {
public:
    ::ndk::ScopedAStatus setLed(int8_t in_index, int8_t in_value);
    ::ndk::ScopedAStatus getLed(int8_t in_index, int8_t* _aidl_return);
};
}  // namespace led
}  // namespace hardware
}  // namespace dinhnamuet
}  // namespace vendor
}  // namespace aidl
