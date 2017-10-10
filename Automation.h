/*
* Lab1 "Lexer" for CS236  (9.27.17)
* Istructor: Woodfield
* Code Writen by: Taylor Allred (taylor.allred21@gmail.com)
*
* Takes in file as argument and outputs tokens in lexicon.
*
*/
#pragma once
#include "Charstream.h"
#include "Token.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Automation
{
public:
	Automation(string fn);
	~Automation();

	void makeTokenList();
	void printTokenList();
	vector<Token*> getTokenList();

private:
	void makeString();
	void makeComment();
	void checkOtherToken();

	Charstream* cs;
	vector<Token*> tokenList;
};

