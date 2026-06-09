#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring> 
#include <map>
#include <bits/stdc++.h>
#include "utils.h"
#include "type.h"
#include "parser.h"
#include "symbol.h"
using namespace std;
char *now;
string token;
char inn[2000];
ifstream file;
bool endFlag,errorFlag;
map<string, string>idenp={
    {"Ident", "IDENFR"},
    {"else", "ELSETK"},
    {"void", "VOIDTK"},
    {";", "SEMICN"},
    {"IntConst", "INTCON"},
    {"!", "NOT"},
    {"*", "MULT"},
    {",", "COMMA"},
    {"StringConst", "STRCON"},
    {"&&", "AND"},
    {"/", "DIV"},
    {"(", "LPARENT"},
    {"CharConst", "CHRCON"},
    {"||", "OR"},
    {"%", "MOD"},
    {")", "RPARENT"},
    {"main", "MAINTK"},
    {"for", "FORTK"},
    {"<", "LSS"},
    {"[", "LBRACK"},
    {"const", "CONSTTK"},
    {"getint", "GETINTTK"},
    {"<=", "LEQ"},
    {"]", "RBRACK"},
    {"int", "INTTK"},
    {"getchar", "GETCHARTK"},
    {">", "GRE"},
    {"{", "LBRACE"},
    {"char", "CHARTK"},
    {"printf", "PRINTFTK"},
    {">=", "GEQ"},
    {"}", "RBRACE"},
    {"break", "BREAKTK"},
    {"return", "RETURNTK"},
    {"==", "EQL"},
    {"continue", "CONTINUETK"},
    {"+", "PLUS"},
    {"!=", "NEQ"},
    {"if", "IFTK"},
    {"-", "MINU"},
    {"=", "ASSIGN"}
};
TOKEN token_ans[100086];
ERROR error_ans[100086];
int anscnt,error_cnt;
int lineNum;
bool isUnderline(char *now){return (*now)=='_';}
bool isAnd(char *now){return (*now)=='&';}
bool isOr(char *now){return (*now)=='|';}
bool isString(char *now){return (*now)=='"';}
bool isChar(char *now){return (*now)=='\'';}
bool isNot(char *now){return (*now)=='!';}
bool isPlus(char *now){return (*now)=='+';}
bool isMinus(char *now){return (*now)=='-';}
bool isMult(char *now){return (*now)=='*';}
bool isDiv(char *now){return (*now)=='/';}
bool isMod(char *now){return (*now)=='%';}
bool isLss(char *now){return (*now)=='<';}
bool isGre(char *now){return (*now)=='>';}
bool isAssign(char *now){return (*now)=='=';}
bool isSemicn(char *now){return (*now)==';';}
bool isComma(char *now) { return (*now) == ','; }        // COMMA
bool isLparent(char *now) { return (*now) == '('; }     // LPARENT
bool isRparent(char *now) { return (*now) == ')'; }     // RPARENT
bool isLbrack(char *now) { return (*now) == '['; }      // LBRACK
bool isRbrack(char *now) { return (*now) == ']'; }      // RBRACK
bool isLbrace(char *now) { return (*now) == '{'; }      // LBRACE
bool isRbrace(char *now) { return (*now) == '}'; }      // RBRACE

bool isSpace(char *now){return (*now)==' ';};
bool isNewline(char *now){return (*now)=='\n';}
bool isTab(char *now){return (*now)=='\t';}
bool isEmpty(char *now){return (*now)=='\0';}
bool isLetter(char *now){
    // 获取当前字符
    char ch = *now;
    // 检查字符是否为字母
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}
bool isDigit(char *now){return '0'<=(*now) && (*now)<='9';}

void catToken(){
    token.push_back(*now);
}
int readNextLine() {
    if (file.getline(inn, 2000)) {
        //inn[strcspn(inn, "\n")] = 0; // 去掉换行符
        now = inn; // 重置指针到行的开头
        lineNum++;
        return 0;
    } else {
        //inn[0] = '\0'; // 如果没有更多行，设置为空字符串
        //now = inn; // 重置指针
        return -1;
    }
}
int isNewLine;
void getc() {
    if (*now != '\0' && *now!='\r') {
        *now++; // 返回当前字符并移动指针
    }
    //
    while(*now == '\0' || *now=='\r' || *now=='\n'){
        isNewLine=1;
        if(readNextLine()==-1){
            endFlag=1;
            break;
        }
    }
}
void retract(){if(now!=inn)*now--;}
string reserver(){
    auto it = idenp.find(token);
    if (it == idenp.end())return "IDENFR";
    return idenp[token];
}
void error(int lNum,string typ){
    //string content = 
    error_ans[++error_cnt]=ERROR{lNum,typ};
    //write("error.txt",to_string(lNum));
    //write("error.txt"," "+typ+"\n");
}
bool compareByLine(const ERROR &a, const ERROR &b) {
    return a.line < b.line; // 从小到大排序
}
void print_error(){
    sort(error_ans+1, error_ans+error_cnt+1, compareByLine);

    for(int i=1;i<=error_cnt;i++){
        write("error.txt",to_string(error_ans[i].line));
        write("error.txt"," "+error_ans[i].type+"\n");
    }
}

int getsym(){
    token.clear();
    while(isSpace(now) || isNewline(now) || isTab(now) || isEmpty(now)|| *now=='\r'){
        getc();
        if(endFlag)break;
    }
    if(endFlag)return 0;
    if(isLetter(now) || isUnderline(now)){
        isNewLine=0;
        while(isLetter(now) || isDigit(now) || isUnderline(now)){
            catToken();
            getc();
            if(isNewLine)break;
            if(endFlag)break;
        }
        token_ans[++anscnt]=TOKEN{token,reserver(),lineNum-isNewLine};
    }else if (isDigit(now)){
        isNewLine=0;
        while(isDigit(now)){
            catToken();
            getc();
            if(isNewLine)break;
        }
        token_ans[++anscnt]=TOKEN{token,"INTCON",lineNum-isNewLine};
    }else if(isString(now)){
        do{
            catToken();
            getc();
            if(endFlag)break;
        }while(!isString(now));
        catToken();
        getc();
        token_ans[++anscnt]=TOKEN{token,"STRCON",lineNum};
    }else if (isChar(now)){
        catToken();//'
        getc();
        catToken();
        if(*now=='\\'){
            getc();
            catToken();
        }
        getc();
        catToken();//'
        getc();
        token_ans[++anscnt]=TOKEN{token,"CHRCON",lineNum};
    }else if(isAnd(now)){
        catToken();
        getc();
        if(isAnd(now)){
            catToken();
            getc();
            token_ans[++anscnt]=TOKEN{token,"AND",lineNum};
        }else {
            error(lineNum,"a");
            token_ans[++anscnt]=TOKEN{token+"&","AND",lineNum};
            return -1;
        }
    }else if(isOr(now)){
        catToken();
        getc();
        if(isOr(now)){
            catToken();
            getc();
            token_ans[++anscnt]=TOKEN{token,"OR",lineNum};
        }else {
            error(lineNum,"a");
            token_ans[++anscnt]=TOKEN{token+"|","OR",lineNum};
            return -1;
        }
    }
    else if(isNot(now)){
        catToken();
        getc();
        if(isAssign(now)){
            catToken();
            getc();
            token_ans[++anscnt]=TOKEN{token,"NEQ",lineNum};
        }else token_ans[++anscnt]=TOKEN{token,"NOT",lineNum};
    }else if(isLss(now)){ 
        catToken();
        getc(); 
        if(isAssign(now)){
            catToken();
            getc();
            token_ans[++anscnt]=TOKEN{token,"LEQ",lineNum};
        }else token_ans[++anscnt] = TOKEN{token, "LSS",lineNum}; 
    }else if(isGre(now)){ 
        catToken(); 
        getc(); 
        if(isAssign(now)){
            catToken();
            getc();
            token_ans[++anscnt]=TOKEN{token,"GEQ",lineNum};
        }else token_ans[++anscnt] = TOKEN{token, "GRE",lineNum};
    }else if(isAssign(now)){ 
        catToken(); 
        getc(); 
        if(isAssign(now)){
            catToken();
            getc();
            token_ans[++anscnt]=TOKEN{token,"EQL",lineNum};
        }else token_ans[++anscnt] = TOKEN{token, "ASSIGN",lineNum}; 
    }else if(isDiv(now)){ 
        catToken(); 
        getc(); 
        if(isDiv(now)){
            if(readNextLine()==-1)endFlag=-1;
            return 0;
        }else if(isMult(now)){
            while(1){
                getc();
                if(isMult(now)){
                    getc();
                    if(isDiv(now)){
                        getc();
                        return 0;
                    }
                    if(now!=inn)retract();
                }
                if(endFlag)break;
            }
        }else token_ans[++anscnt] = TOKEN{token, "DIV"}; 
    }
    else if(isPlus(now)){catToken();token_ans[++anscnt]=TOKEN{token,"PLUS",lineNum};getc();}
    else if(isMinus(now)){catToken();token_ans[++anscnt]=TOKEN{token,"MINU",lineNum};getc();}
    else if(isMult(now)){ catToken(); token_ans[++anscnt] = TOKEN{token, "MULT",lineNum}; getc(); }
    else if(isMod(now)){ catToken(); token_ans[++anscnt] = TOKEN{token, "MOD",lineNum}; getc(); }
    else if(isSemicn(now)){ catToken(); token_ans[++anscnt] = TOKEN{token, "SEMICN",lineNum}; getc(); }
    else if(isComma(now)){ catToken(); token_ans[++anscnt] = TOKEN{token, "COMMA",lineNum}; getc(); }
    else if(isLparent(now)){ catToken(); token_ans[++anscnt] = TOKEN{token, "LPARENT",lineNum}; getc(); }
    else if(isRparent(now)){ catToken(); token_ans[++anscnt] = TOKEN{token, "RPARENT",lineNum}; getc(); }
    else if(isLbrack(now)){ catToken(); token_ans[++anscnt] = TOKEN{token, "LBRACK",lineNum}; getc(); }
    else if(isRbrack(now)){ catToken(); token_ans[++anscnt] = TOKEN{token, "RBRACK",lineNum}; getc(); }
    else if(isLbrace(now)){ catToken(); token_ans[++anscnt] = TOKEN{token, "LBRACE",lineNum}; getc(); }
    else if(isRbrace(now)){ catToken(); token_ans[++anscnt] = TOKEN{token, "RBRACE",lineNum}; getc(); }
    else error(lineNum,"a");
    return 0;
}
int main(){
    file.open("testfile.txt");
    if(readNextLine()==-1)endFlag=1;
    while(!endFlag){
        if(getsym()==-1)errorFlag=1;
    }
    //for(int i=0;i<30;i++)getsym();
    //if(!errorFlag)
    for(int i=1;i<=anscnt;i++)write("lexer.txt",token_ans[i].sym+" "+token_ans[i].ori+" "+to_string(token_ans[i].line)+"\n");//
    
    CompUnit(0);
    print_tree(0);

    //CompUnitError();
    //print_symbol();

    print_error();

    file.close();
    return 0;
}