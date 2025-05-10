// FIXME: your file license if you have one

#pragma once

#include <vendor/dinhnamuet/led/1.0/ILed.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace vendor::dinhnamuet::led::implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct Led : public V1_0::ILed {
    // Methods from ::vendor::dinhnamuet::led::V1_0::ILed follow.
    Return<int32_t> getLed(int32_t index) override;
    Return<int32_t> setLed(int32_t index, int32_t value) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" ILed* HIDL_FETCH_ILed(const char* name);

}  // namespace vendor::dinhnamuet::led::implementation
