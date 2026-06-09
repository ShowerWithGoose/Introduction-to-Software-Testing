/**
 * @file InitVal.cpp
 * @brief Initialize value class
 * @version 1.0
 * @date 2024-10-10
 * @Author 
 */

#include "InitVal.h"
#include "../../../token/Token.h"
#include "../../../util/Util.h"
#include "../../Parser.h"
#include "../../expression/unaryexp/Exp.h"

void InitVal::initValParser() {
    tokenItem token = Token::getNowToken();
    if (token.type == "STRCON") {
        token = Token::getNextToken();
    } else if (Parser::isUnaryExp(token)) {
        Exp::expParser();
        token = Token::getNowToken();
    } else if (token.name == "{") {
        token = Token::getNextToken();
        if (Parser::isUnaryExp(token)) {
            Exp::expParser();
            token = Token::getNowToken();
            while (token.name == ",") {
                token = Token::getNextToken();
                Exp::expParser();
                token = Token::getNowToken();
            }
        }
        if (token.name == "}") {
            token = Token::getNextToken();
        }
    }
    Util::printParserInfo("<InitVal>");
}
