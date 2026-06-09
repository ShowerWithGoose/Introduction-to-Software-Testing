/**
 * @file PrimaryExp.cpp
 * @brief PrimaryExp class
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#include "PrimaryExp.h"
#include "../unaryexp/Number.h"
#include "../unaryexp/Character.h"
#include "../unaryexp/Lval.h"
#include "../unaryexp/Exp.h"
#include "../../../util/Util.h"

void PrimaryExp::primaryExpParser() {
    tokenItem token = Token::getNowToken();
    if(token.type == "INTCON"){
        Number::numberParser();
        token = Token::getNowToken();
    }
    else if(token.type == "CHRCON"){
        Character::characterParser();
        token = Token::getNowToken();
    }
    else if(token.type == "IDENFR"){
        Lval::lvalParser();
        token = Token::getNowToken();
    }
    else if(token.name == "("){
        token = Token::getNextToken();
        Exp::expParser();
        token = Token::getNowToken();
        if(token.name == ")"){
            token = Token::getNextToken();
        }
        else{
            Util::printErrorInfo(token.lineNum, "j");
        }
    }
    Util::printParserInfo("<PrimaryExp>");
}

bool PrimaryExp::isPrimaryExp(const tokenItem &token) {
    return token.name == "(" ;
}
