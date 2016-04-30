/* CS303 - Project 3b - Morse Code Tree
 * (c) Binh Mai, Kati Williams, Jay Wolf
 */

#include "MorseCode.h"
#include <iostream>

void main(void) {
	MorseCode<string> code;
	string temp= code.decode("_... .. _. ...."); // Binh
	cout << "decode: " << temp << endl;

	string encode = code.encode("KATI"); // _._ ._ _ ..
	cout << "encode: " <<  encode << endl << endl;

	system("pause");

	return;
}