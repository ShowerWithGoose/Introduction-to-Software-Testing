/**
 * @file Stmt.cpp
 * @brief 语句类
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#include "Stmt.h"
#include "../../util/Util.h"
#include "Block.h"
#include "../expression/unaryexp/Cond.h"
#include "ForStmt.h"
#include "../Parser.h"
#include "../expression/unaryexp/Exp.h"
#include "../expression/unaryexp/Lval.h"

void Stmt::stmtParser() {
    tokenItem token = Token::getNowToken();
    Token::lookAhead(1);
    if (token.name == "{") {
        Block::blockParser();
        token = Token::getNowToken();
    } else if (token.name == ";") {
        token = Token::getNextToken();
    } else if (token.type == "IFTK") {
        token = Token::getNextToken();
        if (token.name == "(") {
            token = Token::getNextToken();
            Cond::condParser();
            token = Token::getNowToken();
            if (token.name == ")") {
                token = Token::getNextToken();
            } else {
                Util::printErrorInfo(token.lineNum, "j");
            }
            Stmt::stmtParser();
            token = Token::getNowToken();
            if (token.type == "ELSETK") {
                token = Token::getNextToken();
                Stmt::stmtParser();
                token = Token::getNowToken();
            }
        }
    } else if (token.type == "FORTK") {
        token = Token::getNextToken();
        if (token.name == "(") {
            token = Token::getNextToken();
        }
        if (token.type == "IDENFR") {
            ForStmt::forStmtParser();
            token = Token::getNowToken();
        }
        if (token.name == ";") {
            token = Token::getNextToken();
        }
        if (Parser::isUnaryExp(token)) {
            Cond::condParser();
            token = Token::getNowToken();
        }
        if (token.name == ";") {
            token = Token::getNextToken();
        }
        if (token.type == "IDENFR") {
            ForStmt::forStmtParser();
            token = Token::getNowToken();
        }
        if (token.name == ")") {
            token = Token::getNextToken();
        }
        Stmt::stmtParser();
    } else if (token.type == "BREAKTK" || token.type == "CONTINUETK") {
        token = Token::getNextToken();
        if (token.name == ";") {
            token = Token::getNextToken();
        } else {
            Util::printErrorInfo(token.lineNum, "i");
        }
    } else if (token.name == "return") {
        token = Token::getNextToken();
        if (Parser::isUnaryExp(token)) {
            Exp::expParser();
            token = Token::getNowToken();
        }
        token = Token::getNowToken();
        if (token.name == ";") {
            token = Token::getNextToken();
        } else {
            Util::printErrorInfo(token.lineNum, "i");
        }
    } else if (token.name == "printf") {
        token = Token::getNextToken();
        if (token.name == "(") {
            token = Token::getNextToken();
            if (token.type == "STRCON") {
                token = Token::getNextToken();
            }
            while (token.name == ",") {
                token = Token::getNextToken();
                Exp::expParser();
                token = Token::getNowToken();
            }
            if (token.name == ")") {
                token = Token::getNextToken();
            } else {
                Util::printErrorInfo(token.lineNum, "j");
            }
        }
        if (token.name == ";") {
            token = Token::getNextToken();
        } else {
            Util::printErrorInfo(token.lineNum, "i");
        }
    } else if (token.type == "IDENFR" && Token::lookAheadList[0].name != "(" && Util::isExistEQL()) {
        Lval::lvalParser();
        token = Token::getNowToken();
        if (token.name == "=") {
            token = Token::getNextToken();
        }
        if (token.type == "GETINTTK" || token.type == "GETCHARTK") {
            token = Token::getNextToken();
            if (token.name == "(") {
                token = Token::getNextToken();
            }
            if (token.name == ")") {
                token = Token::getNextToken();
            } else {
                Util::printErrorInfo(token.lineNum, "j");
            }
        }
        else if (Parser::isUnaryExp(Token::getNowToken())) {
            Exp::expParser();
            token = Token::getNowToken();
        }
        token = Token::getNowToken();
        if (token.name == ";") {
            token = Token::getNextToken();
        } else {
            Util::printErrorInfo(token.lineNum, "i");
        }
    } else {
        Exp::expParser();
        token = Token::getNowToken();
        if (token.name == ";") {
            token = Token::getNextToken();
        } else {
            Util::printErrorInfo(token.lineNum, "i");
        }
    }
    Util::printParserInfo("<Stmt>");
}

bool Stmt::isStmt(const tokenItem &token) {
    std::string type = token.type;
    return type == "IDENFR" || type == "IFTK" || type == "FORTK" || type == "BREAKTK" ||
           type == "CONTINUETK" || type == "RETURNTK" || type == "PRINTFTK"
           || token.name == "{" || token.name == ";" || Parser::isUnaryExp(token);
}
