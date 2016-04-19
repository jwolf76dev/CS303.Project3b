#include "Morse_Tree.h"
#include <fstream>

string Morse_Tree::trim(const string& the_string)
{ /* trim: trims off excess characters from a string
   * @param: the string to trim
   * @return: the trimmed string
   */

	size_t p = the_string.find_first_not_of(" ");
	if (p == string::npos) return "";
	size_t q = the_string.find_last_not_of(" ");
	return the_string.substr(p, q - p + 1);
}

void Morse_Tree::buildTree() {
	/* buildTree: builds a morse code tree
	 * @param: none
	 * @return: none
	 */

	ifstream in("morse.txt");
	string line, letter, code;
	if (in) {
		while (getline(in, line)) { // Get the line from the file, store it in a variable called line
			letter = line[0]; // Letter will always be the first character of line
			Tokenizer token(line.substr(1), "\n"); // Tokenizer class object, ignores character 0,  new line as the delimiter
			code = trim(token.next_token()); // Code will be from character 1 onwards
		}
	}

}

string Morse_Tree::encode(string enc){
	/*encode: turns a character into morse code
	 * @param: the character to encode
	 * @return: the morse code for the character
	 */

	return string();
}

string Morse_Tree::decode(string dec){
	/*decode: turns morse code into a letter
	* @param: the morse code to decode
	* @return: the letter for the morse code
	*/

	return string();
}
