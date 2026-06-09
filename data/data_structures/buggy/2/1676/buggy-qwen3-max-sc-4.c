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
    while(ch = getchar()) { // @@ [The condition `ch = getchar()` assigns the character to `ch` but does not check for EOF properly. Also, `getchar()` returns `int`, not `char`, so using `char ch` can cause issues with EOF comparison. Moreover, the loop condition should be `while ((ch = getchar()) != EOF && ch != '=')` or similar, but here it runs even when `ch` is 0 (null character), which never happens in normal input, causing potential infinite loop or incorrect behavior. Additionally, the assignment in condition without parentheses around comparison leads to wrong control flow.]
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
    printf("%d", s1[1]); // @@ [The stack `s1` uses 1-based indexing, but if the expression has only one number (e.g., "5="), then `t1` would be 1 and `s1[1]` is correct. However, the initial values of `t1` and `t2` are uninitialized (global variables are zero-initialized, so `t1 = 0`, `t2 = 0`), which is okay. But the real issue is that after processing the last number before '=', it's pushed into `s1` only when a non-digit (i.e., '=') is encountered. However, in the case of single number like "5=", the `else` block runs because `ch` becomes '=', so `s1[++t1] = num;` pushes the number, which is correct. So this line may not be the primary error. The main error is in the loop condition.]
    return 0;
}