TRI_LAYER_ENABLE = yes
CAPS_WORD_ENABLE = yes
# AUTO_SHIFT_ENABLE = yes
ENCODER_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = ssd1306

CONSOLE_ENABLE = no
MAGIC_ENABLE = no
MUSIC_ENABLE = no

LTO_ENABLE = yes

ACHORDION_ENABLE = yes
OPT_DEFS += -DACHORDION_ENABLE
SRC += features/achordion.c

LAYER_LOCK_ENABLE = yes
OPT_DEFS += -DLAYER_LOCK_ENABLE
SRC += features/layer_lock.c

# ORBITAL_MOUSE_ENABLE = yes
# MOUSE_ENABLE = yes
# OPT_DEFS += -DORBITAL_MOUSE_ENABLE
# SRC += features/orbital_mouse.c
