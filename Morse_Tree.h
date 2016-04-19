#ifndef MORSE_TREE_H
#define MORSE_TREE_H

#include <string>
#include "Tokenizer.h"
#include "BTNode.h"
#include <map>
using namespace std;

class Morse_Tree {
private:
	BTNode<string> *currentNode = new BTNode<string>("ROOT");; // A pointer to the root of our tree
	BTNode<string> *root = currentNode;
	map<string, string> encodingMap; // Key = Letter, data = Code

public:
	Morse_Tree() {
		readFile();
	} // Build the tree when object is created

	~Morse_Tree() { // Destructor, delete our pointers
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
};
#endif // !MORSE_TREE_H

