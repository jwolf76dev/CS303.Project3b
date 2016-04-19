#include "Tokenizer.h"
#include "Morse_Tree.h"
#include "MorseCode.h"
#include <iostream>
void main(void) {
	MorseCode code;
	string temp= code.decode("-.- .- - ..  _. . . -.. ...  ... .-.. . . .--."); //kati needs sleep, haven't figured out spaces yet
	cout << temp << endl;
	string encode = code.encode("kati");
	cout << encode << endl;
	system("pause");
}