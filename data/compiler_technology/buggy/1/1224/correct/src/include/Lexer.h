#ifndef _LEXER_H_
#define _LEXER_H_

#include "Type.h"

// main.cpp
extern TOKENS tokens[1000000];
extern int tokenNum;
extern int currow;
// Lexer.cpp
extern SYMTYPE symbol;
extern std::string token;

int getchar();
bool isSpace();
bool isNewline();
bool isTab();
bool isComma();
bool isSemi();
bool isEqu();
bool isPlus();
bool isMinus();
bool isDivi();
bool isStar();
bool isLpar();
bool isRpar();
bool isLbk();
bool isRbk();
bool isLbe();
bool isRbe();
bool isMod();
bool isNot();
bool isLess();
bool isGreater();
bool isAnd();
bool isOr();
void catToken();
void retract();

int transNum();
int getsymbol();

void allTokenGets();
#endif