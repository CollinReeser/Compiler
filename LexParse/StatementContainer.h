

#ifndef STATEMENT_CONTAINER_H
#define STATEMENT_CONTAINER_H

#include <vector>
#include <string>

class StatementContainer
{
public:
private:
	// These are the raw tokens that make up the statement, including the
	// terminating semicolon
	std::vector<std::string> rawStatement;
};

#endif
