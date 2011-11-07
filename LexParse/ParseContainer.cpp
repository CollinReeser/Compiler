

#include <string>
#include <vector>
#include "ParseContainer.h"

ParseContainer::ParseContainer( std::vector<std::string> tokens )
{
	ParseContainer::tokens = tokens;
	ParseContainer::curTok = tokens.begin();
}

std::string nextToken()
{
	return (++ParseContainer::curToken)*;
}
std::string peekNext()
{
	std::string temp = (++ParseContainer::curToken)*;
	ParseContainer::curToken--;
	return temp;
}
std::string previousToken()
{
	return (ParseContainer::curToken--)*;
}
std::string peekPrevious()
{
	std::string temp = (--ParseContainer::curToken)*;
	ParseContainer::curToken++;
	return temp;
}
