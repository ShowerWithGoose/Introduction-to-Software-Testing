#pragma once
//
// Created by  on 2024/10/9.
//

#ifndef BIANYI_TOKEN_H
#define BIANYI_TOKEN_H


#include <string>
#include <map>
enum TokenType {
    IDENFR, INTCON, STRCON, CHRCON, MAINTK, CONSTTK,
    INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK,
    ELSETK, NOT, AND, OR, FORTK,
    GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, PLUS,
    MINU, VOIDTK, MULT, DIV,
    MOD, LSS, LEQ, GRE,
    GEQ, EQL, NEQ, ASSIGN,
    SEMICN, COMMA, LPARENT, RPARENT,
    LBRACK, RBRACK, LBRACE, RBRACE,
    None
};
const std::map<TokenType, std::string> type_code2str = {
        {TokenType::IDENFR, "IDENFR"},
        {TokenType::INTCON, "INTCON"},
        {TokenType::STRCON, "STRCON"},
        {TokenType::CHRCON, "CHRCON"},
        {TokenType::MAINTK, "MAINTK"},
        {TokenType::CONSTTK, "CONSTTK"},
        {TokenType::INTTK, "INTTK"},
        {TokenType::CHARTK, "CHARTK"},
        {TokenType::BREAKTK, "BREAKTK"},
        {TokenType::CONTINUETK, "CONTINUETK"},
        {TokenType::IFTK, "IFTK"},
        {TokenType::ELSETK, "ELSETK"},
        {TokenType::NOT, "NOT"},
        {TokenType::AND, "AND"},
        {TokenType::OR, "OR"},
        {TokenType::FORTK, "FORTK"},
        {TokenType::GETINTTK,"GETINTTK"},
        {TokenType::GETCHARTK,"GETCHARTK"},
        {TokenType::PRINTFTK,"PRINTFTK"},
        {TokenType::RETURNTK,"RETURNTK"},
        {TokenType::PLUS, "PLUS"},
        {TokenType::MINU, "MINU"},
        {TokenType::VOIDTK, "VOIDTK"},
        {TokenType::MULT, "MULT"},
        {TokenType::DIV, "DIV"},
        {TokenType::MOD, "MOD"},
        {TokenType::LSS, "LSS"},
        {TokenType::LEQ, "LEQ"},
        {TokenType::GRE, "GRE"},
        {TokenType::GEQ, "GEQ"},
        {TokenType::EQL, "EQL"},
        {TokenType::NEQ,"NEQ"},
        {TokenType::ASSIGN, "ASSIGN"},
        {TokenType::SEMICN, "SEMICN"},
        {TokenType::COMMA, "COMMA"},
        {TokenType::LPARENT, "LPARENT"},
        {TokenType::RPARENT, "RPARENT"},
        {TokenType::LBRACK, "LBRACK"},
        {TokenType::RBRACK, "RBRACK"},
        {TokenType::LBRACE, "LBRACE"},
        {TokenType::RBRACE, "RBRACE"},
        {TokenType::None, "Error"}
};

class Token {
public:
    std::string word;
    int line;
    int characterCount;
    TokenType type;
    Token(std::string word, TokenType type, int line, int characterCount) : word(word), type(type), line(line), characterCount(characterCount) {}
    std::string getWord() {
        return word;
    }
    Token() {
        this->type = None;
        this->word = "";
        this->line = -1;
		this->characterCount = -1;
    }
    TokenType getLexType() {
        return type;
    }
    const std::string toString() {
        if (type == TokenType::STRCON) return type_code2str.at(type) + ' ' + '"' + word + '"';
        else if (type == TokenType::CHRCON) return  type_code2str.at(type) + ' ' + '\'' + word + '\'';
        return type_code2str.at(type) + ' ' + word 
			//+ ' ' + std::to_string(line) + ' ' + std::to_string(characterCount)
            ;
    }
};
inline bool isIdent(Token token) {
    return token.getLexType() == TokenType::IDENFR;
}
inline bool isINTCON(Token token) {
    return token.getLexType() == TokenType::INTCON;
}
inline bool isSTRCON(Token token) {
    return token.getLexType() == TokenType::STRCON;
}
inline bool isCHRCON(Token token) {
    return token.getLexType() == TokenType::CHRCON;
}
inline bool isMAINTK(Token token) {
	return token.getLexType() == TokenType::MAINTK;
}
inline bool isCONSTTK(Token token) {
	return token.getLexType() == TokenType::CONSTTK;
}
inline bool isINTTK(Token token) {
	return token.getLexType() == TokenType::INTTK;
}
inline bool isCHARTK(Token token) {
	return token.getLexType() == TokenType::CHARTK;
}
    
inline bool isBREAKTK(Token token) {
	return token.getLexType() == TokenType::BREAKTK;
}
    
inline bool isCONTINUETK(Token token) {
	return token.getLexType() == TokenType::CONTINUETK;
}

inline bool isIFTK(Token token) {
	return token.getLexType() == TokenType::IFTK;
}
inline bool isELSETK(Token token) {
	return token.getLexType() == TokenType::ELSETK;
}
inline bool isNOT(Token token) {
	return token.getLexType() == TokenType::NOT;
}
inline bool isAND(Token token) {
	return token.getLexType() == TokenType::AND;
}
inline bool isOR(Token token) {
	return token.getLexType() == TokenType::OR;
}
inline bool isFORTK(Token token) {
	return token.getLexType() == TokenType::FORTK;
}
inline bool isGETINTTK(Token token) {
	return token.getLexType() == TokenType::GETINTTK;
}
inline bool isGETCHARTK(Token token) {
	return token.getLexType() == TokenType::GETCHARTK;
}
inline bool isPRINTFTK(Token token) {
	return token.getLexType() == TokenType::PRINTFTK;
}
inline bool isRETURNTK(Token token) {
	return token.getLexType() == TokenType::RETURNTK;
}
inline bool isPLUS(Token token) {
	return token.getLexType() == TokenType::PLUS;
}
inline bool isMINU(Token token) {
	return token.getLexType() == TokenType::MINU;
}
inline bool isVOIDTK(Token token) {
	return token.getLexType() == TokenType::VOIDTK;
}
inline bool isMULT(Token token) {
	return token.getLexType() == TokenType::MULT;
}
inline bool isDIV(Token token) {
	return token.getLexType() == TokenType::DIV;
}
inline bool isMOD(Token token) {
	return token.getLexType() == TokenType::MOD;
}
inline bool isLSS(Token token) {
	return token.getLexType() == TokenType::LSS;
}
inline bool isLEQ(Token token) {
	return token.getLexType() == TokenType::LEQ;
}
inline bool isGRE(Token token) {
	return token.getLexType() == TokenType::GRE;
}
inline bool isGEQ(Token token) {
	return token.getLexType() == TokenType::GEQ;
}
inline bool isEQL(Token token) {
	return token.getLexType() == TokenType::EQL;
}
inline bool isNEQ(Token token) {
	return token.getLexType() == TokenType::NEQ;
}
inline bool isASSIGN(Token token) {
	return token.getLexType() == TokenType::ASSIGN;
}
inline bool isSEMICN(Token token) {
	return token.getLexType() == TokenType::SEMICN;
}
inline bool isCOMMA(Token token) {
	return token.getLexType() == TokenType::COMMA;
}
inline bool isLPARENT(Token token) {
	return token.getLexType() == TokenType::LPARENT;
}
inline bool isRPARENT(Token token) {
	return token.getLexType() == TokenType::RPARENT;
}
inline bool isLBRACK(Token token) {
	return token.getLexType() == TokenType::LBRACK;
}
inline bool isRBRACK(Token token) {
	return token.getLexType() == TokenType::RBRACK;
}
inline bool isLBRACE(Token token) {
	return token.getLexType() == TokenType::LBRACE;
}
inline bool isRBRACE(Token token) {
	return token.getLexType() == TokenType::RBRACE;
}
inline bool isNone(Token token) {
	return token.getLexType() == TokenType::None;
}

#endif //BIANYI_TOKEN_H
