

#include <string>
#include <vector>
#include "ParseContainer.h"

ParseContainer::ParseContainer( std::vector<std::string> tokens )
{
	ParseContainer::tokens = tokens;
	ParseContainer::curTok = tokens.begin();
}

std::string ParseContainer::nextToken()
{
	return *(++ParseContainer::curTok);
}
std::string ParseContainer::peekNext()
{
	std::string temp = *(++ParseContainer::curTok);
	ParseContainer::curTok--;
	return temp;
}
std::string ParseContainer::previousToken()
{
	return *(ParseContainer::curTok--);
}
std::string ParseContainer::peekPrevious()
{
	std::string temp = *(--ParseContainer::curTok);
	ParseContainer::curTok++;
	return temp;
}
int ParseContainer::size()
{
	return ParseContainer::tokens.size();
}
bool ParseContainer::atEnd()
{
	return ( ParseContainer::curTok == ParseContainer::tokens.end() );
}
