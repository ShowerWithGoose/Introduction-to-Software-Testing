#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LL long long
#define DD double
#define clear(); {int a = s1[t1-1], b = s1[t1]; s1[--t1] = calc(s2[t2], a, b); --t2;} // @@ The macro uses t1 and t2 before they are decremented, but the order of operations in the macro body may cause incorrect stack access. Specifically, when t1 is 1, accessing s1[t1-1] (s1[0]) is valid, but the macro assumes t1 >= 2, which may not hold if the expression starts with an operator. Also, the macro does not check for empty stack conditions.

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
    while(ch = getchar()) { // @@ Missing parentheses around assignment in condition; should be while((ch = getchar()) != EOF) to properly check for end-of-file and avoid potential infinite loop.
        if(ch == ' ') continue;
        if(isdigit(ch)) num = num * 10 + ch - '0';
        else {
            s1[++t1] = num; // @@ When the first character is an operator (e.g., '-'), num is 0 and gets pushed onto the stack, which is incorrect for a valid expression starting with a unary minus (not supported per problem description). Also, if there are consecutive operators, num may be incorrectly pushed.
            num = 0;
            if(ch == '+' || ch == '-') {
                while(t2 > 0) clear(); // @@ The clear() macro uses t1 and t2, but t2 is decremented inside the macro, and the while condition checks t2 > 0 before calling clear(), which is correct, but the macro may access s2[t2] after t2 is decremented in a previous call, leading to out-of-bounds access.
            }
            else if(ch == '*' || ch == '/') {
                while((s2[t2] == '*' || s2[t2] == '/') && t2 > 0) clear(); // @@ The condition checks s2[t2] before verifying t2 > 0, which can cause out-of-bounds access when t2 is 0. Should check t2 > 0 first.
            }
            if(ch != '=') s2[++t2] = ch;
        }
        if(ch == '=') break;
    }
    while(t2 > 0) clear();
    printf("%d", s1[1]); // @@ After all operations, the result should be in s1[1] only if the stack has exactly one element. If the expression is malformed or the algorithm fails, s1[1] may not contain the correct result.
    return 0;
}