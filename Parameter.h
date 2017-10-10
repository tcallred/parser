#pragma once
#include "Lexer.h"

class Parameter
{
public:
	Parameter();
	~Parameter();
	
	virtual string toString() = 0;
};

