// Lexer.h
#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "Token.h"

// 词法分析函数
std::vector<Token> lexer(const std::string &code);

#endif // LEXER_H
