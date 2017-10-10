#include "Scheme.h"



Scheme::Scheme(Lexer* lex)
{
	schemeId = new Id(lex);
	lex->getNextToken("LEFT_PAREN");
	columnNames.push_back(new Id(lex));
	while (lex->top()->getType() == "COMMA") {
		lex->pop();
		columnNames.push_back(new Id(lex));
	}
	lex->getNextToken("RIGHT_PAREN");
}


Scheme::~Scheme()
{
	delete schemeId;
	for (unsigned int i = 0; i < columnNames.size(); i++) {
		delete columnNames[i];
	}
}

string Scheme::toString()
{
	string wholeScheme = "";
	wholeScheme += schemeId->toString() + "(";

	for (unsigned int i = 0; i < columnNames.size(); i++) {
		wholeScheme += columnNames[i]->toString();
		if (i != columnNames.size() - 1)wholeScheme += ",";
	}
	wholeScheme += ")";
	return wholeScheme;
}
