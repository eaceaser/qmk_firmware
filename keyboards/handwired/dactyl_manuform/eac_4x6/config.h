/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define PRODUCT_ID      0x3436
#define DEVICE_VER      0x0001
#define DESCRIPTION     eac dactyl manuform

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// row-driven
#define MATRIX_ROW_PINS { F7, B1, B3, B2, B6 }
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* rgbs */
#define RGB_DI_PIN C7
#define RGBLED_NUM 14
#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT {7, 7}
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_BREATHE_CENTER 1
#define RGBLIGHT_LAYERS

//#define RGBLIGHT_SLEEP
//#define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#define RGBLIGHT_EFFECT_KNIGHT
//#define RGBLIGHT_MODE_BREATHING 1
//
// split
#define USE_SERIAL
//#define SPLIT_USB_DETECT
//#define SPLIT_USB_TIMEOUT 2500
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D1
