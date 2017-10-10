#include "String.h"



String::String(Lexer* lex)
{
	newstring = lex->getNextToken("STRING");
}


String::~String()
{
	delete newstring;
}

string String::toString()
{
	return newstring->getData();
}
