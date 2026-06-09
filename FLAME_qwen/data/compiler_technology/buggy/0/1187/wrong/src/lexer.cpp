#include <iostream>
#include <sstream>
#include "lexer.h"
#include "ERROR.h"

const std::unordered_map<std::string, Token::TokenType> Lexer::_RESERVED_WORD_TABLE1= 
{
    {"main", Token::MAINTK},
    {"const", Token::CONSTTK},
    {"int", Token::INTTK},
    {"char", Token::CHARTK},
    {"break", Token::BREAKTK},
    {"continue", Token::CONTINUETK},
    {"if", Token::IFTK},
    {"else", Token::ELSETK},
    {"for", Token::FORTK},
    {"getint", Token::GETINTTK},
    {"getchar", Token::GETCHARTK},
    {"printf", Token::PRINTFTK},
    {"return", Token::RETURNTK},
    {"void", Token::VOIDTK}
};

bool isDigit(char source) {
    if (source >= '0' && source <= '9') {
        return true;
    }
    return false;
}

bool isNondigit(char source) {
    if (source >= 'A' && source <= 'Z') return true;
    if (source >= 'a' && source <= 'z') return true;
    if (source == '_') return true;
    return false;
}

bool isASCII(char source) {
    if (source >= 32 && source <= 126) return true;
    if (source >= 7 && source <= 12) return true;
    if (source == 0) return true;
    return false;
}

inline void Lexer::getNext() {
    cur_char = this->_input.get();
    if (cur_char == '\n') {
        this->lineno += 1;
    }
    if(_input.eof()) {
        cur_char = EOF;
    }
}

char Lexer::getChar(std::string &str) {
    char result;
    std::stringstream ss;
    ss << '\'';
    if (cur_char == '\\') {
        ss << '\\';
        getNext();
        // 转义
        switch (cur_char) {
            case 'a':
                // 007
                result = 7;
                break;
            case 'b':
                // 008
                result =  8;
            case 't':
                // 009
                result = 9;
            case 'n':
                // 010
                result = 10;
            case 'v':
                // 011
                result = 11;
            case 'f':
                // 012
                result = 12;
            case '\"':
                // 034
                result = 34;
            case '\'':
                // 039
                result = 39;
            case '\\':
                // 092
                result = 92;
            case '0':
                // 000
                result = 0;
            default:
                result = -1;
        }
        ss << cur_char;
    } else {
        // what ever
        result = cur_char;
        ss << cur_char;
    }
    getNext();
    ss << '\'';
    str = ss.str();
    return result;
}

int Lexer::getNum(std::string &str) {
    std::stringstream ss;
    int result = 0;
    do {
        ss << cur_char;
        result = result * 10 + cur_char - '0';
        getNext();
    }while(isDigit(cur_char));
    str =  ss.str();
    return result;
}

std::string Lexer::getIdent() {
    std::stringstream ss;
    do {
        ss << cur_char;
        getNext();
    } while (isNondigit(cur_char) || isDigit(cur_char));
    return ss.str();
}

void Lexer::next(Token &token) {
    switch(cur_char) {
        case '!':
            getNext();
            if (cur_char == '=') {
                getNext();
                // NEQ
                token = Token(Token::NEQ, lineno);
            } else {
                // NOT
                token = Token(Token::NOT, lineno);
            }
            break;
        case '&':
            getNext();
            if (cur_char == '&') {
                getNext();
                // AND
                token = Token(Token::AND, lineno);
            } else {
                // ERROR a
                hasError = true;
                Error *error = new Error(Error::a, lineno);
                error->throwError();
                token = Token(Token::AND, lineno);
            }
            break;
        case '|':
            getNext();
            if (cur_char == '|') {
                getNext();
                // OR
                token = Token(Token::OR, lineno);
            } else {
                // ERROR a
                hasError = true;
                Error *error = new Error(Error::a, lineno);
                error->throwError();
                token = Token(Token::OR, lineno);
            }
            break;
        case '+':
            getNext();
            // PLUS
            token = Token(Token::PLUS, lineno);
            break;
        case '-':
            getNext();
            // MINU
            token = Token(Token::MINU, lineno);
            break;
        case '*':
            getNext();
            // MULT
            token = Token(Token::MULT, lineno);
            break;
        case '/':
            getNext();
            if (cur_char == '/') {
                // single line
                do {
                    getNext();
                    if (cur_char == EOF) {
                        token.type = Token::EOFTK;
                        token.lineno = this->lineno;
                        return;
                    }
                } while (cur_char != '\n');
                getNext();
                next(token);
            } else if (cur_char == '*') {
                // mult line
                do {
                    do {
                        getNext();
                        if (cur_char == EOF) {
                            token.type = Token::EOFTK;
                            token.lineno = this->lineno;
                            return;
                        }
                    } while (cur_char != '*');
                    getNext();
                    if (cur_char == EOF) {
                        token.type = Token::EOFTK;
                        token.lineno = this->lineno;
                        return;
                    }
                } while(cur_char != '/');
                getNext();
                next(token);
            } else {
                // DIV
                token = Token(Token::DIV, lineno);
            }
            break;
        case '%':
            getNext();
            // MOD
            token = Token(Token::MOD, lineno);
            break;
        case '<':
            getNext();
            if (cur_char == '='){
                getNext();
                // LEQ
                token = Token(Token::LEQ, lineno);
            } else {
                // LSS
                token = Token(Token::LSS, lineno);
            }
            break;
        case '>':
            getNext();
            if (cur_char == '=') {
                getNext();
                // GEQ
                token = Token(Token::GEQ, lineno);
            } else {
                // GRE
                token = Token(Token::GRE, lineno);
            }
            break;
        case '=':
            getNext();
            if (cur_char == '=') {
                getNext();
                // EQL
                token = Token(Token::EQL, lineno);
            } else {
                //ASSIGN
                token = Token(Token::ASSIGN, lineno);
            }
            break;
        case ';':
            getNext();
            // SEMICN
            token = Token(Token::SEMICN, lineno);
            break;
        case ',':
            getNext();
            // COMMA
            token = Token(Token::COMMA, lineno);
            break;
        case '(':
            getNext();
            // LPARENT
            token = Token(Token::LPARENT, lineno);
            break;
        case ')':
            getNext();
            // RPARENT
            token = Token(Token::RPARENT, lineno);
            break;
        case '[':
            getNext();
            // LBRACK
            token = Token(Token::LBRACK, lineno);
            break;
        case ']':
            getNext();
            // RBRACK
            token = Token(Token::RBRACK, lineno);
            break;
        case '{':
            getNext();
            // LBRACE
            token = Token(Token::LBRACE, lineno);
            break;
        case '}':
            getNext();
            // RBRACE
            token = Token(Token::RBRACE, lineno);
            break;
        case '\'':
            getNext();
            // CHRCON
            token = Token(Token::CHRCON, lineno);
            getChar(token.content);
            break;
        case '\"':
        {
            // STRCON
            std::stringstream ss;
            do {
                ss << cur_char;
                getNext();
            } while (cur_char != '\"');
            ss << '\"';
            token = Token(Token::STRCON, ss.str(), lineno);
            getNext();
            break;
        }
        case '\n':
        case ' ':
        case '\t':
            getNext();
            next(token);
            break;
        case EOF:
            //EOFTK
            token = Token(Token::EOFTK, lineno);
            break;
        default:
            if (isDigit(cur_char)) {
                // INTCON
                token = Token(Token::INTCON, lineno);
                getNum(token.content);
            } else if (isNondigit(cur_char)){
                // IDENFR or RESERVED
                std::string temp = getIdent();
                auto it = _RESERVED_WORD_TABLE1.find(temp);
                if (it != _RESERVED_WORD_TABLE1.end()) {
                    token = Token(it->second, lineno);
                } else {
                    token = Token(Token::IDENFR, temp, lineno);
                }
            } else {
                // non-idenfied
            }
    }
    return;
}