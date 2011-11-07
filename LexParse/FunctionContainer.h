#ifndef FUNCTION_CONTAINER_H
#define FUNCTION_CONTAINER_H

#include <vector>
#include <string>
#include "ParseContainer.h"

class FunctionContainer
{
	ParseContainer parse(ParseContainer parsing);
private:
	bool isPublic; // False is private
	std::string returnType;
	std::string name;
	std::vector<std::string> signatureRaw;
	std::vector<std::vector<std::string> > rawStatements;
};

#endif
