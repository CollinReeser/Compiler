#ifndef	BOOLEAN_EXP_SIMPLE_H
#define BOOLEAN_EXP_SIMPLE_H

#include <string>
#include "RPNNotation.h"

class BoolExpSimple
{
public:
	void convertSimpleBoolExp( std::string boolExp );
	
private:
	RPNNotation left;
	RPNNotation right;
	std::string operation;
};

#endif
