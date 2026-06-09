/**
 * @file MainFuncDef.cpp
 * @brief 主函数类
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#include "MainFuncDef.h"
#include <iostream>
#include "../../token/Token.h"
#include "../statement/Block.h"
#include "../../util/Util.h"

void MainFuncDef::mainFuncDefParser() {
    tokenItem token = Token::getNowToken();
    if (token.name == "int") {
        token = Token::getNextToken();
    }
    if(token.name == "main"){
        token = Token::getNextToken();
    }
    if (token.name == "(") {
        token = Token::getNextToken();
        if (token.name == ")") {
            token = Token::getNextToken();
        } else {
            Util::printErrorInfo(token.lineNum, "j");
        }
    }
    Block::blockParser();
    Util::printParserInfo("<MainFuncDef>");
}
