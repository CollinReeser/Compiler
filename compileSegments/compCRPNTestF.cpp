
#include <string>
#include <iostream>
#include "../utilities/SimpleTextUtil.h"
#include "../utilities/RPNNotation.h"

std::string compFullCRPNSegment( RPNNotation RPN );

int main(int argc , char** argv)
{
	//std::string infix = "1.2+2.3+(3.4 + 4.5) + (5.6 +6.7)+ 7.8+8.9+10.111";
	std::string infix = "1/2*3+4.5-6/3+8.625*3-(2.5+3.4/1.25)+8.2";
	SimpleTextUtil util;
	std::string postfix = util.convertInfixToPostfix( infix );
	std::cout << "; " << postfix << std::endl;
	//std::cout << "; " << ( 1.2+2.3+(3.4 + 4.5) + (5.6 +6.7)+ 7.8+8.9+10.111 ) << std::endl;
	std::cout << "; " << ( 1/2*3+4.5-6/3+8.625*3-(2.5+3.4/1.25)+8.2 ) << 
		" - Note that the actual output is probably more accurate than this" << std::endl;
	RPNNotation note;
	note.convertStrToRPN( postfix );
	std::string full = compFullCRPNSegment( note );
	std::cout << full << std::endl;
	return 0;
}
