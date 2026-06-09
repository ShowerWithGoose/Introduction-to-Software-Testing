#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LL long long
#define DD double
#define clear(); {int a = s1[t1-1], b = s1[t1]; s1[--t1] = calc(s2[t2], a, b); --t2;}

int s1[100], t1; // @@ [Global variables t1 and t2 are not initialized to 0, leading to undefined behavior when used as indices]
char s2[100], t2; // @@ [Global variables t1 and t2 are not initialized to 0, leading to undefined behavior when used as indices]

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
            s1[++t1] = num; // @@ [When an operator is encountered, the current number is pushed. However, if the expression starts with a negative number or if logic flows incorrectly, this might push an uninitialized 0. More critically, the logic for handling the first number vs subsequent numbers is flawed because it pushes 'num' even when 'num' hasn't been fully parsed for the next operand yet, or pushes 0 if the previous token was an operator. But the main issue is that `num` is reset to 0 immediately after pushing. If the input is "10 +", it pushes 10. Then reads '+'. Pushes 10. Resets num to 0. Then reads next number. This part is actually okay for standard infix parsing IF the stack logic is correct. The real error is in the `clear` macro and stack management.]
            num = 0;
            if(ch == '+' || ch == '-') {
                while(t2 > 0) clear(); // @@ [The clear macro uses s2[t2] but does not decrement t2 inside the macro for the operator stack, it only decrements t2 at the end of the macro definition? No, look at macro: `s1[--t1] = calc(s2[t2], a, b); --t2;`. It calculates using s2[t2] then decrements t2. This implies s2 is 1-indexed or t2 points to top. If t2 is 0 initially, this loop condition `t2 > 0` is safe. However, the order of operands in `calc` is `calc(op, a, b)` where `a` is `s1[t1-1]` and `b` is `s1[t1]`. In `s1[--t1] = ...`, it pops the result back into the position of `a`. This effectively replaces the left operand with the result. This is a valid stack reduction strategy. BUT, look at `clear()` usage. `s2[t2]` is the operator. `s1[t1-1]` is left operand, `s1[t1]` is right operand. Result goes to `s1[t1-1]` (after --t1). Then `--t2` pops operator. This seems logically consistent for a 1-based stack. The problem is likely initialization or the specific handling of the first element.]
            }
            else if(ch == '*' || ch == '/') {
                while((s2[t2] == '*' || s2[t2] == '/') && t2 > 0) clear(); // @@ [Same potential issues with uninitialized t2. Also, checking s2[t2] before checking t2 > 0 in the condition `(s2[t2] == ... && t2 > 0)` is dangerous if t2 is 0 or garbage, as it accesses s2[0] or s2[garbage]. It should be `t2 > 0 && (s2[t2] == ...)`]
            }
            if(ch != '=') s2[++t2] = ch;
        }
        if(ch == '=') break;
    }
    while(t2 > 0) clear();
    printf("%d", s1[1]); // @@ [The final result is expected to be at s1[1] if the stack reduces correctly to a single element. However, due to the initialization error of t1 and t2, the indices are off. If t1 and t2 start at garbage values, everything fails. Even if they started at 0, `s1[++t1]` makes t1=1 for the first number. `s2[++t2]` makes t2=1 for the first operator. The reduction logic `s1[--t1]` reduces t1. If we have `10 + 20`, t1 becomes 2. `clear` uses `s1[1]` and `s1[2]`, stores result in `s1[1]`, t1 becomes 1. t2 becomes 0. Final print `s1[1]` is correct. So the logic holds IF initialized. The primary error is lack of initialization.]
    return 0;
}