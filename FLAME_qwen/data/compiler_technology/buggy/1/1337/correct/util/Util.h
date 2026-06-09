/**
 * Util.h
 * 工具类的头文件
 * @Author
 * @Date 2021-10-03
 * @Version 1.0
 */

#ifndef COMPILER_UTIL_H
#define COMPILER_UTIL_H


#include <string>

class Util {
public:

    static bool isIdentItem(char c);

    static bool isOperator(char c);

    static bool isBinaryOperator(char c);

    static bool isDelimiter(char c);

    static bool isTokenItem(char c);

    static bool isUnaryOperator(const std::string& c);

    static void printParserInfo(const char *info);

    static void printErrorInfo(int lineNum, const char *error);

    static void clearFile();
    static void clearParserInfo();

    static void initEnv();

    static void createFile();

    static void releaseEnv();

    static bool isExistEQL();
};

#endif //COMPILER_UTIL_H
