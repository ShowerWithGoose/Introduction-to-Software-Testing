#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H

#include <string>
#include "LexType.h"

class Token {
private:
    LexType lexType;
    std::string value;
    int lineNum;
    char errorType;

public:
    Token(LexType type = LexType::ERROR, const std::string& val = "", int lineNum = 1, char errorType = '\0')
            : lexType(type), value(val), lineNum(lineNum), errorType(errorType){}

    LexType getType() const { return lexType; }
    std::string getValue() const { return value; }
    int getLineNum() const { return lineNum;}
    char getErrorType() const { return errorType; }

};


#endif //COMPILER_TOKEN_H
