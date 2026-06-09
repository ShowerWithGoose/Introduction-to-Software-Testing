/**
 * VarDecl.cpp --  Parse the variable declaration
 * @file VarDecl.cpp
 * @brief Parse the variable declaration
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#include "VarDecl.h"
#include "../../../token/Token.h"
#include "../../../util/Util.h"
#include "../../Parser.h"
#include "VarDef.h"
#include <fstream>

void VarDecl::varDeclParser() {
    tokenItem token = Token::getNowToken();
    if (Parser::isBType(token)) {
        token = Token::getNextToken();
    }
    VarDef::varDefParser();
    token = Token::getNowToken();
    while (token.name == ",") {
        token = Token::getNextToken();
        VarDef::varDefParser();
        token = Token::getNowToken();
    }
    token = Token::getNowToken();
    if (token.name == ";") {
        token = Token::getNextToken();
    } else {
        Util::printErrorInfo(token.lineNum, "i");
    }
    Util::printParserInfo("<VarDecl>");
}
