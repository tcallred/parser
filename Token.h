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

using namespace std;
class Token
{
public:
	Token(const string& t, const string& d, int l);
	~Token();

	string formatString() const;
	string getType() const;
	string getData() const;
	int getLineNum() const;

private:
	string type;
	string data;
	int line_num;
};

