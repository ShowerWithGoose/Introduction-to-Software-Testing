/**
 * File: ConstExp.cpp
 * @brief 常量表达式类
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */

#include "ConstExp.h"
#include "../multiexp/AddExp.h"
#include "../../../util/Util.h"

void ConstExp::constExpParser() {
    AddExp::addExpParser();
    Util::printParserInfo("<ConstExp>");
}