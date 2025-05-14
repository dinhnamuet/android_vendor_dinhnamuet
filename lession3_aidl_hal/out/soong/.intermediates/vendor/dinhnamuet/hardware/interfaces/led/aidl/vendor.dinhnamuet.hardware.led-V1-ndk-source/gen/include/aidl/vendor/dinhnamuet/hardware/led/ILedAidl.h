#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace vendor {
namespace dinhnamuet {
namespace hardware {
namespace led {
class ILedAidl : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  ILedAidl();
  virtual ~ILedAidl();

  static constexpr uint32_t TRANSACTION_setLed = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getLed = FIRST_CALL_TRANSACTION + 1;

  static std::shared_ptr<ILedAidl> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ILedAidl>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ILedAidl>* instance);
  static bool setDefaultImpl(const std::shared_ptr<ILedAidl>& impl);
  static const std::shared_ptr<ILedAidl>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus setLed(int8_t in_index, int8_t in_value) = 0;
  virtual ::ndk::ScopedAStatus getLed(int8_t in_index, int8_t* _aidl_return) = 0;
private:
  static std::shared_ptr<ILedAidl> default_impl;
};
class ILedAidlDefault : public ILedAidl {
public:
  ::ndk::ScopedAStatus setLed(int8_t in_index, int8_t in_value) override;
  ::ndk::ScopedAStatus getLed(int8_t in_index, int8_t* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace led
}  // namespace hardware
}  // namespace dinhnamuet
}  // namespace vendor
}  // namespace aidl
