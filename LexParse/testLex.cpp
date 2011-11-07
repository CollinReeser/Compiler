

#include "lexer.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc , char** argv)
{
	Lexer lex;
	try
	{
		vector<string> tokens = lex.tokenizeFile("test.col");
		for ( int i = 0; i < tokens.size(); i++ )
		{
			cout << tokens.at(i) << endl;
			if ( tokens.at(i).size() == 0 )
			{
				cout << "HIT" << endl;
			}
		}
	}
	catch (string msg)
	{
		cerr << msg << endl;
	}
	return 0;
}
