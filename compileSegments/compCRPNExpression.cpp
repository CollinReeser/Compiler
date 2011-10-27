// The title stands for "Compile Constant Reverse Polish Notation Expression",
// meaning this assumes that all non-operators in the expression are integer
// or floating point
// constants. This program produces the raw assembly code to evaluate an
// RPN expression, with the result stored on the top of the assembly stack

#include "../utilities/SimpleTextUtil.h"
#include "../utilities/RPNNotation.h"
#include <string>
#include <stack>
#include <vector>


// Make the partial compile functions available globally. Consider wrapping
// these in one public function, so that we don't need to check for whether
// the RPN has any float values externally from these function calls
extern std::string compCRPNSegmentI( RPNNotation RPN );
extern std::string compCRPNSegmentF( RPNNotation RPN );

std::string compCRPNSegmentI( RPNNotation RPN )
{
	SimpleTextUtil util;
	std::string segment;
	for ( int i = 0; i < RPN.size(); i++ )
	{
		if ( util.isOperator( RPN.at( i ) ) )
		{
			if ( RPN.at(i).compare("+") == 0 )
			{
				// Get an addition operand
				segment += "\tmov\t\teax , [esp]\n";
				// Pop the operand
				segment += "\tadd\t\tesp , 4\n";
				// Get another operand
				segment += "\tmov\t\tebx , [esp]\n";
				// Pop the other operand
				segment += "\tadd\t\tesp , 4\n";
				// Add the operands
				segment += "\tadd\t\teax , ebx\n";
				// Push the result onto the stack
				segment += "\tsub\t\tesp , 4\n";
				segment += "\tmov\t\t[esp] , eax\n";
			}
			else if ( RPN.at(i).compare("-") == 0 )
			{
				// Get the subtraction value
				segment += "\tmov\t\tebx , [esp]\n";
				// Pop subtraction value
				segment += "\tadd\t\tesp , 4\n";
				// Get the value to subtract from
				segment += "\tmov\t\teax , [esp]\n";
				// Pop the value to subtract from
				segment += "\tadd\t\tesp , 4\n";
				// Subtract the two values
				segment += "\tsub\t\teax , ebx\n";
				// Push the result onto the stack
				segment += "\tsub\t\tesp , 4\n";
				segment += "\tmov\t\t[esp] , eax\n";
			}
			else if ( RPN.at(i).compare("*") == 0 )
			{
				// Get first mult value
				segment += "\tmov\t\tebx , [esp]\n";
				// Pop mult value
				segment += "\tadd\t\tesp , 4\n";
				// Get second mult value
				segment += "\tmov\t\teax , [esp]\n";
				// Pop second mult value
				segment += "\tadd\t\tesp , 4\n";
				//  Multiply the two values
				segment += "\tmul\t\tebx\n";
				// Push the result onto the stack
				segment += "\tsub\t\tesp , 4\n";
				segment += "\tmov\t\t[esp] , eax\n";
			}
			else if ( RPN.at(i).compare("/") == 0 )
			{
				// Get the divisor value
				segment += "\tmov\t\tebx , [esp]\n";
				// Pop divisor value
				segment += "\tadd\t\tesp , 4\n";
				// Get the dividend
				segment += "\tmov\t\teax , [esp]\n";
				// Pop the dividend
				segment += "\tadd\t\tesp , 4\n";
				// Clear edx for the division
				segment += "\tmov\t\tedx , 0\n";
				// Divide the two values
				segment += "\tdiv\t\tebx\n";
				// Push the result onto the stack
				segment += "\tsub\t\tesp , 4\n";
				segment += "\tmov\t\t[esp] , eax\n";
			}
		}
		else
		{
			segment += "\tsub\t\tesp , 4\n";
			segment += "\tmov\t\t[esp] , dword " + RPN.at(i) + "\n";
		}
	}
	return segment;
}

std::string compCRPNSegmentF( RPNNotation RPN )
{
	SimpleTextUtil util;
	std::string segment;
	for ( int i = 0; i < RPN.size(); i++ )
	{
		if ( util.isOperator( RPN.at( i ) ) )
		{
			if ( RPN.at(i).compare("+") == 0 )
			{
				// Get an addition operand
				segment += "\tfld\t\tdword [esp]\n";
				// Pop the operand
				segment += "\tadd\t\tesp , 4\n";
				// Get second addition operand
				segment += "\tfld\t\tdword [esp]\n";
				// Pop the operand
				segment += "\tadd\t\tesp , 4\n";
				// Add
				segment += "\tfaddp\n";
				// Push the result onto the stack
				segment += "\tsub\t\tesp , 4\n";
				segment += "\tfstp\t\tdword [esp]\n";
			}
			else if ( RPN.at(i).compare("-") == 0 )
			{
				// Get the subtraction value
				segment += "\tmov\t\tebx , [esp]\n";
				// Pop subtraction value
				segment += "\tadd\t\tesp , 4\n";
				// Get the value to subtract from
				segment += "\tmov\t\teax , [esp]\n";
				// Pop the value to subtract from
				segment += "\tadd\t\tesp , 4\n";
				// Subtract the two values
				segment += "\tsub\t\teax , ebx\n";
				// Push the result onto the stack
				segment += "\tsub\t\tesp , 4\n";
				segment += "\tmov\t\t[esp] , eax\n";
			}
			else if ( RPN.at(i).compare("*") == 0 )
			{
				// Get first mult value
				segment += "\tmov\t\tebx , [esp]\n";
				// Pop mult value
				segment += "\tadd\t\tesp , 4\n";
				// Get second mult value
				segment += "\tmov\t\teax , [esp]\n";
				// Pop second mult value
				segment += "\tadd\t\tesp , 4\n";
				//  Multiply the two values
				segment += "\tmul\t\tebx\n";
				// Push the result onto the stack
				segment += "\tsub\t\tesp , 4\n";
				segment += "\tmov\t\t[esp] , eax\n";
			}
			else if ( RPN.at(i).compare("/") == 0 )
			{
				// Get the divisor value
				segment += "\tmov\t\tebx , [esp]\n";
				// Pop divisor value
				segment += "\tadd\t\tesp , 4\n";
				// Get the dividend
				segment += "\tmov\t\teax , [esp]\n";
				// Pop the dividend
				segment += "\tadd\t\tesp , 4\n";
				// Clear edx for the division
				segment += "\tmov\t\tedx , 0\n";
				// Divide the two values
				segment += "\tdiv\t\tebx\n";
				// Push the result onto the stack
				segment += "\tsub\t\tesp , 4\n";
				segment += "\tmov\t\t[esp] , eax\n";
			}
		}
		else
		{
			segment += "\tsub\t\tesp , 4\n";
			segment += "\tmov\t\t[esp] , dword __float32__(" +RPN.at(i)+ ")\n";
		}
	}
	return segment;
}





// Same as compCRPNSegment, except additional code is provided at the beginning
// and the end such that it produces a complete assemble-able file that prints
// the result of the expression to the terminal
std::string compFullCRPNSegment( RPNNotation RPN )
{
	std::string full;
	full += "\t\textern\tprintf\n"; // Gain access to printf
	full += "\t\tSECTION .data\n";
	if ( RPN.isFloat() )
	{
		full += "fmt:\tdb \"%f\", 10, 0\n";
	}
	else
	{
		full += "fmt:\tdb \"%d\", 10, 0\n";
	}
	full += "\t\tSECTION .text\n";
	full += "\t\tglobal main\n"; // Standard GCC entry point
	full += "main:\n";
	full += "\tpush\t\tebp\n";
	full += "\tmov\t\tebp , esp\n";
	// If the expression contains floating point values, we need to evaluate
	// the entire expression as though every value is floating point
	if ( RPN.isFloat() )
	{
		full += compCRPNSegmentF( RPN );
		full += "\tfld\t\tdword [esp]\n"; // The result is on the top of stack
		full += "\tfstp\t\tqword [esp]\n"; // Push expression result for printf
	}
	// Otherwise, evaluate as an integer expression
	else
	{
		full += compCRPNSegmentI( RPN );
		full += "\tmov\t\teax , [esp]\n"; // The result is on the top of stack
		full += "\tpush\t\teax\n"; // Push expression result for printf
	}
	full += "\tpush\t\tdword fmt\n"; // Push control string
	full += "\tcall\t\tprintf\n";
	full += "\tadd\t\tesp , 8\n"; // Remove parameters for printf off stack
	full += "\tmov\t\tesp , ebp\n";
	full += "\tpop\t\tebp\n";
	full += "\tmov\t\teax , 0\n"; // Return code of success
	full += "\tret"; // Return from assembly program
	return full;
}

