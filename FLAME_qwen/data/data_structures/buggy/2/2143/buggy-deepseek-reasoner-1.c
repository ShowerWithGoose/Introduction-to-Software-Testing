#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
char ques[10000],ques0[10000],sig[1000];
int ans[10000],a[1000];

int main() {
    scanf("%s",ques0); // @@ scanf stops at the first space, so only the first token is read. The expression may contain spaces, causing incomplete input.
    int ans0 = 0, k = 0, m = 0, n = 0, p = 0, q = 0;
    for (int i = 0; ques0[i] != '='; i++) { // @@ if the '=' is not in ques0 (e.g., due to space before it), this loop reads beyond the string, causing undefined behavior.
        if (ques0[i] != ' ') {
            ques[k++] = ques0[i];
        }
    }
    // Missing: ques[k] = '\0'; to null-terminate ques. Without it, the next for loop may run out of bounds.
    k = 0;
    for (int i = 0; ques[i] != '\0'; i++) { // @@ ques is not null-terminated, so this loop may access memory beyond the array.
        if (ques[i] >= '0' && ques[i] <= '9') {
            while (ques[i + 1] <= '9' && ques[i + 1] >= '0') {
                p++, i++;
            }
            for (int j = i; j >= i - p; j--) {
                ans[m] += (ques[j] - '0') * pow(10, i - j); // @@ ans[m] is uninitialized, adding to garbage. Also pow may give imprecise results for large integers.
            }
            m++, p = 0;
        }
        else {
            sig[n++] = ques[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (sig[i] == '*') {
            ans[p] *= ans[i + 1]; // @@ ans[p] and ans[i+1] are not guaranteed initialized. p is reused from digit parsing and may not reflect the correct index.
            a[q]++; // @@ a[q] is uninitialized, incrementing garbage.
        }
        else if (sig[i] == '/') {
            ans[p] /= ans[i + 1]; // @@ same issues as above.
            a[q]++; // @@ same.
        }
        else {
            ques0[k++] = sig[i];
            p = i + 1, q++, a[q] = a[q - 1]; // @@ a[q-1] is likely uninitialized, and the index logic for p is incorrect.
        }
    }
    ans0 = ans[0]; // @@ ans[0] may not have been set properly, leading to garbage.
    for (int i = 0; i < k; i++) {
        if (ques0[i] == '+') {
            ans0 += ans[i + 1 + a[i]]; // @@ a[i] contains undefined values, so the index is unpredictable.
        }
        else {
            ans0 -= ans[i + 1 + a[i]]; // @@ same.
        }
    }
    printf("%d", ans0);
    return 0;
}