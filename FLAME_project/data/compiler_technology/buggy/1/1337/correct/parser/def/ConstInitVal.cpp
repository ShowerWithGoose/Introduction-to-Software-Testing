/**
 *
 */
#include <fstream>
#include "ConstInitVal.h"
#include "../../token/Token.h"
#include "../../util/Util.h"
#include "../expression/unaryexp/ConstExp.h"
#include "../Parser.h"

void ConstInitVal::constInitValParser() {
    tokenItem token = Token::getNowToken();
    if(token.type == "STRCON"){
        token = Token::getNextToken();
    }
    else if(Parser::isUnaryExp(token)){
        ConstExp::constExpParser();
        token = Token::getNowToken();
    }
    else if(token.name == "{"){
        token = Token::getNextToken();
        if(Parser::isUnaryExp(token)){
            ConstExp::constExpParser();
            token = Token::getNowToken();
            while(token.name == ","){
                token = Token::getNextToken();
                ConstExp::constExpParser();
                token = Token::getNowToken();
            }
        }
        token = Token::getNowToken();
        if(token.name == "}"){
            token = Token::getNextToken();
        }
    }
    Util::printParserInfo("<ConstInitVal>");
}
