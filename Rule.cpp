#include "Rule.h"



Rule::Rule(Lexer* lex)
{
	// Head predicate
	hp = new HeadPredicate(lex);

	// The colon dash
	lex->getNextToken("COLON_DASH");
	
	// Add the first predicate
	predicates.push_back(new Predicate(lex));

	// And the rest
	while (lex->top()->getType() == "COMMA") {
		lex->pop();
		predicates.push_back(new Predicate(lex));
	}
	// End of predicates 
	lex->getNextToken("PERIOD");
}


Rule::~Rule()
{
	delete hp;
	for (unsigned int i = 0; i < predicates.size(); i++) {
		delete predicates[i];
	}
}

string Rule::toString()
{
	string rule = "";
	rule += hp->toString() + " :- ";
	for (unsigned int i = 0; i < predicates.size(); i++) {
		rule += predicates[i]->toString();
		if (i != predicates.size() - 1)rule += ",";
	}
	rule += ".";
	return rule;
}
