#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKEN_LENGTH 256

char names[14][20] = {"main", "const", "int", "break", "if", "continue", "else", "for", "getint", "printf", "getchar", "return", "void", "char"};
char codes[14][20] = {"MAINTK", "CONSTTK", "INTTK", "BREAKTK", "IFTK", "CONTINUETK", "ELSETK", "FORTK", "GETINTTK", "PRINTFTK", "GETCHARTK", "RETURNTK", "VOIDTK", "CHARTK"};

char curLine[MAX_TOKEN_LENGTH];  // 存放读入的当前行
char token[MAX_LINE_LENGTH];
int curPos = 0;
int inMultLineComment = 0;
char a[20]; 

char* getSym(int lineNum) {
    for(int i = 0; i < 256; i++){
        token[i] = '\0';
    }
    for(int i = 0; i < 20; i++){
        a[i] = '\0';
    }
    int length = strlen(curLine), tokenPos = 0;
    while(curLine[curPos] == ' ' && curPos < length) curPos++;

    if(curPos >= length){
        strcpy(a, "EMPTY_LINE");
        return a;
    }

    if(!inMultLineComment){
        if((curLine[curPos] >= 'a' && curLine[curPos] <= 'z') || (curLine[curPos] >= 'A' && curLine[curPos] <= 'Z') || curLine[curPos] == '_'){
            while((curLine[curPos] >= 'a' && curLine[curPos] <= 'z') || (curLine[curPos] >= 'A' && curLine[curPos] <= 'Z') || (curLine[curPos] >= '0' && curLine[curPos] <= '9') || curLine[curPos] == '_'){
                token[tokenPos++] = curLine[curPos++];
            }
            int flag = 0;
            for(int i = 0; i < 14; i++){
                if(strcmp(token, names[i]) == 0){
                    flag = 1;
                    return codes[i];
                }
            }
            if(flag == 0){
            	strcpy(a, "IDENFR");
                return a;
            }
        }
        else if(curLine[curPos] == '\"'){
            do {
                if(curLine[curPos] == '\\' && curLine[curPos + 1] == '\"'){
                    token[tokenPos++] = curLine[curPos++];
                    token[tokenPos++] = curLine[curPos++];
                }
                else if(curLine[curPos] == '\\' && curLine[curPos + 1] == '\''){
                    token[tokenPos++] = curLine[curPos++];
                    token[tokenPos++] = curLine[curPos++];
                }
                else{
                    token[tokenPos++] = curLine[curPos++];
                }
            } while (curLine[curPos] != '\"');
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "STRCON");
            return a;
        }
        else if(curLine[curPos] == '\''){
            do {
                if(curLine[curPos] == '\\' && curLine[curPos + 1] == '\"'){
                    token[tokenPos++] = curLine[curPos++];
                    token[tokenPos++] = curLine[curPos++];
                }
                else if(curLine[curPos] == '\\' && curLine[curPos + 1] == '\''){
                    token[tokenPos++] = curLine[curPos++];
                    token[tokenPos++] = curLine[curPos++];
                }
                else{
                    token[tokenPos++] = curLine[curPos++];
                }
            } while (curLine[curPos] != '\'');
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "CHRCON");
            return a;
        }
        else if(curLine[curPos] == '/' && curLine[curPos + 1] == '/'){
        	strcpy(a, "SINGLE_LINE_COMMENT");
            return a;
        }
        else if(curLine[curPos] == '/' && curLine[curPos + 1] == '*'){
            curPos += 2;
            while (1) {
                while (curPos < length && curLine[curPos] != '*') curPos++;
                if (curPos >= length) {  // 多行注释不在这行结束
                    inMultLineComment = 1;
                    strcpy(a, "MULTI_LINE_COMMENT");
                    return a;
                } else if (curLine[curPos + 1] == '/') {
                    curPos += 2;
                    strcpy(a, "MULTI_LINE_COMMENT");
                    return a;
                } // else: 单独出现一个*
                curPos++;
            }
        }
        else if(curLine[curPos] >= '0' && curLine[curPos] <= '9'){
            do {
                token[tokenPos++] = curLine[curPos++];
            } while (curLine[curPos] >= '0' && curLine[curPos] <= '9');
            strcpy(a, "INTCON");
            return a;
        }
        else if(curLine[curPos] == '!'){
            token[tokenPos++] = curLine[curPos];
            if (curLine[++curPos] != '='){
            	strcpy(a, "NOT");
                return a;
            }
            else {
                token[tokenPos++] = curLine[curPos++];
                strcpy(a, "NEQ");
                return a;
            }
        }
        else if(curLine[curPos] == '&'){
            if(curLine[curPos + 1] == '&'){
                token[tokenPos++] = curLine[curPos++];
                token[tokenPos++] = curLine[curPos++];
                strcpy(a, "AND");
                return a;
            }
            else{
            	strcpy(a, "ERROR");
                return a;
            }
        }
        else if(curLine[curPos] == '|'){
            if(curLine[curPos + 1] == '|'){
                token[tokenPos++] = curLine[curPos++];
                token[tokenPos++] = curLine[curPos++];
                strcpy(a, "OR");
                return a;
            }
            else{
            	strcpy(a, "ERROR");
                return a;
            }
        }
        else if(curLine[curPos] == '+'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "PLUS");
            return a;
        }
        else if(curLine[curPos] == '-'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "MINU");
            return a;
        }
        else if(curLine[curPos] == '*'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "MULT");
            return a;
        }
        else if(curLine[curPos] == '/'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "DIV");
            return a;
        }
        else if(curLine[curPos] == '%'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "MOD");
            return a;
        }
        else if(curLine[curPos] == '<'){
            token[tokenPos++] = curLine[curPos++];
            if(curLine[curPos] != '='){
            	strcpy(a, "LSS");
                return a;
            }
            else{
                token[tokenPos++] = curLine[curPos++];
                strcpy(a, "LEQ");
                return a;
            }
        }
        else if(curLine[curPos] == '>'){
            token[tokenPos++] = curLine[curPos++];
            if(curLine[curPos] != '='){
            	strcpy(a, "GRE");
                return a;
            }
            else{
                token[tokenPos++] = curLine[curPos++];
                strcpy(a, "GEQ");
                return a;
            }
        }
        else if(curLine[curPos] == '='){
            token[tokenPos++] = curLine[curPos++];
            if(curLine[curPos] != '='){
            	strcpy(a, "ASSIGN");
                return a;
            }
            else{
                token[tokenPos++] = curLine[curPos++];
                strcpy(a, "EQL");
                return a;
            }
        }
        else if(curLine[curPos] == ';'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "SEMICN");
            return a;
        }
        else if(curLine[curPos] == ','){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "COMMA");
            return a;
        }
        else if(curLine[curPos] == '('){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "LPARENT");
            return a;
        }
        else if(curLine[curPos] == ')'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "RPARENT");
            return a;
        }
        else if(curLine[curPos] == '['){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "LBRACK");
            return a;
        }
        else if(curLine[curPos] == ']'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "RBRACK");
            return a;
        }
        else if(curLine[curPos] == '{'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "LBRACE");
            return a;
        }
        else if(curLine[curPos] == '}'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "RBRACE");
            return a;
        }
        else if(curLine[curPos] == '\a' || curLine[curPos] == '\b' || curLine[curPos] == '\t' || curLine[curPos] == '\n' || curLine[curPos] == '\v' || curLine[curPos] == '\f' || curLine[curPos] == '\\' || curLine[curPos] == '\0'){
            strcpy(a, "ELSE");
            return a;
        }
    }
    else{
        while(1){
            while(curPos < length && curLine[curPos] != '*') curPos++;
            if(curPos >= length) {  // 多行注释不在这行结束
                strcpy(a, "MULTI_LINE_COMMENT");
                return a;
            } else if (curLine[curPos + 1] == '/') {
                inMultLineComment = 0;
                curPos += 2;
                strcpy(a, "MULTI_LINE_COMMENT");
                return a;
            } // else: 单独出现一个*
            curPos++;
        }
    }
    strcpy(a, "EMPTY_LINE");
    return a;
}

void parseLine(int lineNum, FILE *input, FILE *output, FILE *error){
    curPos = 0;
    int length = strlen(curLine);
    while(curPos < length){
    	char symbol[20];
    	for(int i = 0; i < 20; i++){
    		symbol[i] = '\0';
		}
		strcpy(symbol, getSym(lineNum));
        if(strcmp(symbol, "SINGLE_LINE_COMMENT") == 0 || strcmp(symbol, "EMPTY_LINE") == 0)
            return;  // 单行注释，后面的也不用看了
        if(strcmp(symbol, "ERROR") == 0){
        	curPos++; 
            fprintf(error, "%d a\n", lineNum);
        }
        else if(strcmp(symbol, "ELSE") == 0){
        	curPos++;
        }
        else if(strcmp(symbol, "MULTI_LINE_COMMENT") != 0) {
            fprintf(output, "%s %s\n", symbol, token);
        }
    }
}

void parse(FILE *input, FILE *output, FILE *error) {
    for(int i = 0; i < 1024; i++){
        curLine[i] = '\0';
    }
    int lineNum = 0;
    while (fgets(curLine, MAX_LINE_LENGTH, input) != NULL) {
        lineNum++;
        parseLine(lineNum, input, output, error);
    }
}

int main() {
    FILE *input = fopen("testfile.txt", "r");
    FILE *output = fopen("lexer.txt", "w");
    FILE *error = fopen("error.txt", "w");

    parse(input, output, error);

    fclose(input);
    fclose(output);
    fclose(error);
    return 0;
}
