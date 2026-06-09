/**
 * @Author:
 * @Version: 1.0
 * @Date: 2024-10-03
 */

#include <fstream>
#include "LAndExp.h"
#include "EqExp.h"
#include "../../../token/Token.h"
#include "../../../util/Util.h"

void LAndExp::lAndExpParser() {
    EqExp::eqExpParser();
    Util::printParserInfo("<LAndExp>");
    tokenItem token = Token::getNowToken();
    while (token.type == "AND") {
        token = Token::getNextToken();
        EqExp::eqExpParser();
        Util::printParserInfo("<LAndExp>");
        token = Token::getNowToken();
    }
}
