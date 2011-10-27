
#include <string>
#include <vector>
#include "lexer.h"
#include "../utilities/SimpleTextUtil.h"


std::vector<std::string> Lexer::tokenizeFile( std::string fileName )
	throw (std::string)
{
	SimpleTextUtil util;
	// Raw lines from a file
	std::vector<std::string> lines;
	// Tokens of lines
	std::vector<std::string> tokens;
	try
	{
		// Pull the lines from the file
		lines = util.fileToLines( fileName );
	}
	catch ( std::string message )
	{
		throw message;
	}
	// Strip comments from the resultant lines
	util.stripMultiComments(lines);
	util.stripLineComments(lines);
	std::string temp;
	// Tokenize the business
	// Loop over lines
	for ( int i = 0; i < lines.size(); i++ )
	{
		// Loop over characters of line
		for ( int j = 0; j < lines.at(i).size(); j++ )
		{
			if ( lines.at(i).at(j) == ' ' && temp.size() == 0 )
			{
				// Skip spaces when we aren't yet building a token
				continue;
			}
			// Space delimited
			if ( lines.at(i).at(j) == ' ' && temp.size() != 0 )
			{
				// Push the token received. Must be a token because space-
				// delimited
				tokens.push_back( temp );
				temp.clear();
				continue;
			}
			// Operator delimited
			if ( util.isOperatorT( lines.at(i).at(j) ) )
			{
				if ( temp.size() == 0 )
				{
					std::string str;
					str += (lines.at(i).at(j));
					tokens.push_back( str );
				}
				else
				{
					tokens.push_back( temp );
					std::string str;
					str += (lines.at(i).at(j));
					tokens.push_back( str );
					temp.clear();
				}
				continue;
			}
			else
			{
				// Start building the token then
				temp += lines.at(i).at(j);
			}
		}
	}
	// If the token was not flushed at loop-exit, flush
	if ( temp.size() != 0 )
	{
		tokens.push_back( temp );
		temp.clear();
	}
	// Fix certain tokenizing errors, like two '<'s next to eachother not being
	// tokenized as "<<". Basically do some compaction or expansion as needed
	tokens = Lexer::internalTokenizeFix( tokens );
	// Return tokenized result
	return tokens;
}


std::vector<std::string> Lexer::internalTokenizeFix( 
	std::vector<std::string> tokens )
{
	// Proceed to do this in a terribly inefficient way:
	
	// Fix bitshifts
	for ( int i = 0; i < tokens.size(); i++ )
	{
		
	}
	return tokens;
}


