#pragma once

#include <stdexcept>
#include <string>
#include <unordered_map>

// X macro technique for defining token types
#define TOKEN_TYPE                                                             \
    X(IDENFR, "IDENFR")                                                         \
    X(INTCON, "INTCON")                                                      \
    X(STRCON, "STRCON")                                                   \
    X(CHRCON, "CHRCON")                                                     \
    X(NOT, "NOT")                                                                \
    X(AND, "AND")                                                               \
    X(OR, "OR")                                                                \
    X(PLUS, "PLUS")                                                               \
    X(MINU, "MINU")                                                               \
    X(MULT, "MULT")                                                               \
    X(DIV, "DIV")                                                                \
    X(MOD, "MOD")                                                                \
    X(SEMICN, "SEMICN")                                                             \
    X(COMMA, "COMMA")                                                              \
    X(LPARENT, "LPARENT")                                                            \
    X(RPARENT, "RPARENT")                                                            \
    X(LBRACK, "LBRACK")                                                             \
    X(RBRACK, "RBRACK")                                                             \
    X(LBRACE, "LBRACE")                                                             \
    X(RBRACE, "RBRACE")                                                             \
    X(ASSIGN, "ASSIGN")                                                             \
    X(EQL, "EQL")                                                               \
    X(NEQ, "NEQ")                                                               \
    X(LSS, "LSS")                                                                \
    X(GRE, "GRE")                                                                \
    X(LEQ, "LEQ")                                                               \
    X(GEQ, "GEQ")                                                               \
    X(MAINTK, "MAINTK")                                                          \
    X(CONSTTK, "CONSTTK")                                                        \
    X(INTTK, "INTTK")                                                            \
    X(CHARTK, "CHARTK")                                                          \
    X(VOIDTK, "VOIDTK")                                                          \
    X(BREAKTK, "BREAKTK")                                                        \
    X(CONTINUETK, "CONTINUETK")                                                  \
    X(IFTK, "IFTK")                                                              \
    X(ELSETK, "ELSETK")                                                          \
    X(FORTK, "FORTK")                                                            \
    X(GETINTTK, "GETINTTK")                                                      \
    X(GETCHARTK, "GETCHARTK")                                                    \
    X(PRINTFTK, "PRINTFTK")                                                      \
    X(RETURNTK, "RETURNTK")                                                      \
    X(ERR, "ERR")                                                            \
    X(EOF_TK, "EOF_TK")                                                   \

struct Token {
    enum TokenType {
#define X(a, b) a,
        TOKEN_TYPE
#undef X
    } type;
    std::string content;
    int lineno;

    Token() = default;

    Token(TokenType type, std::string content, int lineno)
            : type(type), content(content), lineno(lineno) {}
};

inline std::string token_type_to_string(Token::TokenType type) {
    static const std::unordered_map<Token::TokenType, std::string>
            token_type_str = {
#define X(a, b) {Token::a, b},
            TOKEN_TYPE
#undef X
    };
    return token_type_str.at(type);
}
