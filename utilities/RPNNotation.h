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
	bool isFloat();
	
private:
	std::vector<std::string> RPNStructure;
	std::string originalRPN;
};
