//
// Created by  on 2024/10/3.
//

#ifndef COMPILER_LEXICALANALYZER_H
#define COMPILER_LEXICALANALYZER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <map>
using namespace std;



// 单词类型枚举类
enum LexType {
    ILLEGAL,            // 非法字符
    FINISH,             // 文件结尾

    IDENFR,       // Ident
    INTCON,       // IntConst
    STRCON,       // StringConst
    CHRCON,       // CharConst

    // 关键字
    MAINTK,       // main
    CONSTTK,      // const
    INTTK,        // int
    CHARTK,       // char
    BREAKTK,      // break
    CONTINUETK,   // continue
    IFTK,         // if
    ELSETK,       // else
    FORTK,        // for
    VOIDTK,       // void
    GETINTTK,     // getint
    GETCHARTK,    // getchar
    PRINTFTK,     // printf
    RETURNTK,     // return

    // 运算符和分隔符
    NOT,          // !
    AND,          // &&
    OR,           // ||
    MULT,         // *
    DIV,          // /
    MOD,          // %
    LSS,          // <
    LEQ,          // <=
    GRE,          // >
    GEQ,          // >=
    EQL,          // ==
    NEQ,          // !=
    ASSIGN,       // =
    PLUS,         // +
    MINU,         // -

    // 界符
    LPARENT,      // (
    RPARENT,      // )
    LBRACK,       // [
    RBRACK,       // ]
    LBRACE,       // {
    RBRACE,       // }
    SEMICN,       // ;
    COMMA         // ,
};

// 词法分析器类（单例模式）
class Lexer {
public:
    static Lexer &getInstance(ifstream &input, ofstream &output, ofstream &errorFile);
    // 禁止复制构造
    Lexer(const Lexer &) = delete;
    // 禁止赋值操作
    void operator=(const Lexer &) = delete;

    void next();//处理下一个单词
    string getToken();//获得读取的单词值
    string getLexType1();//获得读取的单词类型
    LexType getLexType();

private:
    string source;                // 源程序字符串
    ifstream &sourceFile;  // 输入文件流
    ofstream &outputFile;  // 输出文件流
    ofstream &errorFile;   // 错误文件流
    size_t curPos;                // 当前字符串位置指针
    struct Token {
        string *symbol;
        int number;
        bool isNumber; // 表示当前值是数字
    }token;

    LexType lexType;              // 解析出的单词类型
    //unordered_map <string, LexType> reserveWords; // 保留字表
    //int lineNum;                  // 当前行号

    // 私有构造函数，单例模式
    Lexer(ifstream &input, ofstream &output, ofstream &errorFile);
    // 错误报告
    void reportError(int line, string errStr);
};


#endif //COMPILER_LEXICALANALYZER_H
