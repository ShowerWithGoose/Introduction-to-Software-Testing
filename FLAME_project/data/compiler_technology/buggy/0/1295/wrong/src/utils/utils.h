//
// Created by  on 2024/10/1.
//

#ifndef SYS_COMPILER_UTILS_H
#define SYS_COMPILER_UTILS_H

#include <fstream>
#include <iostream>
#include <vector>

// 判断是否是数字
bool isDigit(char s);

// 判断是否是组成C语言标识符的字符
bool isIdentifierChar(char ch);

// 读入文件内容至字符串
std::string readFileToString(const std::string& filename);

#endif //SYS_COMPILER_UTILS_H
