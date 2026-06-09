#include "token.h"
bool Token::haveError() const {
    return type == ERROR;
}

void Token::print(std::ostream& os) const {
    static const std::unordered_map<TokenType, std::string> typeToString = {
            {IDENFR, "IDENFR"}, {ELSETK, "ELSETK"}, {VOIDTK, "VOIDTK"},
            {SEMICN, "SEMICN"}, {INTCON, "INTCON"}, {NOT, "NOT"},
            {MULT, "MULT"}, {COMMA, "COMMA"}, {STRCON, "STRCON"},
            {AND, "AND"}, {DIV, "DIV"}, {LPARENT, "LPARENT"},
            {CHRCON, "CHRCON"}, {OR, "OR"}, {MOD, "MOD"},
            {RPARENT, "RPARENT"}, {MAINTK, "MAINTK"}, {FORTK, "FORTK"},
            {LSS, "LSS"}, {LBRACK, "LBRACK"}, {CONSTTK, "CONSTTK"},
            {GETINTTK, "GETINTTK"}, {LEQ, "LEQ"}, {RBRACK, "RBRACK"},
            {INTTK, "INTTK"}, {GETCHARTK, "GETCHARTK"}, {GRE, "GRE"},
            {LBRACE, "LBRACE"}, {CHARTK, "CHARTK"}, {PRINTFTK, "PRINTFTK"},
            {GEQ, "GEQ"}, {RBRACE, "RBRACE"}, {BREAKTK, "BREAKTK"},
            {RETURNTK, "RETURNTK"}, {EQL, "EQL"}, {CONTINUETK, "CONTINUETK"},
            {PLUS, "PLUS"}, {NEQ, "NEQ"}, {IFTK, "IFTK"},
            {MINU, "MINU"}, {ASSIGN, "ASSIGN"}, {END, "END"},
            {ERROR, "ERROR"}
    };
    os << typeToString.at(type) << " " << value <<" "<<line<< "\n";
}

void Token::printError(std::ostream& os) const {
    os << value << " a" << std::endl;
}

std::string Token::TokenType2String() const {
    static const std::unordered_map<TokenType, std::string> typeToString = {
            {IDENFR,     "IDENFR"},
            {ELSETK,     "ELSETK"},
            {VOIDTK,     "VOIDTK"},
            {SEMICN,     "SEMICN"},
            {INTCON,     "INTCON"},
            {NOT,        "NOT"},
            {MULT,       "MULT"},
            {COMMA,      "COMMA"},
            {STRCON,     "STRCON"},
            {AND,        "AND"},
            {DIV,        "DIV"},
            {LPARENT,    "LPARENT"},
            {CHRCON,     "CHRCON"},
            {OR,         "OR"},
            {MOD,        "MOD"},
            {RPARENT,    "RPARENT"},
            {MAINTK,     "MAINTK"},
            {FORTK,      "FORTK"},
            {LSS,        "LSS"},
            {LBRACK,     "LBRACK"},
            {CONSTTK,    "CONSTTK"},
            {GETINTTK,   "GETINTTK"},
            {LEQ,        "LEQ"},
            {RBRACK,     "RBRACK"},
            {INTTK,      "INTTK"},
            {GETCHARTK,  "GETCHARTK"},
            {GRE,        "GRE"},
            {LBRACE,     "LBRACE"},
            {CHARTK,     "CHARTK"},
            {PRINTFTK,   "PRINTFTK"},
            {GEQ,        "GEQ"},
            {RBRACE,     "RBRACE"},
            {BREAKTK,    "BREAKTK"},
            {RETURNTK,   "RETURNTK"},
            {EQL,        "EQL"},
            {CONTINUETK, "CONTINUETK"},
            {PLUS,       "PLUS"},
            {NEQ,        "NEQ"},
            {IFTK,       "IFTK"},
            {MINU,       "MINU"},
            {ASSIGN,     "ASSIGN"},
            {END,        "END"},
            {ERROR,      "ERROR"}
    };
    return typeToString.at(type);

}