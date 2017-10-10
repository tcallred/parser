#pragma once
#include "Lexer.h"
#include "Rule.h"
#include "Expression.h"
#include "Parameter.h"
class Rules
{
public:
	Rules(Lexer* lex);
	~Rules();

	void toString();
private:
	vector<Rule*> rules;
};

