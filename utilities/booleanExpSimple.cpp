#include "booleanExpSimple.h"
#include "SimpleTextUtil.h"
#include <string>


void BoolExpSimple::convertSimpleBoolExp( std::string boolExp )
{
	SimpleTextUtil util;
	for ( int i = 0; i < boolExp.size(); i++ )
	{
		if ( isBoolOperator( boolExp.substr( i , 2 ) ) ||
			isBoolOperator( boolExp.substr( i , 1 ) )  )
		{
			BoolExpSimple::left.convertStrToRPN( util.convertInfixToPostfix( 
				boolExp.substr( 0 , i - 1 ) ) );
			BoolExpSimple::right.convertStrToRPN( util.convertInfixToPostfix(
				boolExp.substr( i + 2 ) );
			BoolExpSimple::operation = boolExp.substr( i , 2 );
			break;
		}
	}
}

bool isBoolOperator( std::string operatorCandidate )
{
	if ( operatorCandidate.compare( "==" ) == 0 )
	{
		return true;
	}
	if ( operatorCandidate.compare( "!=" ) == 0 )
	{
		return true;
	}
	if ( operatorCandidate.compare( "<" ) == 0 )
	{
		return true;
	}
	if ( operatorCandidate.compare( "<=" ) == 0 )
	{
		return true;
	}
	if ( operatorCandidate.compare( ">" ) == 0 )
	{
		return true;
	}
	if ( operatorCandidate.compare( ">=" ) == 0 )
	{
		return true;
	}
	return false;
}
