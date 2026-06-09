/**
 * FuncFParams.cpp --  Parse function parameters
 */

#include "FuncFParams.h"
#include "../../token/Token.h"
#include "../../util/Util.h"
#include "../Parser.h"
#include "FuncFParam.h"

void FuncFParams::funcFParamsParser() {
    tokenItem token = Token::getNowToken();
    if(Parser::isBType(token)) {
        FuncFParam::funcFParamParser();
        token = Token::getNowToken();
    }
    token = Token::getNowToken();
    while (token.name == ",") {
        token = Token::getNextToken();
        FuncFParam::funcFParamParser();
        token = Token::getNowToken();
    }
    Util::printParserInfo("<FuncFParams>");
}
