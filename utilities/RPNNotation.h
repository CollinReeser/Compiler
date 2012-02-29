#include <string>
#include <vector>


class RPNNotation
{
public:
	void convertStrToRPN( std::string RPN );
	bool isInitilized();
	std::string at( int i );
	int size();
	void printStructure();
	// Checks if there is an occurance of a floating point value in the entire
	// expression
	bool isExpressionFloat();
	// Checks if there is a floating point value at the index provided
	bool isSingleFloat( int i );
	// See RPNCollapse.cpp - This function is used to simplify the expression
	// before assembly. This particular function operates on known-to-be
	// exclusively integer-based expressions
	friend void collapseRPNI( RPNNotation& RPN );
	
private:
	std::vector<std::string> RPNStructure;
	std::string originalRPN;
};
