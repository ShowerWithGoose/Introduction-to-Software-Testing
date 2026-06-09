#ifndef __CONSTS_H
#define __CONSTS_H
#include <string>
enum TokenEnum
{
    EOFTK,
    SPACETK,
    ENTERTK,
    SINGLECMT,
    MULTCMT,
    IDENFR,
    INTCON,
    STRCON,
    CHRCON,
    MAINTK,
    CONSTTK,
    INTTK,
    CHARTK,
    BREAKTK,
    CONTINUETK,
    IFTK,
    ELSETK,
    NOT,
    AND,
    OR,
    FORTK,
    GETINTTK,
    GETCHARTK,
    PRINTFTK,
    RETURNTK,
    PLUS,
    MINU,
    VOIDTK,
    MULT,
    DIV,
    MOD,
    LSS,
    LEQ,
    GRE,
    GEQ,
    EQL,
    NEQ,
    ASSIGN,
    SEMICN,
    COMMA,
    LPARENT,
    RPARENT,
    LBRACK,
    RBRACK,
    LBRACE,
    RBRACE,
    COUNT
};

const std::string TokenStrings[COUNT] = {
    "EOFTK",   "SPACETK",  "ENTERTK",   "SINGLECMT", "MULTCMT",    "IDENFR", "INTCON", "STRCON", "CHRCON", "MAINTK",
    "CONSTTK", "INTTK",    "CHARTK",    "BREAKTK",   "CONTINUETK", "IFTK",   "ELSETK", "NOT",    "AND",    "OR",
    "FORTK",   "GETINTTK", "GETCHARTK", "PRINTFTK",  "RETURNTK",   "PLUS",   "MINU",   "VOIDTK", "MULT",   "DIV",
    "MOD",     "LSS",      "LEQ",       "GRE",       "GEQ",        "EQL",    "NEQ",    "ASSIGN", "SEMICN", "COMMA",
    "LPARENT", "RPARENT",  "LBRACK",    "RBRACK",    "LBRACE",     "RBRACE"};

#endif
