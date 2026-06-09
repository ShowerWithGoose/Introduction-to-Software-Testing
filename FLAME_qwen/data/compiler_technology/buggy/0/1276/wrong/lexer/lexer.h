#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <fstream>
#include <unordered_map>

enum class TokenType {
    IDENFR, INTCON, STRCON, CHRCON, PLUS, MINU, MULT, DIV, MOD,
    LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN, AND, OR, NOT,
    LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE, SEMICN, COMMA,
    UNKNOWN
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
    bool hasError;  // 添加 hasError 成员变量
    std::unordered_map<std::string, TokenType> keywords = {
            {"int", TokenType::IDENFR}, {"char", TokenType::IDENFR}, {"const", TokenType::IDENFR},
            {"if", TokenType::IDENFR}, {"else", TokenType::IDENFR}, {"for", TokenType::IDENFR},
            {"break", TokenType::IDENFR}, {"continue", TokenType::IDENFR}, {"return", TokenType::IDENFR},
            {"void", TokenType::IDENFR}, {"getint", TokenType::IDENFR}, {"getchar", TokenType::IDENFR},
            {"printf", TokenType::IDENFR}, {"main", TokenType::IDENFR}
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

public:
    Lexer(const std::string &inputFile, const std::string &lexerFile, const std::string &errorFile);
    ~Lexer();
    void analyze();
};

#endif
