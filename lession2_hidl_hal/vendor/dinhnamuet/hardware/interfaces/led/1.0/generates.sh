PACKAGE="vendor.dinhnamuet.led@1.0"
LOC="default/"
hidl-gen -o $LOC -Lc++-impl -rvendor.dinhnamuet:vendor/dinhnamuet/hardware/interfaces \
    -randroid.hidl:system/libhidl/transport $PACKAGE
hidl-gen -o $LOC -Landroidbp-impl -rvendor.dinhnamuet:vendor/dinhnamuet/hardware/interfaces \
    -randroid.hidl:system/libhidl/transport $PACKAGE
