// This file is the implementation of the class RPNNotation, which builds a
// structure to house a provided post-fix notation string into an easily
// queried form. The input of convertStrToRPN should be the output of a call to
// SimpleTextUtil's function, convertInfixToPostfix(infix string)


#include <string>
#include <vector>
#include <iostream>
#include "SimpleTextUtil.h"
#include "RPNNotation.h"
using namespace std;

void RPNNotation::convertStrToRPN( std::string RPN )
{
	RPNNotation::originalRPN = RPN;
	SimpleTextUtil util;
	std::string temp;
	bool newSection = false;
	int section = 0;
	for ( int i = 0; i < RPN.size(); i++ )
	{
		if ( RPN.at( i ) == ' ' )
		{
			newSection = true;
			continue;
		}
		if ( newSection )
		{
			newSection = false;
			section++;
			temp.clear();
			temp += RPN.at( i );
			RPNNotation::RPNStructure.push_back( temp );
			if ( util.isOperator( RPN.at( i ) ) && ( ( i + 1 == RPN.size() ) || 
				( i + 1 != RPN.size() && RPN.at(i + 1) == ' ' ) ) )
			{
				newSection = true;
			}
		}
		else
		{
			if ( util.isOperator( RPN.at( i ) ) )
			{
				newSection = true;
				section++;
				temp.clear();
				temp += RPN.at( i );
				RPNNotation::RPNStructure.push_back( temp );
				//if ( i + 1 != RPN.size() && RPN.at(i + 1) != ' ' )
				//{
					//newSection = false;
				//}
				continue;
			}
			temp += RPN.at( i );
			if ( RPNNotation::size() == 0 )
			{
				RPNNotation::RPNStructure.push_back( temp );
			}
			else
			{
				RPNNotation::RPNStructure[section] = temp;
			}
		}
	}
	return;
}

void RPNNotation::printStructure()
{
	for ( int i = 0; i < RPNNotation::size(); i++ )
	{
		std::cout << RPNNotation::RPNStructure.at( i ) << std::endl;
	}
}

int RPNNotation::size()
{
	return RPNNotation::RPNStructure.size();
}

bool RPNNotation::isInitilized()
{
	return ( ( RPNNotation::RPNStructure.size() > 0 ) ? true : false );
}

bool RPNNotation::isExpressionFloat()
{
	return ( ( RPNNotation::originalRPN.find(".") == std::string::npos ) ?
		false : true );
}

bool RPNNotation::isSingleFloat( int i )
{
	return ( ( RPNNotation::at( i ).find(".") == std::string::npos ) ?
		false : true );
}

std::string RPNNotation::at( int i )
{
	return RPNNotation::RPNStructure.at( i );
}
