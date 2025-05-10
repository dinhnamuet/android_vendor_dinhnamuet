// FIXME: your file license if you have one
#define LOG_TAG "dinhnamuetLED"

#include <utils/Log.h>
#include <fstream>

#include "Led.h"

#define USR_LED "/sys/devices/platform/leds/user"
#define STATUS_LED "/sys/devices/platform/leds/status"

static const std::string ledList[] = {
    USR_LED,
    STATUS_LED,
};

namespace vendor::dinhnamuet::led::implementation {

// Methods from ::vendor::dinhnamuet::led::V1_0::ILed follow.
Return<int32_t> Led::getLed(int32_t index) {
    std::ifstream ledFile(ledList[index]);
    if (!ledFile.is_open()) {
        ALOGE("Failed to open %s", ledList[index].c_str());
        return -1;
    }
    std::string line;
    std::getline(ledFile, line);
    ledFile.close();
    int32_t value = std::stoi(line);
    return value;
}

Return<int32_t> Led::setLed(int32_t index, int32_t value) {
    std::ofstream ledFile(ledList[index]);
    if (!ledFile.is_open()) {
        ALOGE("Failed to open %s", ledList[index].c_str());
        return -1;
    }
    ledFile << value;
    if (ledFile.fail()) {
        ALOGE("Failed to write to %s", ledList[index].c_str());
        return -1;
    }
    ledFile.close();
    return 0;
}
}  // namespace vendor::dinhnamuet::led::implementation
