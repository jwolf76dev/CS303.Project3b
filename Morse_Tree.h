#ifndef MORSE_TREE_H
#define MORSE_TREE_H
#include <string>
#include "Tokenizer.h"
#include "BTNode.h"
using namespace std;

class Morse_Tree {
private:
	BTNode<string> *root; // A pointer to the root of our tree

public:
	Morse_Tree() { buildTree(); } // Build the tree when object is created


	// Tree Building Functions
	string trim(const string&);
	void buildTree();

	// Encoding/Decoding Functions
	string encode(string); // Return morse code for a letter
	string decode(string); // Return letter for a morse code
};
#endif // !MORSE_TREE_H

