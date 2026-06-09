#pragma once
#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <map>
enum Type {
    IDENFR, INTCON, STRCON, CHRCON, MAINTK, CONSTTK,
    INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK,
    ELSETK, NOT, AND, OR, FORTK,
    GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, PLUS,
    MINU, VOIDTK, MULT, DIV,
    MOD, LSS, LEQ, GRE,
    GEQ, EQL, NEQ, ASSIGN,
    SEMICN, COMMA, LPARENT, RPARENT,
    LBRACK, RBRACK, LBRACE, RBRACE
};
const std::map<Type, std::string> type_code2str = {
        {Type::IDENFR, "IDENFR"},
        {Type::INTCON, "INTCON"},
        {Type::STRCON, "STRCON"},
		{Type::CHRCON, "CHRCON"},
        {Type::MAINTK, "MAINTK"},
        {Type::CONSTTK, "CONSTTK"},
        {Type::INTTK, "INTTK"},
		{Type::CHARTK, "CHARTK"},
        {Type::BREAKTK, "BREAKTK"},
        {Type::CONTINUETK, "CONTINUETK"},
        {Type::IFTK, "IFTK"},
        {Type::ELSETK, "ELSETK"},
        {Type::NOT, "NOT"},
        {Type::AND, "AND"},
        {Type::OR, "OR"},
        {Type::FORTK, "FORTK"},
        {Type::GETINTTK,"GETINTTK"},
		{Type::GETCHARTK,"GETCHARTK"},
        {Type::PRINTFTK,"PRINTFTK"},
        {Type::RETURNTK,"RETURNTK"},
        {Type::PLUS, "PLUS"},
        {Type::MINU, "MINU"},
        {Type::VOIDTK, "VOIDTK"},
        {Type::MULT, "MULT"},
        {Type::DIV, "DIV"},
        {Type::MOD, "MOD"},
        {Type::LSS, "LSS"},
        {Type::LEQ, "LEQ"},
        {Type::GRE, "GRE"},
        {Type::GEQ, "GEQ"},
        {Type::EQL, "EQL"},
        {Type::NEQ,"NEQ"},
        {Type::ASSIGN, "ASSIGN"},
        {Type::SEMICN, "SEMICN"},
        {Type::COMMA, "COMMA"},
        {Type::LPARENT, "LPARENT"},
        {Type::RPARENT, "RPARENT"},
        {Type::LBRACK, "LBRACK"},
        {Type::RBRACK, "RBRACK"},
        {Type::LBRACE, "LBRACE"},
        {Type::RBRACE, "RBRACE"},
};

class Token {
public:
	Token(std::string word, Type type, int line) : word(word), type(type), line(line) {}
    std::string getWord() {
		return word;
    }
    Type getLexType() {
        return type;
    }
    const std::string toString() {
        if(type == Type::STRCON) return type_code2str.at(type) + ' ' + '"' + word + '"';
        else if(type == Type::CHRCON) return  type_code2str.at(type)  + ' ' + '\'' + word + '\'';
		return type_code2str.at(type) + ' ' + word;
    }
private:
	std::string word;
	Type type;
    int line;

};
#endif