/**
 * @file Stmt.h
 * @brief 语句类
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#ifndef COMPILER_STMT_H
#define COMPILER_STMT_H


#include <string>
#include "../../token/Token.h"

class Stmt {
public:
    static void stmtParser();

    static bool isStmt(const tokenItem& token);
};


#endif //COMPILER_STMT_H
