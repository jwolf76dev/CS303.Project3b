/* CS303 - Project 3b - Morse Code Tree
* (c) Binh Mai, Kati Williams, Jay Wolf
*/

#ifndef MORSE_TREE_H
#define MORSE_TREE_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "BTNode.h"
#include "Binary_Search_Tree.h"
#include "Tokenizer.h"

using namespace std;

template<typename Item_Type>
class Morse_Tree : public Binary_Search_Tree<Item_Type>
{
private:
	BTNode<string> *currentNode = new BTNode<string>("ROOT");; // A pointer to the root of our tree
	BTNode<string> *root = currentNode;
	map<string, string> encodingMap; // Key = Letter, data = Code
	const string dot = ".*";
	const string dash = "-_~";
public:
	Morse_Tree() {
        // Build the tree when object is created
		readFile();
	}

    // Destructor, deletes our pointers
	~Morse_Tree() {
		root = currentNode = NULL;
		delete root;
		delete currentNode;
	}

	// Tree Building Functions
	string trim(const string&);
	void readFile();
	void buildTree(const string&, const string&);
	void buildMap(const string&, const string&);

	// Encoding/Decoding Functions
	const string encode(const string&); // Return morse code for a letter
	const string decode(const string&); // Return letter for a morse code

	void error(); // Printing errors
};

template<typename Item_Type>
string Morse_Tree<Item_Type>::trim(const string& the_string)
{ /* trim: trims off excess characters from a string
  * @param: the string to trim
  * @return: the trimmed string
  */

	// Find the first non-space character
	size_t p = the_string.find_first_not_of(" ");

	// If empty string, return a blank string
	if (p == string::npos) return "";

	// Find the last non-space character
	size_t q = the_string.find_last_not_of(" ");

	// Return the string of characters between the first and last space
	return the_string.substr(p, q - p + 1);
}

template<typename Item_Type>
void Morse_Tree<Item_Type>::readFile() {
	/* readFile: reads in morse code file then sends it off to build the tree
	* @param: none
	* @return: none
	*/

	// Read in file
	ifstream in("morse.txt");

	// Throw an error if file is not in correct location
	if (!in) {
		cout << "Error, check morse.txt file location" << endl;
		system("pause");
		exit(1);
	}
	string line, code;

	if (in) {
		// Get the line from the file, store it in a variable called line
		while (getline(in, line)) {

			// Tokenizer class object, ignores character 0,  new line as the delimiter
			Tokenizer token(line.substr(1), "\n");

			// Code will be from character 1 onwards
			code = trim(token.next_token());

			// Send letter and code off to be incorporated into the tree
			buildTree(line.substr(0, 1), code);

			// Add the entry to the encoding map
			buildMap(line.substr(0, 1), code);;
		}
	}
	return;
}

template<typename Item_Type>
void Morse_Tree<Item_Type>::buildTree(const string& letter, const string& code) {
	/* buildTree: Build the tree one node at a time
	* @param: the data for the node
	* @param: the morse code for the node
	*/

	currentNode = root; // Reset the current node to the root of the tree

	for (unsigned int i = 0; i < code.length(); i++) { // length of the code is also the tree height
		if (dot.find(code[i])) { // dot, we need to go left
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

	return;
}

template<typename Item_Type>
void Morse_Tree<Item_Type>::buildMap(const string& letter, const string& code){
	/* buildMap: Build the map for encoding
	* @param: the key
	* @param: the morse code which corresponds that key
	*/

	// Add the entry to the encoding map
	encodingMap[letter] = code;
}

template<typename Item_Type>
const string Morse_Tree<Item_Type>::encode(const string& enc){
	/* encode: turns a character into morse code
	* @param: the character to encode
	* @return: the morse code for the character
	*/

	// Throws an error if character is not alphabetic
	if (!isalpha(enc[0])) {
		cout << "ERROR-> Cannot encode expression, non-alpha character found." << endl;
		error();
	}
	return encodingMap[enc];
}

template<typename Item_Type>
const string Morse_Tree<Item_Type>::decode(const string& dec){
	/* decode: turns morse code into a letter
	* @param: the morse code to decode
	* @return: the letter for the morse code
	*/

	// Reset the current node to the root of the tree
	currentNode = root;

	for (unsigned int i = 0; i < dec.length(); i++) {
		if (dot.find(dec[i])) // Dot, go left
			currentNode = currentNode->left;
		else if (dash.find(dec[i])) // Dash, go right, allows for 2 different "dashes" from user
			currentNode = currentNode->right;
		else {
			cout << "ERROR-> Cannot decode expression, please only use . - or _ for decoding." << endl;
			error();
		}
		if (currentNode == NULL) {
			// The code entered is either too long, or not a known code (e.g. ..-- or .....)
			cout << "ERROR-> Code entered is not a known alphabet morse code." << endl;
			error();
		}
	}

	return currentNode->data;
}

template<typename Item_Type>
void Morse_Tree<Item_Type>::error() {
	/* error: pause system so user can read error
	*/

	system("PAUSE");
	exit(1);
}

#endif // !MORSE_TREE_H

