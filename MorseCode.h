#ifndef MORSE_CODE_H
#define MORSE_CODE_H

#include "Morse_Tree.h"
using namespace std;

class MorseCode {
private:
	Morse_Tree morseCodeTree; // Create our Morse code tree
public:
	MorseCode() {}

	string decode(string);
	string encode(string);


};
#endif // !MORSE_CODE_H

