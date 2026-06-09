#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <fstream>
#include <unordered_map>


enum class TokenType {
    IDENFR, INTCON, STRCON, CHRCON, INTTK, MAINTK, PLUS, MINU, MULT, DIV, MOD,
    LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN, AND, OR, NOT,
    LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE, SEMICN, COMMA,
    ELSETK, VOIDTK, FORTK, BREAKTK, CONTINUETK, RETURNTK, GETINTTK, GETCHARTK, PRINTFTK,
    IFTK, CONSTTK, CHARTK, UNKNOWN
};


enum class ErrorType {
    ILLEGAL_SYMBOL = 'a'
};


class Lexer {
private:
    std::ifstream input;
    std::ofstream lexerOutput;
    std::ofstream errorOutput;
    int lineno;
    bool hasError;


    std::unordered_map<std::string, TokenType> keywords = {
            {"int", TokenType::INTTK}, {"main", TokenType::MAINTK}, {"const", TokenType::CONSTTK}, {"char", TokenType::CHARTK},
            {"void", TokenType::VOIDTK}, {"if", TokenType::IFTK}, {"else", TokenType::ELSETK}, {"for", TokenType::FORTK},
            {"break", TokenType::BREAKTK}, {"continue", TokenType::CONTINUETK}, {"return", TokenType::RETURNTK},
            {"getint", TokenType::GETINTTK}, {"getchar", TokenType::GETCHARTK}, {"printf", TokenType::PRINTFTK}
    };


    void handleLessThan();
    void handleGreaterThan();
    void handleEqualSign();
    void handleExclamation();
    void handleAndOperator();
    void handleOrOperator();
    void handleError(char ch);
    void writeToken(TokenType type, const std::string &value);
    void handleStringOrChar(char boundary);
    void handleSlash();


    std::string tokenTypeToString(TokenType type);

public:

    Lexer(const std::string &inputFile, const std::string &lexerFile, const std::string &errorFile);


    ~Lexer();


    void analyze();
};

#endif 
