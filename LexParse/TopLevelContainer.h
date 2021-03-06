#ifndef TOP_LEVEL_CONTAINER_H
#define TOP_LEVEL_CONTAINER_H

#include <vector>
#include <string>
#include "ParseContainer.h"
#include "Structs.h"

class TopLevelContainer
{
public:
	TopLevelContainer( std::vector<std::string> tokens );
private:
	void parseTopLevel();
	// This contains a list of variables found just after include statements,
	// such that the lines:
	// include <vector>
	// include "myLocal"
	// will be parsed to:	fileName: vector , isLocal: false
	//						fileName: myLocal , isLocal: true
	// where local things are kept in quotes, and library things are in wakas
	std::vector<include> includes;
	std::vector<std::string> globalVariableStatements;
	ParseContainer parsing;
};

#endif
