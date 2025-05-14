#pragma once

#include "aidl/vendor/dinhnamuet/hardware/led/ILedAidl.h"

#include <android/binder_ibinder.h>
#include <cassert>

#ifndef __BIONIC__
#ifndef __assert2
#define __assert2(a,b,c,d) ((void)0)
#endif
#endif

namespace aidl {
namespace vendor {
namespace dinhnamuet {
namespace hardware {
namespace led {
class BnLedAidl : public ::ndk::BnCInterface<ILedAidl> {
public:
  BnLedAidl();
  virtual ~BnLedAidl();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
class ILedAidlDelegator : public BnLedAidl {
public:
  explicit ILedAidlDelegator(const std::shared_ptr<ILedAidl> &impl) : _impl(impl) {
  }

  ::ndk::ScopedAStatus setLed(int8_t in_index, int8_t in_value) override {
    return _impl->setLed(in_index, in_value);
  }
  ::ndk::ScopedAStatus getLed(int8_t in_index, int8_t* _aidl_return) override {
    return _impl->getLed(in_index, _aidl_return);
  }
protected:
private:
  std::shared_ptr<ILedAidl> _impl;
};

}  // namespace led
}  // namespace hardware
}  // namespace dinhnamuet
}  // namespace vendor
}  // namespace aidl
