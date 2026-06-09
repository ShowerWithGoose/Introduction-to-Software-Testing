#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LL long long
#define DD double
#define clear(); {int a = s1[t1-1], b = s1[t1]; s1[--t1] = calc(s2[t2], a, b); --t2;}

int s1[100], t1;
char s2[100], t2;

int calc(char op, int a, int b) {
    int res = 0;
    switch (op) {
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    case '*':
        res = a * b;
        break;
    case '/':
        res = a / b;
        break;
    default:
        break;
    }
    return res;
}

int main() {
    char ch;
    int num = 0;
    while(ch = getchar()) { // @@ [The condition `ch = getchar()` assigns the result of getchar() to ch but does not compare it to EOF or check for validity. Also, getchar() returns int, not char, so using char may cause issues with EOF handling. Moreover, the loop condition should be `while ((ch = getchar()) != EOF && ch != '=')` or similar. Additionally, the loop never breaks on '=' inside the loop body before processing, leading to incorrect stack behavior.]
        if(ch == ' ') continue;
        if(isdigit(ch)) num = num * 10 + ch - '0';
        else {
            s1[++t1] = num;
            num = 0;
            if(ch == '+' || ch == '-') {
                while(t2 > 0) clear();
            }
            else if(ch == '*' || ch == '/') {
                while((s2[t2] == '*' || s2[t2] == '/') && t2 > 0) clear();
            }
            if(ch != '=') s2[++t2] = ch;
        }
        if(ch == '=') break;
    }
    while(t2 > 0) clear();
    printf("%d", s1[1]); // @@ [The final result is at s1[t1], not necessarily s1[1]. After all operations, t1 should be 1, but if the expression has only one number, t1 would be 1 and s1[1] is correct. However, due to incorrect parsing logic (e.g., pushing num even when ch is '='), the stack might be in an inconsistent state. Also, if no operators exist, num is never pushed because '=' triggers the else branch, but then ch=='=' skips pushing to s2, yet num hasn't been pushed to s1. So single-number expressions fail.]
    return 0;
}