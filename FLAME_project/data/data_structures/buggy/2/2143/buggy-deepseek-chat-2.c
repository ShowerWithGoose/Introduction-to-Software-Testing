#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
char ques[10000],ques0[10000],sig[1000];
int ans[10000],a[1000];

int main() {
    scanf("%s",ques0);
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
                ans[m] += (ques[j] - '0') * pow(10, i - j); // @@ [Using pow() for integer powers may cause floating-point precision issues and requires linking with -lm; also, the logic for extracting multi-digit numbers is flawed because p is not reset properly and the loop conditions are incorrect]
            }
            m++, p = 0;
        }
        else {
            sig[n++] = ques[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (sig[i] == '*') {
            ans[p] *= ans[i + 1]; // @@ [The index p is not correctly updated; it should track the current position in ans for multiplication/division, but p is only set in the else branch, leading to incorrect accumulation]
            a[q]++;
        }
        else if (sig[i] == '/') {
            ans[p] /= ans[i + 1]; // @@ [Same issue as above; p is not correctly maintained for consecutive * and / operations]
            a[q]++;
        }
        else {
            ques0[k++] = sig[i];
            p = i + 1, q++, a[q] = a[q - 1]; // @@ [The logic for updating p and a is incorrect; p should be the index of the next operand, but using i+1 is wrong because i is the operator index, not operand index]
        }
    }
    ans0 = ans[0];
    for (int i = 0; i < k; i++) {
        if (ques0[i] == '+') {
            ans0 += ans[i + 1 + a[i]]; // @@ [The indexing using a[i] is flawed; a[i] is supposed to track skipped positions due to * and /, but the logic is incorrect and leads to out-of-bounds or wrong values]
        }
        else {
            ans0 -= ans[i + 1 + a[i]]; // @@ [Same issue as above; incorrect indexing due to flawed a array logic]
        }
    }
    printf("%d", ans0);
}