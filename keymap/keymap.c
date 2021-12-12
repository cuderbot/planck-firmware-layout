/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _NUMBER,
  _NAVIGATION,
  _ADJUST,
  _GAM_VAL,
  _GAM_GEN,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  // BACKLIT,
  // EXT_PLV
};

// Layers shortcut
#define NUM MO(_NUMBER)
#define NAV MO(_NAVIGATION)
#define VAL TG(_GAM_VAL)
#define GEN TG(_GAM_GEN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * | CTAB |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | AESC |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |SFT/( |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |NUM   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |     SPC     |     ENT     | GUI  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    LCTL_T(KC_TAB), _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_DEL,
    LALT_T(KC_ESC), _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_BSLS,
    KC_LSPO,        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, NUM,
    XXXXXXX,        XXXXXXX, XXXXXXX, KC_LGUI, KC_BSPC, KC_BSPC, KC_ENT, KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
),

/* Numbers and Symbols
 * ,-----------------------------------------------------------------------------------.
 * | CTAB |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | AESC |   `  |   -  |   =  |   [  |   ]  |   \  |      |      |  Up  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LSFT |      |      |      |      |      |      |      | Left | Down |Right | RSFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |     SPC     |     ENT     | NEXT |VOLDWN|VOLUP | PLAY |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_planck_grid(
    _______,  ________________NUMBER_LEFT________________,  ________________NUMBER_RIGHT________________,  XXXXXXX,
    _______,  KC_GRV, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,    KC_NUBS, XXXXXXX, XXXXXXX,  KC_UP,   XXXXXXX,  XXXXXXX, 
    _______,  ___________________BLANK___________________,  XXXXXXX, XXXXXXX, KC_LEFT,  KC_DOWN, KC_RIGHT, KC_RSFT, 
    XXXXXXX,  VAL, GEN, _______, _______, _______,          _______, _______, KC_MNXT,  KC_VOLD, KC_VOLU,  KC_MPLY
),

/* Navigation
 * ,-----------------------------------------------------------------------------------.
 * | CTAB |      |      |      |      |      |      |      |      |      |      |QWERTY|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | AESC |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LSFT |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |     SPC     |     ENT     |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVIGATION] = LAYOUT_planck_grid(
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TG(_QWERTY),
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
),

/* Valorant
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |      |      |      |      |      |      |QWERTY|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  TAB |   Q  |   W  |   E  |   R  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL |   A  |   S  |   D  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |     SPC     |     ENT     |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAM_VAL] = LAYOUT_planck_grid(
    XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_4,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TG(_QWERTY),,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_LCTRL, KC_A,     KC_S,     KC_D,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
),

/* Genshin Impact
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  TAB |   Q  |   W  |   E  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LSFT |   A  |   S  |   D  |   F  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |     SPC     |     ENT     |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAM_GEN] = LAYOUT_planck_grid(
    XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_4,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |     SPC     |     ENT     |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

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

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

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
  switch (keycode) {
    case NUM:
    case NAV:
      return false;
    default:
      return true;
  }
}