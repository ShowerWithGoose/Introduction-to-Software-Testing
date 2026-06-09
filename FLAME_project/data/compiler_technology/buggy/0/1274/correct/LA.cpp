#include "LA.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string Lexer::source;
int Lexer::curPos;
string Lexer::token;
Type Lexer::lexType;
vector<Token> Lexer::tokens;
int Lexer::lineNum;
int Lexer::number;

std::ofstream lexerout;
std::ofstream errorout;
std::ifstream inputFile;

bool isLetter(char c) {
	if (c >= 'a' && c <= 'z') {
		return true;
	}
	else if (c >= 'A' && c <= 'Z') {
		return true;
	}
	return false;
}
bool isNumber(char c) {
	if (c >= '0' && c <= '9') {
		return true;
	}
	return false;
}
Type wordBelongsTo(string token) {
	if (token == "main") {
		return MAINTK;
	}
	else if (token.compare("const") == 0) {
		return CONSTTK;
	}
	else if (token == "int") {
		return INTTK;
	}
	else if(token == "char") {
		return CHARTK;
	}
	else if (token == "break") {
		return BREAKTK;
	}
	else if (token == "continue") {
		return CONTINUETK;
	}
	else if (token == "if") {
		return IFTK;
	}
	else if (token == "else"){
		return ELSETK;
	}
	else if (token == "for") {
		return FORTK;
	}
	else if (token == "getint") {
		return GETINTTK;
	}
	else if (token == "getchar") {
		return GETCHARTK;
	}
	else if (token == "printf") {
		return PRINTFTK;
	}
	else if (token == "return") {
		return RETURNTK;
	}
	else if (token == "void") {
		return VOIDTK;
	}
	else {
		return IDENFR;
	}
}
void LogError(int lineNum, string errortype) {
	errorout <<  lineNum << " " << errortype << endl;
}
void Lexer::LexicalAnalysis(string filestring) {
	source = filestring;
	curPos = 0;
	lineNum = 1;
	token = "";
	number = 0;
	char now;
	tokens = vector<Token>();
	while (curPos < source.length()) {
		now = source.at(curPos);
		if (isLetter(now) || now == '_') {
			while ((isLetter(now) || now == '_' || isNumber(now))) {
				token += now;
				++curPos;
				if(curPos < source.length())
					now = source.at(curPos);
				else break;
			}
			lexType = wordBelongsTo(token);
			tokens.push_back(Token(token, lexType, lineNum));
			token = "";
			curPos --;
		}
		else if (isNumber(now)) {
			while (isNumber(now)) {
				token += now;
				++curPos;
				if(curPos < source.length())
					now = source.at(curPos);
				else break;
			}
			lexType = INTCON;
			tokens.push_back(Token(token, lexType, lineNum));
			token = "";
			curPos --;
		}
		else if(now == '\n'){
			lineNum++;
		}
		else if (now == '/') {
			++curPos;
			if(curPos < source.length()){
				now = source.at(curPos);
				if (now == '/') {
					while (now != '\n') {
						++curPos;
						if(curPos < source.length())
							now = source.at(curPos);
						else break;
					}
					lineNum ++;
				}
				else if (now == '*') {
					now = source.at(++curPos);
					while (!(now == '*' && source.at(curPos + 1) == '/')) {
						if(now == '\n') lineNum ++;
						++curPos;
						if(curPos < source.length())
							now = source.at(curPos);
						else break;
					}
					curPos ++;
				}
				else {
					lexType = DIV;
					token += '/';
					curPos--;
					tokens.push_back(Token(token, lexType, lineNum));
					token = "";
				}
			}else{
				lexType = DIV;
				token += '/';
				curPos--;
				tokens.push_back(Token(token, lexType, lineNum));
				token = "";
			}
		}
		else if (now == '"') {
			lexType = STRCON;
			now = source.at(++curPos);
			while (now != '"') {
				token += now;
				++curPos;
				if(curPos < source.length())
					now = source.at(curPos);
				else break;
			}
			tokens.push_back(Token(token, lexType, lineNum));
			token = "";
		}
		else if (now == '\'') {
			lexType = CHRCON;
			now = source.at(++curPos);
			while (now != '\'') {
				token += now;
				++curPos;
				if(curPos < source.length())
					now = source.at(curPos);
				else break;
			}
			tokens.push_back(Token(token, lexType, lineNum));
			token = "";
		}
		else {
			bool success = true;
			token += now;
			switch (now) {
			case '+':
				lexType = PLUS;
				break;
			case '-':
				lexType = MINU;
				break;
			case '*':
				lexType = MULT;
				break;
			//case '/':
			//	lexType = DIV;
			//	break;
			case '%':
				lexType = MOD;
				break;
			case '<':
				++curPos;
				if(curPos < source.length())
					now = source.at(curPos);
				else {
					lexType = LSS;
					break;
				}
				if (now == '=') {
					token += now;
					lexType = LEQ;
				}
				else {
					lexType = LSS;
					curPos--;
				}
				break;
			case '>':
				++curPos;
				if(curPos < source.length())
					now = source.at(curPos);
				else {
					lexType = GRE;
					break;
				}
				if (now == '=') {
					token += now;
					lexType = GEQ;
				}
				else {
					lexType = GRE;
					curPos--;
				}
				break;
			case '=':
				++curPos;
				if(curPos < source.length())
					now = source.at(curPos);
				else {
					lexType = ASSIGN;
					break;
				}
				if (now == '=') {
					token += now;
					lexType = EQL;
				}
				else {
					lexType = ASSIGN;
					curPos--;
				}
				break;
			case '!':
				++curPos;
				if(curPos < source.length())
					now = source.at(curPos);
				else {
					lexType = NOT;
					break;
				}
				if (now == '=') {
					token += now;
					lexType = NEQ;
				}else{
					lexType = NOT;
					curPos--;
				}
				break;
			case '&':
				++curPos;
				if(curPos < source.length())
					now = source.at(curPos);
				else{
					LogError(lineNum, "a");
					lexType = AND;
					break;
				}
				if (now == '&') {
					token += now;
					lexType = AND;
				}
				else {
					LogError(lineNum, "a");
					curPos--;
					lexType = AND;
				}
				break;
			case '|':
				++curPos;
				if(curPos < source.length())
					now = source.at(curPos);
				else break;
				if (now == '|') {
					token += now;
					lexType = OR;
				}
				else {
					LogError(lineNum, "a");
					curPos--;
					lexType = OR;
				}
				break;
			case ';':
				lexType = SEMICN;
				break;
			case ',':
				lexType = COMMA;
				break;
			case '(':
				lexType = LPARENT;
				break;
			case ')':
				lexType = RPARENT;
				break;
			case '[':
				lexType = LBRACK;
				break;
			case ']':
				lexType = RBRACK;
				break;
			case '{':
				lexType = LBRACE;
				break;
			case '}':
				lexType = RBRACE;
				break;
			default:
				success = false;
				break;
			}
			if (success) {
				tokens.push_back(Token(token, lexType, lineNum));
			}
			token = "";
		}
		++curPos;
	}
	
}

int main() {
	Lexer lexer;
	lexerout.open("lexer.txt");
	errorout.open("error.txt");
	inputFile.open("testfile.txt");
	std::stringstream buffer;
	if (inputFile.is_open()) {
		buffer << inputFile.rdbuf();
		cout << "read success" << endl;
		lexer.LexicalAnalysis(buffer.str());
		inputFile.close();
	}
	
	for (int i = 0; i < lexer.tokens.size(); i++) {
		lexerout << lexer.tokens[i].toString() << endl;
	}
	lexerout.close();
	errorout.close();
	buffer.clear();
}