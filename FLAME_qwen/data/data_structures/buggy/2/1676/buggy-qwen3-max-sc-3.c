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
    while(ch = getchar()) { // @@ [The condition `ch = getchar()` assigns the character but does not check for EOF properly. Also, `getchar()` returns `int`, not `char`, so using `char ch` may cause issues with EOF comparison. Moreover, the loop condition should be `while ((ch = getchar()) != EOF)` or similar, and `ch` should be declared as `int`.]
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
    printf("%d", s1[1]); // @@ [The stack `s1` uses 1-based indexing (`s1[1]`), but `t1` starts at 0 and is incremented before assignment (`s1[++t1] = num`). If there's only one number in the expression (e.g., "5="), then `t1` becomes 1 and `s1[1]` is valid. However, if the expression is empty or malformed, this could access uninitialized memory. More critically, after processing, the result should be at `s1[t1]`, not necessarily `s1[1]`. For example, if multiple operations remain, `t1` might be greater than 1, but this always prints `s1[1]`, which is incorrect.]
    return 0;
}