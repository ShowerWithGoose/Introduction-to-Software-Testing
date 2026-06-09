/**
 * @file ConstDecl.cpp
 * @brief 常量声明类
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#include "ConstDecl.h"
#include "../../../token/Token.h"
#include "../../Parser.h"
#include "../../def/ConstDef.h"
#include "../../../util/Util.h"

void ConstDecl::constDeclParser() {
    tokenItem token = Token::getNowToken();
    if(token.name == "const"){
        token = Token::getNextToken();
    }
    if(Parser::isBType(token)) {
        token = Token::getNextToken();
    }
    ConstDef::constDefParser();
    token = Token::getNowToken();
    while(token.name == ","){
        token = Token::getNextToken();
        ConstDef::constDefParser();
        token = Token::getNowToken();
    }
    token = Token::getNowToken();
    if(token.name == ";"){
        token = Token::getNextToken();
    }
    else{
        Util::printErrorInfo(token.lineNum, "i");
    }
    Util::printParserInfo("<ConstDecl>");
}
