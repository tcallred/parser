#pragma once
#include "Lexer.h"
#include "Id.h"
#include "Predicate.h"
#include "HeadPredicate.h"
class Rule
{
public:
	Rule(Lexer* lex);
	~Rule();
	string toString();
private:
	HeadPredicate* hp;
	vector<Predicate*> predicates;
};

