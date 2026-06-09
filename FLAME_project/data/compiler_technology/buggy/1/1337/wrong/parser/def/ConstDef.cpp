/**
 * ConstDef.cpp -- Parse const definition
 *
 */

#include "ConstDef.h"
#include "../../token/Token.h"
#include "../expression/unaryexp/ConstExp.h"
#include "../../util/Util.h"
#include "ConstInitVal.h"

void ConstDef::constDefParser() {
    tokenItem token = Token::getNowToken();
    if(token.type == "IDENFR"){
        token = Token::getNextToken();
    }
    if(token.name == "["){
        token = Token::getNextToken();
        ConstExp::constExpParser();
        token = Token::getNowToken();
        if(token.name == "]"){
            token = Token::getNextToken();
        }
        else{
            Util::printErrorInfo(token.lineNum,"k");
        }
    }
    token = Token::getNowToken();
    if(token.name == "="){
        token = Token::getNextToken();
    }
    ConstInitVal::constInitValParser();
    Util::printParserInfo("<ConstDef>");
}
