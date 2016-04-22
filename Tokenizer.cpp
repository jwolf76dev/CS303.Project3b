/* CS303 - Project 3b - Morse Code Tree
*/

#include "Tokenizer.h"
using std::string;

/** Position start and end so that start is the index of the start
of the next token and end is the end.
*/
void Tokenizer::find_next() {
	// Find the first character that is not a delimeter
	start = the_source.find_first_not_of(the_delim, end);

	// Find the next delimeter
	end = the_source.find_first_of(the_delim, start);

}

/** Determine if there are more tokens
@return true if there are more tokens
*/
bool Tokenizer::has_more_tokens() {
	return start != string::npos;
}

/** Retrieve the next token
@return the next token. If there are no more
tokens, an empty string is returned
*/
string Tokenizer::next_token() {

	// Make sure there is a next token
	if (!has_more_tokens())
		return "";
	// Save the next token in return_value
	string token = the_source.substr(start, end - start);

	// Find the following token
	find_next();

	// Return the next token
	return token;
}

