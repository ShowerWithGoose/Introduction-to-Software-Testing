/**
 * @file ConstExp.h
 * @brief 常量表达式类
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#ifndef COMPILER_CONSTEXP_H
#define COMPILER_CONSTEXP_H

#include "../../../token/Token.h"

class ConstExp {
public:
    static void constExpParser();

    bool isConstExp(const tokenItem &token);
};


#endif //COMPILER_CONSTEXP_H
