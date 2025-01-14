#ifndef CONFIG_USER_H

#define CONFIG_USER_H

// Uncomment this for debug mode
// And also set (and unset) CONSOLE_ENABLE in rules.mk
// #define USER_DEBUG_MODE

#include "../../config.h"

#define PREVENT_STUCK_MODIFIERS

#undef COMBO_COUNT
#define COMBO_COUNT 4

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200
#define COMBO_TERM 8

// Set Combined mode for mouse keys
#define MK_COMBINED
#define MOUSEKEY_DELAY 100
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_TIME_TO_MAX 20
#define MOUSEKEY_MAX_SPEED 16

// Set default
#define SPLIT_LAYER_STATE_ENABLE
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_TYPING_HEATMAP
#define RGB_MATRIX_SD_LAYER RGB_MATRIX_RAINBOW_MOVING_CHEVRON

#endif
