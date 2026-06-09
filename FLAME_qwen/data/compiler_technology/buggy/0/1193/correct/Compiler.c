// Compiler.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define WORDLEN 44 
char final[2000][400];
int final0 = 0;//final0表示temp中元素的个数（用于final数组的存储）
int state = 0; //state表示读入的状态，初始值为0
int flag = 0; //flag为1表示报错
char buffer[8000];
int length = 0;//index用于消除空格的中间量
int line = 1; //line 表述行数
char temp[100];
int temp0 = 0;//temp0用于存储temp的状态
FILE* p1, * p2, * p3;
int i = 0, j = 0, k = 0;

void add_word(const char word[]) {
    strcat(final[final0], " ");
    strcat(final[final0], word);
    final0 = final0 + 1;
    return;
}

void add_word_temp(const char word[], int n) {
    strcat(final[final0], " ");
    strncat(final[final0], word, n);
    final0 = final0 + 1;
    return;
}

void dele_temp_n(int n) { //删除temp数组里的前n个字符
    for (k = 0; k < temp0 - n; k = k + 1) {
        temp[k] = temp[n + k];
    }
    temp0 -= n;
    return;
}

void deal_word() { //处理读到纯字母的情况
    if (strncmp(temp, "main", 4) == 0 && temp0 == 4) {
        strcpy(final[final0], "MAINTK");
        add_word("main");
        dele_temp_n(4);
        if (temp0 > 0) {
            deal_word();
        }
        return;
    }
    if (strncmp(temp, "const", 5) == 0 && temp0 == 5) {
        strcpy(final[final0], "CONSTTK");
        add_word("const");
        dele_temp_n(5);
        if (temp0 > 0) {
            deal_word();
        }
        return;
    }
    if (strncmp(temp, "int", 3) == 0 && temp0 == 3) {
        strcpy(final[final0], "INTTK");
        add_word("int");
        dele_temp_n(3);
        if (temp0 > 0) {
            deal_word();
        }
        return;
    }
    if (strncmp(temp, "char", 4) == 0 && temp0 == 4) {
        strcpy(final[final0], "CHARTK");
        add_word("char");
        dele_temp_n(4);
        if (temp0 > 0) {
            deal_word();
        }
        return;
    }
    if (strncmp(temp, "break", 5) == 0 && temp0 == 5) {
        strcpy(final[final0], "BREAKTK");
        add_word("break");
        dele_temp_n(5);
        if (temp0 > 0) {
            deal_word();
        }
        return;
    }
    if (strncmp(temp, "continue", 8) == 0 && temp0 == 8) {
        strcpy(final[final0], "CONTINUETK");
        add_word("continue");
        dele_temp_n(8);
        if (temp0 > 0) {
            deal_word();
        }
        return;
    }
    if (strncmp(temp, "if", 2) == 0 && temp0 == 2) {
        strcpy(final[final0], "IFTK");
        add_word("if");
        dele_temp_n(2);
        if (temp0 > 0) {
            deal_word();
        }
        return;
    }
    if (strncmp(temp, "else", 4) == 0 && temp0 == 4) {
        strcpy(final[final0], "ELSETK");
        add_word("else");
        dele_temp_n(4);
        if (temp0 > 0) {
            deal_word();
        }
        return;
    }
    if (strncmp(temp, "for", 3) == 0 && temp0 == 3) {
        strcpy(final[final0], "FORTK");
        add_word("for");
        dele_temp_n(3);
        if (temp0 > 0) {
            deal_word();
        }
        return;
    }
    if (strncmp(temp, "getint", 6) == 0 && temp0 == 6) {
        strcpy(final[final0], "GETINTTK");
        add_word("getint");
        dele_temp_n(6);
        if (temp0 > 0) {
            deal_word();
        }
        return;
    }
    if (strncmp(temp, "getchar", 7) == 0 && temp0 == 7) {
        strcpy(final[final0], "GETCHARTK");
        add_word("getchar");
        dele_temp_n(7);
        if (temp0 > 0) {
            deal_word();
        }
        return;
    }
    if (strncmp(temp, "printf", 6) == 0 && temp0 == 6) {
        strcpy(final[final0], "PRINTFTK");
        add_word("printf");
        dele_temp_n(6);
        if (temp0 > 0) {
            deal_word();
        }
        return;
    }
    if (strncmp(temp, "return", 6) == 0 && temp0 == 6) {
        strcpy(final[final0], "RETURNTK");
        add_word("return");
        dele_temp_n(6);
        if (temp0 > 0) {
            deal_word();
        }
        return;
    }
    if (strncmp(temp, "void", 4) == 0 && temp0 == 4) {
        strcpy(final[final0], "VOIDTK");
        add_word("void");
        dele_temp_n(4);
        if (temp0 > 0) {
            deal_word();
        }
        return;
    }
    strcpy(final[final0], "IDENFR");
    strcat(final[final0], " ");
    strncat(final[final0], temp, temp0);
    final0 = final0 + 1;
    return;
}

int main()
{
    
    char ch = 0; //ch用于读入字符
    p1 = fopen("testfile.txt", "r");
    p2 = fopen("lexer.txt", "w");
    p3 = fopen("error.txt", "w");
    int result = 0;
    //这里不能去掉空格，否则会影响StringConst类型的结果
    while ((ch = fgetc(p1)) != EOF) {
        buffer[length] = ch;
        length = length + 1;
    }
    for (i = 0; i < length; i = i + 1) { 
        switch (state) {
        case 0: //初始状态
            if (buffer[i] == ' ') {
                continue;
            }
            if (isalpha(buffer[i]) || buffer[i] == '_') { //state = 1,读入字母
                state = 1;
                temp[temp0] = buffer[i];
                temp0 = temp0 + 1;
                break;
            }
            if ((buffer[i] >= '0') && (buffer[i]) <= '9') { //state = 2,读入数字
                state = 2;
                temp[temp0] = buffer[i];
                temp0 = temp0 + 1;
                break;
            }
            if (buffer[i] == '\n') {
                line = line + 1;
                break;
            }
            if (buffer[i] == '|') { //遇到'|'时直接查看下一个字符，不符合要求直接报错
                if (buffer[i + 1] == '|') {
                    i = i + 1;
                    strcpy(final[final0], "OR");
                    add_word("||");
                }
                else {
                    flag = 1;
                    fprintf(p3, "%d a", line);
                }
                break;
            }
            if (buffer[i] == '&') { //'&'同上处理
                if (buffer[i + 1] == '&') {
                    i = i + 1;
                    strcpy(final[final0], "AND");
                    add_word("&&");
                }
                else {
                    flag = 1;
                    fprintf(p3, "%d a", line);
                }
                break;
            }
            if (buffer[i] == '!') { //遇到'!'时分为'!='与单纯的'!'两种情况
                if (buffer[i + 1] == '=') {
                    i = i + 1;
                    strcpy(final[final0], "NEQ");
                    add_word("!=");
                }
                else {
                    strcpy(final[final0], "NOT");
                    add_word("!");
                }
                break;
            }
            if (buffer[i] == '<') { 
                if (buffer[i + 1] == '=') {
                    i = i + 1;
                    strcpy(final[final0], "LEQ");
                    add_word("<=");
                }
                else {
                    strcpy(final[final0], "LSS");
                    add_word("<");
                }
                break;
            }
            if (buffer[i] == '>') { 
                if (buffer[i + 1] == '=') {
                    i = i + 1;
                    strcpy(final[final0], "GEQ");
                    add_word(">=");
                }
                else {
                    strcpy(final[final0], "GRE");
                    add_word(">");
                }
                break;
            }
            if (buffer[i] == '=') { //遇到'<','>','='与'!'同理
                if (buffer[i + 1] == '=') {
                    i = i + 1;
                    strcpy(final[final0], "EQL");
                    add_word("==");
                }
                else {
                    strcpy(final[final0], "ASSIGN");
                    add_word("=");
                }
                break;
            }
            if (buffer[i] == '+') { //+、-、*、/、%、;、,、(、)、[、]、{、}都一样单独判断即可
                strcpy(final[final0], "PLUS");
                add_word("+");
                break;
            }
            if (buffer[i] == '-') { 
                strcpy(final[final0], "MINU");
                add_word("-");
                break;
            }
            if (buffer[i] == '/') {
                if (buffer[i + 1] == '/') {
                    while (buffer[i] != '\n' && buffer[i] != '\0') {
                        i = i + 1;
                    }
                    line = line + 1;
                    break;
                }
                if (buffer[i + 1] == '*') {
                    while (!((buffer[i] == '*') && (buffer[i + 1] == '/'))) {
                        i = i + 1;
                    }
                    i = i + 1;
                    break;
                }
                strcpy(final[final0], "DIV");
                add_word("/");
                break;
            }
            if (buffer[i] == '*') {
                strcpy(final[final0], "MULT");
                add_word("*");
                break;
            }
            if (buffer[i] == '%') {
                strcpy(final[final0], "MOD");
                add_word("%");
                break;
            }
            if (buffer[i] == ';') {
                strcpy(final[final0], "SEMICN");
                add_word(";");
                break;
            }
            if (buffer[i] == ',') {
                strcpy(final[final0], "COMMA");
                add_word(",");
                break;
            }
            if (buffer[i] == '(') {
                strcpy(final[final0], "LPARENT");
                add_word("(");
                break;
            }
            if (buffer[i] == ')') {
                strcpy(final[final0], "RPARENT");
                add_word(")");
                break;
            }
            if (buffer[i] == '[') {
                strcpy(final[final0], "LBRACK");
                add_word("[");
                break;
            }
            if (buffer[i] == ']') {
                strcpy(final[final0], "RBRACK");
                add_word("]");
                break;
            }
            if (buffer[i] == '{') {
                strcpy(final[final0], "LBRACE");
                add_word("{");
                break;
            }
            if (buffer[i] == '}') {
                strcpy(final[final0], "RBRACE");
                add_word("}");
                break;
            }
            if (buffer[i] == '"') {
                temp[temp0] = '"';
                temp0 = temp0 + 1;
                i = i + 1;
                while (buffer[i] != '"') {
                    temp[temp0] = buffer[i];
                    temp0 = temp0 + 1;
                    i = i + 1;
                }
                temp[temp0] = '"';
                temp0 = temp0 + 1;
                strcpy(final[final0], "STRCON");
                add_word_temp(temp, temp0);
                temp0 = 0; //将temp数组的指针改为0即可视为数组被清空
                break;
            }
            if (buffer[i] == '\'') {
                strcpy(final[final0], "CHRCON ");
                strcat(final[final0], "'");
                strncat(final[final0], buffer + i + 1, 2);
                // strncat(final[final0], buffer_i + 2]);
                final0 = final0 + 1;
                if (buffer[i + 1] == '\\') {
                    while (buffer[i + 2] != '\'') {
                        strncat(final[final0 - 1], buffer + i + 3, 1);
                        i++;
                    }
                }
                i = i + 2;
                break;
            }
            break;
            case 1: //读入的是标识符或关键字
                if ((buffer[i] == '_') || (isalpha(buffer[i])) || ((buffer[i] >= '0') && (buffer[i] <= '9'))) { //仍然符合标识符的定义
                    temp[temp0] = buffer[i];
                    temp0 = temp0 + 1;
                    break;
                }
                deal_word(); //否则结算存储的标识符并进行i--以退到state=0时的详细判断
                temp0 = 0;
                i = i - 1;
                state = 0;
                break;
            case 2: //读入的是数字
                if (isalnum(buffer[i])) {
                    temp[temp0] = buffer[i];
                    temp0 = temp0 + 1;
                    break;
                }
                strcpy(final[final0], "INTCON");
                add_word_temp(temp, temp0);
                temp0 = 0;
                i = i - 1;
                state = 0;
                break;
        }
    }
    if (temp0 > 0) { //处理掉可能存在的最后一项
        if (state == 2) {
            strcpy(final[final0], "INTCON");
            add_word_temp(temp, temp0);
        }
        else {
            deal_word();
        }
    }
    if (flag == 0) {
        for (i = 0; i < final0; i = i + 1) {
            fprintf(p2, "%s\n", final[i]);
        }
    }
    /*else {
        fprintf(p3, "%d a", line);
    }*/
    fclose(p1);
    fclose(p2);
    fclose(p3);
    return 0;
}

//if (temp0 > 0) { //读入的不是数字和字母，对temp数组存入的内容进行结算
//
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
