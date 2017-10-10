#pragma once
#include "Lexer.h"
#include "Token.h"
#include "Parameter.h"

class Id: public Parameter
{
public:
	Id(Lexer* lex);
	~Id();
	string toString();
private:
	Token* id;
};

