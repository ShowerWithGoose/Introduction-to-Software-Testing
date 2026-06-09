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
    while(ch = getchar()) { // @@ [The condition `ch = getchar()` assigns the character but doesn't check for EOF properly. Also, `getchar()` returns `int`, not `char`, so using `char ch` can cause issues with EOF comparison. Moreover, the loop condition should be `while ((ch = getchar()) != EOF && ch != '=')` or similar. But more critically, the assignment in condition is missing parentheses for correct precedence if used as loop control, though here it's syntactically valid but logically flawed because it continues even when ch is 0 (null byte), and stops only when ch is 0, which never happens for normal input ending with '='. Actually, the real issue is that `while(ch = getchar())` will exit only when `getchar()` returns 0 (null character), but standard input doesn't contain null; it ends with '='. So the loop may not terminate correctly or may process beyond '='. However, there's a `break` on '=', so maybe it works? But the bigger problem is: `ch` is declared as `char`, but `getchar()` returns `int` to accommodate EOF. If `char` is signed, EOF (-1) becomes 255 or similar, never 0, so loop never exits on EOF. But test case ends with '=', so maybe not the main issue. However, the actual compilation error likely comes from the macro `clear()` being used in a context that produces invalid syntax.]
        if(ch == ' ') continue;
        if(isdigit(ch)) num = num * 10 + ch - '0';
        else {
            s1[++t1] = num;
            num = 0;
            if(ch == '+' || ch == '-') {
                while(t2 > 0) clear(); // @@ [The macro `clear()` expands to a block `{...}` which is not a single statement. Using it in `while(t2 > 0) clear();` becomes `while(t2 > 0) { ... };` which is syntactically valid, BUT the semicolon after the macro expansion creates an empty statement after the block, which is harmless. However, the real issue is that the macro uses `t1-1` and `t1` without checking if there are enough operands. But the compilation error mentioned is "gcc: not found", which is not a code error—it's an environment issue. However, the problem states "Error type: Compilation Error", so we must find a syntax error. Looking closely: the macro definition `#define clear(); {...}` has a semicolon inside the macro name part. This is invalid preprocessor syntax. The correct form is `#define clear() {...}` without the semicolon after `clear()`. The current definition defines a macro named `clear` with replacement text `; {...}`, so when you write `clear();`, it becomes `; {...}();` — which is a syntax error. That’s the real compilation error.]
            }
            else if(ch == '*' || ch == '/') {
                while((s2[t2] == '*' || s2[t2] == '/') && t2 > 0) clear(); // @@ [Same macro issue as above]
            }
            if(ch != '=') s2[++t2] = ch;
        }
        if(ch == '=') break;
    }
    while(t2 > 0) clear(); // @@ [Same macro issue]
    printf("%d", s1[1]);
    return 0;
}