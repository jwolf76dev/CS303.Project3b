#include "MorseCode.h"

string MorseCode::decode(string dec)
{
	// we need a while loop in here
	// stuff for spaces, sentences ect
	return morseCodeTree.decode(dec);
}

string MorseCode::encode(string enc)
{
	// see above
	return morseCodeTree.encode(enc);
}
