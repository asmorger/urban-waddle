#pragma once

#include QMK_KEYBOARD_H
#include "keymap_us_extended.h"

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
};

enum custom_keycodes {
  SELWORD = SAFE_RANGE,
  ENTRTN
};

enum combo_events {
    CAPS_COMBO,
    COMBO_LENGTH
};
