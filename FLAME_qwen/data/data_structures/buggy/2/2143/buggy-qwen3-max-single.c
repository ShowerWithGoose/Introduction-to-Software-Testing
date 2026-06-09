#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
char ques[10000],ques0[10000],sig[1000];
int ans[10000],a[1000];

int main() {
    scanf("%s",ques0); // @@ [Using scanf with %s reads only until first whitespace, but input expression may contain spaces; this causes incomplete reading of the expression]
    int ans0 = 0, k = 0, m = 0, n = 0, p = 0, q = 0;
    for (int i = 0; ques0[i] != '='; i++) {
        if (ques0[i] != ' ') {
            ques[k++] = ques0[i];
        }
    }
    k = 0;
    for (int i = 0; ques[i] != '\0'; i++) {
        if (ques[i] >= '0' && ques[i] <= '9') {
            while (ques[i + 1] <= '9' && ques[i + 1] >= '0') {
                p++, i++;
            }
            for (int j = i; j >= i - p; j--) {
                ans[m] += (ques[j] - '0') * pow(10, i - j); // @@ [Using pow() from math.h for integer powers introduces floating-point inaccuracies; also, ans[m] is not initialized to 0 before accumulation]
            }
            m++, p = 0;
        }
        else {
            sig[n++] = ques[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (sig[i] == '*') {
            ans[p] *= ans[i + 1]; // @@ [Index 'p' is misused here; 'p' was previously used as a digit counter and later reassigned arbitrarily, leading to incorrect operand indexing]
            a[q]++;
        }
        else if (sig[i] == '/') {
            ans[p] /= ans[i + 1]; // @@ [Same indexing error as above; also, division by zero not handled but problem states expression is valid so maybe not critical]
            a[q]++;
        }
        else {
            ques0[k++] = sig[i];
            p = i + 1, q++, a[q] = a[q - 1];
        }
    }
    ans0 = ans[0];
    for (int i = 0; i < k; i++) {
        if (ques0[i] == '+') {
            ans0 += ans[i + 1 + a[i]]; // @@ [The offset 'a[i]' is incorrectly computed and applied; logic for tracking operand positions after * and / reductions is flawed]
        }
        else {
            ans0 -= ans[i + 1 + a[i]]; // @@ [Same issue as above; leads to wrong operands being used for + and -]
        }
    }
    printf("%d", ans0);
}