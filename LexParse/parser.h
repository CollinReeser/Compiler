
#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "ParseContainer.h"
#include "TopLevelContainer.h"

class Parser
{
public:
	TopLevelContainer parse( std::string fileName );
private:
};

#endif
