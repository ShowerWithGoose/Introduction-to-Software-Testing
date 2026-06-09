// Token.cpp
#include "Token.h"

std::map<std::string, std::string> keywords = {
    {"const", "CONSTTK"},
    {"int", "INTTK"},
    {"main", "MAINTK"},
    {"char", "CHARTK"},
    {"break", "BREAKTK"},
    {"continue", "CONTINUETK"},
    {"if", "IFTK"},
    {"else", "ELSETK"},
    {"for", "FORTK"},
    {"return", "RETURNTK"},
    {"printf", "PRINTFTK"},
    {"getint", "GETINTTK"},
    {"getchar", "GETCHARTK"},
    {"void", "VOIDTK"}
};

std::map<std::string, std::string> operators = {
    {"<=", "LEQ"},
    {">=", "GEQ"},
    {"==", "EQL"},
    {"!=", "NEQ"},
    {"<", "LSS"},
    {">", "GRE"},
    {"=", "ASSIGN"},
    {"+", "PLUS"},
    {"-", "MINU"},
    {"*", "MULT"},
    {"/", "DIV"},
    {"%", "MOD"},
    {"!", "NOT"},
    {",", "COMMA"},
    {";", "SEMICN"},
    {"(", "LPARENT"},
    {")", "RPARENT"},
    {"[", "LBRACK"},
    {"]", "RBRACK"},
    {"{", "LBRACE"},
    {"}", "RBRACE"},
    {"&&", "AND"},
    {"||", "OR"},
    {"&", "EAND"},
    {"|", "EOR"}
};
