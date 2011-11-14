#ifndef FUNCTION_CONTAINER_H
#define FUNCTION_CONTAINER_H

#include <vector>
#include <string>
#include "ParseContainer.h"
#include "Structs.h"

class FunctionContainer
{
public:
	// This function is called after first creating a FunctionContainer object
	// upon determining that a function definition is being made. This does a
	// little work in pulling the function signature, then continually passes
	// off parsing duty to StatementContainers, whose contents are returned
	// and stored in the statements vector of this class
	ParseContainer parse(ParseContainer parsing);
private:
	// If true, the function is a global function, and not considered a member
	// of a class
	bool isGlobal;
	// False is private, whether this function declaration is public or private
	// within the confines of a class declaration. For a global function,
	// isPublic holds no meaning (or can be considered true)
	bool isPublic;
	// These are the raw tokens that make up the function signature. A function
	// processSignature will be called at the tail end of the function
	// definition to process the signature into an easier to use format
	std::vector<std::string> signatureRaw;
	// This is the declared return type of the function. Either "void", some
	// primitive type like "int", or a user defined type
	std::string returnType;
	// This is the name of the function
	std::string name;
	// These are the function parameters, where the first entry (at(0)) is the
	// leftmost parameter, and the last entry (at(size()-1)) is the rightmost
	// parameter. A size of zero on this vector means the function takes no
	// parameters
	std::vector<VarDec> functionParameters;
	// This vector will be populated with each of the actual statements within
	// the function, in the topmost scope
	std::vector<StatementContainer> statements;
};

#endif
