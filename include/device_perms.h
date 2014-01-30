/* needed for bluetoothd (Bluez 5.14) */
#define CONTROL_PERMS_APPEND \
    { "bluetoothd", AID_BLUETOOTH, AID_BLUETOOTH }, \
    { "bluetoothd-snoop", AID_NOBODY, AID_NOBODY },

/* need for camera */
#define PROPERTY_PERMS_APPEND \
    {"camera.0.", AID_MEDIA, 0},

