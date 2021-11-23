/* vim: set et ts=2 sw=2 */
#include QMK_KEYBOARD_H

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

extern void rgb_matrix_update_pwm_buffers(void);

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
      _______,_______,_______,_______,_______,_______,             KC_NO,KC_MINUS,KC_EQUAL,KC_LBRACKET,KC_RBRACKET,KC_BSLASH,
      //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _______,_______,_______,_______,_______,_______,             KC_NO,KC_NONUS_HASH,KC_NONUS_BSLASH,KC_PGUP,KC_PGDOWN,KC_ENTER ,
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
      RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,KC_NO,KC_NO,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, EEP_RST,\
      //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
      KC_LGUI, LOWER,NAV,   KC_SPC, RAISE,KC_RALT \
      //`--------------------'  `--------------------'
      ),

  [_NAV] = LAYOUT( \
      //,-----------------------------------------.                ,-----------------------------------------.
      RESET,KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
      //|------+------+------+------+------+------|             |------+------+------+------+------+------|
      _______,_______,_______,_______,_______,_______,          KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_NO,\
      //|------+------+------+------+------+------|   --|       |------+------+------+------+------+------|
      _______,_______,_______,_______,_______,_______,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
      //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
      KC_LGUI, LOWER,KC_NO,   KC_SPC, RAISE,KC_RALT \
      //`--------------------'  `--------------------'
      )
};

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

#ifdef OLED_ENABLE

// When add source files to SRC in rules.mk, you can use functions.
/* const char *my_read_layer_state(void) { */
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#if 1
void oled_render_layer_state(void) {

    oled_write_P(PSTR("Layer: "), false);
	static const PROGMEM char layerNam[][7] =
	{
		"QWERTY",
		"Colemak",
		"Game",
		"Raise",
		"Lower",
		"Adjust",
		"Nav",
		"Unknown"
	};
	int layer = biton32(layer_state);
	if ( layer > _NAV )
		layer = 7;
	oled_write_P(layerNam[layer],false);
}

/* char keylog_str[24] = {}; */
/*  */
/* const char code_to_name[60] = { */
/*     ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', */
/*     'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', */
/*     'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', */
/*     '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', */
/*     'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', */
/*     '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '}; */
/*  */
/* void set_keylog(uint16_t keycode, keyrecord_t *record) { */
/* 	char name = ' '; */
/* 	if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || */
/* 			(keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; } */
/* 	if (keycode < 60) { */
/* 		name = code_to_name[keycode]; */
/* 	} */
/*  */
/* 	// update keylog */
/* 	snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c", */
/* 			record->event.key.row, record->event.key.col, */
/* 			keycode, name); */
/* } */

/* void oled_render_keylog(void) { */
/* 	oled_write(keylog_str, false); */
/* } */

/* void render_bootmagic_status(bool status) { */
/*     #<{(| Show Ctrl-Gui Swap options |)}># */
/*     static const char PROGMEM logo[][2][3] = { */
/*         {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}}, */
/*         {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}}, */
/*     }; */
/*     if (status) { */
/*         oled_write_ln_P(logo[0][0], false); */
/*         oled_write_ln_P(logo[0][1], false); */
/*     } else { */
/*         oled_write_ln_P(logo[1][0], false); */
/*         oled_write_ln_P(logo[1][1], false); */
/*     } */
/* } */
#endif //0


/*  */
/* void oled_task_user(void) { */
/* 	if (is_keyboard_master()) { */
/* 			#<{(| oled_render_logo(); |)}># */
/* 		oled_render_layer_state(); */
/* 		oled_render_keylog(); */
/* 	} else { */
/* 		#<{(| oled_render_layer_state(); |)}># */
/* 		// hack to only set the logo once;  for whatever reason, this causes */
/* 		// *major* problems on the non-master keyboard half. */
/* 		static bool once=true; */
/* 		if  ( once ) */
/* 		{ */
/* 			once = false; */
/* 			oled_render_logo(); */
/* 		} */
/* 	} */
/* } */

#define BONGO
#define RLE

#ifdef BONGO

// WPM-responsive animation stuff here
#    define IDLE_FRAMES 5
#    define IDLE_SPEED 20  // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#    define TAP_FRAMES 2
#    define TAP_SPEED 40  // above this wpm value typing animation to trigger
#    define MAX_SPEED 100  // above this wpm value typing animation to trigger

#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define TAP_FRAME_DURATION 400  // how long each frame lasts in ms
#    define TAP_FRAME_DURATION_WPMMOD -3  // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#ifdef RLE
#    define ANIM_SIZE 221  // number of bytes in array, minimize for adequate firmware size, max is 1024
#else
#    define ANIM_SIZE 512  // number of bytes in array, minimize for adequate firmware size, max is 1024
#endif

uint32_t anim_timer         = 0;
uint32_t anim_sleep         = 0;
uint8_t  current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;
uint32_t anim_frame_duration = ANIM_FRAME_DURATION;

static void draw_frame(const unsigned char* frameData) {
#ifdef RLE
	int cursor = 0;
	uint8_t bytes = pgm_read_byte_near(frameData);
	oled_set_cursor(0, 0);                            // sets cursor to (row, column) using charactar spacing (5 rows on 128x32 screen, anything more will overflow back to the top)
	uint8_t i = 1;
	while ( i < bytes )
	{
		uint8_t count = pgm_read_byte_near(frameData+i);
		i++;

		if ( count & 0x80 ) // uniques
		{
			count &= ~(0x80);
			for ( uint8_t uniqs = 0; uniqs < count; uniqs++ )
			{
				uint8_t value = pgm_read_byte_near(frameData + i);
				i++;
				oled_write_raw_byte(value,cursor);
				cursor++;
			}
		}
		else // duplicates
		{
			uint8_t value = pgm_read_byte_near(frameData + i);
			i++;
			for ( uint8_t reps = 0; reps < count; reps++ )
			{
				oled_write_raw_byte(value,cursor);
				cursor++;
			}
		}
	}
#else
	oled_write_raw_P((char*)frameData, ANIM_SIZE);  // remove if IDLE_FRAMES >1
#endif
}

static void render_anim(void) {
	// Contains:
	// 5 idle frames, 1 prep frame, and 2 tap frames
#ifdef RLE
#include "rledata.h"
#else
#include "rawdata.h"
#endif

    // assumes 1 frame prep stage
	void animation_phase(void) {
		anim_frame_duration = ANIM_FRAME_DURATION;
		if (get_current_wpm() <= IDLE_SPEED) {
			current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
			/* draw_frame(idle[abs((IDLE_FRAMES - 1) - current_idle_frame)]); */
			draw_frame(idle[current_idle_frame]);
		}
		if (get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED) {
			// oled_write_raw_P(prep[abs((PREP_FRAMES-1)-current_prep_frame)], ANIM_SIZE); // uncomment if IDLE_FRAMES >1
			draw_frame(prep[0]);  // remove if IDLE_FRAMES >1
		}
		if (get_current_wpm() >= TAP_SPEED) {
			current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
			draw_frame(tap[current_tap_frame]);

			anim_frame_duration = TAP_FRAME_DURATION + (get_current_wpm() * TAP_FRAME_DURATION_WPMMOD);
			if ( anim_frame_duration > 400 )
				anim_frame_duration = 400;
		}
	}
	if (get_current_wpm() != 000) {
		oled_on();  // not essential but turns on animation OLED with any alpha keypress
		if (timer_elapsed32(anim_timer) > anim_frame_duration) {
			anim_timer = timer_read32();
			animation_phase();
		}
		anim_sleep = timer_read32();
	} else {
		if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
		    oled_off();
		} else {
			if (timer_elapsed32(anim_timer) > anim_frame_duration) {
				anim_timer = timer_read32();
				animation_phase();
			}
		}
	}
}
#endif

static const char PROGMEM crkbd_logo[] = {
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
	0};
void oled_render_logo(void) {
	oled_set_cursor(0, 1);                            // sets cursor to (row, column) using charactar spacing (5 rows on 128x32 screen, anything more will overflow back to the top) */
	oled_write_P(crkbd_logo, false);
}

// Used to draw on to the oled screen
bool oled_task_user(void) {
	if (is_keyboard_master()) {
		oled_render_logo();
	}
	else
	{
#ifdef BONGO
		render_anim();  // renders pixelart
#else
		oled_render_logo(); // or something else, I guess?
#endif
	}
	return false; // today we are feeling very negative.
}

#endif//OLED


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
#ifdef OLED
		/* set_keylog(keycode, record); */
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

/* __attribute__((weak)) void suspend_power_down_keymap(void) {} */
/*  */
/* void suspend_power_down_user(void) { */
/* #ifdef OLED_DRIVER_ENABLE */
/*     oled_off(); */
/* #endif */
/* 	rgb_matrix_disable_noeeprom(); */
/* 	rgb_matrix_update_pwm_buffers(); */
/*     suspend_power_down_keymap(); */
/* } */
/*  */
/* __attribute__((weak)) void suspend_wakeup_init_keymap(void) {} */
/*  */
/* void suspend_wakeup_init_user(void) { */
/* #ifdef OLED_DRIVER_ENABLE */
/*     oled_on(); */
/* #endif */
/* 	rgb_matrix_enable_noeeprom(); */
/* 	rgb_matrix_update_pwm_buffers(); */
/* 	suspend_wakeup_init_keymap(); */
/* } */
