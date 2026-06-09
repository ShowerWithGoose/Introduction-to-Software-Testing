#ifndef COMPILER_TOOLS_H
#define COMPILER_TOOLS_H
#include <iostream>
#include <fstream>
#include <memory>
//Lexer

enum class ErrorType{
    a,b,c,d,e,f,g,h,i,j,k,l,m
};
void error(ErrorType e,int line, std::ofstream &err);
enum Symbol{
    IDENFR,         // 标识符
    INTCON,         // 数字常量
    STRCON,         // 字符串常量
    CHRCON,         // 字符常量
    MAINTK,         // main
    CONSTTK,        // const
    INTTK,          // int
    CHARTK,         // char
    BREAKTK,        // break
    CONTINUETK,     // continue
    IFTK,           // if
    ELSETK,         // else
    NOT,            // !
    AND,            // &&
    OR,             // ||
    FORTK,          // for
    GETINTTK,       // getint
    GETCHARTK,      // getchar
    PRINTFTK,       // printf
    RETURNTK,       // return
    PLUS,           // +
    MINU,           // -
    VOIDTK,         // void
    MULT,           // *
    DIV,            // /
    MOD,            // %
    LSS,            // <
    LEQ,            // <=
    GRE,            // >
    GEQ,            // >=
    EQL,            // ==
    NEQ,            // !=
    ASSIGN,         // =
    SEMICN,         // ;
    COMMA,          // ,
    LPARENT,        // (
    RPARENT,        // )
    LBRACK,         // [
    RBRACK,         // ]
    LBRACE,         // {
    RBRACE          // }
};
extern const char* SymbolStrings[];
struct Token{
    Symbol type;
    std::string value;
};
class Lexer{
public:
    Lexer(std::string in,std::string out,std::string err_out);
    int isSpace();
    int isNewline();
    int isTab();
    int isLetter();
    int isDigit();
    int isComma();
    int isSemi();
    int isNot();
    int isSingleAnd();
    int isSingleOr();
    int isPlus();
    int isMinus();
    int isDivi();
    int isMod();
    int isStar();
    int isLess();
    int isGreater();
    int isEqu();
    int isLpar();
    int isRpar();
    int isLbrack();
    int isRbrack();
    int isUnderLine();
    int isLbrace();
    int isRbrace();
    void retract();
    Symbol reserver();
    void cleanStr();
    void catStr();
    int getToken();
    int tranNum();
    void myGetchar();
    void outputToken();
    void closeStream();
    void closeOutput();
    void openOutput();
    void startPeeking();
    void finishPeeking();
    void errorOutput(ErrorType,int);
    std::ifstream input;
    std::ofstream output;
    std::ofstream err_output;
    Token token;
    int line;
    int tLine;          //前一个非终结符行号
    bool isPeeking;
private:
    char t_char;
    std::string t_string;
    bool isOutput;
    int peekingNum;
    int num;
};




#endif //COMPILER_TOOLS_H
