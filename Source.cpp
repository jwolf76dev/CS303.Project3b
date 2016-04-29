/* CS303 - Project 3b - Morse Code Tree
 * (c) Binh Mai, Kati Williams, Jay Wolf
 */

#include "MorseCode.h"
#include <iostream>

void main(void) {
	MorseCode<string> code;
	string temp= code.decode(".._");
	cout << temp << endl;

	string encode = code.encode("KATI");
	cout << "kati in morse code: " <<  encode << endl;
	system("pause");

	return;
}