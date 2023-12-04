OLED_ENABLE = yes
OLED_DRIVER = ssd1306
BOOTLOADER = atmel-dfu

# Link Time Optimization -> smaller size
LTO_ENABLE = yes

# disable stuff we don't need to further reduce size
# https://docs.qmk.fm/#/squeezing_avr?id=rulesmk-settings
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
MUSIC_ENABLE = no

# required for key_override_t
KEY_OVERRIDE_ENABLE = yes

# required for SH_T
SWAP_HANDS_ENABLE = yes

# required for key combos
COMBO_ENABLE = yes

# use advanced matrix effects (or do not and save space)
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes

# simplify shifting characters
CAPS_WORD_ENABLE = yes
COMMAND_ENABLE = no
