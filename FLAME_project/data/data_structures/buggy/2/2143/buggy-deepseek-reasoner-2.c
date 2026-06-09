#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h> // @@ [Unnecessary inclusion of math.h; the use of pow() causes linker error - should not be used here]
char ques[10000],ques0[10000],sig[1000];
int ans[10000],a[1000];

int main() {
    scanf("%s",ques0); // @@ [scanf reads only a single word, ignoring spaces; the input expression may contain spaces, so entire expression may not be read. Should use fgets or gets.]
    int ans0 = 0, k = 0, m = 0, n = 0, p = 0, q = 0;
    for (int i = 0; ques0[i] != '='; i++) { // @@ [If ques0 does not contain '=' due to incomplete input, loop may go out of bounds or run indefinitely. Also, condition should check for null terminator to avoid buffer overrun.]
        if (ques0[i] != ' ') {
            ques[k++] = ques0[i];
        }
    }
    k = 0;
    for (int i = 0; ques[i] != '\0'; i++) {
        if (ques[i] >= '0' && ques[i] <= '9') {
            while (ques[i + 1] <= '9' && ques[i + 1] >= '0') { // @@ [Potential out-of-bounds when i+1 accesses beyond string terminator; also logic for p is flawed.]
                p++, i++;
            }
            for (int j = i; j >= i - p; j--) {
                ans[m] += (ques[j] - '0') * pow(10, i - j); // @@ [Use of pow() is problematic: requires linking math library, introduces floating-point errors, and is inefficient. Should use integer arithmetic to reconstruct number.]
            }
            m++, p = 0;
        }
        else {
            sig[n++] = ques[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (sig[i] == '*') {
            ans[p] *= ans[i + 1]; // @@ [Variable p is not properly set for the left operand of multiplication; also ans index may be incorrect due to missing operand tracking.]
            a[q]++;
        }
        else if (sig[i] == '/') {
            ans[p] /= ans[i + 1]; // @@ [Same issue as above; integer division may produce incorrect results due to precedence not handled properly.]
            a[q]++;
        }
        else {
            ques0[k++] = sig[i]; // @@ [Overwrites the input buffer ques0 which still contains original string; causes confusion later.]
            p = i + 1, q++, a[q] = a[q - 1];
        }
    }
    ans0 = ans[0]; // @@ [Assuming ans[0] is the first operand, but after multiplication loop, ans[0] may have been modified incorrectly.]
    for (int i = 0; i < k; i++) {
        if (ques0[i] == '+') {
            ans0 += ans[i + 1 + a[i]]; // @@ [Indexing with a[i] is unclear and likely incorrect; does not correctly access operands after multiplication/division.]
        }
        else {
            ans0 -= ans[i + 1 + a[i]];
        }
    }
    printf("%d", ans0);
}