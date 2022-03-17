/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "features/keycodes.h"

// includes gboards combos from http://combos.gboards.ca/docs/install/
#include "g/keymap_combo.h"
#include "keymap_us_extended.h"

#include <stdio.h> 
#include "features/select_word.h"
#include "features/layermodes.h"
#include "features/case_mods.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_2(
  //,----------------------------------------------------------.                         ,-------------------------------------------------------------/
        KC_Q,          KC_W,      KC_E,       KC_R,        KC_T,                                    KC_Y,       KC_U,      KC_I,       KC_O,       KC_P,
  //|--------+-------------+----------+-----------+------------|                         |--------------+-----------+----------+----------+------------+
         KC_A,         KC_S,      KC_D,       KC_F,        KC_G,                             TD(DANCE_3),       KC_J,LT(4, KC_K),LT(3, KC_L),    KC_SCLN,
  //|--------+-------------+----------+-----------+------------|                         |--------------+-----------+----------+----------+------------+
         KC_Z,         KC_X,      KC_C,TD(DANCE_2),        KC_B,                                    KC_N,TD(DANCE_4),   KC_COMM,    KC_DOT,     KC_LEAD,
  //|--------+-------------+----------+-----------+------------+--------------|  |--------+-------------+-----------+----------+----------+------------+|
                                   MT(MOD_MEH,KC_SPACE), OSM(MOD_LSFT),    OSM(MOD_RCTL),  OSL(1)
                                     //`--------------------------------------'  `--------------------------------'

  ),
  [_SYM] = LAYOUT_split_3x5_2(
  //,-------------------------------------------.                    ,----------------------------------------------.
     KC_HASH, KC_COLN,      KC_LABK,     KC_RABK, KC_HASH,     LALT(KC_SPACE), KC_UNDS,   KC_PIPE,KC_QUOTE,  KC_DLR,
  //|-------+--------+--------+--------+--------|                    |--------+--------+---------+--------+---------|
     KC_LCBR, KC_RCBR,      KC_LPRN,     KC_RPRN,  KC_NO,             KC_EQUAL, KC_TILD, KC_SLASH, KC_DQUO, KC_ENTER,
  //|-------+--------+--------+--------+--------|                    |--------+--------+---------+--------+--------+|
      KC_DEL, KC_EXLM,  KC_LBRACKET, KC_RBRACKET, KC_BSPC,                TO(_NUM), KC_MINUS,KC_BSLASH, KC_GRAVE,   KC_ESC,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+---------+--------+--------+|
                                        KC_NO, LCTL(KC_BSPC),     KC_TAB,  KC_NO
                            //`--------------------------'  `--------------------------'
  ),
  [_NUM] = LAYOUT_split_3x5_2(
  //,---------------------------------------------.                    ,---------------------------------------------.
     KC_SLASH,    KC_7,    KC_8,    KC_9,  KC_PLUS,                      KC_QUES,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
  //|--------+--------+--------+--------+---------|                    |--------+--------+--------+--------+--------+|
         KC_0,    KC_1,    KC_2,    KC_3, KC_MINUS,                      KC_EXLM,   KC_F4,   KC_F5,   KC_F6,  KC_F11,
  //|--------+--------+--------+--------+---------|                    |--------+--------+--------+--------+--------+|
      KC_ASTR,    KC_4,    KC_5,    KC_6, KC_EQUAL,                      KC_LGUI,   KC_F1,   KC_F2,  KC_DOT,  KC_F12,
  //|--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+|
                                            TO(_BASE), KC_LSFT,     SELWORD,   TO(_NAV)
                             //`---------------------------'  `--------------------------'
  ),
  [_NAV] = LAYOUT_split_3x5_2(
  //,----------------------------------------------.                    ,--------------------------------------------------------------.
       RESET,  KC_PGUP,    KC_UP,  _______, _______,                      _______, _______, _______,       _______,             _______,
  //|-------+---------+---------+---------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_HOME,  KC_LEFT,  KC_DOWN, KC_RIGHT,  KC_END,                      _______, KC_LGUI, LCTL(KC_LALT), _______, LCTL(LSFT(KC_LALT)),
  //|-------+---------+---------+---------+--------|                    |--------+--------+--------+--------------+--------------------|
     _______,KC_PGDOWN,  _______,  _______, _______,                      _______, _______, _______,       _______,             RESET,
  //|-------+---------+---------+---------+--------+--------|  |--------+--------+--------+--------+--------------+--------------------|
                                            KC_LSFT, KC_BSPC,     KC_DEL, ENTRTN
                                        //`---------------------------'  `--------------------------'
  ),
  [_NUM2] = LAYOUT_split_3x5_2(
  //,---------------------------------------------.                    ,---------------------------------------------.
     KC_SLASH,    KC_7,    KC_8,    KC_9,  KC_PLUS,                      _______,   _______,   _______,   _______,  _______,
  //|--------+--------+--------+--------+---------|                    |--------+--------+--------+--------+--------+|
         KC_0,    KC_1,    KC_2,    KC_3, KC_MINUS,                      _______,   _______,   _______,   _______,  _______,
  //|--------+--------+--------+--------+---------|                    |--------+--------+--------+--------+--------+|
      KC_ASTR,    KC_4,    KC_5,    KC_6, KC_EQUAL,                      _______,   _______,   _______,  _______,  _______,
  //|--------+--------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+--------+|
                                            TO(_BASE), KC_LSFT,     KC_LGUI,   ENTRTN
                             //`---------------------------'  `--------------------------'
  ),
  [_SYM2] = LAYOUT_split_3x5_2(
  //,-------------------------------------------.                    ,----------------------------------------------.
     KC_HASH, KC_COLN,      KC_LABK,     KC_RABK, KC_HASH,             _______, _______,  _______, _______,  _______,
  //|-------+--------+--------+--------+--------|                    |--------+--------+---------+--------+---------|
     KC_LCBR, KC_RCBR,      KC_LPRN,     KC_RPRN,  KC_NO,              _______, _______,  KC_EQUAL, _______,  _______,
  //|-------+--------+--------+--------+--------|                    |--------+--------+---------+--------+--------+|
      KC_DEL, KC_EXLM,  KC_LBRACKET, KC_RBRACKET, KC_BSPC,             _______, _______,  _______, _______,  _______,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+---------+--------+--------+|
                                        KC_NO, LCTL(KC_BSPC),     KC_TAB,  KC_LEAD
                            //`--------------------------'  `--------------------------'=
  ),
};

static bool linux_mode = false;
bool in_linux(void) {
    return linux_mode;
}

static bool swap_caps_escape = true;
bool is_caps_swapped(void) {
    return swap_caps_escape;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_num_word(keycode, record)) { return false; } 
  if (!process_case_modes(keycode, record)) { return false; } 
  if (!process_select_word(keycode, record, SELWORD)) { return false; }

  switch (keycode)
  { 
    case ENTRTN:
        if (record->event.pressed) {
            layer_move(_BASE);
            
            tap_code16(KC_ENTER);
            return false;            
        } 
        break;

    case NUMWORD:
        process_num_word_activation(record);
        return false;

    case CAPSWORD:
        if (record->event.pressed) {
            enable_caps_word();
        }
        return false;

    case SNAKECASE:
        if (record->event.pressed) {
            enable_xcase_with(KC_UNDS);
        }
        return false;

    default:
        break;
  }

  return true;
}

// https://github.com/andrewjrae/kyria-keymap#case-modes
bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        // Keycodes to ignore (don't disable caps word)
            case KC_A ... KC_Z:
            case KC_1 ... KC_0:
            case KC_MINS:
            case KC_UNDS:
            case KC_BSPC:
            case CAPSWORD:
            case SNAKECASE:
            // If mod chording disable the mods
            if (record->event.pressed && (get_mods() != 0)) {
                return true;
            }
            break;
        default:
            if (record->event.pressed) {
                return true;
            }
            break;
    }
    return false;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  //caps_word_task();

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) { SEND_STRING(SS_LCTL(SS_TAP(X_E) SS_TAP(X_F))); }
    SEQ_ONE_KEY(KC_N) { SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_INSERT)))); }
    SEQ_ONE_KEY(KC_Z) { SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_Z)))); }

    // Dotnet
    SEQ_ONE_KEY(KC_B) { SEND_STRING(SS_LCTRL(SS_LSFT("b"))); }
    SEQ_ONE_KEY(KC_R) { SEND_STRING(SS_LCTL(SS_TAP(X_R) SS_TAP(X_R))); }

    SEQ_TWO_KEYS(KC_D, KC_B) { SEND_STRING("dotnet build" SS_TAP(X_ENTER)); }
    SEQ_TWO_KEYS(KC_D, KC_T) { SEND_STRING("dotnet test" SS_TAP(X_ENTER)); }
    SEQ_TWO_KEYS(KC_D, KC_W) { SEND_STRING("dotnet watch" SS_TAP(X_ENTER)); }
    SEQ_TWO_KEYS(KC_D, KC_O) { SEND_STRING("dotnet outdated " SS_TAP(X_ENTER)); }

    SEQ_TWO_KEYS(KC_A, KC_F) { SEND_STRING("() => ;" SS_TAP(X_LEFT)); }

    // Git
    SEQ_TWO_KEYS(KC_G, KC_P) { SEND_STRING("git push "); }
    SEQ_THREE_KEYS(KC_G, KC_F, KC_P) { SEND_STRING("git push --force-with-lease"); }
    SEQ_TWO_KEYS(KC_G, KC_U) { SEND_STRING("git pull "); }
    SEQ_TWO_KEYS(KC_G, KC_A) { SEND_STRING("git add ."); }
    SEQ_TWO_KEYS(KC_G, KC_D) { SEND_STRING("git diff "); }
    SEQ_THREE_KEYS(KC_G, KC_D, KC_S) { SEND_STRING("git diff --staged "); }
    SEQ_TWO_KEYS(KC_G, KC_L) { SEND_STRING("git log "); }
    SEQ_THREE_KEYS(KC_G, KC_L, KC_O) { SEND_STRING("git log --oneline "); }
    SEQ_TWO_KEYS(KC_G, KC_O) { SEND_STRING("git checkout "); }
    SEQ_THREE_KEYS(KC_G, KC_O, KC_B) { SEND_STRING("git checkout -b "); }
    SEQ_TWO_KEYS(KC_G, KC_S) { SEND_STRING("git status "); }
    SEQ_TWO_KEYS(KC_G, KC_C) { SEND_STRING("git commit "); }
    SEQ_THREE_KEYS(KC_G, KC_C, KC_S) { SEND_STRING("git commit -sm ''" SS_TAP(X_LEFT)); }
    SEQ_THREE_KEYS(KC_G, KC_C, KC_A) { SEND_STRING("git commit --amend -m ''" SS_TAP(X_LEFT)); }
  }
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[6];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_W);
        tap_code16(KC_W);
        tap_code16(KC_W);
    }
    if(state->count > 3) {
        tap_code16(KC_W);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_W); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_W)); break;
        case DOUBLE_TAP: register_code16(KC_W); register_code16(KC_W); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_W); register_code16(KC_W);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_W); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_W)); break;
        case DOUBLE_TAP: unregister_code16(KC_W); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_W); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_T);
        tap_code16(KC_T);
        tap_code16(KC_T);
    }
    if(state->count > 3) {
        tap_code16(KC_T);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_T); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_T)); break;
        case DOUBLE_TAP: register_code16(KC_T); register_code16(KC_T); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_T); register_code16(KC_T);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_T); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_T)); break;
        case DOUBLE_TAP: unregister_code16(KC_T); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_T); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_V);
        tap_code16(KC_V);
        tap_code16(KC_V);
    }
    if(state->count > 3) {
        tap_code16(KC_V);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_V); break;
        case SINGLE_HOLD: register_code16(KC_F22); break;
        case DOUBLE_TAP: register_code16(KC_V); register_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_V); register_code16(KC_V);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_V); break;
        case SINGLE_HOLD: unregister_code16(KC_F22); break;
        case DOUBLE_TAP: unregister_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_V); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_H);
        tap_code16(KC_H);
        tap_code16(KC_H);
    }
    if(state->count > 3) {
        tap_code16(KC_H);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_H); break;
        case SINGLE_HOLD: register_code16(LALT(KC_ENTER)); break;
        case DOUBLE_TAP: register_code16(KC_H); register_code16(KC_H); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_H); register_code16(KC_H);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_H); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_ENTER)); break;
        case DOUBLE_TAP: unregister_code16(KC_H); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_H); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_M);
        tap_code16(KC_M);
        tap_code16(KC_M);
    }
    if(state->count > 3) {
        tap_code16(KC_M);
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_M); break;
        case SINGLE_HOLD: register_code16(KC_F21); break;
        case DOUBLE_TAP: register_code16(KC_M); register_code16(KC_M); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_M); register_code16(KC_M);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_M); break;
        case SINGLE_HOLD: unregister_code16(KC_F21); break;
        case DOUBLE_TAP: unregister_code16(KC_M); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_M); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
    }
    if(state->count > 3) {
        tap_code16(KC_SLASH);
    }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_SLASH); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_GRAVE)); break;
        case DOUBLE_TAP: register_code16(KC_SLASH); register_code16(KC_SLASH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_SLASH); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_GRAVE)); break;
        case DOUBLE_TAP: unregister_code16(KC_SLASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLASH); break;
    }
    dance_state[5].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
};
