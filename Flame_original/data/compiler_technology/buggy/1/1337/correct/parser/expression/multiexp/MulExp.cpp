/**
 * File: MulExp.cpp
 * ----------------
 * This file implements the MulExp.h interface.
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#include <fstream>
#include "MulExp.h"
#include "../../../token/Token.h"
#include "../unaryexp/UnaryExp.h"
#include "../../../util/Util.h"

void MulExp::mulExpParser() {
    UnaryExp::unaryExpParser();
    Util::printParserInfo("<MulExp>");

    tokenItem token = Token::getNowToken();
    while(token.type == "MULT" || token.type == "DIV" || token.type == "MOD") {
        token = Token::getNextToken();
        UnaryExp::unaryExpParser();
        Util::printParserInfo("<MulExp>");
        token = Token::getNowToken();
    }
}
