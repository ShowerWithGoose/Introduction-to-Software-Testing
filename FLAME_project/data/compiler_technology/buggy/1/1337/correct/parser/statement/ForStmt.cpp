/**
 * File: ForStmt.cpp
 * @brief For statement class
 * @version 1.0
 * @date 2024-10-10
 * @Author 
 */
#include "ForStmt.h"
#include "../../token/Token.h"
#include "../expression/unaryexp/Lval.h"
#include "../expression/unaryexp/Exp.h"
#include "../../util/Util.h"

void ForStmt::forStmtParser() {
    Lval::lvalParser();
    tokenItem token = Token::getNowToken();
    if(token.name == "="){
        token = Token::getNextToken();
    }
    Exp::expParser();
    Util::printParserInfo("<ForStmt>");
}
