/**
 * Lval.cpp
 * @brief Lval class
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#include <fstream>
#include "Lval.h"
#include "../../../token/Token.h"
#include "Exp.h"
#include "../../../util/Util.h"

void Lval::lvalParser() {
    tokenItem token = Token::getNowToken();
    if (token.type == "IDENFR") {
        token = Token::getNextToken();
    }
    if (token.name == "[") {
        token = Token::getNextToken();
        Exp::expParser();
        token = Token::getNowToken();
        if (token.name == "]") {
            token = Token::getNextToken();
        } else {
            Util::printErrorInfo(token.lineNum, "k");
        }
    }
    Util::printParserInfo("<LVal>");
}
