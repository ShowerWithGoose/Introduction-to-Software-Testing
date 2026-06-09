#ifndef COMPILER_LEXER_H
#define COMPILER_LEXER_H

#include <unordered_map>
#include <string>
#include <vector>
#include "LexType.h"
#include "Token.h"

using namespace std;
class Lexer {

public:
    static Lexer& getInstance();
    void loadSource(const std::string& filename);
    Token next();
    void setCorrectNessToFalse() { correctNess = false; }
    bool getCorrectNess() { return correctNess; }
    void addToken(Token token);
    vector<Token> getTokens() { return tokens; }
    Lexer(const Lexer&) = delete;
    Lexer& operator=(const Lexer&) = delete;

private:
    Lexer();
    bool isReserveWords(string word);
    bool isLetterOrUnderscore(char ch);
    bool isDigit(char ch);
    string source;
    int curPos;
    int lineNum;

    bool correctNess = true;
    Token token;
    unordered_map<string, LexType> reserveWords;
    std::vector<Token> tokens;

};


#endif //COMPILER_LEXER_H
