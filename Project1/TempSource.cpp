#include "Tokenizer.h"
#include <fstream>
#include <iostream>
using namespace std;

/** Function to remove the leading and trailing spaces from a string */
string trim(const string& the_string)
{
	size_t p = the_string.find_first_not_of(" ");
	if (p == string::npos) return "";
	size_t q = the_string.find_last_not_of(" ");
	return the_string.substr(p, q - p + 1);
}

void main(void) {

	ifstream in("morse.txt");
	if (in) {
		string line, letter, code;
		while (getline(in, line)) { //Get the line from the file, store it in a variable called line
			letter = line[0]; //Letter will always be the first character of line
			Tokenizer token(line.substr(1), "\n"); //Tokenizer class object, ignores character 0,  new line as the delimiter
			code = trim(token.next_token()); //the code will be from character 1 onwards

			cout << "letter: " << letter << "\t code: " << code << "\t code length: " << code.length() << endl; //length was to check for extra spaces
		}
	}
	system("pause");
}