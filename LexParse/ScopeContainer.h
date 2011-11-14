// This class acts as the superclass to a series of subclasses, each 
// representing possible programming scopes, such as if blocks and for blocks


#ifndef SCOPE_CONTAINER_H
#define SCOPE_CONTAINER_H

#include "ParseContainer.h"

class ScopeContainer
{
public:
	virtual ParseContainer parse(ParseContainer parsing) = 0;
private:
};

#endif
