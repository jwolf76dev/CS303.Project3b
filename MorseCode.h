/* CS303 - Project 3b - Morse Code Tree
* (c) Binh Mai, Kati Williams, Jay Wolf
*/

#ifndef MORSE_CODE_H
#define MORSE_CODE_H

#include "Morse_Tree.h"
using namespace std;

class MorseCode {
private:
	Morse_Tree morseCodeTree; // Create our Morse code tree
public:
	MorseCode() {}
	~MorseCode() {}

	string decode(const string&);
	string encode(const string);
};
#endif // !MORSE_CODE_H

