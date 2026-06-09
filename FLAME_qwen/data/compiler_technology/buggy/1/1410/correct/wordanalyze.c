#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "wordanalyze.h"
#define MAX_STRING_LENGTH 10000
#define MAX_IDENTIFIER_LENGTH 100
#include "main.h"

char instring[MAX_STRING_LENGTH];
char ch;
int ll = 1;
int ii=0;
long long int num;
char a[MAX_IDENTIFIER_LENGTH];
int j=0;
int flag_String = 0;
typedef struct {
    const char *name;
    const char *code;
} Tokenname;
FILE *error_output;
int have_wrong = 0;
struct Token *old_token;
int old_token_num = 0;

Tokenname tokenname[] = {
        {"Ident", "IDENFR"}, {"IntConst", "INTCON"}, {"StringConst", "STRCON"}, {"CharConst", "CHRCON"},
        {"main", "MAINTK"}, {"const", "CONSTTK"}, {"int", "INTTK"}, {"char", "CHARTK"}, {"break", "BREAKTK"},
        {"continue", "CONTINUETK"}, {"if", "IFTK"}, {"else", "ELSETK"}, {"void", "VOIDTK"}, {";", "SEMICN"},
        {"!", "NOT"}, {"&&", "AND"}, {"||", "OR"}, {"+", "PLUS"}, {"-", "MINU"}, {"*", "MULT"},
        {"/", "DIV"}, {"%", "MOD"}, {"(", "LPARENT"}, {")", "RPARENT"}, {"[", "LBRACK"}, {"]", "RBRACK"},
        {"{", "LBRACE"}, {"}", "RBRACE"}, {"for", "FORTK"}, {"getint", "GETINTTK"}, {"getchar", "GETCHARTK"},
        {"printf", "PRINTFTK"}, {"return", "RETURNTK"}, {"<", "LSS"}, {"<=", "LEQ"}, {">", "GRE"},
        {">=", "GEQ"}, {"==", "EQL"}, {"!=", "NEQ"}, {"=", "ASSIGN"}, {",", "COMMA"}
};

void error() {

    fprintf(error_output, "%d a",ll);
    have_wrong = 1;
}
//
int nextch() {
    if (j<ii) {
        ch = instring[j];
        j++;
        return 1;
    }
    j++;
    return 0;
}

void getsym(FILE *output) {
    int k;
    while (ch == ' '){
        if(!nextch()) return;
    }
    while(ch == '\n'){
        ll++;
        if(!nextch()) return;
    }
    if(ch == '/') { // 第一个 /
        nextch();
        if(ch == '/'){
            while(ch != '\n'){
                if(nextch()==0) return;
            }
        }
        else if(ch == '*'){
            int flag = 0;
            while(flag<2){
                nextch();
                if(ch=='*'){
                    flag=1;
                    continue;
                }
                if(flag==1&&ch!='/'){
                    flag = 0;
                }
                if(flag==1&&ch=='/'){
                    flag = 2;
                }
                if(ch=='\n') ll++;
            }
            nextch();
            return;
        }
        else{
            ch = '/';
            j--;
        }
    }
    if(ch == '"'){
        k = 0;
        do {
            if (k < MAX_IDENTIFIER_LENGTH - 1) {
                if(ch=='\n'){
                    a[k++]='\\';
                    a[k++]='n';
                }
                else a[k++] = ch;
            }
            nextch();
            if(ch=='"') break;
        } while (1);
        a[k] = ch;
        a[k+1] = '\0';
        nextch();
        if(flag_String) fprintf(output,"\n");
        if(!flag_String) flag_String=1;
        old_token[old_token_num].line = ll;
        strcpy(old_token[old_token_num].type,"STRCON");
        strcpy(old_token[old_token_num].value,a);
        old_token_num++;
        fprintf(output,"%d STRCON %s",ll,a);
    }
    else if(ch == '\''){
        k = 0;
        do {
            if (k < MAX_IDENTIFIER_LENGTH - 1) {
                a[k++] = ch;
            }
            nextch();
            if(ch=='\''&&a[k-1]!='\\') break;
        } while (1);
        a[k] = ch;
        a[k+1] = '\0';
        nextch();
        if(flag_String) fprintf(output,"\n");
        if(!flag_String) flag_String=1;
        old_token[old_token_num].line = ll;
        strcpy(old_token[old_token_num].type,"CHRCON");
        strcpy(old_token[old_token_num].value,a);
        old_token_num++;
        fprintf(output,"%d CHRCON %s",ll,a);
    }
    else if (isalpha(ch)||ch=='_') {
        k = 0;
        do {
            if (k < MAX_IDENTIFIER_LENGTH - 1) {
                a[k++] = ch;
            }
            nextch();
        } while (isalnum(ch)||ch=='_');
        a[k] = '\0';

        // 根据标识符查找 token
        for (int i = 0; i < sizeof(tokenname) / sizeof(tokenname[0]); i++) {
            if (strcmp(a, tokenname[i].name) == 0) {
                if(flag_String) fprintf(output,"\n");
                if(!flag_String) flag_String=1;
                old_token[old_token_num].line = ll;
                strcpy(old_token[old_token_num].type,tokenname[i].code);
                strcpy(old_token[old_token_num].value,a);
                old_token_num++;
                fprintf(output, "%d %s %s", ll, tokenname[i].code, a); // 输出格式为 类别码 单词
                return;
            }
        }
        if(flag_String) fprintf(output,"\n");
        if(!flag_String) flag_String=1;
        old_token[old_token_num].line = ll;
        strcpy(old_token[old_token_num].type,"IDENFR");
        strcpy(old_token[old_token_num].value,a);
        old_token_num++;
        fprintf(output, "%d IDENFR %s", ll,a); // 默认标识符类型
    } else if (isdigit(ch)) {
        k = 0;
        num = 0;
        do {
            num = 10 * num + (ch - '0');
            a[k]=ch;
            k++;
            nextch();
        } while (isdigit(ch));
        a[k]='\0';
        if(flag_String) fprintf(output,"\n");
        if(!flag_String) flag_String=1;
        old_token[old_token_num].line = ll;
        strcpy(old_token[old_token_num].type,"INTCON");
        strcpy(old_token[old_token_num].value,a);
        old_token_num++;
        fprintf(output, "%d INTCON %s", ll,a); // 输出格式为 类别码 数字
    }else {
        if(ch==' '||ch=='\n') return;
        // 处理其他符号
        k=0;
        a[0]=ch;
        k++;
        nextch();
        if(a[0] == '>' || a[0]=='<'||a[0]=='='||a[0]=='!'){
            if(ch=='='){
                a[k++]=ch;
                nextch();
            }
        }
        if(a[0] == '&'){
            if(ch != '&'){
                error();
//                a[k++]='&';
                a[k] = '\0';
                old_token[old_token_num].line = ll;
                strcpy(old_token[old_token_num].type,"AND");
                strcpy(old_token[old_token_num].value,"&");
                old_token_num++;
            }
            else{
                a[k++]=ch;
                nextch();
            }
        }
        if(a[0] == '|'){
            if(ch != '|'){
                error();
//                a[k++]='|';
                a[k] = '\0';
                old_token[old_token_num].line = ll;
                strcpy(old_token[old_token_num].type,"OR");
                strcpy(old_token[old_token_num].value,"|");
                old_token_num++;
            }
            else{
                a[k++]=ch;
                nextch();
            }
        }
        a[k] = '\0';
        for (int i = 0; i < sizeof(tokenname) / sizeof(tokenname[0]); i++) {
            if (strcmp(a, tokenname[i].name) == 0) {
                if(flag_String) fprintf(output,"\n");
                if(!flag_String) flag_String=1;
                old_token[old_token_num].line = ll;
                strcpy(old_token[old_token_num].type,tokenname[i].code);
                strcpy(old_token[old_token_num].value,a);
                old_token_num++;
                fprintf(output, "%d %s %s", ll, tokenname[i].code, a); // 输出格式为 类别码 符号
//                nextch();
                return;
            }
        }
    }
}

int gettokennum(){
    return old_token_num;
}
Token* wordanalyze() {
//    FILE *input = fopen("D:\\Cproject\\Compiler\\textfile.txt", "r");
    FILE *input = fopen("testfile.txt", "r");
    FILE *output = fopen("lexer.txt", "w");
    error_output = fopen("error.txt", "w");

    char c;

    old_token = malloc(10000 * sizeof (Token));
    while((c = getc(input))!=EOF){
        instring[ii++] = c;
    }
    ch = instring[j];
    j++;
    while (j<ii) {
        if (ch != EOF) {
            getsym(output);
        }
    }

    fclose(input);
    fclose(output);
    fclose(error_output);
    return old_token;
}
