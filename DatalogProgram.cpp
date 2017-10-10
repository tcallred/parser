#include "DatalogProgram.h"



DatalogProgram::DatalogProgram(Lexer* lex)
{
	theDom = new Domain();
	theSchemes = new Schemes(lex);
	theFacts = new Facts(lex, theDom);
	theRules = new Rules(lex);
	theQueries = new Queries(lex);
	lex->getNextToken("EOF");
}


DatalogProgram::~DatalogProgram()
{
	delete theSchemes, theFacts, theRules, theQueries;
}

void DatalogProgram::toString()
{
	theSchemes->toString();
	theFacts->toString();
	theRules->toString();
	theQueries->toString();
	theDom->toString();
}
