/* CS303 - Project 3b - Morse Code Tree
* (c) Binh Mai, Kati Williams, Jay Wolf
*/

#include "MorseCode.h"
#include "Tokenizer.h"

string MorseCode::decode(const string& dec)
{
	/* decode: Decode morse code into letters
	* @param: the string to decode
	* @return: the decoded string
	*/

	string decoded;
	Tokenizer token(dec); // We need to tokenize the string, default delimitor is space

	while (token.has_more_tokens()) {
		decoded += morseCodeTree.decode(token.next_token());
	}

	return decoded;
}

string MorseCode::encode( const string enc)
{
	/* encode: Encode a series of letters into morse code
	 * @param: the string (single word) to encode, letter case doesn't matter
	 * @return: the encoded string
	 */

	string encoded,singleLetter;

	for (unsigned int i = 0; i < enc.length(); i++) { // for each letter in the word
		singleLetter = tolower(enc[i]);
		encoded += morseCodeTree.encode(singleLetter); // Send characters serially to Morse_Tree; LETTER
		encoded += ' '; //Space between letters in the word of morse code
	}

	return encoded;
}


