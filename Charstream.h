/*
* Lab1 "Lexer" for CS236  (9.27.17)
* Istructor: Woodfield
* Code Writen by: Taylor Allred (taylor.allred21@gmail.com)
*
* Takes in file as argument and outputs tokens in lexicon.
*
*/
#pragma once
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <sstream>
using namespace std;
class Charstream
{
public:
	Charstream();
	Charstream(ifstream& fs);
	~Charstream();

	/*
	* Peeks at the char in the next position
	*/
	char peek(unsigned int i) const;

	char getCharAtPos() const;

	void advancePosition(unsigned int i);

	void toNextLine();

	string getString(unsigned int count);

	string getStringEnd();

	int getLineNumber() const;

	int getPosition() const;

	int getVecSize() const;

	bool isEmpty() const;

	bool isTooFar(int offset) const;

private:
	vector<char> lines;
	unsigned int position;
	unsigned int line_num;
};

