

#include "lexer.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc , char** argv)
{
	Lexer lex;
	// This run tests the original lexing function
	cout << "\n\nThe following is the output of tokenizeFile(): \n\n" <<
		endl;
	try
	{
		vector<string> tokens = lex.tokenizeFile("lexer.h");
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
	// This run tests the V2 lexing function
	cout << "\n\nThe following is the output of tokenizeFileV2(): \n\n" <<
		endl;
	try
	{
		vector<LineTokens> tokens = lex.tokenizeFileV2("lexer.h");
		for ( int i = 0; i < tokens.size(); i++ )
		{
			cout << "Line " << tokens.at(i).lineNum << ": ";
			for ( int j = 0; j < tokens.at( i ).tokens.size(); j++ )
			{
				cout << tokens.at(i).tokens.at(j) << " ";
				if ( tokens.at(i).tokens.size() == 0 )
				{
					cout << " FAIL_HIT ";
				}
			}
			cout << endl;
		}
	}
	catch (string msg)
	{
		cerr << msg << endl;
	}
	return 0;
}
