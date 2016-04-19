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
	string line, letter, code;
	if (in) {
		while (getline(in, line)) { // Get the line from the file, store it in a variable called line
			letter = line[0]; // Letter will always be the first character of line
			Tokenizer token(line.substr(1), "\n"); // Tokenizer class object, ignores character 0,  new line as the delimiter
			code = trim(token.next_token()); // Code will be from character 1 onwards
			buildTree(letter, code); // Send letter and code off to be incorporated into the tree
		}
	}
}

void Morse_Tree::buildTree(string letter, string code) {
	/* buildTree: Build the tree one node at a time
	 * @param: the data for the node
	 * @param: the morse code for the node
	 */
	BTNode<string> *temp = root, *head = root;
	for (int i = 0; i < code.length(); i++) { // length of the code is also the tree height
		if (code[i] == '.') { // dot, we need to go left
			if (temp->left == NULL) {
				temp->left = new BTNode<string>("TEMP"); // Create a dummy node
				root->left = temp->left; // Connect the nodes
			}
			temp = root = temp->left; // Move the pointers along
		}
		else { // dash, we need to go right
			if (temp->right == NULL) {
				temp->right = new BTNode<string>("TEMP"); // Make a dummy node
				root->right = temp->right; // Connect the nodes
			}
			temp = root = temp->right; // Move the pointers along
		}
	}
	temp->data = letter; // Fill the node data with the letter
	root = head; // Reset the root to the head of the tree

	temp = head = NULL; // Set the temp nodes to NULL before deletion
	delete temp;
	delete head;
}

string Morse_Tree::encode(string enc){
	/*encode: turns a character into morse code
	 * @param: the character to encode
	 * @return: the morse code for the character
	 */
	BTNode<string> *head = root;
	string encoded;
	// TODO: ALL OF THIS FUNCTION

	return string();
}

string Morse_Tree::decode(string dec){
	/*decode: turns morse code into a letter
	* @param: the morse code to decode
	* @return: the letter for the morse code
	*/

	BTNode<string> *temp = root;
	for (int i = 0; i < dec.length(); i++) {
		if (dec[i] == '.') // Dot, go left
			temp = temp->left;
		else // Dash, go right
			temp = temp->right;
	}
	string decoded = temp->data;
	temp = NULL;
	delete temp; // remove temp pointer
	return decoded;
}
