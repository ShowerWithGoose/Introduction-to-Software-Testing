/**
 *
 */

#include "Number.h"
#include "../../../token/Token.h"
#include "../../../util/Util.h"
#include <fstream>

void Number::numberParser() {
    tokenItem token = Token::getNowToken();
    if(token.type == "INTCON"){
       token = Token::getNextToken();
    }
    Util::printParserInfo("<Number>");
}
