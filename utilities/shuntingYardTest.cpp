#include <iostream>
#include "SimpleTextUtil.h"

using namespace std;

int main( int argc , char** argv )
{
	SimpleTextUtil util;
	//string infix("-5+(-4+-10)--6-6");
	string infix( "5.0+var-(-4+var2/var)--6*3.0" );
	try
	{
		string postfix = util.convertInfixToPostfix( infix );
		cout << postfix << endl;
	}
	catch ( std::string err )
	{
		cerr << err << endl;
	}
}
