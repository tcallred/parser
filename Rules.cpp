#include "Rules.h"



Rules::Rules(Lexer* lex)
{
	lex->getNextToken("RULES");
	lex->getNextToken("COLON");
	do {
		rules.push_back(new Rule(lex));
	} while (lex->top()->getType() == "ID");
}


Rules::~Rules()
{
	for (unsigned int i = 0; i < rules.size(); i++) {
		delete rules[i];
	}
}

void Rules::toString()
{
	cout << "Rules(" << rules.size() << "):" << endl;
	for (unsigned int i = 0; i < rules.size(); i++) {
		cout << "\t" << rules[i]->toString() << endl;
	}
}
