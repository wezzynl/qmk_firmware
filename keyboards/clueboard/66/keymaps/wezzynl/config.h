#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../rev2/config.h"

#define PREVENT_STUCK_MODIFIERS

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 6

#undef COMBO_COUNT
#define COMBO_COUNT 4

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200
#define COMBO_TERM 8

#endif
