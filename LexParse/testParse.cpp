

#include <string>
#include <vector>
#include <iostream>
#include "parser.h"
#include "TopLevelContainer.h"

using namespace std;

int main(int argc , char** argv)
{
	Parser parse;
	try
	{
		TopLevelContainer tree = parse.parse("test.col");
	}
	catch (string msg)
	{
		cerr << msg << endl;
	}
	return 0;
}
