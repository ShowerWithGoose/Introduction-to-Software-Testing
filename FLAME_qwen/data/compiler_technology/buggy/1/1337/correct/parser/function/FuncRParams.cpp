/**
 * @file FuncRParams.cpp
 * @brief FuncRParams class
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#include "FuncRParams.h"
#include "../../token/Token.h"
#include "../../util/Util.h"
#include "../expression/unaryexp/Exp.h"
#include <iostream>

void FuncRParams::funcRParamsParser() {
    Exp::expParser();
    tokenItem token = Token::getNowToken();
    while (token.name == ",") {
        token = Token::getNextToken();
        Exp::expParser();
        token = Token::getNowToken();
    }
    Util::printParserInfo("<FuncRParams>");
}
