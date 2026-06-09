/**
 * 工具类
 * @Author:
 * @Date: 2024-10-05
 * @Version: 1.0
 * @Description: 工具类
 */

#include "Util.h"
#include "../token/Token.h"
#include<iostream>
#include<map>
#include <fstream>

//token的map映射
std::map<std::string, std::string> tokenMap = {
        {"Ident",       "IDENFR"},
        {"else",        "ELSETK"},
        {"void",        "VOIDTK"},
        {";",           "SEMICN"},
        {"IntConst",    "INTCON"},
        {"!",           "NOT"},
        {"*",           "MULT"},
        {",",           "COMMA"},
        {"StringConst", "STRCON"},
        {"&&",          "AND"},
        {"/",           "DIV"},
        {"(",           "LPARENT"},
        {"CharConst",   "CHRCON"},
        {"||",          "OR"},
        {"%",           "MOD"},
        {")",           "RPARENT"},
        {"main",        "MAINTK"},
        {"for",         "FORTK"},
        {"<",           "LSS"},
        {"[",           "LBRACK"},
        {"const",       "CONSTTK"},
        {"getint",      "GETINTTK"},
        {"<=",          "LEQ"},
        {"]",           "RBRACK"},
        {"int",         "INTTK"},
        {"getchar",     "GETCHARTK"},
        {">",           "GRE"},
        {"{",           "LBRACE"},
        {"char",        "CHARTK"},
        {"printf",      "PRINTFTK"},
        {">=",          "GEQ"},
        {"}",           "RBRACE"},
        {"break",       "BREAKTK"},
        {"return",      "RETURNTK"},
        {"==",          "EQL"},
        {"continue",    "CONTINUETK"},
        {"+",           "PLUS"},
        {"!=",          "NEQ"},
        {"if",          "IFTK"},
        {"-",           "MINU"},
        {"=",           "ASSIGN"}
};

//是否属于token的组合部分
bool Util::isTokenItem(char c) {
    return isalpha(c) || isdigit(c) || c == '_';
}

//是否是标识符的组成部分
bool Util::isIdentItem(char c) {
    return isalpha(c) || c == '_';
}

// 是运算符
bool Util::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '%' || c == '|' || c == '&'
           || c == '<' || c == '>' || c == '!' || c == '=';
}

//是否是两个运算符的第一个
bool Util::isBinaryOperator(char c) {
    return c == '&' || c == '|' || c == '<' || c == '>' || c == '=';
}

//是否是界符
bool Util::isDelimiter(char c) {
    return c == ',' || c == ';' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}';
}

//是否是单目运算符
bool Util::isUnaryOperator(const std::string &c) {
    return c == "+" || c == "-" || c == "!";
}

void Util::printParserInfo(const char *info) {
    std::ofstream parserFile("parser.txt", std::ios::app);
    parserFile << info << std::endl;
    parserFile.close();
}


void Util::printErrorInfo(int lineNum, const char *error) {
    std::ofstream errorFile("error.txt", std::ios::app);
    errorFile << Token::tokenList[Token::tokenIndex - 1].lineNum << " " << error << std::endl;
    errorFile.close();
}

void Util::clearFile() {
    clearParserInfo();
}

void Util::clearParserInfo() {
    std::ofstream file("parser.txt");
    file.close();
}

void Util::initEnv() {
    createFile();
    clearFile();
    Token::tokenInit();
}

void Util::createFile() {
    //创建输出文件
    std::ofstream lexerFile("lexer.txt");
    std::ofstream errorFile("error.txt");
    std::ofstream parserFile("parser.txt");
}

bool Util::isExistEQL() {
    tokenItem token = Token::getNowToken();
    for (int i = Token::tokenIndex; i < Token::tokenList.size(); i++) {
        if (Token::tokenList[i].name == ";" || Token::tokenList[i].lineNum != token.lineNum) {
            break;
        }
        if (Token::tokenList[i].name == "=") {
            return true;
        }
    }
    return false;
}


