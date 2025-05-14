#pragma once

#include "aidl/vendor/dinhnamuet/hardware/led/ILedAidl.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace vendor {
namespace dinhnamuet {
namespace hardware {
namespace led {
class BpLedAidl : public ::ndk::BpCInterface<ILedAidl> {
public:
  explicit BpLedAidl(const ::ndk::SpAIBinder& binder);
  virtual ~BpLedAidl();

  ::ndk::ScopedAStatus setLed(int8_t in_index, int8_t in_value) override;
  ::ndk::ScopedAStatus getLed(int8_t in_index, int8_t* _aidl_return) override;
};
}  // namespace led
}  // namespace hardware
}  // namespace dinhnamuet
}  // namespace vendor
}  // namespace aidl
