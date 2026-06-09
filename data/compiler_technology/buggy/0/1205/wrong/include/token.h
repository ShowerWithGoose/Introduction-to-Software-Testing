#pragma once

#include <string>
#include <unordered_map>

#define TOKEN_TYPE \
    X(IDENFR, "Ident") \
    X(INTCON, "IntConst") \
    X(STRCON, "StringConst") \
    X(CHRCON, "CharConst") \
    X(MAINTK, "main") \
    X(CONSTTK, "const") \
    X(INTTK, "int") \
    X(CHARTK, "char") \
    X(BREAKTK, "break") \
    X(CONTINUETK, "continue") \
    X(IFTK, "if") \
    X(ELSETK, "else") \
    X(NOT, "!") \
    X(AND, "&&") \
    X(OR, "||") \
    X(FORTK, "for") \
    X(GETINTTK, "getint") \
    X(GETCHARTK, "getchar") \
    X(PRINTFTK, "printf") \
    X(RETURNTK, "return") \
    X(VOIDTK, "void") \
    X(PLUS, "+") \
    X(MINU, "-") \
    X(MULT, "*") \
    X(DIV, "/") \
    X(MOD, "%") \
    X(LSS, "<") \
    X(LEQ, "<=") \
    X(GRE, ">") \
    X(GEQ, ">=") \
    X(EQL, "==") \
    X(NEQ, "!=") \
    X(ASSIGN, "=") \
    X(SEMICN, ";") \
    X(COMMA, ",") \
    X(LPARENT, "(") \
    X(RPARENT, ")") \
    X(LBRACK, "[") \
    X(RBRACK, "]") \
    X(LBRACE, "{") \
    X(RBRACE, "}") \
    X(EOFTK, "EOF") \
    X(ERROR, "error")

#define TokenType_Str \
    {Token::IDENFR, "IDENFR"},\
    {Token::INTCON, "INTCON"},\
    {Token::STRCON, "STRCON"},\
    {Token::CHRCON, "CHRCON"},\
    {Token::MAINTK, "MAINTK"},\
    {Token::CONSTTK, "CONSTTK"},\
    {Token::INTTK, "INTTK"},\
    {Token::CHARTK, "CHARTK"},\
    {Token::BREAKTK, "BREAKTK"},\
    {Token::CONTINUETK, "CONTINUETK"},\
    {Token::IFTK, "IFTK"},\
    {Token::ELSETK, "ELSETK"},\
    {Token::NOT, "NOT"},\
    {Token::AND, "AND"},\
    {Token::OR, "OR"},\
    {Token::FORTK, "FORTK"},\
    {Token::GETINTTK, "GETINTTK"},\
    {Token::GETCHARTK, "GETCHARTK"},\
    {Token::PRINTFTK, "PRINTFTK"},\
    {Token::RETURNTK, "RETURNTK"},\
    {Token::VOIDTK, "VOIDTK"},\
    {Token::PLUS, "PLUS"},\
    {Token::MINU, "MINU"},\
    {Token::MULT, "MULT"},\
    {Token::DIV, "DIV"},\
    {Token::MOD, "MOD"},\
    {Token::LSS, "LSS"},\
    {Token::LEQ, "LEQ"},\
    {Token::GRE, "GRE"},\
    {Token::GEQ, "GEQ"},\
    {Token::EQL, "EQL"},\
    {Token::NEQ, "NEQ"},\
    {Token::ASSIGN, "ASSIGN"},\
    {Token::SEMICN, "SEMICN"},\
    {Token::COMMA, "COMMA"},\
    {Token::LPARENT, "LPARENT"},\
    {Token::RPARENT, "RPARENT"},\
    {Token::LBRACK, "LBRACK"},\
    {Token::RBRACK, "RBRACK"},\
    {Token::LBRACE, "LBRACE"},\
    {Token::RBRACE, "RBRACE"},\
    {Token::ERROR, "ERROR"}

struct Token {
    enum TokenType {
#define X(a, b) a,
        TOKEN_TYPE
#undef X
    } type;
    std::string content;
    int lineno;

    Token() = default;

    Token(const TokenType type, const std::string &content, const int lineNum)
        : type(type), content(content), lineno(lineNum) {}
};

inline std::string TokenType2Str(const Token::TokenType type) {
    static const std::unordered_map<Token::TokenType, std::string>
        token_type_str = {TokenType_Str};
    return token_type_str.at(type);
}
