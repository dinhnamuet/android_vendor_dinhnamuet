package vendor.dinhnamuet.hardware.led;

@VintfStability
interface ILedAidl {
    void setLed(in byte index, in byte value);
    byte getLed(in byte index);
}