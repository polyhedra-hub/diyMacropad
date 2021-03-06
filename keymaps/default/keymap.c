/* Copyright 2021 polyhedra-hub
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
 #include <time.h>
#include QMK_KEYBOARD_H
static void render_logo(void);
int pocetak=1;



// Defines names for use in layer keycodes and the keymap
enum layer_names {
    BASE, FN, THIRD

};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [BASE] = LAYOUT(
        TO(FN), KC_1, KC_E, KC_2,
        KC_3, KC_4, KC_5, KC_6,
	      KC_7, KC_8, KC_9, KC_B,
	      KC_C, KC_D, KC_F, KC_G
    ),

    [FN] = LAYOUT(
        TO(BASE), TO(THIRD), KC_E, KC_3,
        KC_3, KC_4, KC_5, KC_6,
	      KC_7, KC_8, KC_9, KC_B,
	      KC_C, KC_D, KC_F, KC_G
    ),
    [THIRD] = LAYOUT(
      TO(FN), TO(BASE), KC_N, KC_P,
      KC_3, KC_4, KC_5, KC_6,
      KC_7, KC_8, KC_9, KC_B,
      KC_C, KC_D, KC_F, KC_G
    )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

      oled_clear();
        pocetak=0;
        switch (keycode) {
      case KC_2:
          oled_clear();
            pocetak=0;
            break;
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

void oled_task_user(void) {
  if(pocetak==1){
    render_logo();
    return;
  }
  oled_write_P(PSTR("Layer: "), false);
  switch (get_highest_layer(layer_state)) {
    case BASE:
    oled_write_P(PSTR("Default\n"), false);
    break;
    case FN:
    oled_write_P(PSTR("FN\n"), false);
    break;
    case THIRD:
    oled_write_P(PSTR("THIRD\n"), false);
    break;
    default:
    oled_write_ln_P(PSTR("Undefined"), false);

  }}

static void render_logo(void) {
static const char PROGMEM my_logo[] = {
  // Paste the code from the previous step below this line!
      // 'tr', 128x64px
       0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x06, 0xdf, 0x0c, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xc7, 0xcf, 0xfe, 0xfe, 0xfc, 0x10, 0x40, 0xf8, 0xfc, 0xfe, 
	0x1e, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f, 0xfe, 0xfc, 0xf8, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x3f, 0xff, 0xfc, 0xf0, 0xf0, 0xfc, 0xff, 0x3f, 0x0f, 0x03, 
	0x00, 0x00, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 
	0xff, 0xff, 0xff, 0xe7, 0xe7, 0xe7, 0xe7, 0x07, 0x00, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 
	0x0e, 0x3e, 0xfe, 0xfc, 0xf8, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xc7, 0xcf, 0xfe, 0xfe, 
	0x7c, 0x38, 0x00, 0x00, 0x80, 0xf0, 0xfe, 0xff, 0x3f, 0x3f, 0xff, 0xfe, 0xf0, 0x80, 0x00, 0x00, 
	0x10, 0x1c, 0x1b, 0x14, 0x10, 0x02, 0x01, 0x01, 0x02, 0x00, 0x14, 0x19, 0x1e, 0x1c, 0x10, 0x00, 
	0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x1f, 
	0x1f, 0x1c, 0x1c, 0x1c, 0x1c, 0x1e, 0x1f, 0x0f, 0x07, 0x01, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x18, 
	0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x1f, 
	0x1f, 0x1f, 0x1f, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1c, 0x1c, 0x1c, 
	0x1e, 0x1f, 0x0f, 0x0f, 0x03, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x03, 0x07, 0x1f, 0x1f, 0x1c, 
	0x18, 0x00, 0x10, 0x1c, 0x1f, 0x1f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x1f, 0x1f, 0x1c, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
       };

oled_write_raw_P(my_logo, sizeof(my_logo));
}
