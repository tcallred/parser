#pragma once
#include "Lexer.h"
#include "Id.h"
class HeadPredicate
{
public:
	HeadPredicate(Lexer* lex);
	~HeadPredicate();

	string toString();
private:
	Id* hpId;
	vector<Id*> hpColumns;
};

