#include "Predicate.h"



Predicate::Predicate(Lexer* lex)
{
	predId = new Id(lex);
	lex->getNextToken("LEFT_PAREN");

	// Check parameter block
	if (lex->top()->getType() == "ID") {
		parameters.push_back(new Id(lex));
	}
	else if (lex->top()->getType() == "STRING") {
		parameters.push_back(new String(lex));
	}
	else if (lex->top()->getType() == "LEFT_PAREN") {
		parameters.push_back(new Expression(lex));
	}
	else {
		lex->getNextToken("ERROR");
	}

	while (lex->top()->getType() == "COMMA") {
		lex->pop();

		// Check parameter block
		if (lex->top()->getType() == "ID") {
			parameters.push_back(new Id(lex));
		}
		else if (lex->top()->getType() == "STRING") {
			parameters.push_back(new String(lex));
		}
		else if (lex->top()->getType() == "LEFT_PAREN") {
			parameters.push_back(new Expression(lex));
		}
		else {
			lex->getNextToken("ERROR");
		}
	}
	lex->getNextToken("RIGHT_PAREN");
}


Predicate::~Predicate()
{
	delete predId;
	for (unsigned int i = 0; i < parameters.size(); i++) {
		delete parameters[i];
	}
}

string Predicate::toString()
{
	string p = "";
	p += predId->toString() + "(";

	for (unsigned int i = 0; i < parameters.size(); i++) {
		p += parameters[i]->toString();
		if (i != parameters.size() - 1)p += ",";
	}
	p += ")";
	return p;
}
