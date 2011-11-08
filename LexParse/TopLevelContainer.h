#ifndef TOP_LEVEL_CONTAINER_H
#define TOP_LEVEL_CONTAINER_H

#include <vector>
#include <string>
#include "ClassContainer.h"
#include "FunctionContainer.h"
#include "ParseContainer.h"

struct include
{
	// The library or user stuff to include
	std::string fileName;
	// Whether it is a local or library thing
	bool isLocal; 
};

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
	std::vector<ClassContainer> classDefinitions;
	std::vector<FunctionContainer> globalFunctionDefinitions;
	ParseContainer parsing;
};

#endif
