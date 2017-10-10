#include "Facts.h"



Facts::Facts(Lexer* lex, Domain* dom)
{
	lex->getNextToken("FACTS");
	lex->getNextToken("COLON");
	do {
		facts.push_back(new Fact(lex, dom));
	} while (lex->top()->getType() == "ID");
}


Facts::~Facts()
{
	for (unsigned int i = 0; i < facts.size(); i++) {
		delete facts[i];
	}
}

void Facts::toString()
{
	cout << "Facts(" << facts.size() << "):" << endl;
	for (unsigned int i = 0; i < facts.size(); i++) {
		cout << "\t" << facts[i]->toString() << "." << endl;
	}

}
