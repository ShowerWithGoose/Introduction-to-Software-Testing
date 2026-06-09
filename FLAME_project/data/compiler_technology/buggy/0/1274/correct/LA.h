#pragma once
#ifndef LA_H
#define LA_H

#include <string>
#include <vector>
#include "Token.h"


using namespace std;
class Lexer {
public:
	static string source;
	static int curPos;
	static string token;
	static Type lexType;
	static vector<Token> tokens;
	static int lineNum;
	static int number;
	void LexicalAnalysis(string filestring);

};
#endif
