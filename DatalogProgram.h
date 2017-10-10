#pragma once
#include "Lexer.h"
#include "Schemes.h"
#include "Facts.h"
#include "Rules.h"
#include "Queries.h"
#include "Domain.h"

class DatalogProgram
{
public:
	DatalogProgram(Lexer* lex);
	~DatalogProgram();

	void toString();
private:
	Domain* theDom;
	Schemes* theSchemes;
	Facts* theFacts;
	Rules* theRules;
	Queries* theQueries;
};

