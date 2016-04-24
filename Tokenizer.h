/* CS303 - Project 3b - Morse Code Tree
*/

#ifndef TOKENIZER_H
#define TOKENIZER_H
#include<string>

class Tokenizer {
private:
    
    // Function to find the beginning and end of string
	void find_next();
    
	// The string to be split into tokens
	std::string the_source;
    
	// The string of delimeters
	std::string the_delim;
    
	// The index of the start of the next token
	size_t start;
    
	// The index of the end of the next token
	size_t end;
public:
    /* Construct a String Tokenizer
     * @param source The string to be split into tokens
     * @param delim The string containing the delimeters. If
     * this parameter is omitted, a space character is assumed.
     */
    Tokenizer(std::string source, std::string delim = " ") :
    the_source(source), the_delim(delim), start(0), end(0) {
        find_next();
    }
    
    // Function to determine if there are more tokens to process
    bool has_more_tokens();
    
    // Function to retrieve the next token
    std::string next_token();
};

#endif // !TOKENIZER_H
