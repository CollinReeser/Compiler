#include <vector>
#include <string>
#include "TopLevelContainer.h"
#include "ParseContainer.h"

TopLevelContainer::TopLevelContainer( std::vector<std::string> tokens ) :
	parsing(tokens)
{
	TopLevelContainer::parseTopLevel();
	return;
}

void TopLevelContainer::parseTopLevel()
{
	// In this section, we parse the includes
	while( !parsing.atEnd() )
	{
		if ( parsing.peekNext() == "include" )
		{
			// Pull the next token, strip the enclosing quotes or wakas,
			// and populate the includes vector with an include struct
			// containing the relevant information
		}
		else
		{
			// Exit parsing includes, as the next thing we peeked at was not
			// the "include" keyword
			break;
		}
	}
	// In this section, we "recursively" parse classes and global functions,
	// as well as global variables
	return;
}
