#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring> 
#include <map>
#include <bits/stdc++.h>
using namespace std;
void write(string fileName, string content) {
    // 打开文件以写入
    ofstream outfile(fileName, std::ios::app);
    
    // 检查文件是否成功打开

    // 将字符数组写入文件
    outfile << content;
    // 关闭文件
    outfile.close();
}
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
struct TOKEN{
    string ori,sym;
}ans[100086];
int anscnt;
int lineNum;
bool isUnderline(){return (*now)=='_';}
bool isAnd(){return (*now)=='&';}
bool isOr(){return (*now)=='|';}
bool isString(){return (*now)=='"';}
bool isChar(){return (*now)=='\'';}
bool isNot(){return (*now)=='!';}
bool isPlus(){return (*now)=='+';}
bool isMinus(){return (*now)=='-';}
bool isMult(){return (*now)=='*';}
bool isDiv(){return (*now)=='/';}
bool isMod(){return (*now)=='%';}
bool isLss(){return (*now)=='<';}
bool isGre(){return (*now)=='>';}
bool isAssign(){return (*now)=='=';}
bool isSemicn(){return (*now)==';';}
bool isComma() { return (*now) == ','; }        // COMMA
bool isLparent() { return (*now) == '('; }     // LPARENT
bool isRparent() { return (*now) == ')'; }     // RPARENT
bool isLbrack() { return (*now) == '['; }      // LBRACK
bool isRbrack() { return (*now) == ']'; }      // RBRACK
bool isLbrace() { return (*now) == '{'; }      // LBRACE
bool isRbrace() { return (*now) == '}'; }      // RBRACE

bool isSpace(){return (*now)==' ';};
bool isNewline(){return (*now)=='\n';}
bool isTab(){return (*now)=='\t';}
bool isEmpty(){return (*now)=='\0';}
bool isLetter(){
    // 获取当前字符
    char ch = *now;
    // 检查字符是否为字母
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}
bool isDigit(){return '0'<=(*now) && (*now)<='9';}
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
void getc() {
    if (*now != '\0') {
        *now++; // 返回当前字符并移动指针
    }
    while(*now == '\0'){
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
    write("error.txt",to_string(lNum));
    write("error.txt"," "+typ+"\n");
}
int getsym(){
    token.clear();
    while(isSpace() || isNewline() || isTab() || isEmpty()){
        getc();
        if(endFlag)break;
    }
    if(endFlag)return 0;
    if(isLetter() || isUnderline()){
        while(isLetter() || isDigit() || isUnderline()){
            catToken();
            getc();
            if(endFlag)break;
        }
        ans[++anscnt]=TOKEN{token,reserver()};
    }else if (isDigit()){
        while(isDigit()){catToken();getc();}
        ans[++anscnt]=TOKEN{token,"INTCON"};
    }else if(isString()){
        do{
            catToken();
            getc();
            if(endFlag)break;
        }while(!isString());
        catToken();
        getc();
        ans[++anscnt]=TOKEN{token,"STRCON"};
    }else if (isChar()){
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
        ans[++anscnt]=TOKEN{token,"CHRCON"};
    }else if(isAnd()){
        catToken();
        getc();
        if(isAnd()){
            catToken();
            getc();
            ans[++anscnt]=TOKEN{token,"AND"};
        }else {
            error(lineNum,"a");
            return -1;
        }
    }else if(isOr()){
        catToken();
        getc();
        if(isOr()){
            catToken();
            getc();
            ans[++anscnt]=TOKEN{token,"OR"};
        }else {
            error(lineNum,"a");
            return -1;
        }
    }
    else if(isNot()){
        catToken();
        getc();
        if(isAssign()){
            catToken();
            getc();
            ans[++anscnt]=TOKEN{token,"NEQ"};
        }else ans[++anscnt]=TOKEN{token,"NOT"};
    }else if(isLss()){ 
        catToken();
        getc(); 
        if(isAssign()){
            catToken();
            getc();
            ans[++anscnt]=TOKEN{token,"LEQ"};
        }else ans[++anscnt] = TOKEN{token, "LSS"}; 
    }else if(isGre()){ 
        catToken(); 
        getc(); 
        if(isAssign()){
            catToken();
            getc();
            ans[++anscnt]=TOKEN{token,"GEQ"};
        }else ans[++anscnt] = TOKEN{token, "GRE"};
    }else if(isAssign()){ 
        catToken(); 
        getc(); 
        if(isAssign()){
            catToken();
            getc();
            ans[++anscnt]=TOKEN{token,"EQL"};
        }else ans[++anscnt] = TOKEN{token, "ASSIGN"}; 
    }else if(isDiv()){ 
        catToken(); 
        getc(); 
        if(isDiv()){
            if(readNextLine()==-1)endFlag=-1;
            return 0;
        }else if(isMult()){
            while(1){
                getc();
                if(isMult()){
                    getc();
                    if(isDiv()){
                        getc();
                        return 0;
                    }
                    if(now!=inn)retract();
                }
                if(endFlag)break;
            }
        }else ans[++anscnt] = TOKEN{token, "DIV"}; 
    }
    else if(isPlus()){catToken();ans[++anscnt]=TOKEN{token,"PLUS"};getc();}
    else if(isMinus()){catToken();ans[++anscnt]=TOKEN{token,"MINU"};getc();}
    else if(isMult()){ catToken(); ans[++anscnt] = TOKEN{token, "MULT"}; getc(); }
    else if(isMod()){ catToken(); ans[++anscnt] = TOKEN{token, "MOD"}; getc(); }
    else if(isSemicn()){ catToken(); ans[++anscnt] = TOKEN{token, "SEMICN"}; getc(); }
    else if(isComma()){ catToken(); ans[++anscnt] = TOKEN{token, "COMMA"}; getc(); }
    else if(isLparent()){ catToken(); ans[++anscnt] = TOKEN{token, "LPARENT"}; getc(); }
    else if(isRparent()){ catToken(); ans[++anscnt] = TOKEN{token, "RPARENT"}; getc(); }
    else if(isLbrack()){ catToken(); ans[++anscnt] = TOKEN{token, "LBRACK"}; getc(); }
    else if(isRbrack()){ catToken(); ans[++anscnt] = TOKEN{token, "RBRACK"}; getc(); }
    else if(isLbrace()){ catToken(); ans[++anscnt] = TOKEN{token, "LBRACE"}; getc(); }
    else if(isRbrace()){ catToken(); ans[++anscnt] = TOKEN{token, "RBRACE"}; getc(); }
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
    if(!errorFlag)for(int i=1;i<=anscnt;i++)write("lexer.txt",ans[i].sym+" "+ans[i].ori+"\n");//cout<<ans[i].sym<<" "<<ans[i].ori<<endl;
    file.close();
    return 0;
}