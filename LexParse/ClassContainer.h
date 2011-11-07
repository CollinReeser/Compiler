#ifndef CLASS_CONTAINER_H
#define CLASS_CONTAINER_H

#include <vector>
#include <string>
#include "FunctionContainer.h"
#include "ParseContainer.h"

class ClassContainer
{
	ParseContainer parse(ParseContainer parsing);
private:
	std::string name;
	std::vector<std::string> privateVariableStatements;
	std::vector<ClassContainer> publicVariableStatements;
	std::vector<FunctionContainer> functionDefinitions;
};

#endif
