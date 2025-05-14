#include "aidl/vendor/dinhnamuet/hardware/led/ILedAidl.h"

#include <android/binder_parcel_utils.h>
#include <aidl/vendor/dinhnamuet/hardware/led/BnLedAidl.h>
#include <aidl/vendor/dinhnamuet/hardware/led/BpLedAidl.h>

namespace aidl {
namespace vendor {
namespace dinhnamuet {
namespace hardware {
namespace led {
static binder_status_t _aidl_vendor_dinhnamuet_hardware_led_ILedAidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnLedAidl> _aidl_impl = std::static_pointer_cast<BnLedAidl>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*setLed*/): {
      int8_t in_index;
      int8_t in_value;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_index);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_value);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->setLed(in_index, in_value);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*getLed*/): {
      int8_t in_index;
      int8_t _aidl_return;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_index);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getLed(in_index, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_vendor_dinhnamuet_hardware_led_ILedAidl_clazz = ::ndk::ICInterface::defineClass(ILedAidl::descriptor, _aidl_vendor_dinhnamuet_hardware_led_ILedAidl_onTransact);

BpLedAidl::BpLedAidl(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpLedAidl::~BpLedAidl() {}

::ndk::ScopedAStatus BpLedAidl::setLed(int8_t in_index, int8_t in_value) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_index);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_value);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*setLed*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ILedAidl::getDefaultImpl()) {
    _aidl_status = ILedAidl::getDefaultImpl()->setLed(in_index, in_value);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpLedAidl::getLed(int8_t in_index, int8_t* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_index);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*getLed*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ILedAidl::getDefaultImpl()) {
    _aidl_status = ILedAidl::getDefaultImpl()->getLed(in_index, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readData(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnLedAidl
BnLedAidl::BnLedAidl() {}
BnLedAidl::~BnLedAidl() {}
::ndk::SpAIBinder BnLedAidl::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_vendor_dinhnamuet_hardware_led_ILedAidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markVintfStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for ILedAidl
const char* ILedAidl::descriptor = "vendor.dinhnamuet.hardware.led.ILedAidl";
ILedAidl::ILedAidl() {}
ILedAidl::~ILedAidl() {}


std::shared_ptr<ILedAidl> ILedAidl::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_vendor_dinhnamuet_hardware_led_ILedAidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<ILedAidl>(interface);
  }
  return ::ndk::SharedRefBase::make<BpLedAidl>(binder);
}

binder_status_t ILedAidl::writeToParcel(AParcel* parcel, const std::shared_ptr<ILedAidl>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t ILedAidl::readFromParcel(const AParcel* parcel, std::shared_ptr<ILedAidl>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = ILedAidl::fromBinder(binder);
  return STATUS_OK;
}
bool ILedAidl::setDefaultImpl(const std::shared_ptr<ILedAidl>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!ILedAidl::default_impl);
  if (impl) {
    ILedAidl::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<ILedAidl>& ILedAidl::getDefaultImpl() {
  return ILedAidl::default_impl;
}
std::shared_ptr<ILedAidl> ILedAidl::default_impl = nullptr;
::ndk::ScopedAStatus ILedAidlDefault::setLed(int8_t /*in_index*/, int8_t /*in_value*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ILedAidlDefault::getLed(int8_t /*in_index*/, int8_t* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder ILedAidlDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool ILedAidlDefault::isRemote() {
  return false;
}
}  // namespace led
}  // namespace hardware
}  // namespace dinhnamuet
}  // namespace vendor
}  // namespace aidl
