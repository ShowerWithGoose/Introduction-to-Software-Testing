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
    while(ch = getchar()) { // @@ [The condition `ch = getchar()` assigns the character to `ch` but does not check for EOF properly. Also, `getchar()` returns `int`, not `char`, so using `char ch` can cause incorrect comparison with EOF, leading to infinite loops or undefined behavior. Additionally, the loop condition should be `while ((ch = getchar()) != EOF && ch != '=')` or similar, but current logic breaks only when `ch == '='`. However, more critically, the assignment in condition is missing parentheses around the assignment when used in a condition that expects a boolean; but the real issue is type of `ch` and EOF handling.]
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
    printf("%d", s1[1]); // @@ [The stack `s1` uses 1-based indexing (`s1[++t1]`), but if the expression has only one number (e.g., "5="), then `t1` would be 1 and `s1[1]` is correct. However, if the expression is empty or parsing fails, `s1[1]` may be uninitialized. More importantly, after processing, the result should be at `s1[t1]`, not necessarily `s1[1]`. For example, if multiple operations are performed and the stack shrinks, `t1` may be 1, but relying on `s1[1]` assumes the final result is always there, which may not hold if initial `t1` wasn't zero-initialized properly or if stack management is off. Also, global variables `t1` and `t2` are not initialized to 0 explicitly (though they are zero-initialized as globals), but the bigger issue is assuming result is at index 1 instead of `s1[t1]`.]
    return 0;
}