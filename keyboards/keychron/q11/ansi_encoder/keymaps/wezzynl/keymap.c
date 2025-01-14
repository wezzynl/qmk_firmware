/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#ifndef USER_DEBUG_MODE
  // This is for debugging
  #include "print.h"
#endif

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    SD,
    CTL,
};

// #define RELEASE_CTRL_SEMI 24873 // This is for Clueboard
#define RELEASE_CTRL_SEMI 8489 // This is for Keychron Q11

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define xxxxxx KC_NO   // Disallows fallback to keys from lower layer
#define xxxx KC_NO   // Disallows fallback to keys from lower layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,                   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RM_VALD,   RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_INS,   KC_DEL,   KC_MUTE,
        _______,  KC_GRV,                   KC_1,     KC_2,       KC_3,   KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,                   KC_Q,     KC_W,       KC_E,   KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  MT(MOD_LCTL, KC_ESCAPE),  KC_A,     KC_S,       KC_D,   KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        _______,  KC_LSFT,                  KC_Z,     KC_X,       KC_C,   KC_V,     KC_B,      KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  MO(MAC_FN),               KC_LCTL,  KC_LOPT,    KC_LCMD,          KC_ENT,                        KC_SPC,             KC_RCMD,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_91_ansi(
        QK_BOOT,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  _______,  QK_BOOT,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,   _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

    [SD] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,                   KC_BRID,  KC_BRIU,         KC_MCTL,  KC_LPAD,  RM_VALD,   RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_INS,   KC_DEL,   KC_MUTE,
        _______,  KC_GRV,                   xxxx,     xxxx,            xxxx,     KC_END,   xxxx,      xxxx,     xxxx,        xxxx,                 xxxx,                 KC_HOME,  xxxxxx,     xxxxxx,   KC_BSPC, KC_PGUP,
        _______,  LCTL(KC_TAB),             xxxx,     LCTL(KC_RIGHT),  xxxx,     KC_R,     xxxx,      xxxx,     KC_PGUP,     LSFT(LGUI(KC_LBRC)),  LSFT(LGUI(KC_RBRC)),  xxxx,     KC_LBRC,    xxxxxx,   xxxxxx,  KC_PGDN,
        _______,  KC_ESC,                   KC_A,     xxxx,            KC_PGDN,  KC_F,     KC_BSPC,   KC_LEFT,  KC_DOWN,     KC_UP,                KC_RIGHT,             KC_F19,   xxxxxx,               KC_ENT,   _______,
        _______,  KC_LSFT,                  KC_Z,     KC_X,            KC_C,     KC_V,     KC_B,      KC_N,     KC_M,        KC_COMM,              KC_DOT,               KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,                  KC_LOPT,  MO(MAC_FN),      KC_LCMD,  KC_ENT,                                     KC_SPC,               KC_RCMD,              MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [CTL] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,                   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RM_VALD,   RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_INS,   KC_DEL,   KC_MUTE,
        _______,  LSFT(KC_TAB),             KC_1,     KC_2,       KC_3,   KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,                   KC_Q,     KC_W,       KC_E,   KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  MT(MOD_LCTL, KC_ESCAPE),  KC_A,     KC_S,       KC_D,   KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        _______,  KC_LSFT,                  KC_Z,     KC_X,       KC_C,   KC_V,     KC_B,      KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,                  KC_LOPT,  MO(MAC_FN), KC_LCMD,          KC_ENT,                        KC_SPC,             KC_RCMD,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_BASE] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LWIN,  KC_LALT,  MO(WIN_FN),         KC_SPC,                        KC_SPC,             KC_RALT,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_91_ansi(
        QK_BOOT,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,   RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  QK_BOOT,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,   _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [SD]       = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [CTL]      = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif // ENCODER_MAP_ENABLE

void sd_layer_on(void) {
    layer_on(SD);
    rgb_matrix_mode(RGB_MATRIX_SD_LAYER);
}
void sd_layer_off(void) {
    layer_off(SD);
    rgb_matrix_mode(RGB_MATRIX_DEFAULT_MODE);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case MAC_FN:
            case WIN_FN:
                rgb_matrix_set_color(i, RGB_YELLOW);
                break;
            default:
                break;
        }
    }
    return false;
}

bool forced_ctl_tab = false;
bool forced_super_duper = false;
bool sticky_super_duper = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifndef USER_DEBUG_MODE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
  #endif

  uint8_t layer = biton32(layer_state);

  switch (keycode) {
    case QK_BOOT:
        rgb_matrix_mode(RGB_MATRIX_BAND_SPIRAL_VAL);
        break;
    }

  if (layer == CTL) {
    switch (keycode) {
    case KC_LALT:
      if (!record->event.pressed && forced_ctl_tab) {
        unregister_code(KC_LCTL);
        layer_off(CTL);
        forced_ctl_tab = false;
      }
    }
  }

  if (layer == SD) {
    // Not sure what keycode RELEASE_CTRL_SEMI is but it's what I found when printing keycode
    // to the console when releasing control as MOD_LCTL (going back from ctrl-semi/SD)
    switch (keycode) {
      case KC_4:
        if(!record->event.pressed && keyboard_report->mods & MOD_BIT(KC_LSFT) ) {
          unregister_code(KC_LSFT);
          register_code(KC_LALT);
          register_code(KC_DOWN);
          unregister_code(KC_DOWN);
          unregister_code(KC_LALT);
          return false;
        }
      return false;

      case RELEASE_CTRL_SEMI:
        if(!record->event.pressed && forced_super_duper && keycode == RELEASE_CTRL_SEMI && sticky_super_duper == false) {
          forced_super_duper = false;
          sd_layer_off();
          return false;
        }
        return true;

      case KC_ESCAPE:
        if(record->event.pressed) {
          forced_super_duper = false;
          sticky_super_duper = false;
          sd_layer_off();
        }
        return false;

      case KC_LBRC:
        if(record->event.pressed) {
          if (sticky_super_duper) {
            forced_super_duper = false;
            sticky_super_duper = false;
            sd_layer_off();
          } else {
            sticky_super_duper = true;
          }
        }
        return false;
      default:
        return true;
    }
  }

  if (layer != MAC_BASE) { return true; }

  switch (keycode) {
    // Tab prev/next
    case KC_I:
      if(record->event.pressed && (keyboard_report->mods & MOD_MASK_SHIFT) && (keyboard_report->mods & MOD_MASK_GUI)) {
        clear_mods();
        register_code(KC_LCTL);
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
        unregister_code(KC_LCTL);

        register_code(KC_LSFT);
        register_code(KC_LGUI);
        return false;
      }
    case KC_O:
      if(record->event.pressed && (keyboard_report->mods & MOD_MASK_SHIFT) && (keyboard_report->mods & MOD_MASK_GUI)) {
        clear_mods();
        register_code(KC_LCTL);
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
        unregister_code(KC_LCTL);

        register_code(KC_LSFT);
        register_code(KC_LGUI);
        return false;
      }
    // Alt tab movements
    case KC_TAB:
      if (record->event.pressed && keyboard_report->mods & MOD_BIT(KC_LALT) && forced_ctl_tab == false) {
        forced_ctl_tab = true;
        clear_mods();
        register_code(KC_LCTL);
        layer_on(CTL);
        register_code(KC_TAB);
        unregister_code(KC_TAB);
        return false;
      }
      return true;
    case KC_GRAVE:
      if (record->event.pressed && keyboard_report->mods & MOD_BIT(KC_LALT) && forced_ctl_tab == false) {
        forced_ctl_tab = true;
        clear_mods();
        register_code(KC_LCTL);
        layer_on(CTL);
        register_code(KC_LSFT);
        register_code(KC_TAB);
        unregister_code(KC_TAB);
        unregister_code(KC_LSFT);
        return false;
      }
      return true;

    case KC_SCLN:
      if (record->event.pressed && keyboard_report->mods & MOD_BIT(KC_LCTL) && forced_super_duper == false) {
        forced_super_duper = true;
        sd_layer_on();
        clear_mods();
        return false;
      }
      return true;

    default:
      return true;
  }
}


// user defined combo
enum combo_events {
  COMBO_SUPERDUPER,
};

const uint16_t PROGMEM combo_superduper[] = {KC_S, KC_D, COMBO_END};

__attribute__ ((weak))
combo_t key_combos[COMBO_COUNT] = {
  [COMBO_SUPERDUPER] = COMBO_ACTION(combo_superduper),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
  case COMBO_SUPERDUPER:
    if (pressed) {
      sd_layer_on();
    } else {
      sd_layer_off();
    }
    break;
  }
}
