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
    while(ch = getchar()) { // @@ [The condition `ch = getchar()` assigns the result of getchar() to ch but does not compare it; also, getchar() returns int, not char, so EOF handling is broken. This causes infinite loop or undefined behavior when input ends.]
        if(ch == ' ') continue;
        if(isdigit(ch)) num = num * 10 + ch - '0';
        else {
            s1[++t1] = num;
            num = 0;
            if(ch == '+' || ch == '-') {
                while(t2 > 0) clear();
            }
            else if(ch == '*' || ch == '/') {
                while((s2[t2] == '*' || s2[t2] == '/') && t2 > 0) clear(); // @@ [Accessing s2[t2] when t2 could be 0 leads to reading uninitialized memory or out-of-bounds access because s2[0] is never set as a valid operator. The condition should check t2 > 0 before accessing s2[t2].]
            }
            if(ch != '=') s2[++t2] = ch;
        }
        if(ch == '=') break;
    }
    while(t2 > 0) clear();
    printf("%d", s1[1]); // @@ [If the expression has only one number (e.g., "5="), s1[1] is never set because the else block (which pushes num to s1) is skipped. Also, t1 may be 0, so s1[1] is uninitialized. Should print s1[t1] instead.]
    return 0;
}