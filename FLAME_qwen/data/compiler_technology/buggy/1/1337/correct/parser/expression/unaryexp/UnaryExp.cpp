/**
 * @file UnaryExp.cpp
 * @brief UnaryExp class
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#include "UnaryExp.h"
#include "../../../token/Token.h"
#include "../../../util/Util.h"
#include "../multiexp/PrimaryExp.h"
#include "../../function/FuncRParams.h"
#include "../../Parser.h"
#include<fstream>

void UnaryExp::unaryExpParser() {
    Token::lookAhead(1);
    tokenItem token = Token::getNowToken();
    if(Util::isUnaryOperator(token.name)){
        token = Token::getNextToken();
        Util::printParserInfo("<UnaryOp>");
        UnaryExp::unaryExpParser();
        token = Token::getNowToken();
    }
    else if(token.type == "IDENFR" && Token::lookAheadList[0].name == "("){
        token = Token::getNextToken();
        if(token.name == "("){
            token = Token::getNextToken();
            if(Parser::isUnaryExp(token)){
                FuncRParams::funcRParamsParser();
                token = Token::getNowToken();
            }
            if(token.name == ")"){
                token = Token::getNextToken();
            }
            else{
                Util::printErrorInfo(token.lineNum,"j");
            }
        }
    }
    else{
        PrimaryExp::primaryExpParser();
        token = Token::getNowToken();
    }
    Util::printParserInfo("<UnaryExp>");
}
