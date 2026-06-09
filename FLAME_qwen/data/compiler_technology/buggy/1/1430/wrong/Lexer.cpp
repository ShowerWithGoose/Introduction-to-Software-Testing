// Lexer.cpp
#include "Lexer.h"
#include <cctype>
#include <iostream>

std::vector<Token> lexer(const std::string &code) {
    std::vector<Token> tokens;
    int i = 0, line = 1;
    while (i < code.size()) {
        if (std::isspace(code[i])) {
            if (code[i] == '\n') line++;
            i++;
        } else if (std::isalpha(code[i]) || code[i] == '_') {
            int start = i;
            while (i < code.size() && (std::isalnum(code[i]) || code[i] == '_')) i++;
            std::string word = code.substr(start, i - start);
            if (keywords.count(word)) {
                tokens.push_back({keywords[word], word, line});
            } else {
                tokens.push_back({"IDENFR", word, line});
            }
        } else if (std::isdigit(code[i])) {
            int start = i;
            while (i < code.size() && std::isdigit(code[i])) i++;
            tokens.push_back({"INTCON", code.substr(start, i - start), line});
        } else if (code[i] == '"') {
            int start = i++;
            while (i < code.size() && code[i] != '"') i++;
            i++;
            tokens.push_back({"STRCON", code.substr(start, i - start), line});
        } else if (code[i] == '\'') {
            if (i + 3 < code.size() && code[i + 3] == '\'') {
                if (code[i + 1] == '\\') {
                    char nextChar = code[i + 2];
                    std::string validEscapeChars = "abtnvf\"'\\0";
                    if (validEscapeChars.find(nextChar) != std::string::npos) {
                        tokens.push_back({"CHRCON", code.substr(i, 4), line});
                    } else {
                        std::cerr << "非法转义字符: \\" << nextChar << std::endl;
                    }
                } else {
                    std::cerr << "字符常量格式错误，期待转义字符" << std::endl;
                }
                i += 4;
            } else if (i + 2 < code.size() && code[i + 2] == '\'') {
                char charConst = code[i + 1];
                if (charConst >= 32 && charConst <= 126) {
                    tokens.push_back({"CHRCON", code.substr(i, 3), line});
                } else {
                    std::cerr << "非法字符常量: " << charConst << std::endl;
                }
                i += 3;
            } else {
                std::cerr << "字符常量格式错误" << std::endl;
                i += 3;
            }
        } else {
            if (i + 1 < code.size()) {
                std::string twoCharOp = code.substr(i, 2);
                if (operators.count(twoCharOp)) {
                    tokens.push_back({operators[twoCharOp], twoCharOp, line});
                    i += 2;
                    continue;
                }
            }
            std::string oneCharOp = std::string(1, code[i]);
            if (operators.count(oneCharOp)) {
                tokens.push_back({operators[oneCharOp], oneCharOp, line});
                i++;
            } else {
                std::cerr << "未知符号: " << code[i] << std::endl;
                i++;
            }
        }
    }
    return tokens;
}
