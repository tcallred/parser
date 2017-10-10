#pragma once
#include "Lexer.h"
#include "Fact.h"
#include "Domain.h"
class Facts
{
public:
	Facts(Lexer* lex, Domain* dom);
	~Facts();

	void toString();
private:
	vector<Fact*> facts;
};

