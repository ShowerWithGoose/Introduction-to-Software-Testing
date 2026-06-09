//#include <iostream>
#include <unordered_map>
#include "token.h"

class Lexer {
public:
    bool hasError;
    void next(Token &token);
    Lexer(std::istream &in, char first_char) : _input(in), cur_char(first_char) {hasError = false; lineno = 1;}
   
private:
    std::istream& _input;
    char cur_char;
    int lineno;
    static const std::unordered_map<std::string, Token::TokenType> _RESERVED_WORD_TABLE1;
    void getNext();
    char getChar();
    char getChar(std::string &str);
    int getNum(std::string &str);
    std::string getIdent();
};