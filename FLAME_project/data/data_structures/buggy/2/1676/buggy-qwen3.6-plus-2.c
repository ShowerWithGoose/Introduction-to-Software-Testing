#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LL long long
#define DD double
#define clear(); {int a = s1[t1-1], b = s1[t1]; s1[--t1] = calc(s2[t2], a, b); --t2;}

int s1[100], t1; // @@ [Global variables t1 and t2 are not initialized to 0, leading to undefined behavior when used as indices.]
char s2[100], t2; // @@ [Global variables t1 and t2 are not initialized to 0, leading to undefined behavior when used as indices.]

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
    while(ch = getchar()) {
        if(ch == ' ') continue;
        if(isdigit(ch)) num = num * 10 + ch - '0';
        else {
            s1[++t1] = num; // @@ [When an operator is encountered, the current number is pushed. However, if the expression starts with a negative number or if logic flows incorrectly, this might push an uninitialized 0. More critically, the logic for handling the first number vs subsequent numbers is mixed with operator processing.]
            num = 0;
            if(ch == '+' || ch == '-') {
                while(t2 > 0) clear(); // @@ [The clear macro uses s2[t2] but does not check if t2 is valid before accessing in the macro expansion context properly relative to the loop condition here, though the condition t2>0 is present. The main issue is logical precedence handling.]
            }
            else if(ch == '*' || ch == '/') {
                while((s2[t2] == '*' || s2[t2] == '/') && t2 > 0) clear(); // @@ [Accessing s2[t2] before checking t2 > 0 leads to out-of-bounds access or using uninitialized memory if t2 is 0. The condition should check t2 > 0 first.]
            }
            if(ch != '=') s2[++t2] = ch;
        }
        if(ch == '=') break;
    }
    while(t2 > 0) clear();
    printf("%d", s1[1]); // @@ [The final result is stored in s1[1] only if the stack logic is perfectly aligned. Due to the initialization error of t1/t2 and potential off-by-one errors in stack management (using 1-based indexing without proper init), this index is likely incorrect or the value is wrong.]
    return 0;
}