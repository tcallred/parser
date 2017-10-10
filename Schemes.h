#pragma once
#include "Lexer.h"
#include "Scheme.h"

class Schemes
{
public:
	Schemes(Lexer* lex);
	~Schemes();

	void toString();

private:
	vector<Scheme*> schemes;
};

