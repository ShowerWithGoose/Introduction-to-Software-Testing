/**
 * FuncFParam.cpp -- 语法分析器的 FuncFParam 类实现
 */

#include "FuncFParam.h"
#include "../../token/Token.h"
#include "../../util/Util.h"
#include "../Parser.h"

void FuncFParam::funcFParamParser() {
    tokenItem token = Token::getNowToken();
    if(Parser::isBType(token)){
        token = Token::getNextToken();
    }
    if(token.type == "IDENFR"){
        token = Token::getNextToken();
    }
    if(token.name == "["){
        token = Token::getNextToken();
        if(token.name == "]"){
            token = Token::getNextToken();
        }
        else{
            Util::printErrorInfo(token.lineNum, "k");
        }
    }
    Util::printParserInfo("<FuncFParam>");
}
