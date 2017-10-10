#include "Expression.h"



Expression::Expression(Lexer* lex)
{
	lex->getNextToken("LEFT_PAREN");

	// Check param for LEFT SIDE
	if (lex->top()->getType() == "ID") {
		leftSide = new Id(lex);
	}
	else if (lex->top()->getType() == "STRING") {
		leftSide = new String(lex);
	}
	else if (lex->top()->getType() == "LEFT_PAREN") {
		leftSide = new Expression(lex);
	}
	else {
		lex->getNextToken("ERROR");
	}

	// Check OPERATION
	if (lex->top()->getType() == "ADD") {
		op = lex->getNextToken("ADD");
	}
	else if (lex->top()->getType() == "MULTIPLY") {
		op = lex->getNextToken("MULTIPLY");
	}
	else {
		lex->getNextToken("ERROR");
	}

	// Check param for RIGHT SIDE
	if (lex->top()->getType() == "ID") {
		rightSide = new Id(lex);
	}
	else if (lex->top()->getType() == "STRING") {
		rightSide = new String(lex);
	}
	else if (lex->top()->getType() == "LEFT_PAREN") {
		rightSide = new Expression(lex);
	}
	else {
		lex->getNextToken("ERROR");
	}
	lex->getNextToken("RIGHT_PAREN");
}


Expression::~Expression()
{
	delete leftSide, op, rightSide;
}

string Expression::toString()
{
	return "(" + leftSide->toString() + op->getData() + rightSide->toString() + ")" ;
}
