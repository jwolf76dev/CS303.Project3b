/* CS303 - Project 3b - Morse Code Tree
* (c) Binh Mai, Kati Williams, Jay Wolf
*/

#ifndef MORSE_CODE_H
#define MORSE_CODE_H

#include "Morse_Tree.h"
using namespace std;

class MorseCode {
private:
    // Creates the Morse code tree
	Morse_Tree morseCodeTree;
    
public:
	MorseCode() {}
	~MorseCode() {}
    
    // Function that turns characters into morse code
	string decode(const string&);
    
    // Function that converts morse code into characters
	string encode(const string);
};
#endif // !MORSE_CODE_H

