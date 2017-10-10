#include "Query.h"



Query::Query(Lexer* lex)
{
	predicate = new Predicate(lex);
	lex->getNextToken("Q_MARK");
}


Query::~Query()
{
	delete predicate;
}

string Query::toString()
{
	return predicate->toString() + "?";
}
