// This program tests the functionality of the RPNNotation class


#include <string>
#include "RPNNotation.h"
#include "SimpleTextUtil.h"
#include <iostream>
using namespace std;

int main( int argc , char** argv )
{
	RPNNotation note;
	SimpleTextUtil util;
	std::string rpn = util.convertInfixToPostfix("5+-5.0--5+var");
	cout << rpn << endl;
	cout << "Converted from string" << endl;
	note.convertStrToRPN(rpn);
	cout << "Converted to structure" << endl;
	note.printStructure();
	cout << "Printed structure" << endl;
}
