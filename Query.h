#pragma once
#include "Lexer.h"
#include "Predicate.h"
class Query
{
public:
	Query(Lexer* lex);
	~Query();
	string toString();
private:
	Predicate* predicate;
};

