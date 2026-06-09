#ifndef COMPILER_LEXER_H
#define COMPILER_LEXER_H

#include<string>
#include<vector>

#define STRGETINT "getint"
#define STRGETCHAR "getchar"
#define STRPRINTF "printf"

enum{
    IDENFR=1,INTCON,STRCON,CHRCON,MAINTK,CONSTTK,INTTK,CHARTK,BREAKTK,CONTINUETK,IFTK,
    ELSETK,NOT,AND,OR,FORTK,GETINTTK,GETCHARTK,PRINTFTK,RETURNTK,PLUS,MINU,
    VOIDTK,MULT,DIV,MOD,LSS,LEQ,GRE,GEQ,EQL,NEQ,ASSIGN,
    SEMICN,COMMA,LPARENT,RPARENT,LBRACK,RBRACK,LBRACE,RBRACE,
    MAXCODE
};

struct Word{
    int code,line;
    std::string content;
    Word(int code,int line):code(code),line(line){}
    Word(int code,int line,std::string content):code(code),line(line),content(std::move(content)){}
};

extern std::vector<Word>words;

bool getWords(const char *fn);
bool isWordType(const std::string &str,int type);
void printWord(int code,FILE *fp);
void printWord(int code,const std::string &content,FILE *fp);
bool printWords(const char *fn);

#endif
