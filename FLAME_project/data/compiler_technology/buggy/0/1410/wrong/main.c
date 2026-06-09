#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 10000
#define MAX_IDENTIFIER_LENGTH 100
#define MAX_RESERVED_WORDS 50
#define NMAX 10

char instring[MAX_STRING_LENGTH];
char ch;
int ll = 1;
int cc = 0;
int ii=0;
long long int num;
char a[MAX_IDENTIFIER_LENGTH];
int sym = 0;
int e = 0;
int j=0;
int flag_String = 0;
typedef struct {
    const char *name;
    const char *code;
} Token;
FILE *error_output;
// 根据您提供的类别码更新了 token 数组
Token tokens[] = {
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
                a[k++] = ch;
            }
            nextch();
            if(ch=='"') break;
        } while (1);
        a[k] = ch;
        a[k+1] = '\0';
        nextch();
        fprintf(output,"STRCON %s\n",a);
    }
    else if(ch == '\''){
        k = 0;
        int aaa=0;
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
        fprintf(output,"CHRCON %s\n",a);
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
        for (int i = 0; i < sizeof(tokens) / sizeof(tokens[0]); i++) {
            if (strcmp(a, tokens[i].name) == 0) {
                fprintf(output, "%s %s\n", tokens[i].code, a); // 输出格式为 类别码 单词
                return;
            }
        }
        fprintf(output, "IDENFR %s\n", a); // 默认标识符类型
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
        fprintf(output, "INTCON %s\n", a); // 输出格式为 类别码 数字
    }else {
        if(ch==' '||ch=='\n') return;
        // 处理其他符号
        k=0;
        a[0]=ch;
        k++;
        char chh;
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
            }
            a[k++]=ch;
            nextch();
        }
        if(a[0] == '|'){
            if(ch != '|'){
                error();
            }
            a[k++]=ch;
            nextch();
        }
        a[k] = '\0';
        for (int i = 0; i < sizeof(tokens) / sizeof(tokens[0]); i++) {
            if (strcmp(a, tokens[i].name) == 0) {
                fprintf(output, "%s %s\n", tokens[i].code, a); // 输出格式为 类别码 符号
//                nextch();
                return;
            }
        }
    }
}

int main() {
//    FILE *input = fopen("D:\\Cproject\\Compiler\\textfile.txt", "r");
    FILE *input = fopen("testfile.txt", "r");
    FILE *output = fopen("lexer.txt", "w");
    error_output = fopen("error.txt", "w");

    if (!input) {
        fprintf(stderr, "Failed to open input file.\n");
        return 1;
    }
    if (!output) {
        fprintf(stderr, "Failed to open output file.\n");
        fclose(input);
        return 1;
    }
    char c;

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
    return 0;
}
