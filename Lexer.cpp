/*
* Lab1 "Lexer" for CS236  (9.27.17)
* Istructor: Woodfield
* Code Writen by: Taylor Allred (taylor.allred21@gmail.com)
*
* Takes in file as argument and outputs tokens in lexicon.
*
*/
#include "Lexer.h"



Lexer::Lexer(string fn)
{
	automata = new Automation(fn);
	analyze();
}


Lexer::~Lexer()
{
	delete automata;
}

void Lexer::analyze()
{
	automata->makeTokenList();
	tokens = automata->getTokenList();
	currToken = 0;
	destroyComments();
	//automata->printTokenList();
}

Token * Lexer::getNextToken(string tokenType)
{

	Token* result = tokens[currToken];
	string resultType = result->getType();
	if ((resultType == "EOF" && tokenType != "EOF") || resultType != tokenType) {
		throw result;
	}
	currToken++;
	return result;
}

Token * Lexer::peekToken()
{
	return tokens[currToken+1];
}

Token * Lexer::top()
{

	return tokens[currToken];
}

void Lexer::pop()
{
	currToken++;
}

void Lexer::destroyComments()
{
	vector<int> markedForDeath;
	for (unsigned int i = 0; i < tokens.size(); i++) {
		if (tokens[i]->getType() == "COMMENT") {
			markedForDeath.push_back(i);
		}
	}
	for (int i = markedForDeath.size() - 1; i >= 0; i--) {
		tokens.erase(tokens.begin() + markedForDeath[i]);
	}
}
