#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int pan(char l, char r){
    if (r-l>1) { // @@ 错误：应允许差为1的情况（如a-b），否则无法正确处理相邻字符
        if (isdigit(l)* isalpha(r)) { // @@ 错误：条件应为同时是数字或同时是字母，且应处理数字-数字情况
            return 1;
        }
        if (isalpha(l)* isalpha(r)) { // @@ 错误：缺少数字-数字的处理，且此条件不会匹配数字-数字情况
            if (isupper(l)* isupper(r)|| islower(l)* islower(r)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {

    char s[1000001];
    gets(s);
    int len = strlen(s);
    for (int i = 0; i <len ; i++) {
        if (s[i]!='-') {
            putchar(s[i]);
        }
        else{
            if (i==0||i==len-1) {
                putchar('-');
            }
            else{
                if (pan(s[i-1],s[i+1])) {
                    for (int j = s[i-1]+1; j <s[i+1] ; j++) {
                        putchar(j);
                    }
                }
                else{
                    putchar('-');
                }
            }
        }
    }
    return 0;
}