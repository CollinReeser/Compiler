#ifndef PARSE_CONTAINER_H
#define PARSE_CONTAINER_H

#include <vector>
#include <string>

class ParseContainer
{
public:
	ParseContainer(std::vector<std::string> tokens);
	std::string nextToken();
	std::string peekNext();
	std::string previousToken();
	std::string peekPrevious();
private:
	std::vector<std::string> tokens;
	std::vector<std::string>::iterator curTok;
};

#endif
