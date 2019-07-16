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
#define JC_SLEEP LCTL(LSFT(KC_POWER))
#define JC_SCREEN_CLIP LCMD(LCTL(LSFT(KC_4)))
#define JC_WITCH_PREV LSFT(KC_TAB)
#define JC_NEXT_WS LCMD(KC_PGUP)
#define JC_PREV_WS LCMD(KC_PGDN)
