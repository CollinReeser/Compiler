#ifndef CLASS_CONTAINER_H
#define CLASS_CONTAINER_H

#include <vector>
#include <string>
#include "FunctionContainer.h"
#include "ParseContainer.h"
#include "Structs.h"

class ClassContainer
{
public:
	// We take our parsing construct, and continue to parse the tokens, except
	// we are now parsing within the context of a class definition
	ParseContainer parse(ParseContainer parsing);
	// Call this at the tail end of the class definition (when the closing
	// brace for the class definition is encountered) in order to further
	// process the variable declarations into an easier to use format
	void processVarDecs();
private:
	// This is the name of the class
	std::string name;
	// These are the raw statements for variable declaration, that will be
	// further processed by individual functions into a variable declaration
	// vector
	std::vector<std::string> privateVariableStatements;
	std::vector<ClassContainer> publicVariableStatements;
	// Here we will contain the processed variable statements
	std::vector<VarDec> privateVariableDeclarations;
	std::vector<VarDec> publicVariableDeclarations;
	// Here we contain function definitions
	std::vector<FunctionContainer> functionDefinitions;
};

#endif
