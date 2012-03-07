// The purpose of this function is to take an RPN collection and collapse it,
// where-in the constants within the expression that can be arithmetically
// manipulated (are not joined to variables with operators), are collapsed, so
// that the overall expression is smaller. Intended behavior is such that
// an arbitrary-length expression with only constants would be reduced to one
// constant

// For debugging purposes
//#define TEST

#include "SimpleTextUtil.h"
#include "RPNNotation.h"
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#ifdef TEST
#include <iostream>
#endif

extern void collapseRPNI( RPNNotation& RPN );

int calcCollapseI( int valOne , int valTwo , std::string oper )
{
#ifdef TEST
	std::cout << "calcCollapseI entered." << std::endl;
#endif
	if ( oper.compare( "+" ) == 0 )
	{
#ifdef TEST
	std::cout << "calcCollapseI exited in addition." << std::endl;
#endif
		return valOne + valTwo;
	}
	else if ( oper.compare( "-" ) == 0 )
	{
#ifdef TEST
	std::cout << "calcCollapseI exited in subtraction." << std::endl;
#endif
		return valOne - valTwo;
	}
	else if ( oper.compare( "*" ) == 0 )
	{
#ifdef TEST
	std::cout << "calcCollapseI exited in multiplication." << std::endl;
#endif
		return valOne * valTwo;
	}
	else if ( oper.compare( "/" ) == 0 )
	{
#ifdef TEST
	std::cout << "calcCollapseI exited in division." << std::endl;
#endif
		return valOne / valTwo;
	}
	else if ( oper.compare( "%" ) == 0 )
	{
#ifdef TEST
	std::cout << "calcCollapseI exited in modulus." << std::endl;
#endif
		return valOne % valTwo;
	}
#ifdef TEST
	std::cout << "calcCollapseI abnormally exited." << std::endl;
#endif
	// Failure, but this should never be reached ever
	return 0;
}

void collapseRPNI( RPNNotation& RPN )
{
	SimpleTextUtil util;
	// Make a copy of the expression structure
	std::vector<std::string> structCopy = RPN.RPNStructure;
	// Indicates that a collapsing operation occured in the loop through the
	// RPN structure, meaning that we should loop again until all possible
	// collapsing has been accomplished
	bool change = true;
	while ( change )
	{
		change = false;
		for ( int i = 0; i < structCopy.size(); i++ )
		{
			// Check if there are at least two tokens beyond the current
			//token
			if ( i + 1 < structCopy.size() && i + 2 < structCopy.size() )
			{
				// If there are, check if the current token and the next token
				// are numbers, and that the i + 2 token is an operator
				if ( !util.isOperator( structCopy.at( i ) ) &&
					!util.isOperator( structCopy.at( i + 1 ) ) &&
					util.isOperator( structCopy.at( i + 2 ) ) )
				{
					// Finally, try to convert the two number tokens to
					// actual integer values. If this part fails, then the
					// "numbers" were actually variable names, and this section
					// cannot be collapsed. However, if they are numbers,
					// calculate the operation and collapse the expression
					std::stringstream ss1;
					std::stringstream ss2;
					int valOne;
					int valTwo;
					int valResult;
					ss1.str( structCopy.at(i) );
					ss2.str( structCopy.at(i + 1) );
					ss1 >> valOne;
					ss2 >> valTwo;
					// Successfully converted constant integer values; the
					// values were not variable strings
					if ( !ss1.fail() && !ss2.fail() )
					{
#ifdef TEST
						std::cout << "First value:\t" << valOne << "\n";
						std::cout << "Second value:\t" << valTwo << "\n";
						std::cout << "Operator\t" << structCopy.at( i + 2 );
						std::cout << std::endl;
#endif
						// Calculate result of collapsing operation
						valResult = calcCollapseI( valOne , valTwo , 
							structCopy.at( i + 2 ) );
#ifdef TEST
						std::cout << "Result:\t\t" << valResult << std::endl;
#endif
						// Convert the calculated integer to a string
						std::stringstream resultConverter;
						std::string reductionResult;
						resultConverter << valResult;
						reductionResult = resultConverter.str();
						// Erase the two values and the operator. Note that it
						// is ... + i + 3 because the range is right-exclusive
						structCopy.erase( structCopy.begin() + i , 
							structCopy.begin() + i + 3 );
						// Insert the collapsed value
						structCopy.insert( structCopy.begin() + i , 
							reductionResult );
						// We did change something in the expression
						change = true;
					}
				}
			}
		}
	}
	RPN.RPNStructure = structCopy;
	return;
}
