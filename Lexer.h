/*
* Lab1 "Lexer" for CS236  (9.27.17)
* Istructor: Woodfield
* Code Writen by: Taylor Allred (taylor.allred21@gmail.com)
*
* Takes in file as argument and outputs tokens in lexicon.
*
*/
#pragma once
#include <string>
#include <fstream>
#include "Charstream.h"
#include "Automation.h"
using namespace std;
class Lexer
{
public:
	Lexer(string fn);
	~Lexer();

	void analyze();
	Token* getNextToken(string tokenType);
	Token* peekToken();
	Token* top();
	void pop();
private:
	void destroyComments();
	Automation* automata;
	vector<Token*> tokens;
	unsigned int currToken;
};

