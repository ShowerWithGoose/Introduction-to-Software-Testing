#include <iostream>
#include <fstream>
#include "include/Lexer.h"


Lexer& Lexer::getInstance() {
    static Lexer instance;
    return instance;
}

Lexer::Lexer() : curPos(0), lineNum(1) {
    reserveWords = {
            {"Ident", LexType::IDENFR},
            {"IntConst", LexType::INTCON},
            {"StringConst", LexType::STRCON},
            {"CharConst", LexType::CHRCON},
            {"main", LexType::MAINTK},
            {"const", LexType::CONSTTK},
            {"int", LexType::INTTK},
            {"char", LexType::CHARTK},
            {"break", LexType::BREAKTK},
            {"continue", LexType::CONTINUETK},
            {"if", LexType::IFTK},
            {"else", LexType::ELSETK},
            {"!", LexType::NOT},
            {"&&", LexType::AND},
            {"||", LexType::OR},
            {"for", LexType::FORTK},
            {"getint", LexType::GETINTTK},
            {"getchar", LexType::GETCHARTK},
            {"printf", LexType::PRINTFTK},
            {"return", LexType::RETURNTK},
            {"+", LexType::PLUS},
            {"-", LexType::MINU},
            {"void", LexType::VOIDTK},
            {"*", LexType::MULT},
            {"/", LexType::DIV},
            {"%", LexType::MOD},
            {"<", LexType::LSS},
            {"<=", LexType::GEQ},
            {">", LexType::GRE},
            {">=", LexType::GEQ},
            {"==", LexType::EQL},
            {"!=", LexType::NEQ},
            {"=", LexType::ASSIGN},
            {";", LexType::SEMICN},
            {",", LexType::COMMA},
            {"(", LexType::LPARENT},
            {")", LexType::RPARENT},
            {"[", LexType::LBRACK},
            {"]", LexType::RBRACK},
            {"{", LexType::LBRACE},
            {"}", LexType::RBRACE}
    };
}

void Lexer::loadSource(const std::string &filename) {

    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error! Can not open file" << endl;
        return ;
    }
    char ch;
    while (inFile.get(ch)) {
        source += ch;
    }
    inFile.close();
}

Token Lexer::next() {
    int number;
    LexType lexType;
    while (curPos < source.size() && std::isspace(source[curPos])) {
        if (source[curPos] == '\n') {
            lineNum++;
        }
        curPos++;
    }
    if (curPos >= source.size()) {
        return Token(LexType::END, "EOF", lineNum);
    }
    switch (source[curPos]) {
        case '!': {
            if (curPos + 1 < source.size() && source[curPos+1] == '=') {
                curPos++;
                token = Token(LexType::NEQ, "!=", lineNum);
                break;
            }
            else {
                token = Token(LexType::NOT, "!", lineNum);
                break;
            }
        }
        case '&': {
            if (curPos + 1 < source.size() && source[curPos+1] == '&') {
                curPos++;
                token = Token(LexType::AND, "&&", lineNum);
                break;
            }
            else {
                token = Token(LexType::ERROR, "&", lineNum, 'a');
                break;
            }
        }
        case '|': {
            if (curPos + 1 < source.size() && source[curPos+1] == '|') {
                curPos++;
                token = Token(LexType::OR, "||", lineNum);
                break;
            }
            else {
                token = Token(LexType::ERROR, "|", lineNum, 'a');
                break;
            }
        }
        case '+': {
            token = Token(LexType::PLUS, "+", lineNum);
            break;
        }
        case '-': {
            token = Token(LexType::MINU, "-", lineNum);
            break;
        }
        case '*': {
            token = Token(LexType::MULT, "*", lineNum);
            break;
        }
        case '/': {
            if (curPos + 1 < source.size() && (source[curPos+1] == '/' || source[curPos+1] == '*')) {
                if (source[curPos+1] == '/') {
                    curPos++;
                    while (curPos + 1 < source.size()) {
                        curPos++;
                        if (source[curPos] == '\n') {
                            break;
                        }
                    }
                    token = Token(LexType::NULLVAL);
                    break;
                } else if (source[curPos+1] == '*') {
                    curPos++;
                    while (curPos + 1 < source.size()) {
                        curPos++;
                        if (source[curPos] == '*') {
                            while (curPos + 1 < source.size()) {
                                curPos++;
                                if (source[curPos] == '/') {
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    token = Token(LexType::NULLVAL);
                    break;
                }
            } else {
                token = Token(LexType::DIV, "/", lineNum);
                break;
            }
        }
        case '%': {
            token = Token(LexType::MOD, "%", lineNum);
            break;
        }
        case '<': {
            if (curPos + 1 < source.size() && source[curPos+1] == '=') {
                curPos++;
                token = Token(LexType::LEQ, "<=", lineNum);
                break;
            }
            else {
                token = Token(LexType::LSS, "<", lineNum);
                break;
            }
        }
        case '>': {
            if (curPos + 1 < source.size() && source[curPos+1] == '=') {
                curPos++;
                token = Token(LexType::GEQ, ">=", lineNum);
                break;
            }
            else {
                token = Token(LexType::GRE, ">", lineNum);
                break;
            }
        }
        case '=': {
            if (curPos + 1 < source.size() && source[curPos+1] == '=') {
                curPos++;
                token = Token(LexType::EQL, "==", lineNum);
                break;
            }
            else {
                token = Token(LexType::ASSIGN, "=", lineNum);
                break;
            }
        }
        case ';': {
            token = Token(LexType::SEMICN, ";", lineNum);
            break;
        }
        case ',': {
            token = Token(LexType::COMMA, ",", lineNum);
            break;
        }
        case '(': {
            token = Token(LexType::LPARENT, "(", lineNum);
            break;
        }
        case ')': {
            token = Token(LexType::RPARENT, ")", lineNum);
            break;
        }
        case '[': {
            token = Token(LexType::LBRACK, "[", lineNum);
            break;
        }
        case ']': {
            token = Token(LexType::RBRACK, "]", lineNum);
            break;
        }
        case '{': {
            token = Token(LexType::LBRACE, "{", lineNum);
            break;
        }
        case '}': {
            token = Token(LexType::RBRACE, "}", lineNum);
            break;
        }
        default: {
            string word = "";
            char c = source[curPos];
            if (isLetterOrUnderscore(c)) {
                word += c;
                while (curPos + 1 < source.size() && (isDigit(source[curPos+1]) || isLetterOrUnderscore(source[curPos+1]))) {
                    curPos++;
                    c = source[curPos];
                    word += c;
                }
                lexType = LexType::IDENFR;
            } else if (isDigit(c)) {
                word += c;
                while (curPos + 1 < source.size() && isDigit(source[curPos+1])) {
                    curPos++;
                    c = source[curPos];
                    word += c;
                }
                lexType = LexType::INTCON;
            } else if (c == '\'') {
                word += c;
                if (curPos + 1 < source.size() && source[curPos+1] == '\\') {
                    curPos++;
                    c = source[curPos];
                    word += c;
                }
                curPos++;
                c = source[curPos];
                word += c;
                if (curPos + 1 < source.size() && source[curPos+1] == '\'') {
                    curPos++;
                    c = source[curPos];
                    word += c;
                    lexType = LexType::CHRCON;
                } //暂不清楚读到非法字符后该如何处理
            } else if (c == '\"') {
                word += c;
                while (curPos + 1 < source.size()) {
                    curPos++;
                    c = source[curPos];
                    word += c;
                    if (c == '\"')
                        break;
                }
                lexType = LexType::STRCON;
            }

            if (isReserveWords(word)) {
                auto it = reserveWords.find(word);
                lexType = it->second;
            }
            if (!word.empty()) {
                token = Token(lexType, word, lineNum);
            } else {
                token = Token(LexType::NULLVAL);
            }
        }
    }
    curPos++;
    return token;
}

void Lexer::addToken(Token token) {
    tokens.push_back(token);
}

bool Lexer::isReserveWords(string word) {
    if (reserveWords.find(word) != reserveWords.end()) {
        return true;
    } else {
        return false;
    }
}

bool Lexer::isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

bool Lexer::isLetterOrUnderscore(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return true;
    } else if (ch >= 'A' && ch <= 'Z') {
        return true;
    } else if (ch == '_') {
        return true;
    } else {
        return false;
    }
}