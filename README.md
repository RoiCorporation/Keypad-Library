# Keypad Library

<h2>Keypad_4_by_3 structure’s functions</h2>


<h2>initialize_4_by_3</h2>




* Description: this function initializes the Keypad_4_by_3 structure.
* Parameters: seven integer types and one Keypad_4_by_3 as arguments (this one passed by reference), whose parameters will be the aforementioned integers. The first four integers will be configured as OUTPUT pins while the last three of them will be INPUT pins.
* The function returns the updated Keypad_4_by_3 structure.
* No preconditions nor postconditions to be met.
* define_standard_keymap_4_by_3
* Description: this function sets the elements in the array passed as an argument to the characters of a commercially available four by three keypad matrix
* Parameters: the multidimensional character array to be standardized.
* The function returns the updated array
* No preconditions nor postconditions to be met.
* row_and_col_4_by_3
* Description: this auxiliary determines the values for both the row and the column of the keypad matrix where the button being pressed is.
* Parameters: two integers passed by reference (the row and the column ones, respectively), plus the Keypad_4_by_3 structure being used (required for the input-output routine needed to determine which button is being pressed).
* The function returns the row and column values of the pressed button.
* Preconditions: the Keypad_4_by_3 structure must be initialized.
* get_key_4_by_3
* Description: this function delivers the character of the button being pressed.
* Parameters: the four by three array associated with the matrix (customized or standard -see the _define_standard_keymap_4_by_3_ function-) and the Keypad_4_by_3 structure linked with the keypad being used.
* The function returns the character of the array associated with the keypad’s button being pressed.
* Preconditions: the Keypad_4_by_3 structure must be initialized.
* Additional considerations: in an iterative scenario, the function should be used with enough time delay in between each successive call so that no unwanted consecutive button presses are detected (the recommended time delay is 180 milliseconds).
* get_password_4_by_3
* Description: when this function is called, it will allocate enough memory to store a password of the specified length. Then, it will wait until the full password is introduced, whereupon it will be stored in the mentioned memory space.
* Parameters: the positive-integer password’s length, an array that identifies the characters associated with each keypad button (customized or standard -see the _define_standard_keymap_4_by_3_ function-) and the Keypad_4_by_3 structure representing the keypad being used.
* The function returns a _Password_ type variable or NULL, in case there wasn’t enough memory space to store the password.
* Preconditions: the Keypad_4_by_3 structure must be initialized.
* Additional considerations: the time between each button press was set to 180 milliseconds. Therefore, two consecutive presses made less than 180 milliseconds from each other will be recognized as only one.
* change_password_4_by_3
* Description: this function changes the password it receives and allows the user to type the new password.
* Parameters: the _Password_ type variable to be changed, the character array associated with the keypad (customized or standard -see the _define_standard_keymap_4_by_3_ function-) and the Keypad_4_by_3 structure of the keypad in use.
* The function returns the new password.
* Preconditions: the Keypad_4_by_3 structure must be initialized.
* Additional considerations: as is the case with the _get_password_4_by_3_ function, the time between each button press was set to 180 milliseconds. Therefore, two consecutive presses made less than 180 milliseconds from each other will be recognized as only one.

<h2>Keypad_4_by_4 structure’s functions</h2>




* initialize_4_by_4
* This function sets the Keypad_4_by_4 structure’s fields to the values passed as arguments. Besides, it also automatically establishes the first four arguments as outputs and the last four as inputs (this step is necessary for other functions).
* Parameters: eight integer types and one Keypad_4_by_4 as arguments (this one passed by reference), whose parameters will be the aforementioned integers. The first four integers will be configured as OUTPUT pins while the last four of them will be INPUT pins.
* The function returns the updated Keypad_4_by_4 structure.
* No preconditions nor postconditions.
* define_standard_keymap_4_by_4
* Description: this function sets the elements in the array passed as an argument to the characters of a commercially available four by four keypad matrix
* Parameters: the multidimensional character array to be standardized.
* The function returns the updated array
* No preconditions nor postconditions to be met.
* row_and_col_4_by_4
* Description: this auxiliary function determines the values for both the row and the column of the keypad matrix where the button being pressed is.
* Parameters: two integers passed by reference (the row and the column ones, respectively), plus the Keypad_4_by_4 structure being used (required for the input-output routine needed to determine which button is being pressed).
* The function returns the row and column values of the pressed button.
* Preconditions: the Keypad_4_by_3 structure must be initialized.
* get_key_4_by_4
* Description: this function delivers the character of the button being pressed.
* Parameters: the four by four array associated with the matrix (customized or standard -see the _define_standard_keymap_4_by_4_ function-) and the Keypad_4_by_4 structure linked with the keypad being used.
* The function returns the character of the array associated with the keypad’s button being pressed.
* Preconditions: the Keypad_4_by_4 structure must be initialized.
* Postcondition: in an iterative scenario, the function should be used with enough time delay in between each successive call so that no unwanted consecutive button presses are detected (the recommended time delay is 180 milliseconds).
* get_password_4_by_4
* Description: when this function is called, it will allocate enough memory to store a password of the specified length. Then, it will wait until the full password is introduced, whereupon it will be stored in the mentioned memory space.
* Parameters: the positive-integer password’s length, an array that identifies the characters associated with each keypad button (customized or standard -see the _define_standard_keymap_4_by_4_ function-) and the Keypad_4_by_4 structure representing the keypad being used.
* The function returns a _Password_ type variable or NULL, in case there wasn’t enough memory space to store the password.
* Preconditions: the Keypad_4_by_4 structure must be initialized.
* Additional considerations: the time between each button press was set to 180 milliseconds. Therefore, two consecutive presses made less than 180 milliseconds from each other will be recognized as only one.
* change_password_4_by_4
* Description: this function changes the password it receives and allows the user to type the new password.
* Parameters: the _Password_ type variable to be changed, the character array associated with the keypad (customized or standard -see the _define_standard_keymap_4_by_4_ function-) and the Keypad_4_by_4 structure of the keypad in use.
* The function returns the new password.
* Preconditions: the Keypad_4_by_4 structure must be initialized.
* Additional considerations: as is the case with the _get_password_4_by_4_ function, the time between each button press was set to 180 milliseconds. Therefore, two consecutive presses made less than 180 milliseconds from each other will be recognized as only one.

<h2>Common, non-Keypad-type related functions</h2>




* get_length
* Description: this function obtains the length of the password it’s given.
* Parameters: a _Password_ type variable.
* The function returns the length of the password.
* No preconditions nor postconditions to be met.
* check_password
* Description: this function checks to see if two passwords are the same.
* Parameters: two _Password_ type variables.
* The function returns a boolean value: _true_ if the two passwords are equal, _false_ otherwise.
* No preconditions nor postconditions to be met.
* show_password
* Description: when called, this function prints in the Serial Monitor the password it’s passed.
* Parameters: a _Password_ type variable.
* The function doesn’t return any value.
* Preconditions: the Serial communication protocol has been initialized -with the _Serial.begin()_ function, for example-.
