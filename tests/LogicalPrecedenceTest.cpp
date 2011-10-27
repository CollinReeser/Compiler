#include <iostream>
using namespace std;

int main( int argc , char** argv )
{
	if ( false && true || false )
	{
		cout << "|| Precedence over &&" << endl;
	}
	else
	{
		cout << "&& precedence over ||" << endl;
	}
	if ( true && !true || false )
	{
		cout << "OR Precedence over !." << endl;
	}
	else
	{
		cout << "! Precedence over OR." << endl;
	}
	int temp = 5;
	te/*Hello, world!*/mp = 6;
	cout << temp << endl;
}
