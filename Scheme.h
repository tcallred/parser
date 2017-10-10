#pragma once
#include "Lexer.h"
#include "Id.h"

class Scheme
{
public:
	Scheme(Lexer* lex);
	~Scheme();

	string toString();
private:
	Id* schemeId;
	vector<Id*> columnNames;
};

