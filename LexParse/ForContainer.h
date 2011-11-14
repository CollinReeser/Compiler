
#ifndef FOR_CONTAINER_H
#define FOR_CONTAINER_H

#include "ScopeContainer.h"
#include "Structs.h"

class ForContainer : public ScopeContainer
{
	// This does the work of processing the for statement
	ParseContainer parse(ParseContainer parsing);
	// Called at the tail end of the for block, when the terminating brace for
	// the for statement is reached, this function simplifies the
	// rawForCondition statement into the three vectors containing actual
	// StatementContainers
	void processForCondition();
private:
	// This is the entirety of the inside of the for condition, where for the
	// line "for ( int i = 0; i < 10; i++ )", the tokens in the rawForCondition
	// are "int i = 0 ; i < 10 ; i ++"
	std::vector<std::string> rawForCondition;
	// This vector contains the declarations of the index variables, or the line
	// "int i = 0 ;" from above. In complex for loop statements, index variable
	// declarations are separated by commas, as in 
	// "for( int i = 0 , int j = 0; i < 10 && j < 10; i++ , j++)"
	std::vector<StatementContainer> indexVars;
	// This vector contains the logical statements that make up the middle
	// section of a for statement, where each entry into this vector is a 
	// separate logical statement, where in the for loop these statements are
	// separated by commas
	std::vector<StatementContainer> logicalChecks;
	// This vector contains the incrementing statements, separated by commas in
	// the original for statement, that make up the third section of for loop
	// statements
	std::vector<StatementContainer> incrementors;
};

#endif
