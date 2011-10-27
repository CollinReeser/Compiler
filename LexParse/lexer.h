
#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>


class Lexer
{
public:
	std::vector<std::string> tokenizeFile( std::string fileName )
		throw (std::string);
private:
	std::vector<std::string> internalTokenizeFix( 
		std::vector<std::string> tokens );
};

#endif
