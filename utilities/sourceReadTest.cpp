#include <iostream>
#include <vector>
#include <string>
#include "SimpleTextUtil.h"

using namespace std;

int main( int argc , char** argv )
{
	SimpleTextUtil util;
	string file("test.col");
	// Try to open the file and split it to lines
	try
	{	
		vector<string> fileLines = util.fileToLines( file );
		cout << "File that was read: " << endl;
		util.printFile( fileLines );
		cout << "End file print." << endl;
		cout << endl;
		// Strip multi-line comments from the file
		util.stripMultiComments( fileLines );
		cout << "File after multi-line comments-strip:" << endl;
		util.printFile( fileLines );
		cout << "End file print." << endl;
		// Strip the line comments from the file
		util.stripLineComments( fileLines );
		cout << "File after line comments-strip:" << endl;
		util.printFile( fileLines );
		cout << "End file print." << endl;
	}
	// Catch and print the error message if there was one
	catch ( string msg )
	{
		cerr << msg << endl;
	}
}
