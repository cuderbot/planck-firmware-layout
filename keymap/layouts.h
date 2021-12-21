#include QMK_KEYBOARD_H
#include "muse.h"



enum planck_layers {
  _QWERTY,
  _NUMBER,
  _NAVIGA,
  _ADJUST,
  _VALORA,
  _GENIMP,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

// Wrappers
#define CURRENT_LAYOUT(...)  LAYOUT_planck_2x2u(__VA_ARGS__)

// Layers shortcut
#define NUM MO(_NUMBER)
#define NAV MO(_NAVIGATION)
#define VAL TG(_GAM_VAL)
#define GEN TG(_GAM_GEN)

// Shortcuts
#define KC_CTTB LCTL_T(KC_TAB)
#define KC_ALEC LALT_T(KC_ESC)

/* QWERTY (35 keys)
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  | CTAB | Bksp |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  | AESC |  '   |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |SFT/( |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |NUM   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | NUM  |      |      | GUI  |     SPC     |     ENT     |   `  |   -  |   =  |   \  |
 * `-----------------------------------------------------------------------------------'
 *                                      ___QWERTY_L1___
 *                                      ___QWERTY_L2___
 *                                      ___QWERTY_L3___
 *                                      ___QWERTY_L4___
 */
#define QWERTY_L1   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T, KC_CTTB, KC_BSPC, KC_Y, KC_U,   KC_I,     KC_O,   KC_P
#define QWERTY_L2   KC_A,     KC_S,     KC_D,     KC_F,     KC_G, KC_ALEC, KC_QUOT, KC_H, KC_J,   KC_K,     KC_L,   KC_SCLN
#define QWERTY_L3   KC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V, KC_B,    KC_RSPC, KC_N, KC_M,   KC_COMM,  KC_DOT, KC_SLASH
#define QWERTY_L4   NUM,      _______,  _______,  KC_LGUI,        KC_SPC,         KC_ENT, KC_GRV, KC_MINS,  KC_EQL, KC_NUBS 

/* Numbers and Symbols  (35 keys)
 * ,-----------------------------------------------------------------------------------.
 * | CTTB |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ALEC |   `  |   -  |   =  |   [  |   ]  |   \  |      |      |  Up  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LSFT |      |      |      |      |      |      |      | Left | Down |Right | RSFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |     SPC     |     ENT     | NEXT |VOLDWN|VOLUP | PLAY |
 * `-----------------------------------------------------------------------------------'
 *                                      ___NUMBER_L1___
 *                                      ___NUMBER_L2___
 *                                      ___NUMBER_L3___
 *                                      ___NUMBER_L4___
 */
#define NUMBER_L1 KC_CTTB,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______
#define NUMBER_L2 KC_ALEC,  KC_GRV,   KC_MINS,  KC_EQL,   KC_NUBS,  _______,  _______,  _______,  _______,  _______,  _______,  _______
#define NUMBER_L3 KC_LSFT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
#define NUMBER_L4 NUM,      _______,  _______,  KC_LGUI,             KC_SPC,             KC_ENT,  _______,  _______,  _______,  _______ 


/* Navigation  (35 keys)
 * ,-----------------------------------------------------------------------------------.
 * | CTTB |      |      |      |      |      |      |      |      |      |      |QWERTY|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ALEC |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LSFT |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |     SPC     |     ENT     |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *                                      ___NAVIGA_L1___
 *                                      ___NAVIGA_L2___
 *                                      ___NAVIGA_L3___
 *                                      ___NAVIGA_L4___
 */
#define NAVIGA_L1 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
#define NAVIGA_L2 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
#define NAVIGA_L3 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
#define NAVIGA_L4 _______,  _______,  _______,  KC_LGUI,             KC_SPC,             KC_ENT,  _______,  _______,  _______,  _______ 


/* Adjust (Lower + Raise)  (35 keys)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |     SPC     |     ENT     |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *                                      ___ADJUST_L1___
 *                                      ___ADJUST_L2___
 *                                      ___ADJUST_L3___
 *                                      ___ADJUST_L4___
 */

#define ADJUST_L1 RESET,    _______,  DEBUG,    RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  KC_DEL
#define ADJUST_L2 _______,  _______,  MU_MOD,   AU_ON,    AU_OFF,   AG_NORM,  AG_SWAP,  QWERTY,   _______,  _______,  _______,  _______
#define ADJUST_L3 _______,  MUV_DE,   MUV_IN,   MU_ON,    MU_OFF,   MI_ON,    MI_OFF,   TERM_ON,  TERM_OFF, _______,  _______,  _______
#define ADJUST_L4 _______,  _______,  _______,  KC_LGUI,             KC_SPC,             KC_ENT,  _______,  _______,  _______,  _______ 


/* Valorant  (35 keys)
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |      |      |      |      |      |      |QWERTY|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  TAB |   Q  |   W  |   E  |   R  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL |   A  |   S  |   D  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |     SPC     |     ENT     |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *                                      ___VALORA_L1___
 *                                      ___VALORA_L2___
 *                                      ___VALORA_L3___
 *                                      ___VALORA_L4___
 */
#define VALORA_L1 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
#define VALORA_L2 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
#define VALORA_L3 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
#define VALORA_L4 _______,  _______,  _______,  KC_LGUI,             KC_SPC,             KC_ENT,  _______,  _______,  _______,  _______


/* Genshin Impact  (35 keys)
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |      |      |      |      |      |      |QWERTY|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  TAB |   Q  |   W  |   E  |   R  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL |   A  |   S  |   D  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |     SPC     |     ENT     |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *                                      ___GENIMP_L1___
 *                                      ___GENIMP_L2___
 *                                      ___GENIMP_L3___
 *                                      ___GENIMP_L4___
 */
#define GENIMP_L1 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
#define GENIMP_L2 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
#define GENIMP_L3 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
#define GENIMP_L4 _______,  _______,  _______,  KC_LGUI,             KC_SPC,             KC_ENT,  _______,  _______,  _______,  _______

