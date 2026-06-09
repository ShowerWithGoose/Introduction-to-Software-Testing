//
// Created by  on 2024-09-02.
//

#include "Token.h"
#include "../../errors/Error.h"

namespace frontend {
    // 保留字映射到TokenType
    std::unordered_map<std::string, Token::TokenType> reserved_to_type_map = {
            {"main", Token::TokenType::MAINTK},
            {"const", Token::TokenType::CONSTTK},
            {"int", Token::TokenType::INTTK},
            {"break", Token::TokenType::BREAKTK},
            {"continue", Token::TokenType::CONTINUETK},
            {"if", Token::TokenType::IFTK},
            {"else", Token::TokenType::ELSETK},
            {"for", Token::TokenType::FORTK},
            {"return", Token::TokenType::RETURNTK},
            {"void", Token::TokenType::VOIDTK},
            {"getint", Token::TokenType::GETINTTK},
            {"printf", Token::TokenType::PRINTFTK},
            {"char", Token::TokenType::CHARTK},
            {"getchar", Token::TokenType::GETCHARTK}
    };

    // 分界符映射到TokenType
    std::unordered_map<std::string, Token::TokenType> delimiter_to_type_map = {
            {"!", Token::TokenType::NOT},
            {"&&", Token::TokenType::AND},
            {"||", Token::TokenType::OR},
            {"+", Token::TokenType::PLUS},
            {"-", Token::TokenType::MINU},
            {"*", Token::TokenType::MULT},
            {"/", Token::TokenType::DIV},
            {"%", Token::TokenType::MOD},
            {"<", Token::TokenType::LSS},
            {"<=", Token::TokenType::LEQ},
            {">", Token::TokenType::GRE},
            {">=", Token::TokenType::GEQ},
            {"==", Token::TokenType::EQL},
            {"!=", Token::TokenType::NEQ},
            {"=", Token::TokenType::ASSIGN},
            {";", Token::TokenType::SEMICN},
            {",", Token::TokenType::COMMA},
            {"(", Token::TokenType::LPARENT},
            {")", Token::TokenType::RPARENT},
            {"[", Token::TokenType::LBRACK},
            {"]", Token::TokenType::RBRACK},
            {"{", Token::TokenType::LBRACE},
            {"}", Token::TokenType::RBRACE},
    };

    // TokenType映射到字符表示
    std::string token_type_to_string_map[] = {
            "IDENFR", "INTCON", "STRCON", "CHRCON", "MAINTK", "CONSTTK", "INTTK",
            "BREAKTK", "CONTINUETK", "IFTK","ELSETK", "FORTK",
            "RETURNTK", "VOIDTK", "GETINTTK", "PRINTFTK", "CHARTK", "GETCHARTK", "NOT",
            "AND", "OR", "PLUS", "MINU", "MULT",
            "DIV", "MOD", "LSS", "LEQ", "GRE",
            "GEQ", "EQL", "NEQ","ASSIGN", "SEMICN",
            "COMMA", "LPARENT", "RPARENT", "LBRACK", "RBRACK", "LBRACE", "RBRACE",
    };
    int Token::tryMatchReserved(const std::string &text, int start_index) {
        if (start_index + 4 < text.size() && text.substr(start_index, 4) == "main" && !isIdentifierChar(text[start_index + 4])) {
            return start_index + 4;
        }
        if (start_index + 5 < text.size() && text.substr(start_index, 5) == "const" && !isIdentifierChar(text[start_index + 5])) {
            return start_index + 5;
        }
        if (start_index + 3 < text.size() && text.substr(start_index, 3) == "int" && !isIdentifierChar(text[start_index + 3])) {
            return start_index + 3;
        }
        if (start_index + 5 < text.size() && text.substr(start_index, 5) == "break" && !isIdentifierChar(text[start_index + 5])) {
            return start_index + 5;
        }
        if (start_index + 8 < text.size() && text.substr(start_index, 8) == "continue" && !isIdentifierChar(text[start_index + 8])) {
            return start_index + 8;
        }
        if (start_index + 2 < text.size() && text.substr(start_index, 2) == "if" && !isIdentifierChar(text[start_index + 2])) {
            return start_index + 2;
        }
        if (start_index + 4 < text.size() && text.substr(start_index, 4) == "else" && !isIdentifierChar(text[start_index + 4])) {
            return start_index + 4;
        }
        if (start_index + 3 < text.size() && text.substr(start_index, 3) == "for" && !isIdentifierChar(text[start_index + 3])) {
            return start_index + 3;
        }
        if (start_index + 6 < text.size() && text.substr(start_index, 6) == "return" && !isIdentifierChar(text[start_index + 6])) {
            return start_index + 6;
        }
        if (start_index + 4 < text.size() && text.substr(start_index, 4) == "void" && !isIdentifierChar(text[start_index + 4])) {
            return start_index + 4;
        }
        if (start_index + 6 < text.size() && text.substr(start_index, 6) == "getint" && !isIdentifierChar(text[start_index + 6])) {
            return start_index + 6;
        }
        if (start_index + 6 < text.size() && text.substr(start_index, 6) == "printf" && !isIdentifierChar(text[start_index + 6])) {
            return start_index + 6;
        }
        if (start_index + 4 < text.size() && text.substr(start_index, 4) == "char" && !isIdentifierChar(text[start_index + 4])) {
            return start_index + 4;
        }
        if (start_index + 7 < text.size() && text.substr(start_index, 7) == "getchar" && !isIdentifierChar(text[start_index + 7])) {
            return start_index + 7;
        }
        return 0;
    }

    int Token::tryMatchIdentifier(const std::string &text, int start_index) {
        // 特判首字符不合法
        if (!isIdentifierChar(text[start_index]) || isDigit(text[start_index])) {
            return 0;
        }
        int res = start_index;
        while (res < text.size() && isIdentifierChar(text[res])) { res++; }
        return res;
    }

    int Token::tryMatchStr(const std::string &text, int start_index) {
        if (text[start_index] != '\"') { return 0; }
        int res = start_index + 1;
        while (res < text.size()) {
            if (text[res] == '\\') {
                res += 2;
            } else if (text[res] != '\"') {
                res++;
            } else {
                break;
            }
        }
//        while (text[res] != '\"') { res++; }
        return res + 1;
    }

    int Token::tryMatchInt(const std::string &text, int start_index) {
        if (!isDigit(text[start_index])) { return 0; }
        int res = start_index + 1;
        while (res < text.size() && isDigit(text[res])) { res++; }
        return res;
    }

    int Token::tryMatchDelimiter(const std::string &text, int start_index) {
        if (text[start_index] == '!') {
            if (start_index + 1 < text.size() && text[start_index + 1] == '=') { return start_index + 2; }
            return start_index + 1;
        }
        if (start_index + 1 < text.size() && text[start_index] == '&' && text[start_index + 1] == '&') {
            return start_index + 2;
        }
        if (start_index + 1 < text.size() && text[start_index] == '|' && text[start_index + 1] == '|') {
            return start_index + 2;
        }
        if (text[start_index] == '+') {
            return start_index + 1;
        }
        if (text[start_index] == '-') {
            return start_index + 1;
        }
        if (text[start_index] == '*') {
            return start_index + 1;
        }
        if (text[start_index] == '/') {
            return start_index + 1;
        }
        if (text[start_index] == '%') {
            return start_index + 1;
        }
        if (text[start_index] == '<') {
            if (text[start_index + 1] == '=') { return start_index + 2; }
            return start_index + 1;
        }
        if (text[start_index] == '>') {
            if (text[start_index + 1] == '=') { return start_index + 2; }
            return start_index + 1;
        }
        if (text[start_index] == '=') {
            if (text[start_index + 1] == '=') { return start_index + 2; }
            return start_index + 1;
        }
        if (text[start_index] == ';') {
            return start_index + 1;
        }
        if (text[start_index] == ',') {
            return start_index + 1;
        }
        if (text[start_index] == '(' || text[start_index] == ')') {
            return start_index + 1;
        }
        if (text[start_index] == '[' || text[start_index] == ']') {
            return start_index + 1;
        }
        if (text[start_index] == '{' || text[start_index] == '}') {
            return start_index + 1;
        }
        return -1;
    }

    int Token::tryMatchChar(const std::string &text, int start_index) {
        if (text[start_index] != '\'') { return 0; }
        int res = start_index + 1;
//        while (res < text.size() && text[res] != '\'') { res++; }
        while (res < text.size()) {
            if (text[res] == '\\') {
                res += 2;
            } else if (text[res] != '\'') {
                res++;
            } else {
                break;
            }
        }
        return res + 1;
    }
} // frontend