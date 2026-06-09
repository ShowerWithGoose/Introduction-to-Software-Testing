/**
 * @file Block.cpp
 * @brief 块语句类
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#include<iostream>
#include "Block.h"
#include "BlockItem.h"
#include "Stmt.h"
#include "../declaration/Decl.h"
#include "../../util/Util.h"

void Block::blockParser() {
    tokenItem token = Token::getNowToken();
    if (token.name == "{") {
        token = Token::getNextToken();
    }
    while(isBlockItem(token)){
        BlockItem::blockItemParser();
        token = Token::getNowToken();
    }
    token = Token::getNowToken();
    if(token.name == "}"){
        token = Token::getNextToken();
    }
    Util::printParserInfo("<Block>");
}

bool Block::isBlockItem(const tokenItem& token) {
    return Decl::isDecl(token) || Stmt::isStmt(token);
}