#line 1 "/Users/roilopezbarata/Documents/Arduino/matrix_keypad/Keypad_Library.h"

#ifndef KEYPAD_LIBRARY_H
#define KEYPAD_LIBRARY_H



#include <Arduino.h>

#define DELAY_TIME 180

typedef char *Password;




/*----------------------------------------------------------------------------------*/

// Declarations for the 4 by 3 keypad implementation

// 4 by 3 Keypad structure declaration

struct Keypad_4_by_3 {

  // Pins to be configured as outputs (in reality, the rows of the matrix)
  int out_1;
  int out_2;
  int out_3;
  int out_4;

  // Pins to be configured as inputs (in reality, the columns of the matrix)
  int in_1;
  int in_2;
  int in_3;

};



// Functions for the 4 by 3 keypad implementation

void initialize_4_by_3(int o1, int o2, int o3, int o4, int i1, int i2, int i3, Keypad_4_by_3 *my_keypad);
void row_and_col_4_by_3(int *my_row, int *my_col, Keypad_4_by_3 my_keypad);
void define_standard_keymap_4_by_3(char key_layout[4][3]);
char get_key_4_by_3(char key_layout[4][3], Keypad_4_by_3 my_keypad);
Password get_password_4_by_3(int length, char key_layout[4][3], Keypad_4_by_3 my_keypad);
void change_password_4_by_3(Password pass, char key_layout[4][3], Keypad_4_by_3 my_keypad);









/*----------------------------------------------------------------------------------*/

// Declarations for the 4 by 4 keypad implementation

// 4 by 4 Keypad structure declaration

struct Keypad_4_by_4 {

  // Pins to be configured as outputs (in reality, the rows of the matrix)
  int out_1;
  int out_2;
  int out_3;
  int out_4;

  // Pins to be configured as inputs (in reality, the columns of the matrix)
  int in_1;
  int in_2;
  int in_3;
  int in_4;

};



// Functions for the 4 by 4 keypad implementation

void initialize_4_by_4(int o1, int o2, int o3, int o4, int i1, int i2, int i3, int i4, Keypad_4_by_4 *my_keypad);
void row_and_col_4_by_4(int *my_row, int *my_col, Keypad_4_by_4 my_keypad);
void define_standard_keymap_4_by_4(char key_layout[4][4]);
char get_key_4_by_4(char key_layout[4][4], Keypad_4_by_4 my_keypad);
Password get_password_4_by_4(int length, char key_layout[4][4], Keypad_4_by_4 my_keypad);
void change_password_4_by_4(Password pass, char key_layout[4][4], Keypad_4_by_4 my_keypad);







/*----------------------------------------------------------------------------------*/

// Shared, non keypad-type-dependent functions

bool check_password(Password pass1, Password pass2);
int get_length(Password pass);
void show_password(Password pass);





#endif