/**
 * @file Exp.cpp
 * @brief Exp class
 * @version 1.0
 * @date 2024-10-03
 * @Author 
 */
#include "Exp.h"
#include "../multiexp/AddExp.h"
#include "../../../util/Util.h"

void Exp::expParser() {
    AddExp::addExpParser();
    Util::printParserInfo("<Exp>");
}

