/**
 * File: AddExp.cpp
 * @brief AddExp class
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#include <fstream>
#include "AddExp.h"
#include "MulExp.h"
#include "../../../token/Token.h"
#include "../../../util/Util.h"

void AddExp::addExpParser() {
    MulExp::mulExpParser();
    Util::printParserInfo("<AddExp>");
    tokenItem token = Token::getNowToken();
    while(token.name == "+" || token.name == "-") {
        token = Token::getNextToken();
        MulExp::mulExpParser();
        Util::printParserInfo("<AddExp>");
        token = Token::getNowToken();
    }
}
