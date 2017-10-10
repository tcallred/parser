#pragma once
#include "Lexer.h"
#include "Parameter.h"
#include "Id.h"
#include "Token.h"
#include "String.h"

class Expression : public Parameter
{
public:
	Expression(Lexer* lex);
	~Expression();
	string toString();
private:
	Parameter* leftSide;
	Parameter* rightSide;
	Token* op;
};

