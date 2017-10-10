#pragma once
#include "Lexer.h"
#include "Token.h"
#include "Parameter.h"
class String: public Parameter
{
public:
	String(Lexer* lex);
	~String();
	string toString();
private:
	Token* newstring;
};

