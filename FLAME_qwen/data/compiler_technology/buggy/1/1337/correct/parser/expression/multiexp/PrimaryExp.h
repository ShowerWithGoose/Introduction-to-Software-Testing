/**
 * @file PrimaryExp.h
 * @brief PrimaryExp class
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#ifndef COMPILER_PRIMARYEXP_H
#define COMPILER_PRIMARYEXP_H


#include "../../../token/Token.h"

class PrimaryExp {
public:
    static void primaryExpParser();
    static bool isPrimaryExp(const tokenItem& token);
};


#endif //COMPILER_PRIMARYEXP_H
