#include "Fact.h"



Fact::Fact(Lexer* lex, Domain* dom)
{
	factId = new Id(lex);
	lex->getNextToken("LEFT_PAREN");
	columnNames.push_back(new String(lex));
	while (lex->top()->getType() == "COMMA") {
		lex->pop();
		columnNames.push_back(new String(lex));
	}
	lex->getNextToken("RIGHT_PAREN");
	lex->getNextToken("PERIOD");
	dom->addVec(columnNames);
}


Fact::~Fact()
{
	delete factId;
	for (unsigned int i = 0; i < columnNames.size(); i++) {
		delete columnNames[i];
	}
}

string Fact::toString()
{
	string fact = "";
	fact += factId->toString() + "(";
	for (unsigned int i = 0; i < columnNames.size(); i++) {
		fact += columnNames[i]->toString();
		if (i != columnNames.size() - 1)fact += ",";
	}
	fact += ")";
	return fact;
}
