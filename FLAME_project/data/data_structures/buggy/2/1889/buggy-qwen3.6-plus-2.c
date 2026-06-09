#include <stdio.h>
#include <string.h>

int main() {
    int num[5] = {0};
    char pnt[5] = {'+'};
    scanf("%d %c", &num[1], &pnt[1]);
    while (pnt[1] != '=') {
        scanf("%d %c", &num[2], &pnt[2]);
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
            num[1] = num[1] + num[2];
        } else if (pnt[1] == '-') {
            num[1] = num[1] - num[2];
        }
        pnt[1] = pnt[2]; // @@ The logic for updating the operator is flawed. When the inner while loop finishes, pnt[2] holds the next additive operator (+, -, or =). However, if the expression ends with '=', pnt[2] becomes '='. The outer loop condition checks pnt[1]. By assigning pnt[2] to pnt[1], we update the current operator. But there is a subtle issue: if the last operation was part of a high-precedence chain, pnt[2] might be '='. The real issue is that `num[1]` accumulates the result, but `num[2]` is overwritten in the next iteration of the outer loop before being used if the previous operator was additive. Actually, the main bug is that `num[1]` is used as the accumulator for the left-hand side of the additive expression, but `num[2]` is the right-hand side. When `pnt[1]` is updated to `pnt[2]`, it correctly gets the next operator. However, the variable `num[1]` holds the running total. The problem arises because `num[2]` is not reset or managed correctly across iterations relative to `num[1]`. Specifically, after `num[1] = num[1] + num[2]`, `num[1]` holds the new sum. In the next iteration, `scanf` reads into `num[2]`. This seems correct for standard precedence parsing. Let's look closer at the failure case: `24 / 4 / 3 / 2 + 100 ...`.
        // Step 1: Reads 24, /. Inner loop: reads 4, /. 24/4=6. Reads 3, /. 6/3=2. Reads 2, +. 2/2=1. pnt[2] is '+'. Exit inner.
        // pnt[1] is '/'. Wait, initial pnt[1] was '/'.
        // Initial: num[1]=24, pnt[1]='/'.
        // Outer loop start. pnt[1] != '='.
        // scanf -> num[2]=4, pnt[2]='/'.
        // Inner loop: pnt[2]=='/'. scanf -> num[3]=3, pnt[3]='/'. num[2]=4/3=1. pnt[2]='/'.
        // Inner loop: pnt[2]=='/'. scanf -> num[3]=2, pnt[3]='+'. num[2]=1/2=0. pnt[2]='+'.
        // Inner loop exits.
        // if (pnt[1] == '+') ... else if (pnt[1] == '-'). pnt[1] is '/'. Neither matches.
        // So num[1] remains 24. This is the bug. The code only handles + and - for combining num[1] and num[2]. It assumes num[1] has already been processed by higher precedence operators or is the start. But here, the first operator was '/', which is high precedence. The reference code handles this by always processing * and / immediately on num[1]. This buggy code tries to process * and / on num[2] inside the inner loop, but it fails to combine the initial num[1] with the result of the high-precedence chain if the operator preceding num[1] (stored in pnt[1]) was * or /.
        // In the reference code, pnt[0] stores the pending additive operator. num[0] is the accumulator. num[1] is the current term being built.
        // In this buggy code, pnt[1] is the operator BEFORE num[1]? No, scanf("%d %c", &num[1], &pnt[1]) reads number then operator. So pnt[1] is the operator AFTER num[1].
        // If pnt[1] is * or /, it should have been handled. But the code enters the outer loop, reads num[2] and pnt[2]. Then it handles * and / between num[2] and subsequent numbers. It NEVER handles * or / between num[1] and num[2] if pnt[1] was * or /. It only handles + and -.
        // Therefore, if the expression starts with high precedence operations or has them in sequence, the connection between num[1] and num[2] via * or / is ignored if pnt[1] is * or /.
        // Correction: The code needs to handle the case where pnt[1] is * or / by combining num[1] and num[2] before checking + or -. Or, more simply, the structure should mimic the reference: maintain an accumulator and a current term.
    }

    printf("%d", num[1]);
    return 0;
}