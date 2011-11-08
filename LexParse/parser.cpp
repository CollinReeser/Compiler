

#include <vector>
#include <string>
#include "lexer.h"
#include "parser.h"
#include "ParseContainer.h"
#include "TopLevelContainer.h"
#include "ClassContainer.h"
#include "FunctionContainer.h"

TopLevelContainer Parser::parse( std::string fileName )
{
	Lexer lex;
	std::vector<std::string> tokens = lex.tokenizeFile(fileName);
	TopLevelContainer container(tokens);
	return container;
}
