#ifndef BOOLEAN_EXP_COMPLEX_H
#define BOOLEAN_EXP_COMPLEX_H


#include <string>
#include "boolExpSimple.h"

class BoolExpComplex
{
public:
	void convertComplexBoolExp( std::string boolExp );
	
private:
	std::vector<BoolExpSimple> simpleExpressions;
	std::vector<std::string> logOperations;
};

#endif
