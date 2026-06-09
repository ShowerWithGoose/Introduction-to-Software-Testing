#include <stdio.h>

int main() {
    char c[101];//
    gets(c); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers no longer support it, leading to compilation errors. Use 'fgets' instead.]
    for (int i = 0; c[i]; i++) {
        if (c[i] == '-') {
            if (('0' <= c[i - 1] && c[i - 1] <= '9' ) && ('0' <= c[i + 1] && c[i + 1] <= '9')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] + 1 < c[i + 1]; c[i - 1]++) { // @@ [The loop initializer 'c[i - 1]' does nothing; more critically, modifying 'c[i - 1]' inside the loop alters the original string, which can cause incorrect behavior in subsequent iterations or comparisons. Also, the loop condition may skip the last character.]
                        printf("%c", c[i - 1] + 1);
                    }
                }
            } else if (('a' <= c[i - 1] && c[i - 1] <= 'z' ) && ('a' <= c[i + 1] && c[i + 1] <= 'z')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] + 1 < c[i + 1]; c[i - 1]++) { // @@ [Same issue: modifying 'c[i - 1]' corrupts the input string and leads to undefined behavior; also, the loop condition excludes the upper bound character.]
                        printf("%c", c[i - 1] + 1);
                    }
                }
            } else if (('A' <= c[i - 1] && c[i - 1] <= 'Z' ) && ('A' <= c[i + 1] && c[i + 1] <= 'Z')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] < c[i + 1]; c[i - 1]++) { // @@ [Modifying 'c[i - 1]' is incorrect and destructive; also, this loop prints one extra character beyond the intended range because it prints 'c[i - 1] + 1' even when 'c[i - 1]' equals 'c[i + 1] - 1', which may overshoot.]
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