#pragma once
#ifndef TOKEN_H_
#include<string>
#include <iostream>
#include <map>
#define SINGLE_TOKEN_LEN 1
#define DOUBLE_TOKEN_LEN 2
using std::string;
class Token
{
public:
	enum class TokenType {
		UNKNOWN, MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK, ELSETK, FORTK,
		GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, VOIDTK,
		IDENFR, CHRCON, INTCON, STRCON,
		NEQ, NOT, AND, OR, PLUS, MINU, MULT, DIV, MOD, LEQ, GEQ, LSS, GRE, EQL, ASSIGN,
		SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE
	};

	Token(TokenType, string, int);
	TokenType get_type() const;
	string get_content() const;
	int get_line_index() const;
	friend std::ostream& operator<<(std::ostream& os, const Token& person);
	

private:
	TokenType type;
	string content;
	int line_index;
};

extern std::map<Token::TokenType, std::string> tokenTypeToString;

void initializeTokenTypeMap();

#endif

