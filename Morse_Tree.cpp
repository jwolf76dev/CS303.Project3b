#include "Morse_Tree.h"
#include <fstream>
#include <iostream>

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

void Morse_Tree::readFile() {
	/* readFile: reads in morse code file then sends it off to build the tree
	 * @param: none
	 * @return: none
	 */

	ifstream in("morse.txt");
	if (!in) {
		cout << "Error, check morse.txt file location" << endl;
		system("pause");
		exit(1);
	}
	string line, code;
	if (in) {
		while (getline(in, line)) { // Get the line from the file, store it in a variable called line
			Tokenizer token(line.substr(1), "\n"); // Tokenizer class object, ignores character 0,  new line as the delimiter
			code = trim(token.next_token()); // Code will be from character 1 onwards

			buildTree(line.substr(0, 1), code); // Send letter and code off to be incorporated into the tree
			buildMap(line.substr(0,1), code);; // add the entry to the encoding map
		}
	}
}

void Morse_Tree::buildTree(string letter, string code) {
	/* buildTree: Build the tree one node at a time
	 * @param: the data for the node
	 * @param: the morse code for the node
	 */
	currentNode = root; // Reset the current node to the root of the tree

	for (unsigned int i = 0; i < code.length(); i++) { // length of the code is also the tree height
		if (code[i] == '.') { // dot, we need to go left
			if (currentNode->left == NULL) {
				currentNode->left = new BTNode<string>("TEMP"); // Create a dummy node
			}
			currentNode = currentNode->left; // Move the pointers along
		}
		else { // dash, we need to go right, no need for different dashes, as the file only contains '_'
			if (currentNode->right == NULL) {
				currentNode->right = new BTNode<string>("TEMP"); // Make a dummy node
			}
			currentNode = currentNode->right; // Move the pointers along
		}
	}
	currentNode->data = letter; // Fill the node data with the letter

}

void Morse_Tree::buildMap(string letter, string code){
	/* buildMap: Build the map for encoding
	* @param: the key
	* @param: the morse code which corresponds that key
	*/

	encodingMap[letter] = code; // add the entry to the encoding map
}

const string Morse_Tree::encode(string enc){
	/*encode: turns a character into morse code
	 * @param: the character to encode
	 * @return: the morse code for the character
	 */
	// From the technical requirements: You may use a binary search tree or a map to store the codes for letters.
	//TODO: ERROR checking

	return encodingMap[enc];
}

const string Morse_Tree::decode(string dec){
	/*decode: turns morse code into a letter
	* @param: the morse code to decode
	* @return: the letter for the morse code
	*/

	currentNode = root; // Reset the current node to the root of the tree

	for (unsigned int i = 0; i < dec.length(); i++) {
		if (dec[i] == '.') // Dot, go left
			currentNode = currentNode->left;
		else if (dec[i] == '_' || dec[i] == '-') // Dash, go right, allows for 2 different "dashes" from user
			currentNode = currentNode->right;
		else {
			cout << "ERROR-> Unrecognized character, please only use . - or _ for decoding." << endl;
			system("pause");
			exit(1);
		}
	}
	
	return currentNode->data;
}
