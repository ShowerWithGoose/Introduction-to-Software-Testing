#include <stdio.h>

int main() {
    char c[101];//
    gets(c); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers no longer support it, leading to compilation errors.]
    for (int i = 0; c[i]; i++) {
        if (c[i] == '-') {
            if (('0' <= c[i - 1] && c[i - 1] <= '9' ) && ('0' <= c[i + 1] && c[i + 1] <= '9')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] + 1 < c[i + 1]; c[i - 1]++) { // @@ [The loop initialization 'c[i - 1]' does nothing; more critically, modifying 'c[i - 1]' inside the loop alters the original string, causing incorrect behavior and potential out-of-bound issues in subsequent iterations. Also, the loop condition logic is flawed—it should iterate from c[i-1]+1 up to c[i+1]-1 inclusive.]
                        printf("%c", c[i - 1] + 1);
                    }
                }
            } else if (('a' <= c[i - 1] && c[i - 1] <= 'z' ) && ('a' <= c[i + 1] && c[i + 1] <= 'z')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] + 1 < c[i + 1]; c[i - 1]++) { // @@ [Same issue as above: modifies original string and uses incorrect loop structure.]
                        printf("%c", c[i - 1] + 1);
                    }
                }
            } else if (('A' <= c[i - 1] && c[i - 1] <= 'Z' ) && ('A' <= c[i + 1] && c[i + 1] <= 'Z')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] < c[i + 1]; c[i - 1]++) { // @@ [This loop condition 'c[i - 1] < c[i + 1]' will cause one extra iteration compared to the other cases, and again modifies the original string. Moreover, inconsistent logic across digit/lower/upper cases leads to incorrect expansion (e.g., for A-D, it prints B, C, D instead of B, C).]
                        printf("%c", c[i - 1] + 1);
                    }
                }
            } else {
                printf("%c", c[i]);
            }
        } else {
            printf("%c", c[i]);
        }
    }

    return 0;
}