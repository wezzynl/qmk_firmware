#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../rev2/config.h"

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

#endif
