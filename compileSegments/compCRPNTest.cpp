
#include <string>
#include <iostream>
#include "../utilities/SimpleTextUtil.h"
#include "../utilities/RPNNotation.h"

std::string compFullCRPNSegment( RPNNotation RPN );

int main(int argc , char** argv)
{
	std::string infix = "(12+(19*8+(2*56+(-304-2*(1001+(17-(16+(-22*(3+3*12)))))))))+60/12"; // 297
	SimpleTextUtil util;
	std::string postfix = util.convertInfixToPostfix( infix );
	std::cout << "; " << postfix << std::endl;
	RPNNotation note;
	note.convertStrToRPN( postfix );
	std::string full = compFullCRPNSegment( note );
	std::cout << full << std::endl;
	return 0;
}
