Unoficial CM-10.2 for Sony Xperia U

Getting Started :

    mkdir cm-10.2
    cd cm-10.2
    repo init -u git://github.com/CyanogenMod/android.git -b cm-10.2
    repo sync -j16
    cd device
    mkdir sony
    cd sony
    git clone https://github.com/Andrewas/android_device_sony_kumquat.git -b master kumquat
    cd kumquat

Now connect your phone which have runing FXP CM10 or CM10.1/CM10.2:

    ./extract-files.sh
    cd ../../..
    cd hardware
    git clone https://github.com/Andrewas/android_hardware_semc.git -b master semc
    cd ..
    mkdir -p kernel/sony
    cd kernel/sony
    git clone https://github.com/munjeni/android_kernel_xperiago.git -b jb-dev u8500
    cd ../..

Patch android source code :

    sudo patch -p1 < device/sony/kumquat/patches/external_bluetooth_bluedroid.patch
    sudo patch -p1 < device/sony/kumquat/patches/external_wpa_supplicant_8.patch
    sudo patch -p1 < device/sony/kumquat/patches/framework_av.patch
    sudo patch -p1 < device/sony/kumquat/patches/framework_native.patch
    sudo patch -p1 < device/sony/kumquat/patches/hardware_libhardware.patch
    sudo patch -p1 < device/sony/kumquat/patches/hardware_libhardware_legacy.patch
    sudo patch -p1 < device/sony/kumquat/patches/system_core.patch

Our step is optional!!! Use only if you going to sync CM source code daily, than simple revert each patch before you sync CM source code :

    sudo patch -p1 -R < device/sony/kumquat/patches/external_bluetooth_bluedroid.patch
    sudo patch -p1 -R < device/sony/kumquat/patches/external_wpa_supplicant_8.patch
    sudo patch -p1 -R < device/sony/kumquat/patches/framework_av.patch
    sudo patch -p1 -R < device/sony/kumquat/patches/framework_native.patch
    sudo patch -p1 -R < device/sony/kumquat/patches/hardware_libhardware.patch
    sudo patch -p1 -R < device/sony/kumquat/patches/hardware_libhardware_legacy.patch
    sudo patch -p1 -R < device/sony/kumquat/patches/system_core.patch
    sudo patch -p1 -R < device/sony/kumquat/patches/system_netd.patch
    repo forall -p -c 'git checkout -f'
    repo sync
    sudo patch -p1 < device/sony/kumquat/patches/external_bluetooth_bluedroid.patch
    sudo patch -p1 < device/sony/kumquat/patches/external_wpa_supplicant_8.patch
    sudo patch -p1 < device/sony/kumquat/patches/framework_av.patch
    sudo patch -p1 < device/sony/kumquat/patches/framework_native.patch
    sudo patch -p1 < device/sony/kumquat/patches/hardware_libhardware.patch
    sudo patch -p1 < device/sony/kumquat/patches/hardware_libhardware_legacy.patch
    sudo patch -p1 < device/sony/kumquat/patches/system_core.patch
    sudo patch -p1 < device/sony/kumquat/patches/system_netd.patch

Download CM prebuilts :
   cd vendor/cm
   ./get-prebuilts
   cd ../..

You are ready to build :

    . build/envsetup.sh
    lunch cm_kumquat-userdebug
    make otapackage

ENJOY! 
