/* CS303 - Project 3b - Morse Code Tree
* (c) Binh Mai, Kati Williams, Jay Wolf
*/

#include "MorseCode.h"
#include "Tokenizer.h"

template<typename Item_Type>
string MorseCode::decode(const string& dec)
{
	/* decode: Decode morse code into letters
	 * @param: the string to decode
	 * @return: the decoded string
	 */

	string decoded;
    // Tokenize the given string, and the default delimitor is space
	Tokenizer token(dec);

	while (token.has_more_tokens()) {
		decoded += morseCodeTree.decode(token.next_token());
	}

	return decoded;
}

template<typename Item_Type>
string MorseCode::encode( const string enc)
{
	/* encode: Encode a series of letters into morse code
	 * @param: the string (single word) to encode, letter case doesn't matter
	 * @return: the encoded string
	 */

	string encoded,singleLetter;
    
    // For each letter in the word
	for (unsigned int i = 0; i < enc.length(); i++) {
		singleLetter = tolower(enc[i]);
    
        // Send characters serially to Morse_Tree (one letter at a time)
		encoded += morseCodeTree.encode(singleLetter);
        
        //Space between letters in the word of morse code
		encoded += ' ';
	}

	return encoded;
}


