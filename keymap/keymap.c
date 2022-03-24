#include QMK_KEYBOARD_H
#include "muse.h"
#include "layouts.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = CURRENT_LAYOUT(QWERTY_L1,QWERTY_L2,QWERTY_L3,QWERTY_L4),
[_NUMBER] = CURRENT_LAYOUT(NUMBER_L1,NUMBER_L2,NUMBER_L3,NUMBER_L4),
[_NAVIGA] = CURRENT_LAYOUT(NAVIGA_L1,NAVIGA_L2,NAVIGA_L3,NAVIGA_L4),
[_ADJUST] = CURRENT_LAYOUT(ADJUST_L1,ADJUST_L2,ADJUST_L3,ADJUST_L4),
[_VALORA] = CURRENT_LAYOUT(VALORA_L1,VALORA_L2,VALORA_L3,VALORA_L4),
};


// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _NUMBER, _NAVIGATION, _ADJUST);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    // case BACKLIT:
    //   if (record->event.pressed) {
    //     register_code(KC_RSFT);
    //     #ifdef BACKLIGHT_ENABLE
    //       backlight_step();
    //     #endif
    //     #ifdef KEYBOARD_planck_rev5
    //       writePinLow(E6);
    //     #endif
    //   } else {
    //     unregister_code(KC_RSFT);
    //     #ifdef KEYBOARD_planck_rev5
    //       writePinHigh(E6);
    //     #endif
    //   }
    //   return false;
    //   break;
    // case EXT_PLV:
    //   if (record->event.pressed) {
    //     #ifdef AUDIO_ENABLE
    //       PLAY_SONG(plover_gb_song);
    //     #endif
    //     layer_off(_PLOVER);
    //   }
    //   return false;
    //   break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

// bool dip_switch_update_user(uint8_t index, bool active) {
//     switch (index) {
//         case 0: {
// #ifdef AUDIO_ENABLE
//             static bool play_sound = false;
// #endif
//             if (active) {
// #ifdef AUDIO_ENABLE
//                 if (play_sound) { PLAY_SONG(plover_song); }
// #endif
//                 layer_on(_ADJUST);
//             } else {
// #ifdef AUDIO_ENABLE
//                 if (play_sound) { PLAY_SONG(plover_gb_song); }
// #endif
//                 layer_off(_ADJUST);
//             }
// #ifdef AUDIO_ENABLE
//             play_sound = true;
// #endif
//             break;
//         }
//         case 1:
//             if (active) {
//                 muse_mode = true;
//             } else {
//                 muse_mode = false;
//             }
//     }
//     return true;
// }

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  // switch (keycode) {
  //   case NUM:
  //   case NAV:
  //     return false;
  //   default:
  //     return true;
  // }

  return true;
}