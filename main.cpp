#include <iostream>
#include <string>
#include "Token.h"
#include "Automation.h"
#include "Lexer.h"
#include "Charstream.h"
#include "DatalogProgram.h"



using namespace std;

int main(int argc, char* argv[]) {

	/*vector<string> files = { "text1.txt", "text2.txt", "text3.txt",
		"text4.txt", "text5.txt", "text6.txt", "text7.txt",
		"text8.txt", "text9.txt", "text10.txt"};*/
	//for (unsigned int i = 0; i < files.size(); i++) {
		try {
			Lexer* lex = new Lexer(argv[1]);
			DatalogProgram* dlp = new DatalogProgram(lex);
			cout << "Success!" << endl;
			dlp->toString();
			delete lex, dlp;
		}
		catch (Token* token) {
			cout << "Failure!" << endl;
			cout << token->formatString() << endl;
		}
	//}
	

	return 0;
}