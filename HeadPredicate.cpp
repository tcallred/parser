#include "HeadPredicate.h"



HeadPredicate::HeadPredicate(Lexer* lex)
{
	hpId = new Id(lex);
	lex->getNextToken("LEFT_PAREN");
	hpColumns.push_back(new Id(lex));
	while (lex->top()->getType() == "COMMA") {
		lex->pop();
		hpColumns.push_back(new Id(lex));
	}
	lex->getNextToken("RIGHT_PAREN");
}


HeadPredicate::~HeadPredicate()
{
	delete hpId;
	for (unsigned int i = 0; i < hpColumns.size(); i++) {
		delete hpColumns[i];
	}
}

string HeadPredicate::toString()
{
	string hp = "";
	hp += hpId->toString() + "(";

	for (unsigned int i = 0; i < hpColumns.size(); i++) {
		hp += hpColumns[i]->toString();
		if (i != hpColumns.size() - 1)hp += ",";
	}
	hp += ")";
	return hp;
}
