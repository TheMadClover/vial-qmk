SERIAL_DRIVER = vendor

SRC += oneshot.c
SRC += swapper.c
SRC += encoder.c
SRC += ghosting.c
SRC += matrix.c

COMBO_ENABLE = yes
VIA_ENABLE = yes
VIAL_ENABLE = yes
ENCODER_MAP_ENABLE = yes

CAPS_WORD_ENABLE = yes
CUSTOM_MATRIX = lite
WS2812_DRIVER = vendor
RGBLIGHT_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
