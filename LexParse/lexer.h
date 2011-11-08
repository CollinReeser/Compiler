// This class tokenizes a file into a vector of strings, based off the lexical
// expectations of a language as yet unnamed, although strongly leaning towards
// the name "Language". Very C-like in nature. The lexing is simple enough
// and general enough to be easily adapted to virtually any language, as the
// tokens are simply deliminited by operators and some such, with function
// extensions to combine operators into more complex forms.



#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>


class Lexer
{
public:
	// This function opens the file of name fileName, and attempts to populate
	// a vector of strings with the tokens, using a few private functions to
	// clean up the result
	std::vector<std::string> tokenizeFile( std::string fileName )
		throw (std::string);
private:
	// This function combines simple operators into complex ones when the
	// operators are adjacent in the vector. For example, if two "<" strings
	// are adjacent in the token vector, they are combined into "<<"
	std::vector<std::string> internalTokenizeFix( 
		std::vector<std::string> tokens );
	// This function removes tabs and whitespace from the beginning and end
	// of tokens
	std::vector<std::string> internalRemoveWhitespace( 
		std::vector<std::string> tokens );
	// This function removes entries into the token vector if the entry is
	// of size zero
	std::vector<std::string> internalRemoveNullTokens( 
		std::vector<std::string> tokens );
};

#endif
