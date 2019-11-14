/* vim: set et ts=2 sw=2 */
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#if defined( RGBLIGHT_ENABLE )
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _GAME 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5
#define _NAV 6

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  GAME,
  LOWER,
  RAISE,
  ADJUST,
  /* BACKLIT, */
  RGBRST
};

#define NAV LT(_NAV,KC_SPC)
//#define NAV MO(_NAV)
#define CTL_ESC LCTL_T(KC_ESCAPE) // tap-escape hold-lctrl
#define RSHFT_ENTER RSFT_T(KC_ENTER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
      //,-----------------------------------------.                ,-----------------------------------------.
      KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                   KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,KC_BSPC,\
      //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTL_ESC,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                   KC_H,  KC_J,  KC_K,  KC_L,KC_SCLN,KC_QUOT,\
      //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                   KC_N,  KC_M,KC_COMM,KC_DOT,KC_SLSH,RSHFT_ENTER,\
      //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
      KC_LGUI, LOWER,NAV,   KC_SPC, RAISE,KC_RALT \
      //`--------------------'  `--------------------'
      ),

  [_COLEMAK] = LAYOUT( \
      //,-----------------------------------------.                ,-----------------------------------------.
      KC_TAB,   KC_Q,  KC_W,  KC_F,  KC_P,  KC_G,                    KC_J,  KC_L,  KC_U,  KC_Y,KC_SCLN,KC_BSPC,\
      //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTL_ESC,  KC_A,  KC_R,  KC_S,  KC_T,  KC_D,                   KC_H,  KC_N,  KC_E,  KC_I, KC_O, KC_QUOT,\
      //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                   KC_K,  KC_M,KC_COMM,KC_DOT,KC_SLSH,RSHFT_ENTER,\
      //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
      KC_LGUI, LOWER,NAV,   KC_SPC, RAISE,KC_RALT \
      //`--------------------'  `--------------------'
      ),

  [_GAME] = LAYOUT( \
      //,-----------------------------------------.                ,-----------------------------------------.
      KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                   KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,KC_BSPC,\
      //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_ESC,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                   KC_H,  KC_J,  KC_K,  KC_L,KC_SCLN,KC_QUOT,\
      //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                   KC_N,  KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_ENTER,\
      //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
      KC_LCTL, LOWER,KC_SPC,   KC_SPC, RAISE,KC_RALT \
      //`--------------------'  `--------------------'
      ),

  [_LOWER] = LAYOUT( \
      //,-----------------------------------------.                ,-----------------------------------------.
      KC_TILD,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,              KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSPC,
      //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                  KC_NO,KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE ,
      //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_F7, KC_F8, KC_F9, KC_F10,KC_F11,KC_F12,              KC_NO,KC_NONUS_HASH,KC_NONUS_BSLASH,KC_HOME,KC_END,KC_ENTER,
      //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
      KC_LGUI, LOWER,NAV,   KC_SPC, RAISE,KC_RALT
      //`--------------------'  `--------------------'
      ),

  [_RAISE] = LAYOUT( \
      //,-----------------------------------------.                ,-----------------------------------------.
      KC_GRAVE,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                 KC_6,  KC_7,  KC_8,  KC_9,  KC_0,KC_BSPC,\
      //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6 ,                 KC_NO,KC_MINUS,KC_EQUAL,KC_LBRACKET,KC_RBRACKET,KC_BSLASH,
      //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_F7, KC_F8, KC_F9, KC_F10,KC_F11,KC_F12,                 KC_NO,KC_NONUS_HASH,KC_NONUS_BSLASH,KC_PGUP,KC_PGDOWN,KC_ENTER ,
      //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
      KC_LGUI, LOWER,NAV,   KC_SPC, RAISE,KC_RALT \
      //`--------------------'  `--------------------'
      ),

  [_ADJUST] = LAYOUT( \
      //,-----------------------------------------.                ,-----------------------------------------.
      QWERTY,RGBRST, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, GAME, COLEMAK,
      //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      RGB_TOG,RGB_HUI,RGB_SAI,RGB_VAI,KC_NO,KC_NO,                 KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_NO,\
      //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,KC_NO,KC_NO,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
      //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
      KC_LGUI, LOWER,NAV,   KC_SPC, RAISE,KC_RALT \
      //`--------------------'  `--------------------'
      ),

  [_NAV] = LAYOUT( \
      //,-----------------------------------------.                ,-----------------------------------------.
      RESET,KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
      //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                 KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_NO,\
      //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
      //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
      KC_LGUI, LOWER,KC_NO,   KC_SPC, RAISE,KC_RALT \
      //`--------------------'  `--------------------'
      )
};

int RGB_current_mode;

/* void persistent_default_layer_set(uint16_t default_layer) { */
/*   eeconfig_update_default_layer(default_layer); */
/*   default_layer_set(default_layer); */
/* } */

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  RGB_current_mode = rgblight_config.mode;
#endif
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
  iota_gfx_init(!has_usb());   // turns on the display
#endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

char layer_state_str[24];
// When add source files to SRC in rules.mk, you can use functions.
const char *my_read_layer_state(void) {

  switch (biton32(layer_state)) {
    case _QWERTY:
    case _COLEMAK:
    case _GAME:
      switch (biton32(default_layer_state))
      {
        case _QWERTY:
          snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY");
          break;
        case _COLEMAK:
          snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Colemak");
          break;
        case _GAME:
          snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Game");
          break;
        default:
          snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
      }
      break;
    case _RAISE:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
      break;
    case _LOWER:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
      break;
    case _ADJUST:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
      break;
    case _NAV:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Navigation");
      break;
    default:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}

const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

/* const char *read_mode_icon(bool swap); */
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
  iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, my_read_layer_state());
    /* matrix_write_ln(matrix, read_keylog()); */
    //matrix_write_ln(matrix, read_keylogs());
    /* matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui)); */
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        default_layer_set(1UL<<_COLEMAK);
      }
      return false;
    case GAME:
      if (record->event.pressed) {
        default_layer_set(1UL<<_GAME);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
    case RGB_MOD:
#if defined( RGBLIGHT_ENABLE )
      if (record->event.pressed) {
        rgblight_mode(RGB_current_mode);
        rgblight_step();
        RGB_current_mode = rgblight_config.mode;
      }
      return false;
#endif
    case RGBRST:
#ifdef RGBLIGHT_ENABLE
      if (record->event.pressed) {
        eeconfig_update_rgblight_default();
        rgblight_enable();
        RGB_current_mode = rgblight_config.mode;
      }
#endif
      break;
    case KC_SCOLON:
      if (record->event.pressed && get_mods() & MOD_BIT(KC_LCTL))
      {
        /* register_code(KC_LSHIFT); */
        tap_code(KC_ESC);
        /* unregister_code(KC_LSHIFT); */
        return false;
      }
      return true;
  }
  return true;
}

