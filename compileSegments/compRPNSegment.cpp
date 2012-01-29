// DEPRECTAED. All code in this file should not be expected to work toward any
// purpose whatsoever, and should therefore not be used under any circumstances.


#include "../utilities/SimpleTextUtil.h"
#include "../utilities/RPNNotation.h"
#include <string>
#include <stack>
#include <vector>

std::string compRPNSegment( RPNNotation RPN )
{
	SimpleTextUtil util;
	bool firstSection = true;
	std::stack<std::string> operands;
	std::vector<std::string> block;
	std::string instruction;
	instruction = "mov eax , 0";
	block.push_back( instruction );
	instruction.clear();
	for ( int i = 0; i < RPN.size(); i++ )
	{
		if ( util.isOperator( RPN.at( i ) ) )
		{
			if ( firstSection && operands.size() >= 2 )
			{
				instruction += "lea eax , [";
				instruction += operands.top();
				operands.pop();
				instruction += RPN.at( i );
				instruction += operands.top();
				operands.pop();
				instruction += "]";
				block.push_back( instruction );
				instruction.clear();
				firstSection = false;
			}
			else if ( !firstSection && operands.size() >= 2 )
			{
				instruction += "lea ebx , [";
				instruction += operands.top();
				operands.pop();
				instruction += RPN.at( i );
				instruction += operands.top();
				operands.pop();
				instruction += "]";
				block.push_back( instruction );
				instruction.clear();
				instruction += "add eax , ebx";
				block.push_back( instruction );
				instruction.clear();
			}
			else if ( !firstSection )
			{
				instruction += "lea eax , [";
				instruction += operands.top();
				operands.pop();
				instruction += RPN.at( i );
				instruction += operands.top();
				operands.pop();
				instruction += "]";
				block.push_back( instruction );
				instruction.clear();
			}
		}
	}
	return instruction;
}
