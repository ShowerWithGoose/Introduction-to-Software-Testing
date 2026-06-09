/**
 * Character:
 */

#include <fstream>
#include "Character.h"
#include "../../../token/Token.h"
#include "../../../util/Util.h"

void Character::characterParser() {
    tokenItem token = Token::getNowToken();
    if(token.type == "CHRCON"){
        token = Token::getNextToken();
    }
    Util::printParserInfo("<Character>");
}