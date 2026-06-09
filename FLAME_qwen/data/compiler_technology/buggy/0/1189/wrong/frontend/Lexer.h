#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <unordered_map>

using namespace std;

enum TokenType {
    IDENFR = 0, // Ident
    INTCON, // IntConst
    STRCON, // StringConst
    CHRCON, // CharConst
    MAINTK, // main
    CONSTTK, //const
    INTTK, //int
    CHARTK, //char
    BREAKTK, //break
    CONTINUETK, //continue
    IFTK, //if
    ELSETK, //else
    FORTK, //for
    GETINTTK, //getint
    GETCHARTK, //getchar
    PRINTFTK, //printf
    RETURNTK, //return
    VOIDTK, //void
    NOT, // !
    AND, // &&
    OR, // ||
    PLUS, // +
    MINU, // -
    MULT, // *
    DIV, // /
    MOD, // %
    LSS, // <
    LEQ, // <=
    GRE, // >
    GEQ, // >=
    EQL, // ==
    NEQ, // !=
    ASSIGN, // =
    SEMICN, // ;
    COMMA, // ,
    LPARENT, // (
    RPARENT, // )
    LBRACK, // [
    RBRACK, // ]
    LBRACE, // {
    RBRACE, // }
};

class Lexer {
    string fileText; // 读入的文件内容
    char Char; // 当前读入的字符
    char LastChar; // 上一个读入的字符
    string Token; // 当前读入的单词
    int curPos; // 当前读入的字符的位置
    TokenType symbol; // 当前读入的单词的类型
    int lineNum; // 当前读入的行数
    unordered_map<string, TokenType> reserves;
    unordered_map<TokenType, string> typeToString;

    int getsym(); // 词法分析
    void getChar(); // 读字符到Char，移动指针
    void clearToken(); // 清空Token
    bool isLetter() const; // 判断是否为字母
    bool isDigit() const; // 判断是否为数字
    void catToken(); // 将当前读入的字符拼接到Token后
    void retract(); // 读字符指针后退一个字符
    int isReserve(); // 判断Token中的字符串是保留字，还是标识符

public:
    explicit Lexer(const string &fileText); // 构造函数
    void lexicalAnalysis(); // 词法分析
};


#endif //LEXER_H
