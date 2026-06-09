#include <utility>

#include "include/Token.h"
std::map<Token::TokenType, std::string> tokenTypeToString;

Token::Token(const TokenType token_type,string content, const int line_index) :
type(token_type), content(std::move(content)), line_index(line_index)
{
}

string Token::get_content() const
{
	return content;
}

Token::TokenType Token::get_type() const
{
	return type;
}

int Token::get_line_index() const
{
	return line_index;
}



std::ostream& operator<<(std::ostream& os, const Token& token) {
    if (tokenTypeToString.empty()) {
        initializeTokenTypeMap();
    }
    os << tokenTypeToString[token.get_type()] << " " << token.get_content() << std::endl;
	return os;
}



void initializeTokenTypeMap() {
    tokenTypeToString = {
        {Token::TokenType::UNKNOWN, "UNKNOWN"},
        {Token::TokenType::MAINTK, "MAINTK"},
        {Token::TokenType::CONSTTK, "CONSTTK"},
        {Token::TokenType::INTTK, "INTTK"},
        {Token::TokenType::CHARTK, "CHARTK"},
        {Token::TokenType::BREAKTK, "BREAKTK"},
        {Token::TokenType::CONTINUETK, "CONTINUETK"},
        {Token::TokenType::IFTK, "IFTK"},
        {Token::TokenType::ELSETK, "ELSETK"},
        {Token::TokenType::FORTK, "FORTK"},
        {Token::TokenType::GETINTTK, "GETINTTK"},
        {Token::TokenType::GETCHARTK, "GETCHARTK"},
        {Token::TokenType::PRINTFTK, "PRINTFTK"},
        {Token::TokenType::RETURNTK, "RETURNTK"},
        {Token::TokenType::VOIDTK, "VOIDTK"},
        {Token::TokenType::IDENFR, "IDENFR"},
        {Token::TokenType::CHRCON, "CHRCON"},
        {Token::TokenType::INTCON, "INTCON"},
        {Token::TokenType::STRCON, "STRCON"},
        {Token::TokenType::NEQ, "NEQ"},
        {Token::TokenType::NOT, "NOT"},
        {Token::TokenType::AND, "AND"},
        {Token::TokenType::OR, "OR"},
        {Token::TokenType::PLUS, "PLUS"},
        {Token::TokenType::MINU, "MINU"},
        {Token::TokenType::MULT, "MULT"},
        {Token::TokenType::DIV, "DIV"},
        {Token::TokenType::MOD, "MOD"},
        {Token::TokenType::LEQ, "LEQ"},
        {Token::TokenType::GEQ, "GEQ"},
        {Token::TokenType::LSS, "LSS"},
        {Token::TokenType::GRE, "GRE"},
        {Token::TokenType::EQL, "EQL"},
        {Token::TokenType::ASSIGN, "ASSIGN"},
        {Token::TokenType::SEMICN, "SEMICN"},
        {Token::TokenType::COMMA, "COMMA"},
        {Token::TokenType::LPARENT, "LPARENT"},
        {Token::TokenType::RPARENT, "RPARENT"},
        {Token::TokenType::LBRACK, "LBRACK"},
        {Token::TokenType::RBRACK, "RBRACK"},
        {Token::TokenType::LBRACE, "LBRACE"},
        {Token::TokenType::RBRACE, "RBRACE"}
    };
}