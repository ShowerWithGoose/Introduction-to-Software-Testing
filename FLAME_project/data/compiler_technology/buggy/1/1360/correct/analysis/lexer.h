#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "token.h"


class Lexer {
public:
    Lexer(const std::string &source);
    std::vector<Token> tokenize();

private:
    std::string source;
    int position;
    int line;

    void skipWhitespace();
    void skipLineComment();
    void skipBlockComment();
    Token identifier();
    Token integer();
    Token stringLiteral();
    Token charLiteral();
    Token handleSpecialTokens();
};

#endif // LEXER_H
