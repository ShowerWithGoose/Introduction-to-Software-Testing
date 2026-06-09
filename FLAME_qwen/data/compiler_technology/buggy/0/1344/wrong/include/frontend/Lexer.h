#include "Token.h"
#include <list>
#include <cstring>
#include <fstream>

using namespace std;

class Lexer {
private:
	list<string> token_lists;
	string cur_token;
	string cur_line;
	ifstream &input;
	ofstream &output_for_lexer;
	ofstream &output_error;
	int line_num, index;
	Token_Type cur_type;
	bool annotation = false;
	
private:
	void getNum();
	void getWord();
	void getStr();
	void getChar();
	void getSym();

	void printOut();
	void printOut_for_error();

	void parseLine();
	void skip_comment();

public:
	Lexer(ifstream &input, ofstream &output_for_lexer, ofstream &output_error);
	void work();
	void next();
};