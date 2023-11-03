#include "Keypad_Library.h"


// Function definitions for the 4 by 3 keypad implementation


Keypad::Keypad(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
}







void initialize_4_by_3(int o1, int o2, int o3, int o4, int i1, int i2, int i3, Keypad_4_by_3 *my_keypad) {


  // Pins to be configured as outputs (in reality, the rows of the matrix)
  (*my_keypad).out_1 = o1;
  (*my_keypad).out_2 = o2;
  (*my_keypad).out_3 = o3;
  (*my_keypad).out_4 = o4;


  // Pins to be configured as inputs (in reality, the columns of the matrix)
  (*my_keypad).in_1 = i1;
  (*my_keypad).in_2 = i2;
  (*my_keypad).in_3 = i3;


  // Establishing the nature of each group of digital pins (some work as inputs, others work as outputs)
  pinMode((*my_keypad).out_1, OUTPUT);
  pinMode((*my_keypad).out_2, OUTPUT);
  pinMode((*my_keypad).out_3, OUTPUT);
  pinMode((*my_keypad).out_4, OUTPUT);

  pinMode((*my_keypad).in_1, INPUT);
  pinMode((*my_keypad).in_2, INPUT);
  pinMode((*my_keypad).in_3, INPUT);


}





void define_standard_keymap_4_by_3(char key_layout[4][3]) {

  // Auxiliary keymap to copy into the desired array
  char standard_layout_4_by_4[4][3] = {
    {'1', '2', '3'}, 
    {'4', '5', '6'}, 
    {'7', '8', '9'}, 
    {'*', '0', '#'}
  };

  // The loops iterate through the standard layout matrix and copy each element in the corresponding index of the desired arrary
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 3; j++) {
      key_layout[i][j] = standard_layout_4_by_4[i][j];
    }
  }
}





void row_and_col_4_by_3(int *my_row, int *my_col, Keypad_4_by_3 my_keypad) {


  // Set to HIGH all the "sender" pins
  digitalWrite(my_keypad.out_1, HIGH);
  digitalWrite(my_keypad.out_2, HIGH);
  digitalWrite(my_keypad.out_3, HIGH);
  digitalWrite(my_keypad.out_4, HIGH);


  // Find the column where the button pressed is and then get the particular row by changing the "outputs" to LOW
  if(digitalRead(my_keypad.in_1) == HIGH) {
    *my_col = 1;
    digitalWrite(my_keypad.out_1, LOW);
    if(digitalRead(my_keypad.in_1) == LOW) {
      *my_row = 1;
    }
    else{
      digitalWrite(my_keypad.out_2, LOW);
      if(digitalRead(my_keypad.in_1) == LOW) {
        *my_row = 2;
      }
      else {
        digitalWrite(my_keypad.out_3, LOW);
        if(digitalRead(my_keypad.in_1) == LOW) {
          *my_row = 3;
        }
        else {
          digitalWrite(my_keypad.out_4, LOW);
          if(digitalRead(my_keypad.in_1) == LOW) {
            *my_row = 4;
          }
          else {
            *my_row = 0;
          }
        }
      }
    }
  }


  else if (digitalRead(my_keypad.in_2) == HIGH) {
    *my_col = 2;
    digitalWrite(my_keypad.out_1, LOW);
    if(digitalRead(my_keypad.in_2) == LOW) {
      *my_row = 1;
    }
    else{
      digitalWrite(my_keypad.out_2, LOW);
      if(digitalRead(my_keypad.in_2) == LOW) {
        *my_row = 2;
      }
      else {
        digitalWrite(my_keypad.out_3, LOW);
        if(digitalRead(my_keypad.in_2) == LOW) {
          *my_row = 3;
        }
        else {
          digitalWrite(my_keypad.out_4, LOW);
          if(digitalRead(my_keypad.in_2) == LOW) {
            *my_row = 4;
          }
          else {
            *my_row = 0;
          }
        }
      }
    }
  }


  else if (digitalRead(my_keypad.in_3) == HIGH) {
    *my_col = 3;
    digitalWrite(my_keypad.out_1, LOW);
    if(digitalRead(my_keypad.in_3) == LOW) {
      *my_row = 1;
    }
    else{
      digitalWrite(my_keypad.out_2, LOW);
      if(digitalRead(my_keypad.in_3) == LOW) {
        *my_row = 2;
      }
      else {
        digitalWrite(my_keypad.out_3, LOW);
        if(digitalRead(my_keypad.in_3) == LOW) {
          *my_row = 3;
        }
        else {
          digitalWrite(my_keypad.out_4, LOW);
          if(digitalRead(my_keypad.in_3) == LOW) {
            *my_row = 4;
          }
          else {
            *my_row = 0;
          }
        }
      }
    }
  }


}




char get_key_4_by_3(char key_layout[4][3], Keypad_4_by_3 my_keypad) {

  int row = 0;
  int column = 0;

  while(row == 0) {
    row_and_col_4_by_3(&row, &column, my_keypad);
  }
  return key_layout[row - 1][column - 1];
}



Password get_password_4_by_3(int length, char key_layout[4][3], Keypad_4_by_3 my_keypad) {

  // Initializing the password
  Password password_ptr = malloc((length + 1) * sizeof(char));

  if(password_ptr != NULL) {
    Password aux_password_ptr = password_ptr;

    // Asking and storing each character of the password in adjacent memory addresses
    for(int i = 0; i < length; i++) {
      *aux_password_ptr = get_key_4_by_3(key_layout, my_keypad);
      aux_password_ptr++;
      delay(DELAY_TIME);
    }

    // The password must end with a null character
    *aux_password_ptr = '\0';

    // The function returns a "Password" type variable
    return password_ptr;
  }

  else {
    return NULL;
  }

}



void change_password_4_by_3(Password pass, char key_layout[4][3], Keypad_4_by_3 my_keypad) {

  // Iterate through the string and replace each character with the keypad input
  while(*pass != '\0') {
    *pass = get_key_4_by_3(key_layout, my_keypad);
    delay(DELAY_TIME);
    pass++;
  }

}









/*----------------------------------------------------------------------------------*/



// Function definitions for the 4 by 4 keypad implementation


void initialize_4_by_4(int o1, int o2, int o3, int o4, int i1, int i2, int i3, int i4, Keypad_4_by_4 *my_keypad) {


  // Pins to be configured as outputs (in reality, the rows of the matrix)
  (*my_keypad).out_1 = o1;
  (*my_keypad).out_2 = o2;
  (*my_keypad).out_3 = o3;
  (*my_keypad).out_4 = o4;


  // Pins to be configured as inputs (in reality, the columns of the matrix)
  (*my_keypad).in_1 = i1;
  (*my_keypad).in_2 = i2;
  (*my_keypad).in_3 = i3;
  (*my_keypad).in_4 = i4;


  // Establishing the nature of each group of digital pins (some work as inputs, others work as outputs)
  pinMode((*my_keypad).out_1, OUTPUT);
  pinMode((*my_keypad).out_2, OUTPUT);
  pinMode((*my_keypad).out_3, OUTPUT);
  pinMode((*my_keypad).out_4, OUTPUT);

  pinMode((*my_keypad).in_1, INPUT);
  pinMode((*my_keypad).in_2, INPUT);
  pinMode((*my_keypad).in_3, INPUT);
  pinMode((*my_keypad).in_4, INPUT);


}



void define_standard_keymap_4_by_4(char key_layout[4][4]) {

  // Auxiliary keymap to copy into the desired array
  char standard_layout_4_by_4[4][4] = {
    {'1', '2', '3', 'A'}, 
    {'4', '5', '6', 'B'}, 
    {'7', '8', '9', 'C'}, 
    {'*', '0', '#', 'D'}
  };

  // The loops iterate through the standard layout matrix and copy each element in the corresponding index of the desired arrary
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      key_layout[i][j] = standard_layout_4_by_4[i][j];
    }
  }
}




void row_and_col_4_by_4(int *my_row, int *my_col, Keypad_4_by_4 my_keypad) {


  // Set to HIGH all the "sender" pins
  digitalWrite(my_keypad.out_1, HIGH);
  digitalWrite(my_keypad.out_2, HIGH);
  digitalWrite(my_keypad.out_3, HIGH);
  digitalWrite(my_keypad.out_4, HIGH);


  // Find the column where the button pressed is and then get the particular row by changing the "outputs" to LOW
  if(digitalRead(my_keypad.in_1) == HIGH) {
    *my_col = 1;
    digitalWrite(my_keypad.out_1, LOW);
    if(digitalRead(my_keypad.in_1) == LOW) {
      *my_row = 1;
    }
    else{
      digitalWrite(my_keypad.out_2, LOW);
      if(digitalRead(my_keypad.in_1) == LOW) {
        *my_row = 2;
      }
      else {
        digitalWrite(my_keypad.out_3, LOW);
        if(digitalRead(my_keypad.in_1) == LOW) {
          *my_row = 3;
        }
        else {
          digitalWrite(my_keypad.out_4, LOW);
          if(digitalRead(my_keypad.in_1) == LOW) {
            *my_row = 4;
          }
          else {
            *my_row = 0;
          }
        }
      }
    }
  }


  else if (digitalRead(my_keypad.in_2) == HIGH) {
    *my_col = 2;
    digitalWrite(my_keypad.out_1, LOW);
    if(digitalRead(my_keypad.in_2) == LOW) {
      *my_row = 1;
    }
    else{
      digitalWrite(my_keypad.out_2, LOW);
      if(digitalRead(my_keypad.in_2) == LOW) {
        *my_row = 2;
      }
      else {
        digitalWrite(my_keypad.out_3, LOW);
        if(digitalRead(my_keypad.in_2) == LOW) {
          *my_row = 3;
        }
        else {
          digitalWrite(my_keypad.out_4, LOW);
          if(digitalRead(my_keypad.in_2) == LOW) {
            *my_row = 4;
          }
          else {
            *my_row = 0;
          }
        }
      }
    }
  }


  else if (digitalRead(my_keypad.in_3) == HIGH) {
    *my_col = 3;
    digitalWrite(my_keypad.out_1, LOW);
    if(digitalRead(my_keypad.in_3) == LOW) {
      *my_row = 1;
    }
    else{
      digitalWrite(my_keypad.out_2, LOW);
      if(digitalRead(my_keypad.in_3) == LOW) {
        *my_row = 2;
      }
      else {
        digitalWrite(my_keypad.out_3, LOW);
        if(digitalRead(my_keypad.in_3) == LOW) {
          *my_row = 3;
        }
        else {
          digitalWrite(my_keypad.out_4, LOW);
          if(digitalRead(my_keypad.in_3) == LOW) {
            *my_row = 4;
          }
          else {
            *my_row = 0;
          }
        }
      }
    }
  }


  else if (digitalRead(my_keypad.in_4) == HIGH) {
    *my_col = 4;
    digitalWrite(my_keypad.out_1, LOW);
    if(digitalRead(my_keypad.in_4) == LOW) {
      *my_row = 1;
    }
    else{
      digitalWrite(my_keypad.out_2, LOW);
      if(digitalRead(my_keypad.in_4) == LOW) {
        *my_row = 2;
      }
      else {
        digitalWrite(my_keypad.out_3, LOW);
        if(digitalRead(my_keypad.in_4) == LOW) {
          *my_row = 3;
        }
        else {
          digitalWrite(my_keypad.out_4, LOW);
          if(digitalRead(my_keypad.in_4) == LOW) {
            *my_row = 4;
          }
          else {
            *my_row = 0;
          }
        }
      }
    }
  }

}




char get_key_4_by_4(char key_layout[4][4], Keypad_4_by_4 my_keypad) {

  int row = 0;
  int column = 0;

  while(row == 0) {
    row_and_col_4_by_4(&row, &column, my_keypad);
  }
  return key_layout[row - 1][column - 1];
}



Password get_password_4_by_4(int length, char key_layout[4][4], Keypad_4_by_4 my_keypad) {

  // Initializing the password
  Password password_ptr = malloc((length + 1) * sizeof(char));

  if(password_ptr != NULL) {
    Password aux_password_ptr = password_ptr;

    // Asking and storing each character of the password in adjacent memory addresses
    for(int i = 0; i < length; i++) {
      *aux_password_ptr = get_key_4_by_4(key_layout, my_keypad);
      aux_password_ptr++;
      delay(DELAY_TIME);
    }

    // The password must end with a null character
    *aux_password_ptr = '\0';

    // The function returns a "Password" type variable
    return password_ptr;
  }

  else {
    return NULL;
  }

}






void change_password_4_by_4(Password pass, char key_layout[4][4], Keypad_4_by_4 my_keypad) {

  // Iterate through the string and replace each character with the keypad input
  while(*pass != '\0') {
    *pass = get_key_4_by_4(key_layout, my_keypad);
    delay(DELAY_TIME);
    pass++;
  }

}





/*----------------------------------------------------------------------------------*/


// Common functions to all types of keypads


int get_length(Password pass) {

  // Return variable
  int length = 0;

  // Iterate until the end of the password and add one for every character in it
  while(*pass != '\0') {
    length++;
    *pass++;
  }
  return length;
}



bool check_password(Password pass1, Password pass2) {

  // The boolean variable result holds the value that the function will return
  bool result = true;

  // The chek loop will stop once it reaches the null character in either or both of the passwords
  while(*pass1 != '\0' && *pass2 != '\0') {
    if(*pass1 != *pass2) {
      result = false;
      break;
    }
    pass1++;
    pass2++;
  }
  return result;
}



void show_password(Password pass) {

  // Iterate and print each character until the end of the password
  while(*pass != '\0') {
    Serial.print(*pass);
    pass++;
  }
  Serial.println();
}