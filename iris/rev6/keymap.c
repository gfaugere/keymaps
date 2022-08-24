#include QMK_KEYBOARD_H


#define _BASE 0
#define _LAYER_LEFT_SINGLE_TAP_MODIFIER 1
#define _LAYER_RIGHT_SINGLE_TAP_MODIFIER 2
#define _LAYER_LEFT_DUAL_TAP_MODIFIER 3
#define _LAYER_RIGHT_DUAL_TAP_MODIFIER 4

// Tap Dance declarations
enum
{
  TD_WIN_ALT,
  TD_MAJ_LCK,
  TD_LEFT_MOD,
  TD_RIGHT_MOD,
};
// Functions used in tap dancing

void left_mod_finish(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    layer_on(_LAYER_LEFT_SINGLE_TAP_MODIFIER);
  } else {
    layer_on(_LAYER_LEFT_DUAL_TAP_MODIFIER);
  }
}
void left_mod_reset(qk_tap_dance_state_t *state, void *user_data) {
  layer_off(_LAYER_LEFT_SINGLE_TAP_MODIFIER);
  layer_off(_LAYER_LEFT_DUAL_TAP_MODIFIER);
}
void right_mod_finish(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    layer_on(_LAYER_RIGHT_SINGLE_TAP_MODIFIER);
    layer_on(_LAYER_LEFT_SINGLE_TAP_MODIFIER);
  } else {
    layer_on(_LAYER_RIGHT_DUAL_TAP_MODIFIER);
  }
}
void right_mod_reset(qk_tap_dance_state_t *state, void *user_data) {
  layer_off(_LAYER_RIGHT_SINGLE_TAP_MODIFIER);
  layer_off(_LAYER_LEFT_SINGLE_TAP_MODIFIER);
  layer_off(_LAYER_RIGHT_DUAL_TAP_MODIFIER);
}
// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_WIN_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LGUI),
    [TD_MAJ_LCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_LEFT_MOD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, left_mod_finish, left_mod_reset),
    [TD_RIGHT_MOD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, right_mod_finish, right_mod_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
TD(TD_MAJ_LCK), KC_A,  KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_NUHS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,           KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                        TD(TD_WIN_ALT), TD(TD_LEFT_MOD), KC_SPC,              KC_ENT, TD(TD_RIGHT_MOD), KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LAYER_LEFT_SINGLE_TAP_MODIFIER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, KC_UP,   _______, _______, KC_LBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NUBS, _______, _______, _______, _______, _______, KC_HOME,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LAYER_RIGHT_SINGLE_TAP_MODIFIER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_P, BL_STEP, _______,                            _______, _______, KC_MINS, KC_EQL,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LAYER_LEFT_DUAL_TAP_MODIFIER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LAYER_RIGHT_DUAL_TAP_MODIFIER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, KC_PGUP, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, KC_PGDN, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (layer_state_is(_LAYER_RIGHT_SINGLE_TAP_MODIFIER)) {
    if (clockwise) {
      tap_code(KC_MS_WH_DOWN);
    } else {
      tap_code(KC_MS_WH_UP);
    }
  } else if (layer_state_is(_LAYER_RIGHT_DUAL_TAP_MODIFIER)) {
    if (clockwise) {
      tap_code(KC_MS_WH_LEFT);
    } else {
      tap_code(KC_MS_WH_RIGHT);
    }
  } else {
    if (clockwise) {
      tap_code(KC_VOLD);
    } else {
      tap_code(KC_VOLU);
    }
  }
  return false;
}

void rgb_matrix_indicators_user(void) {
    rgb_matrix_sethsv(0, 0, 50);
    led_t led_state = host_keyboard_led_state();
    switch (get_highest_layer(layer_state)) {
        case _LAYER_LEFT_SINGLE_TAP_MODIFIER:
            rgb_matrix_set_color(1, 127, 0, 0);
            rgb_matrix_set_color(2, 127, 0, 0);
            rgb_matrix_set_color(3, 127, 0, 0);
            rgb_matrix_set_color(4, 127, 0, 0);
            rgb_matrix_set_color(5, 127, 0, 0);
            rgb_matrix_set_color(23, 127, 0, 0);
            rgb_matrix_set_color(27, 127, 0, 0);
            rgb_matrix_set_color(39, 127, 0, 0);
            rgb_matrix_set_color(38, 127, 0, 0);
            rgb_matrix_set_color(37, 127, 0, 0);
            rgb_matrix_set_color(36, 127, 0, 0);
            rgb_matrix_set_color(35, 127, 0, 0);
            rgb_matrix_set_color(34, 127, 0, 0);
            rgb_matrix_set_color(42, 127, 0, 0);
            rgb_matrix_set_color(45, 127, 0, 0);
            rgb_matrix_set_color(46, 127, 0, 0);
            rgb_matrix_set_color(48, 127, 0, 0);
            rgb_matrix_set_color(49, 127, 0, 0);
            rgb_matrix_set_color(50, 127, 0, 0);
            rgb_matrix_set_color(61, 127, 0, 0);
            rgb_matrix_set_color(25, 255, 0, 0);
            break;
        case _LAYER_RIGHT_SINGLE_TAP_MODIFIER:
            rgb_matrix_sethsv(85, 255, 127);
            break;
        case _LAYER_LEFT_DUAL_TAP_MODIFIER:
            rgb_matrix_sethsv(170, 255, 127);
            if (!led_state.num_lock) {
                rgb_matrix_set_color(38, 255, 0, 0);
            }
            break;
        case _LAYER_RIGHT_DUAL_TAP_MODIFIER:
            rgb_matrix_sethsv(191, 255, 127);
            break;
    }
    if (led_state.caps_lock) {
        rgb_matrix_set_color(12, 255, 0, 0);
    }
}
