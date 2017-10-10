#pragma once
#include "Lexer.h"
#include "Parameter.h"
#include "Id.h"
#include "String.h"
#include "Expression.h"

class Predicate
{
public:
	Predicate(Lexer* lex);
	~Predicate();

	string toString();

private:
	Id* predId;
	vector<Parameter*> parameters;
};

