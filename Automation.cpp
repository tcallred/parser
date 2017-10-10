/*
* Lab1 "Lexer" for CS236  (9.27.17)
* Istructor: Woodfield
* Code Writen by: Taylor Allred (taylor.allred21@gmail.com)
*
* Takes in file as argument and outputs tokens in lexicon.
*
*/
#include "Automation.h"

Automation::Automation(string fn)
{
	ifstream in;
	in.open(fn);
	cs = new Charstream(in);
	in.close();
}


Automation::~Automation()
{
	delete cs;
	for (unsigned int i = 0; i < tokenList.size(); i++) {
		delete tokenList.at(i);
	}
}

void Automation::makeTokenList()
{
	char currChar;
	while (!cs->isEmpty()) {
		// Get the current char
		currChar = cs->getCharAtPos();
		Token* newToken;
		// Determine if it's an easy token or not
		switch (currChar) {
		case ',':
			newToken = new Token("COMMA", ",", cs->getLineNumber());
			tokenList.push_back(newToken);
			cs->advancePosition(1);
			break;
		case '.':
			newToken = new Token("PERIOD", ".", cs->getLineNumber());
			tokenList.push_back(newToken);
			cs->advancePosition(1);
			break;
		case '?':
			newToken = new Token("Q_MARK", "?", cs->getLineNumber());
			tokenList.push_back(newToken);
			cs->advancePosition(1);
			break;
		case '(':
			newToken = new Token("LEFT_PAREN", "(", cs->getLineNumber());
			tokenList.push_back(newToken);
			cs->advancePosition(1);
			break;
		case ')':
			newToken = new Token("RIGHT_PAREN", ")", cs->getLineNumber());
			tokenList.push_back(newToken);
			cs->advancePosition(1);
			break;
		case ':':
			if (cs->peek(1) == '-') {
				newToken = new Token("COLON_DASH", ":-", cs->getLineNumber());
				tokenList.push_back(newToken);	
				cs->advancePosition(2);
			}
			else {
				newToken = new Token("COLON", ":", cs->getLineNumber());
				tokenList.push_back(newToken);
				cs->advancePosition(1);
			}
			break;
		case '*':
			newToken = new Token("MULTIPLY", "*", cs->getLineNumber());
			tokenList.push_back(newToken);
			cs->advancePosition(1);
			break;
		case '+':
			newToken = new Token("ADD", "+", cs->getLineNumber());
			tokenList.push_back(newToken);
			cs->advancePosition(1);
			break;
		case '\n':
			cs->toNextLine();
			cs->advancePosition(1);
			break;
		case '\'':
			makeString();
			break;
		case '#':
			makeComment();
			break;
		case ' ':
			cs->advancePosition(1);
			break;
		case '\t':
			cs->advancePosition(1);
			break;
		default:
			checkOtherToken();
		}	
	}
	// Create eof token
	Token* eofToken = new Token("EOF", "", cs->getLineNumber());
	tokenList.push_back(eofToken);
}

void Automation::printTokenList()
{
	for (unsigned int i = 0; i < tokenList.size(); i++) {
		cout << tokenList.at(i)->formatString() << endl;
	}
	cout << "Total Tokens = " << tokenList.size();
}

vector<Token*> Automation::getTokenList()
{
	return tokenList;
}

void Automation::makeString()
{
	int stringEndOffset = 1;
	int newLineCount = 0;
	bool invalid = false;
	bool doubleTooFar = false;
	while ((cs->peek(stringEndOffset) != '\'') ||
		((cs->peek(stringEndOffset + 1) == '\'') && (cs->peek(stringEndOffset) == '\''))) {
		if (cs->peek(stringEndOffset) == '\n') newLineCount++;
		
		if ((cs->peek(stringEndOffset + 1) == '\'') && (cs->peek(stringEndOffset) == '\'')) {
			stringEndOffset += 2;
			if (cs->isTooFar(stringEndOffset)) {
				invalid = true;
				doubleTooFar = true;
				break;
			}
		}
		else {
			stringEndOffset++;
		}
		if (cs->getPosition() + stringEndOffset + 1 >= cs->getVecSize()) {
			if (cs->peek(stringEndOffset) == '\n') {
				newLineCount++;
			}
			invalid = true;
			break;
		}
		
	}
	if (invalid) {
		if (doubleTooFar) {
			// Create invalid token
			Token* invalidToken = new Token("UNDEFINED", cs->getStringEnd(), cs->getLineNumber());
			tokenList.push_back(invalidToken);
		}
		else {
			if (cs->peek(stringEndOffset) == '\'') {
				// Not invalid
				Token* newToken = new Token("STRING", cs->getStringEnd(), cs->getLineNumber());
				tokenList.push_back(newToken);
			}
			else {
				// Create invalid token
				Token* invalidToken = new Token("UNDEFINED", cs->getStringEnd(), cs->getLineNumber());
				tokenList.push_back(invalidToken);
			}

		}
		
		
	}
	else {
		Token* newToken = new Token("STRING", cs->getString(stringEndOffset + 1), cs->getLineNumber());
		tokenList.push_back(newToken);
	}
	
	for (int i = 0; i < newLineCount; i++) cs->toNextLine();
	// Then change the position of charstream
	cs->advancePosition(stringEndOffset + 1);
}

void Automation::makeComment()
{
	int commentEndOffset = 1;
	if (cs->peek(1) == '|') {
		// Then we have a multiline comment
		// Increase offset by one
		commentEndOffset++;
		// Init new line count
		int newLineCount = 0;
		bool invalid = false;
		// Go until you reach |# or EOF
		while (!(cs->peek(commentEndOffset) == '|' && cs->peek(commentEndOffset + 1) == '#')) {
			if (cs->peek(commentEndOffset) == '\n') newLineCount++;
			commentEndOffset++;
			if (cs->getPosition() + commentEndOffset + 1 >= cs->getVecSize()) {
				invalid = true;
				break;
			}
		}
		
		if (invalid) {
			if (cs->peek(commentEndOffset - 1) == '|' && cs->peek(commentEndOffset) == '#') {
				// Not invalid
				// Make comment token
				Token* newToken = new Token("COMMENT", cs->getStringEnd(), cs->getLineNumber());
				tokenList.push_back(newToken);
			}

			// Create invalid token
			Token* invalidToken = new Token("UNDEFINED", cs->getStringEnd(), cs->getLineNumber());
			tokenList.push_back(invalidToken);
		}
		else {
			// If one more is too far make end string 
			if (cs->isTooFar(commentEndOffset + 2)) {
				// Make comment token
				Token* newToken = new Token("COMMENT", cs->getStringEnd(), cs->getLineNumber());
				tokenList.push_back(newToken);
			}
			else {
				// Make comment token
				Token* newToken = new Token("COMMENT", cs->getString(commentEndOffset + 2), cs->getLineNumber());
				tokenList.push_back(newToken);
			}
			
		}
		
		// Update new lines
		for (int i = 0; i < newLineCount; i++) cs->toNextLine();
		// Increase position past the |#
		cs->advancePosition(commentEndOffset + 2);
	}
	else {
		//Just a single line comment
		while (cs->peek(commentEndOffset) != '\n' && !cs->isTooFar(commentEndOffset + 1)) {
			commentEndOffset++;
		}
		if (cs->isTooFar(commentEndOffset + 1) && cs->peek(commentEndOffset) != '\n') {
			// End of file
			Token* newToken = new Token("COMMENT", cs->getStringEnd(), cs->getLineNumber());
			tokenList.push_back(newToken);
		}
		else {
			// Just a new line
			Token* newToken = new Token("COMMENT", cs->getString(commentEndOffset), cs->getLineNumber());
			tokenList.push_back(newToken);
			// Increase line
			cs->toNextLine();
		}
		
		// And increase position
		cs->advancePosition(commentEndOffset + 1);
	}
}

void Automation::checkOtherToken()
{
	// Keywords
	const string SCHEMES = "Schemes";
	const string FACTS = "Facts";
	const string RULES = "Rules";
	const string QUERIES = "Queries";

	Token* newToken;
	// Check if it's a keyword
	if (cs->getString(SCHEMES.length()) == SCHEMES && !isalpha(cs->peek(SCHEMES.length())) && !isdigit(cs->peek(SCHEMES.length()))) {
		// It's a scheme keyword
		newToken = new Token("SCHEMES", SCHEMES, cs->getLineNumber());
		tokenList.push_back(newToken);
		cs->advancePosition(SCHEMES.length());
	}
	else if (cs->getString(FACTS.length()) == FACTS && !isalpha(cs->peek(FACTS.length())) && !isdigit(cs->peek(FACTS.length()))) {
		// Facts
		newToken = new Token("FACTS", FACTS, cs->getLineNumber());
		tokenList.push_back(newToken);
		cs->advancePosition(FACTS.length());
	}
	else if (cs->getString(RULES.length()) == RULES && !isalpha(cs->peek(RULES.length())) && !isdigit(cs->peek(RULES.length()))) {
		// Rules
		newToken = new Token("RULES", RULES, cs->getLineNumber());
		tokenList.push_back(newToken);
		cs->advancePosition(RULES.length());
	}
	else if (cs->getString(QUERIES.length()) == QUERIES && !isalpha(cs->peek(QUERIES.length())) && !isdigit(cs->peek(QUERIES.length()))) {
		// Queries
		newToken = new Token("QUERIES", QUERIES, cs->getLineNumber());
		tokenList.push_back(newToken);
		cs->advancePosition(QUERIES.length());
	}
	else {
		// ID or invalid
		if (isalpha(cs->getCharAtPos())) {
			int idOffset = 1;
			while (isalpha(cs->peek(idOffset)) || isdigit(cs->peek(idOffset))) {
				idOffset++;
			}
			newToken = new Token("ID", cs->getString(idOffset), cs->getLineNumber());
			tokenList.push_back(newToken);
			cs->advancePosition(idOffset);
		}
		else {
			newToken = new Token("UNDEFINED", cs->getString(1), cs->getLineNumber());
			tokenList.push_back(newToken);
			cs->advancePosition(1);
		}
	}
}
