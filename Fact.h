#pragma once
#include "Lexer.h"
#include "Id.h"
#include "String.h"
#include "Domain.h"
class Fact
{
public:
	Fact(Lexer* lex, Domain* dom);
	~Fact();

	string toString();
private:
	vector<String*> columnNames;
	Id* factId;
};

