#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

// I'm not using the Oryx Configurator, but for some reason this #define is
// required in order to get layer LEDs to enable.
#define ORYX_CONFIGURATOR
#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

#define PLANCK_EZ_USER_LAYER_LIGHT_HANDLING 1

#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define USB_POLLING_INTERVAL_MS 1

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

//#define RETRO_TAPPING
#define PERMISSIVE_HOLD
#undef IGNORE_MOD_TAP_INTERRUPT
//#define COMBO_COUNT 1
//#define TAPPING_TERM 200

#define PLANCK_EZ_LED_LOWER 3
#define PLANCK_EZ_LED_RAISE 4
#define PLANCK_EZ_LED_ADJUST 5
