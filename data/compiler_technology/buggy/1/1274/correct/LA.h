#pragma once
//
// Created by  on 2024/10/9.
//

#ifndef BIANYI_LA_H
#define BIANYI_LA_H

#include "Token.h"
#include <iostream>
#include "MyFileStream.h"
using namespace std;
class Lexer {
public:
    static string source;
    static int curPos;
    static string token;
    static TokenType lexType;
	//  π”√Lexer::tokens∑√Œ 
    static vector<Token> tokens;
    static int lineNum;
    static int characterNum;
    static int number;
    void LexicalAnalysis(string filestring);
};
#endif
