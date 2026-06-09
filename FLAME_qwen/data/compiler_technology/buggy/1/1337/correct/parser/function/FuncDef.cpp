/**
 * @file FuncDef.cpp
 * @brief FuncDef class implementation file
 * @version 1.0
 * @date 2024-10-10
 * @Author 
 */

#include <fstream>
#include "FuncDef.h"
#include "../../token/Token.h"
#include "../Parser.h"
#include "FuncRParams.h"
#include "../statement/Block.h"
#include "../../util/Util.h"
#include "FuncFParams.h"

void FuncDef::funcDefParser() {
    tokenItem token = Token::getNowToken();
    if (Parser::isFuncType(token)) {
        token = Token::getNextToken();
    }
    Util::printParserInfo("<FuncType>");
    if (token.type == "IDENFR") {
        token = Token::getNextToken();
    }
    if (token.name == "(") {
        token = Token::getNextToken();
        if (Parser::isBType(token)) {
            FuncFParams::funcFParamsParser();
            token = Token::getNowToken();
        }
        token = Token::getNowToken();
        if (token.name == ")") {
            token = Token::getNextToken();
        } else {
            Util::printErrorInfo(token.lineNum, "j");
        }
    }
    Block::blockParser();
    token = Token::getNowToken();
    Util::printParserInfo("<FuncDef>");
}