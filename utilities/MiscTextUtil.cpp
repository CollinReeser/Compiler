
#include "SimpleTextUtil.h"

bool SimpleTextUtil::isOperatorT( char operatorCandidate )
{
	switch ( operatorCandidate )
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '=':
		case '(':
		case ')':
		case '<':
		case '>':
		case ';':
		case '"':
		case '%':
		case '&':
		case '\'':
		case '.':
		case '[':
		case ']':
		case '{':
		case '}':
		case '|':
		case '^':
		case '~':
			return true;
		default:
			return false;
	}
}
