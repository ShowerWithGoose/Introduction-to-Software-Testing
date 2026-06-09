#include <stdio.h>
#include <string.h>

int main() {
    int num[5] = {0};
    char pnt[5] = {'+'};
    scanf("%d %c", &num[1], &pnt[1]); // @@ [Initial parsing assumes first token is a number followed by an operator, but does not handle the case where the expression starts with a negative number or has leading spaces properly; however, more critically, the logic fails to correctly accumulate results across multiple additive terms because it only uses num[1] as accumulator]
    while (pnt[1] != '=') {
        scanf("%d %c", &num[2], &pnt[2]); // @@ [This reads the next number and operator, but if the current operator (pnt[1]) is '+' or '-', and the next operator (pnt[2]) is '*' or '/', it processes the multiplication/division chain correctly. However, after processing that chain, it combines num[1] and num[2] using pnt[1], then sets pnt[1] = pnt[2]. The problem arises when there are multiple additive operations: num[1] is overwritten instead of maintaining a running total.]
        while (pnt[2] == '*' || pnt[2] == '/') {
            scanf("%d %c", &num[3], &pnt[3]);
            if (pnt[2] == '*') {
                num[2] = num[2] * num[3];
            } else if (pnt[2] == '/') {
                num[2] = num[2] / num[3];
            }
            pnt[2] = pnt[3];
        }
        if (pnt[1] == '+') {
            num[1] = num[1] + num[2]; // @@ [Here, num[1] is being updated as the running total, but this approach fails when there are multiple additive terms because it doesn't preserve the overall accumulated value correctly across iterations. For example, in "A op1 B op2 C op3 D =", after processing B op2 C (if op2 is * or /), it does A op1 (result of B op2 C), then sets pnt[1] to op3. But if op3 is again + or -, then in the next iteration, it will read D and combine (A op1 ...) with D using op3 — which is correct in structure, BUT the issue is that the initial value of num[0] is never used, and the accumulator is num[1], which was originally the first number. This works only if the expression starts with a positive number and has no precedence issues beyond two levels. However, the real flaw is that the program does not maintain a separate accumulator for the total sum; it reuses num[1] both as the first operand and as the running total, which breaks when the first term itself is the result of a multiplication/division chain. In the given test case, the first term "24 / 4 / 3 / 2" is processed correctly into num[1] = 1, then "+100" makes num[1]=101, then "-50" → 51, "-40" → 11, then "+ (10*20*30*40 /40 /30)" which is +200 → 211. But the buggy output is 234, suggesting that the multiplication/division part is being miscalculated or applied incorrectly due to operator precedence handling across segments. Actually, looking closer: the main error is that the program assumes that after reading the first number and operator, every subsequent step reads one more number and operator, processes any following * or /, then applies the previous +/-. But the very first operator (pnt[1]) is the one after the first number. So for "24 / 4 / 3 / 2 + ...", the first scanf reads 24 and '/', so pnt[1] is '/', which is not '=' so enters loop. Then it reads 4 and '/', sees pnt[2] is '/', so enters inner while: reads 3 and '/', computes 4/3=1, then pnt[2] becomes '/'; then reads 2 and '+', computes 1/2=0, pnt[2]='+'. Then it checks pnt[1] which is still '/' — but wait! The code then does: if (pnt[1]=='+')... else if (pnt[1]=='-')... but pnt[1] is '/', so it skips both! Then sets pnt[1] = pnt[2] which is '+'. So the result of the division chain (0) is never combined with the initial 24! That's the critical bug. The program only applies + or - from pnt[1], but if the first operator is * or /, it never gets applied to the initial num[1] (which is 24). Instead, it processes the * / chain into num[2], but then ignores combining it with num[1] because pnt[1] is * or /, not + or -. So the 24 is lost, and num[1] remains 24, then later when it does "+100", it becomes 124, etc., leading to wrong result.]
        } else if (pnt[1] == '-') {
            num[1] = num[1] - num[2];
        }
        pnt[1] = pnt[2];
    }

    printf("%d", num[1]);
    return 0;
}