#ifndef UTILS_H
#define UTILS_H

#include <bits/stdc++.h>
using namespace std;

void write(string fileName, string content);
void error(int lNum,string typ);

bool isUnderline(char *now); 
bool isAnd(char *now); 
bool isOr(char *now); 
bool isString(char *now); 
bool isChar(char *now); 
bool isNot(char *now); 
bool isPlus(char *now); 
bool isMinus(char *now); 
bool isMult(char *now); 
bool isDiv(char *now); 
bool isMod(char *now); 
bool isLss(char *now); 
bool isGre(char *now); 
bool isAssign(char *now); 
bool isSemicn(char *now); 
bool isComma(char *now); 
bool isLparent(char *now); 
bool isRparent(char *now); 
bool isLbrack(char *now); 
bool isRbrack(char *now); 
bool isLbrace(char *now); 
bool isRbrace(char *now); 
bool isSpace(char *now); 
bool isNewline(char *now); 
bool isTab(char *now); 
bool isEmpty(char *now); 
bool isLetter(char *now); 
bool isDigit(char *now);


#endif