#include "Id.h"



Id::Id(Lexer* lex)
{
	id = lex->getNextToken("ID");
}


Id::~Id()
{
	delete id;
}

string Id::toString()
{
	return id->getData();
}
