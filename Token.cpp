/*
* Lab1 "Lexer" for CS236  (9.27.17)
* Istructor: Woodfield
* Code Writen by: Taylor Allred (taylor.allred21@gmail.com)
*
* Takes in file as argument and outputs tokens in lexicon.
*
*/
#include "Token.h"

Token::Token(const string & t, const string & d, int l)
{
	type = t;
	data = d;
	line_num = l;
}

Token::~Token()
{
}

string Token::formatString() const
{
	return "(" + type + ",\"" + data + "\"," + to_string(line_num) + ")";
}

string Token::getType() const
{
	return type;
}

string Token::getData() const
{
	return data;
}

int Token::getLineNum() const
{
	return line_num;
}
