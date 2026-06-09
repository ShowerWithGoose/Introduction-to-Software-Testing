/**
 * File: VarDef.cpp
 * @brief 变量定义类
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#include "VarDef.h"
#include "../../Parser.h"
#include "../../expression/unaryexp/ConstExp.h"
#include "../../../util/Util.h"
#include "InitVal.h"

void VarDef::varDefParser() {
    tokenItem token = Token::getNowToken();
    if (token.type == "IDENFR") {
        token = Token::getNextToken();
    }
    if (token.name == "[") {
        token = Token::getNextToken();
        ConstExp::constExpParser();
        token = Token::getNowToken();
        if (token.name == "]") {
            token = Token::getNextToken();
        } else {
            Util::printErrorInfo(token.lineNum, "k");
        }
    }
    if(token.name == "="){
        token = Token::getNextToken();
        InitVal::initValParser();
    }
    Util::printParserInfo("<VarDef>");
}
