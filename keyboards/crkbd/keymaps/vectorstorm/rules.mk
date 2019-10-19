
# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \

# Simple RGBlight functionality
#RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.

# Fancy RGB Matrix functionity
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = WS2812

LINK_TIME_OPTIMIZATION_ENABLE = yes
MOUSEKEY_ENABLE = no
COMBO_ENABLE = no
TAP_DANCE_ENABLE = no
NKRO_ENABLE = yes

