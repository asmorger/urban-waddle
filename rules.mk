MOUSEKEY_ENABLE  = yes    # Mouse keys
RGBLIGHT_ENABLE  = no    # Enable WS2812 RGB underlight.
OLED_ENABLE      = no
OLED_DRIVER      = SSD1306
LTO_ENABLE       = yes
TAP_DANCE_ENABLE = yes
LEADER_ENABLE    = yes
COMBO_ENABLE     = yes

SRC += features/caps_word.c
SRC += features/select_word.c
SRC += features/layermodes.c

# this enables the keyboard-driven reset functionality
BOOTLOADER = atmel-dfu
