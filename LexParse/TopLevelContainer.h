#ifndef TOP_LEVEL_CONTAINER_H
#define TOP_LEVEL_CONTAINER_H

#include <vector>
#include <string>
#include "ClassContainer.h"
#include "FunctionContainer.h"
#include "ParseContainer.h"

class TopLevelContainer
{
public:
	TopLevelContainer( std::vector<std::string> tokens );
	void parseTopLevel( ParseContainer parsing );
private:
	std::vector<std::string> includeStatements;
	std::vector<std::string> globalVariableStatements;
	std::vector<ClassContainer> classDefinitions;
	std::vector<FunctionContainer> globalFunctionDefinitions;
};

#endif
