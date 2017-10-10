#include "Schemes.h"


Schemes::Schemes(Lexer * lex)
{
	lex->getNextToken("SCHEMES");
	lex->getNextToken("COLON");
	do {
		schemes.push_back(new Scheme(lex));
	} while (lex->top()->getType() == "ID");
}

Schemes::~Schemes()
{
	for (unsigned int i = 0; i < schemes.size(); i++) {
		delete schemes[i];
	}
}

void Schemes::toString()
{
	cout << "Schemes(" << schemes.size() << "):" << endl;
	for (unsigned int i = 0; i < schemes.size(); i++) {
		cout << "\t" << schemes[i]->toString() << endl;
	}
}
