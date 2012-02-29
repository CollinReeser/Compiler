// This program tests the functionality of the RPNCollapseI function, and should
// also eventually test the yet-to-exist RPNCollapseF function

#include "RPNNotation.h"
#include "SimpleTextUtil.h"
#include <string>
#include <iostream>


int main( int argc , char** argv )
{
	std::string infix = "(14+(19*8+(2*56+(-304-2*(1001+(17-(16+(-22*(3+3*12)))))))))+60/12";
	int val = (14+(19*8+(2*56+(-304-2*(1001+(17-(16+(-22*(3+3*12)))))))))+60/12;
	SimpleTextUtil util;
	std::string postfix = util.convertInfixToPostfix( infix );
	RPNNotation note;
	note.convertStrToRPN(postfix);
	std::cout << "Before conversion:\n" << std::endl;
	for ( int i = 0; i < note.size(); i++ )
	{
		std::cout << note.at(i) << std::endl;
	}
	std::cout << "\nAfter conversion:\n" << std::endl;
	collapseRPNI( note );
	for ( int i = 0; i < note.size(); i++ )
	{
		std::cout << note.at(i) << std::endl;
	}
	std::cout << "Note that this should be condensed to: " << val << std::endl;
	// Now again, but with a few variables stuck in
	std::cout << "\nAgain, but with a few variables stuck in:\n" << std::endl;
	infix = "(VAR1+(19*8+(2*56+(-304-VAR2*(1001+(17-(16+(-22*(3+3*12)))))))))+60/12";
	postfix = util.convertInfixToPostfix( infix );
	note.convertStrToRPN(postfix);
	std::cout << "Before conversion:\n" << std::endl;
	for ( int i = 0; i < note.size(); i++ )
	{
		std::cout << note.at(i) << std::endl;
	}
	std::cout << "\nAfter conversion:\n" << std::endl;
	collapseRPNI( note );
	for ( int i = 0; i < note.size(); i++ )
	{
		std::cout << note.at(i) << std::endl;
	}
	return 0;
}

