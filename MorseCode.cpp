#include "MorseCode.h"
#include "Tokenizer.h"

string MorseCode::decode(string dec)
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

string MorseCode::encode(string enc)
{
	/* encode: Encode a series of letters into morse code
	 * @param: the string to encode
	 * @return: the encoded string
	 */

	string encoded,temp;
	Tokenizer token(enc); // Tokenize the input string, default delimitor is a space
	while (token.has_more_tokens()) {
		temp = token.next_token(); // temp variable is necessary for serial data send
		for (unsigned int i = 0; i < temp.length(); i++) {
			encoded += morseCodeTree.encode(temp.substr(i, 1)); // Send characters serially to Morse_Tree
			encoded += ' '; //Space between letters
		}	
	}

	return encoded;
}
