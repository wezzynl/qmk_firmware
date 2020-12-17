// #include "print.h"

#include QMK_KEYBOARD_H

// Helpful defines for a bit more readability in the keymaps
#define _______ KC_TRNS // Allows fallback to keys from lower layer
#define xxxxxxx KC_NO   // Disallows fallback to keys from lower layer

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0 // Base layer
#define _FL 1 // Fn layer
#define _CL 2 // Color layer (includes firmware reset: fn+s+r)
#define _PL 3 // Programming layer
#define _SD 4 // SuperDuper layer
#define _CTL 5 // Control Tab layer
#define _GL 7 // GOD layer should always be at top so we're always able to switch to it.

// These are called with `FUNC(x)` where `x` is the index.
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESCAPE),
};


/* Empty map
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______,                   _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______,                            \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,                   \
  _______, _______, _______, _______,          _______, _______,                   _______, _______,  _______,  _______, _______, _______, _______,
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
  [_BL] = KEYMAP(
                 KC_GRAVE,         KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_GRV,  KC_BSPC,          KC_PGUP, \
                 KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,                   KC_PGDOWN, \
                 MT(MOD_LCTL, KC_ESCAPE),  KC_A,   KC_S,   KC_D,   KC_F,           KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT, \
                 KC_LSFT, KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,           KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,  MO(_FL),          KC_UP,            \
                 TT(_SD), MO(_GL), KC_LALT,KC_LGUI,        KC_ENT, KC_SPC,                         MO(_FL), KC_RGUI,  MO(_PL), KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _FL: Function Layer
   */
  [_FL] = KEYMAP(
                 KC_GRV,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______, KC_DEL,           BL_STEP, \
                 _______, _______, _______,_______,_______,_______,_______,_______,_______,KC_SLCK, KC_PAUS,  _______,  _______,  _______,                   _______, \
                 _______, _______, MO(_CL),_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                            \
                 _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  MO(_FL),          KC_PGUP,          \
                 _______, _______, _______,_______,        _______,_______,                         _______,  _______,  _______,  MO(_FL), KC_HOME, KC_PGDN, KC_END),

  /* Keymap _CL: Color layer (includes reset: fn+s+r)
   */
  [_CL] = KEYMAP(
                 _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______, RGB_TOG,          RGB_VAI, \
                 _______, _______, _______,_______,RESET,  _______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                   RGB_VAD, \
                 _______, _______, MO(_CL),_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                            \
                 _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  MO(_FL),          RGB_SAI,          \
                 _______, _______, _______,_______,        RGB_MOD,   RGB_MOD,                      _______,  _______,  _______,  MO(_FL), RGB_HUD, RGB_SAD, RGB_HUI),

  // Programming Layer
  [_PL] = KEYMAP(
                 _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,     _______,    _______, _______, _______, _______, RGB_VAI, \
                 _______, _______, _______, _______, _______, _______, _______,  KC_LBRC, KC_RBRC, _______,     _______,    _______, _______, _______,          RGB_VAD, \
                 _______, KC_LALT, _______, _______, KC_LGUI, KC_BSPC, KC_MINUS, KC_LPRN, KC_RPRN, KC_KP_EQUAL, KC_KP_PLUS, _______, _______, _______, \
                 _______, _______, _______, _______, _______, _______, _______,  KC_LCBR, KC_RCBR, _______, _______, _______, _______, MO(_FL), RGB_SAI,          \
                 _______, _______, _______, _______,          _______, _______,           _______,  _______,    _______, MO(_FL), RGB_HUD, RGB_SAD, RGB_HUI),

  // Super Duper
  [_SD] = KEYMAP(
                 xxxxxxx,       xxxxxxx, xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,          RGB_VAI, \
                 LCTL(KC_TAB),  _______, xxxxxxx,xxxxxxx,KC_R   ,xxxxxxx,xxxxxxx,LGUI(KC_C),LSFT(LGUI(KC_LBRC)),LSFT(LGUI(KC_RBRC)), xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                   RGB_VAD, \
                 KC_ESCAPE,     KC_LALT, _______,_______,KC_LGUI,KC_BSPC,KC_LEFT,KC_DOWN,KC_UP, KC_RIGHT, KC_F19, xxxxxxx, xxxxxxx, _______, \
                 _______,       _______, xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx, LGUI(KC_V),KC_ENT,KC_BSPC,LGUI(KC_X), xxxxxxx, xxxxxxx,          MO(_FL), RGB_SAI, \
                 _______,       _______, _______,KC_LSFT,        KC_ENT ,   KC_LALT,           KC_F19 , xxxxxxx, _______, MO(_FL), RGB_HUD, RGB_SAD, RGB_HUI),

  // Control tab layer
  [_CTL] = KEYMAP(
                 LSFT(KC_TAB),         KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_GRV,  KC_BSPC,          KC_PGUP, \
                 KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,                   KC_PGDOWN, \
                 FUNC(0),  KC_A,   KC_S,   KC_D,   KC_F,           KC_G,   KC_H,   KC_TAB,   LSFT(KC_TAB),   KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT, \
                 KC_LSFT, KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,           KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,  MO(_FL),          KC_UP,            \
                 MO(_PL), MO(_GL), KC_LCTL,KC_LGUI,        KC_ENT, KC_SPC,                         MO(_FL), KC_RGUI,  MO(_PL), KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT),

  // GOD layer
  [_GL] = KEYMAP(
                 xxxxxxx,       xxxxxxx, xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, TO(_BL),          KC__VOLUP, \
                 LCTL(KC_TAB),  xxxxxxx, xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                   KC__VOLDOWN, \
                 FUNC(0),       KC_LALT, _______,_______,KC_LGUI,xxxxxxx,KC_LEFT,KC_DOWN,KC_UP, KC_RIGHT, xxxxxxx, xxxxxxx, xxxxxxx, _______, \
                 _______,       _______, xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          KC__MUTE, KC_AUDIO_VOL_UP,          \
                 _______,       xxxxxxx, xxxxxxx,KC_LSFT,        KC_ENT ,   LCTL(LGUI(KC_SPC)),           KC_F19 , xxxxxxx, _______, MO(_FL), xxxxxxx, KC_AUDIO_VOL_DOWN, xxxxxxx),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
};

rgblight_config_t rgblight_config;
void disable_rgb(void) {
  dprintf("eeconfig_update_rgblight_default\n");
  rgblight_config.enable = 1;
  rgblight_config.mode = 1;
  rgblight_config.hue = 0;
  rgblight_config.sat = 0;
  rgblight_config.val = 0;
  eeconfig_update_rgblight(rgblight_config.raw);
}

void enable_rgb(void) {
  dprintf("eeconfig_update_rgblight_default\n");
  rgblight_config.enable = 1;
  rgblight_config.mode = 1;
  rgblight_config.hue = 0;
  rgblight_config.sat = 255;
  rgblight_config.val = 155;
  eeconfig_update_rgblight(rgblight_config.raw);
}

void LayerLEDSet(uint8_t layr) {
  switch (layr) {
  case _FL:
    enable_rgb();
    rgblight_setrgb(255, 125, 0);
    break;
  case _CL:
    enable_rgb();
    rgblight_setrgb(255, 0, 0);
    break;
  case _SD:
    enable_rgb();
    rgblight_setrgb(0, 0, 255);
    break;
  case _PL:
    enable_rgb();
    rgblight_setrgb(0, 255, 0);
    break;
  case _GL:
    enable_rgb();
    rgblight_setrgb(255, 255, 255);
    break;
  case _CTL:
    enable_rgb();
    rgblight_setrgb(0, 0, 25);
    break;
  default:
    disable_rgb();
    rgblight_setrgb(0, 0, 0);
    break;
  }
  return;
}

uint8_t old_layer = _BL;
bool led_shift = false;

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  if (old_layer != layer) {
    LayerLEDSet(layer);
    old_layer = layer;
  }
  if (!led_shift && layer == _SD && keyboard_report->mods & MOD_BIT(KC_LGUI)) {
    rgblight_setrgb(255, 255, 0);
    led_shift = true;
  } else if (!led_shift && layer == _SD && keyboard_report->mods & MOD_BIT(KC_LALT)) {
    rgblight_setrgb(0, 255, 255);
    led_shift = true;
  } else if (led_shift && !(keyboard_report->mods & MOD_BIT(KC_LGUI)) && !(keyboard_report->mods & MOD_BIT(KC_LALT))) {
    led_shift = false;
    LayerLEDSet(layer);
  }
}

void leader_start(void) {
  enable_rgb();
  rgblight_setrgb(255, 255, 255);
}

void leader_end(void) {
  disable_rgb();
  rgblight_setrgb(0, 0, 0);
}

bool forced_ctl_tab = false;
bool forced_super_duper = false;
bool sticky_super_duper = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
  uint8_t layer = biton32(layer_state);
  if (layer == _CTL) {
    switch (keycode) {
    case KC_LALT:
      if (!record->event.pressed && forced_ctl_tab) {
        unregister_code(KC_LCTL);
        layer_off(_CTL);
        forced_ctl_tab = false;
      }
    }
  }

  if (layer ==_SD) {
    // Not sure what keycode 24873 is but it's what I found when printing keycode
    // to the console when releasing control as MOD_LCTL
    // uprintf("%u", MOD_LCTL);
    switch (keycode) {
      case 24873:
        if(!record->event.pressed && forced_super_duper && keycode == 24873 && sticky_super_duper == false) {
          forced_super_duper = false;
          layer_off(_SD);
          return false;
        }
        return true;

      case KC_ESCAPE:
        if(record->event.pressed) {
          forced_super_duper = false;
          sticky_super_duper = false;
          layer_off(_SD);
        }
        return false;

      case KC_R:
        if(record->event.pressed) {
          if (sticky_super_duper) {
            forced_super_duper = false;
            sticky_super_duper = false;
            layer_off(_SD);
          } else {
            sticky_super_duper = true;
          }
        }
        return false;
      default:
        return true;
    }
  }

  if (layer != _BL) { return true; }

  switch (keycode) {
    // Alt tab movements
    case KC_TAB:
      if (record->event.pressed && keyboard_report->mods & MOD_BIT(KC_LALT) && forced_ctl_tab == false) {
        forced_ctl_tab = true;
        clear_mods();
        register_code(KC_LCTL);
        layer_on(_CTL);
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
        layer_on(_CTL);
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
        layer_on(_SD);
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
  COMBO_PROGRAM,
  COMBO_COMMAND,
  COMBO_CONTROL,
};


const uint16_t PROGMEM combo_superduper[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_program[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_command[] = {KC_K, KC_M, COMBO_END};
const uint16_t PROGMEM combo_control[] = {KC_J, KC_N, COMBO_END};

__attribute__ ((weak))
combo_t key_combos[COMBO_COUNT] = {
  [COMBO_SUPERDUPER] = COMBO_ACTION(combo_superduper),
  [COMBO_PROGRAM] = COMBO_ACTION(combo_program),
  [COMBO_COMMAND] = COMBO_ACTION(combo_command),
  [COMBO_CONTROL] = COMBO_ACTION(combo_control),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
  case COMBO_SUPERDUPER:
    if (pressed) {
      layer_on(_SD);
    } else {
      layer_off(_SD);
    }
    break;

  case COMBO_PROGRAM:
    if (pressed) {
      layer_on(_PL);
    } else {
      layer_off(_PL);
    }
    break;

  case COMBO_COMMAND:
    if (pressed) {
      enable_rgb();
      rgblight_setrgb(0, 180, 220);
      add_mods(MOD_BIT(KC_LGUI));
      send_keyboard_report();
    } else {
      disable_rgb();
      rgblight_setrgb(0, 0, 0);
      del_mods(MOD_BIT(KC_LGUI));
      send_keyboard_report();
    }
    break;

  case COMBO_CONTROL:
    if (pressed) {
      enable_rgb();
      rgblight_setrgb(255, 0, 185);
      add_mods(MOD_BIT(KC_RCTL));
      send_keyboard_report();
    } else {
      disable_rgb();
      rgblight_setrgb(0, 0, 0);
      del_mods(MOD_BIT(KC_RCTL));
      send_keyboard_report();
    }
    break;
  }
}
