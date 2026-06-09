#include <iostream>
#include <map>

using namespace std;

enum Token_Type {
	IDENFR, INTCON, STRCON, CHRCON, 
	MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK, ELSETK,
	NOT, AND, OR, 
	FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, 
	PLUS, MINU, 
	VOIDTK, 
	MULT, DIV, MOD, LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN, 
	SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,
	ANDOP, OROP
};

extern map<string, Token_Type> ReserveWord;
extern map<string, Token_Type> symbol;
extern map<Token_Type, string> out_for_lexer;