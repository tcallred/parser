#include "Queries.h"



Queries::Queries(Lexer* lex)
{
	lex->getNextToken("QUERIES");
	lex->getNextToken("COLON");
	do {
		queries.push_back(new Query(lex));
	} while (lex->top()->getType() == "ID");

}


Queries::~Queries()
{
	for (unsigned int i = 0; i < queries.size(); i++) {
		delete queries[i];
	}
}

void Queries::toString()
{
	cout << "Queries(" << queries.size() << "):" << endl;
	for (unsigned int i = 0; i < queries.size(); i++) {
		cout << "\t" << queries[i]->toString() << endl;
	}
}
