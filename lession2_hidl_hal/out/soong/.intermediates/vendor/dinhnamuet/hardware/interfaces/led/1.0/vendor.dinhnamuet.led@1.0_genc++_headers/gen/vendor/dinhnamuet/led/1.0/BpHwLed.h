#ifndef HIDL_GENERATED_VENDOR_DINHNAMUET_LED_V1_0_BPHWLED_H
#define HIDL_GENERATED_VENDOR_DINHNAMUET_LED_V1_0_BPHWLED_H

#include <hidl/HidlTransportSupport.h>

#include <vendor/dinhnamuet/led/1.0/IHwLed.h>

namespace vendor {
namespace dinhnamuet {
namespace led {
namespace V1_0 {

struct BpHwLed : public ::android::hardware::BpInterface<ILed>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwLed(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef ILed Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::vendor::dinhnamuet::led::V1_0::ILed follow.
    static ::android::hardware::Return<int32_t>  _hidl_getLed(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t index);
    static ::android::hardware::Return<int32_t>  _hidl_setLed(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t index, int32_t value);

    // Methods from ::vendor::dinhnamuet::led::V1_0::ILed follow.
    ::android::hardware::Return<int32_t> getLed(int32_t index) override;
    ::android::hardware::Return<int32_t> setLed(int32_t index, int32_t value) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;
    ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;
    ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> setHALInstrumentation() override;
    ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;
    ::android::hardware::Return<void> ping() override;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;
    ::android::hardware::Return<void> notifySyspropsChanged() override;
    ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

private:
    std::mutex _hidl_mMutex;
    std::vector<::android::sp<::android::hardware::hidl_binder_death_recipient>> _hidl_mDeathRecipients;
};

}  // namespace V1_0
}  // namespace led
}  // namespace dinhnamuet
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_DINHNAMUET_LED_V1_0_BPHWLED_H
