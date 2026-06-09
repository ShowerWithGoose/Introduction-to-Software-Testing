#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <unordered_map>
#include <string>

enum TokenType {
    IDENFR, ELSETK, VOIDTK, SEMICN,
    INTCON, NOT, MULT, COMMA,
    STRCON, AND, DIV, LPARENT,
    CHRCON, OR, MOD, RPARENT,
    MAINTK, FORTK, LSS, LBRACK,
    CONSTTK, GETINTTK, LEQ, RBRACK,
    INTTK, GETCHARTK, GRE, LBRACE,
    CHARTK, PRINTFTK, GEQ, RBRACE,
    BREAKTK, RETURNTK, EQL,
    CONTINUETK, PLUS, NEQ,
    IFTK, MINU, ASSIGN,
    END, ERROR
};

struct Token {
    TokenType type;
    std::string value;
    int line;

    bool haveError() const;
    void print(std::ostream& os) const;
    void printError(std::ostream& os) const;
    std::string TokenType2String() const;
};

#endif // TOKEN_H
