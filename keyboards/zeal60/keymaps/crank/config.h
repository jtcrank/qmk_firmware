#pragma once

/* enable/disable LEDs based on layout */
#undef RGB_BACKLIGHT_USE_SPLIT_BACKSPACE
#define RGB_BACKLIGHT_USE_SPLIT_BACKSPACE 0

#undef RGB_BACKLIGHT_USE_SPLIT_LEFT_SHIFT
#define RGB_BACKLIGHT_USE_SPLIT_LEFT_SHIFT 0

#undef RGB_BACKLIGHT_USE_SPLIT_RIGHT_SHIFT
#define RGB_BACKLIGHT_USE_SPLIT_RIGHT_SHIFT 0

#undef RGB_BACKLIGHT_USE_7U_SPACEBAR
#define RGB_BACKLIGHT_USE_7U_SPACEBAR 0

#undef RGB_BACKLIGHT_USE_ISO_ENTER
#define RGB_BACKLIGHT_USE_ISO_ENTER 0

#undef RGB_BACKLIGHT_DISABLE_HHKB_BLOCKER_LEDS
#define RGB_BACKLIGHT_DISABLE_HHKB_BLOCKER_LEDS 0

/* Custom Definitions */
#define TAPPING_TERM 200

#define JC_SLEEP LCMD(KC_L)
#define JC_CMD LALT(KC_F2)
// #define JC_SCREEN_CLIP LCMD(LCTL(LSFT(KC_4)))
#define JC_CHROME_MENU LCTL(LSFT(KC_M))
#define JC_SCREEN_CLIP LCTL(LSFT(KC_PSCR))
#define JC_WITCH_PREV LSFT(KC_TAB)
#define JC_NEXT_WS LCMD(KC_PGUP)
#define JC_PREV_WS LCMD(KC_PGDN)
#define JC_TMUX C(KC_B)
#define JC_ALBERT LCMD(LCTL(LSFT(KC_A)))

/* Mouse Settings */
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 8
#define MOUSEKEY_TIME_TO_MAX 80
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 80
