#include QMK_KEYBOARD_H

#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _HYPER 3

// Fillers to make layering more clear

#define ____ KC_TRNS

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define HYPER MO(_HYPER)

#define ALL_LEDS 0, 14
#define HSV_GRUVBOX_PURPLE 226, 143, 143
#define HSV_GRUVBOX_BLUE 128, 125, 135
#define HSV_GRUVBOX_RED 1, 219, 204
#define HSV_GRUVBOX_GREEN 43, 212, 153

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT( \
    KC_TAB,   KC_Q,     KC_W,   KC_E,   KC_R,   KC_T,               KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_BSLASH, \
    KC_ESC,   KC_A,     KC_S,   KC_D,   KC_F,   KC_G,               KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,  \
    KC_LSFT,  KC_Z,     KC_X,   KC_C,   KC_V,   KC_B,               KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_MINUS, \
    KC_GRAVE, KC_EQUAL, KC_HOME,KC_END,                                             KC_PGUP, KC_PGDN,KC_LBRC, KC_RBRC, \
                                   LOWER, RAISE     ,               KC_ENT, KC_SPC,                                  \
                                   KC_LCTRL, KC_LALT,               KC_BSPC, KC_PGUP,                               \
                                      KC_LGUI, KC_NO,               KC_PGUP, KC_PGDN                                \
),


[_LOWER] = LAYOUT(
    _______,_______,_______,_______,_______,_______,            _______, KC_P7, KC_P8,  KC_P9,  RESET,  KC_MUTE,   \
    _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,            KC_RPRN, KC_P4, KC_P5,  KC_P6,  KC_MINS,KC_VOLU,   \
    _______,_______,_______,_______,_______,_______,            NK_TOGG, KC_P1, KC_P2,  KC_P3,  KC_EQL, KC_VOLD,   \
    _______,RGB_M_B,RGB_VAI,RGB_TOG,                                            _______,_______,_______,_______,   \
                                            _______,HYPER,      _______, KC_P0,                                    \
                                            _______,_______,    _______,_______,                                   \
                                            _______,_______,    _______,_______                                    \
),

[_RAISE] = LAYOUT(
    KC_GRAVE ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,            KC_6   ,KC_7   ,KC_8   ,KC_9   , KC_0  ,KC_EQUAL,   \
    _______  ,_______,_______,_______,_______,_______,            KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,KC_VOLU,   \
    _______  ,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,KC_VOLD,   \
    _______  ,_______,_______,_______,                                            _______,_______,_______,_______,   \
                                            HYPER  ,_______,    _______, _______,                                   \
                                            _______,_______,    KC_DEL , _______,                                   \
                                            _______,_______,    KC_HOME,KC_END                                     \
),

[_HYPER] = LAYOUT(
    _______,KC_F1  ,KC_F2   ,KC_F3  ,KC_F4   ,KC_F5,            KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  , KC_F10,KC_MUTE,   \
    _______,_______,_______,_______,_______,_______,            KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,   \
    _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,KC_VOLD,   \
    _______,_______,_______,_______,                                            _______,_______,_______,EEP_RST,   \
                                            _______,_______,    KC_DEL, _______,                                   \
                                            _______,_______,    _______,_______,                                   \
                                            _______,_______,    _______,_______                                    \
)
};

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM base_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {ALL_LEDS, HSV_GRUVBOX_PURPLE}
);

const rgblight_segment_t PROGMEM raise_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {ALL_LEDS, HSV_GRUVBOX_BLUE}
);

const rgblight_segment_t PROGMEM lower_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {ALL_LEDS, HSV_GRUVBOX_RED}
);

const rgblight_segment_t PROGMEM hyper_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {ALL_LEDS, HSV_GRUVBOX_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer_rgb,
    lower_layer_rgb,
    raise_layer_rgb,
    hyper_layer_rgb
);

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
  rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
  rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
  rgblight_set_layer_state(3, layer_state_cmp(state, _HYPER));
  //rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+3);
  return state;
}
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  //rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
#ifdef RGBLIGHT_LAYERS
  rgblight_layers = my_rgb_layers;
#endif
}

void suspend_power_down_user(void) {
  //rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
}

void suspend_wakeup_init_user(void) {
  //rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
