#pragma once
#include "Lexer.h"
#include "Query.h"
class Queries
{
public:
	Queries(Lexer* lex);
	~Queries();

	void toString();
private:
	vector<Query*> queries;
};

