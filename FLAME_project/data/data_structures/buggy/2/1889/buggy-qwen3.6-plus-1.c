#include <stdio.h>
#include <string.h>

int main() {
    int num[5] = {0};
    char pnt[5] = {'+'};
    scanf("%d %c", &num[1], &pnt[1]);
    while (pnt[1] != '=') {
        scanf("%d %c", &num[2], &pnt[2]); // @@ The logic fails when the operator following a high-precedence chain is '+' or '-'. After processing the inner while loop for '*' or '/', pnt[2] holds the next low-precedence operator (e.g., '+'). The code then updates pnt[1] to this operator. However, in the next iteration of the outer while loop, it immediately reads a new number and operator into num[2] and pnt[2], overwriting the pending low-precedence term's operator context incorrectly or skipping terms. Specifically, the structure assumes a fixed pattern that breaks with multiple sequential low-precedence operators or complex mixing. The main issue is that `pnt[1]` is updated to `pnt[2]` (which might be '+' or '-') at the end of the loop, but the next `scanf` reads the NEXT term. If the expression is `A + B - C`, after processing `A+B`, `pnt[1]` becomes `-`. Then `scanf` reads `C` and the next operator. This part actually looks logically similar to the reference. Let's look closer at the failure case: `24 / 4 / 3 / 2 + ...`.
        // Trace: 
        // 1. Read 24, '/'. pnt[1]='/'.
        // 2. Enter outer while. Read 4, '/'. pnt[2]='/'.
        // 3. Inner while: pnt[2]=='/'. Read 3, '/'. num[2]=4/3=1. pnt[2]='/'.
        // 4. Inner while: pnt[2]=='/'. Read 2, '+'. num[2]=1/2=0. pnt[2]='+'.
        // 5. Inner while exits.
        // 6. pnt[1] is '/'. So we do num[1] (24) / num[2] (0)? No, the reference code accumulates into num[1] inside the inner loop? No, the reference code uses num[1] as the running result of the high-precedence chain. 
        // In the buggy code: num[1] is 24. num[2] became 0.
        // The code checks pnt[1] which is '/'. It does NOT handle '/' in the if/else block below (only + and -). 
        // Ah, the bug is that the initial operator pnt[1] can be '*' or '/', but the accumulation step `if (pnt[1] == '+') ... else if (pnt[1] == '-')` ignores '*' and '/'. 
        // In the first iteration, pnt[1] is '/'. The code skips the accumulation block. Then sets pnt[1] = pnt[2] ('+').
        // So num[1] remains 24. But it should have been updated by the division chain.
        // The reference code handles this by initializing pnt[0] to '+' and num[0] to 0, and always accumulating num[1] into num[0] based on pnt[0]. Then pnt[0] takes pnt[1].
        // The buggy code tries to accumulate into num[1] directly but fails to handle the case where the previous operator (pnt[1]) was * or /, because it only checks for + and -.
        
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
        } // @@ Missing handling for when pnt[1] is '*' or '/'. If pnt[1] is '*' or '/', the result of the high-precedence calculation in num[2] should be combined with num[1] using that operator. Currently, it is ignored, leaving num[1] unchanged from its previous value, which is incorrect for the first term or subsequent terms following a high-precedence operator that wasn't reduced to +/-.
        pnt[1] = pnt[2];
    }

    printf("%d", num[1]);
    return 0;
}