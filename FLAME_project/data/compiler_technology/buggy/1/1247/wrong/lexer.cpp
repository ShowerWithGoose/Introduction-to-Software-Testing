#include "error.h"
#include "lexer.h"

#include<cctype>
#include<cstdio>
#include<map>
#include<string>
#include<vector>

#define map std::map
#define string std::string
#define vector std::vector

#define dc(a,b) ((a)<<8|(b))

static const char *const word_name[MAXCODE]={
        nullptr,
        "IDENFR","INTCON","STRCON","CHRCON","MAINTK","CONSTTK",
        "INTTK","CHARTK","BREAKTK","CONTINUETK","IFTK",
        "ELSETK","NOT","AND","OR","FORTK","GETINTTK",
        "GETCHARTK","PRINTFTK","RETURNTK","PLUS","MINU",
        "VOIDTK","MULT","DIV","MOD","LSS","LEQ",
        "GRE","GEQ","EQL","NEQ","ASSIGN",
        "SEMICN","COMMA","LPARENT","RPARENT","LBRACK","RBRACK",
        "LBRACE","RBRACE",
};

static const char *const word_def_content[MAXCODE]={
        nullptr,
        nullptr,nullptr,nullptr,nullptr,"main","const",
        "int","char","break","continue","if",
        "else","!","&&","||","for","getint",
        "getchar","printf","return","+","-",
        "void","*","/","%","<","<=",
        ">",">=","==","!=","=",
        ";",",","(",")","[","]",
        "{","}",
};

static const map<string,int>token_dict={
        {"const",CONSTTK},
        {"int",INTTK},
        {"char",CHARTK},
        {"break",BREAKTK},
        {"continue",CONTINUETK},
        {"if",IFTK},
        {"else",ELSETK},
        {"for",FORTK},
        {"return",RETURNTK},
        {"void",VOIDTK},
};

static const map<int,int>sym_dict={
        {'!',NOT},
        {dc('&','&'),AND},
        {dc('|','|'),OR},
        {'+',PLUS},
        {'-',MINU},
        {'*',MULT},
        {'/',DIV},
        {'%',MOD},
        {'<',LSS},
        {dc('<','='),LEQ},
        {'>',GRE},
        {dc('>','='),GEQ},
        {dc('=','='),EQL},
        {dc('!','='),NEQ},
        {'=',ASSIGN},
        {';',SEMICN},
        {',',COMMA},
        {'(',LPARENT},
        {')',RPARENT},
        {'[',LBRACK},
        {']',RBRACK},
        {'{',LBRACE},
        {'}',RBRACE},
};

vector<Word>words;

static int ch,line=1;
static FILE *rfp;
#define gc() (ch=fgetc(rfp))

static bool getWord(){
    repeat:
    while(isspace(ch)){
        if(ch=='\n') line++;
        gc();
    }
    if(ch==EOF) return false;
    if(isalpha(ch)||ch=='_'){
        string s(1,(char)ch);
        while(isalnum(gc())||ch=='_') s+=(char)ch;
        if(token_dict.count(s)){
            words.push_back({token_dict.at(s),line,""});
        }
        else{
            words.push_back({IDENFR,line,s});
        }
    }
    else if(isdigit(ch)){
        string s(1,(char)ch);
        while(isdigit(gc())) s+=(char)ch;
        words.push_back({INTCON,line,s});
    }
    else if(ch=='"'){
        string s="\"";
        for(int pch;;){
            pch=ch,gc();
            ast(ch!=EOF&&ch!='\n');
            s+=(char)ch;
            if(pch!='\\'&&ch=='"') break;
        }
        words.push_back({STRCON,line,s});
        gc();
    }
    else if(ch=='\''){
        string s="'";
        for(int pch;;){
            pch=ch,gc();
            ast(ch!=EOF&&ch!='\n');
            s+=(char)ch;
            if(pch!='\\'&&ch=='\'') break;
        }
        words.push_back({CHRCON,line,s});
        gc();
    }
    else{
        int pch=ch;gc();
        if(pch=='/'){
            if(ch=='/'){
                while(gc()!='\n'){
                    if(ch==EOF) return false;
                }
                goto repeat;
            }
            else if(ch=='*'){
                for(bool flag=false;;flag=true){
                    pch=ch,gc();
                    ast(ch!=EOF);
                    if(flag&&pch=='*'&&ch=='/') break;
                    if(ch=='\n') line++;
                }
                gc();
                goto repeat;
            }
        }
        int key=dc(pch,ch);
        if(sym_dict.count(key)){
            words.push_back({sym_dict.at(key),line,""});
            gc();
        }
        else if(sym_dict.count(pch)){
            words.push_back({sym_dict.at(pch),line,""});
        }
        else{
            ast(pch=='&'||pch=='|');
            words.push_back({pch=='&'?AND:OR,line,""});
            errors.push_back({line,'a'});
        }
    }
    return true;
}

bool getWords(const char *fn){
    if((rfp=fopen(fn,"r"))){
        words.clear();
        for(gc();getWord(););
        fclose(rfp);
        return true;
    }
    return false;
}

bool isWordType(const string &str,int type){
    return str==word_def_content[type];
}

void printWord(int code,FILE *fp){
    fprintf(fp,"%s %s\n",word_name[code],word_def_content[code]);
}

void printWord(int code,const string &content,FILE *fp){
    fprintf(fp,"%s %s\n",word_name[code],content.c_str());
}

static const int specType[]={MAINTK,GETINTTK,GETCHARTK,PRINTFTK};
bool printWords(const char *fn){
    FILE *fp=fopen(fn,"w");
    if(fp){
        for(const Word &word:words){
            if(word_def_content[word.code]) printWord(word.code,fp);
            else{
                if(word.code==IDENFR){
                    for(int type:specType){
                        if(word.content==word_def_content[type]){
                            printWord(type,fp);
                            goto l_printWords;
                        }
                    }
                }
                printWord(word.code,word.content,fp);
            }
            l_printWords:;
        }
        fclose(fp);
        return true;
    }
    return false;
}
