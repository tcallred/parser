/*
* Lab1 "Lexer" for CS236  (9.27.17)
* Istructor: Woodfield
* Code Writen by: Taylor Allred (taylor.allred21@gmail.com)
*
* Takes in file as argument and outputs tokens in lexicon.
*
*/

#include "Charstream.h"



Charstream::Charstream()
{
}

Charstream::Charstream(ifstream& fs)
{
	// Copy file to vector
	std::vector<char> fileContents((std::istreambuf_iterator<char>(fs)),
		std::istreambuf_iterator<char>());
	lines = fileContents;
	// Init pos and line num
	position = 0;
	line_num = 1;
}


Charstream::~Charstream()
{
}

char Charstream::peek(unsigned int i) const
{
	return lines[position + i];
}

char Charstream::getCharAtPos() const
{
	return lines[position];
}

void Charstream::advancePosition(unsigned int i)
{
	position += i;
}

void Charstream::toNextLine()
{
	line_num++;
}

string Charstream::getString(unsigned int count)
{
	if (position + count >= lines.size()) {
		return "";
	}
	else {
		string str(lines.begin() + position, lines.begin() + position + count);
		return str;
	}
	
}

string Charstream::getStringEnd()
{
	string str(lines.begin() + position, lines.end());
	return str;
}

int Charstream::getLineNumber() const
{
	return line_num;
}

int Charstream::getPosition() const
{
	return position;
}

int Charstream::getVecSize() const
{
	return lines.size();
}

bool Charstream::isEmpty() const
{
	return position >= lines.size();
}

bool Charstream::isTooFar(int offset) const
{
	return position + offset >= lines.size();
}
