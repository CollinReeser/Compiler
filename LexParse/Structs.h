
#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>

struct include
{
	// The library or user stuff to include
	std::string fileName;
	// Whether it is a local or library thing
	bool isLocal; 
};

struct VarDec
{
	// The type of the variable
	std::string type;
	// The name of the variable
	std::string name;
};

#endif
