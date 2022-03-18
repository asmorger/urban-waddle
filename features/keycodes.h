#pragma once

#include QMK_KEYBOARD_H
#include "keymap_us_extended.h"

enum layers {
  _QWERTY = 0,
  _SYM,
  _NUM,
  _NAV,
  _NUM2,
  _SYM2,
  _COLEMAK
};

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
  ENTRTN,
  CANCEL,
  CAPSWORD,
  NUMWORD,
  SNAKECASE
};