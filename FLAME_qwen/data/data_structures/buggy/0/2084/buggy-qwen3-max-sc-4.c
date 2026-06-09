#include <stdio.h>

int main() {
    char c[101];//
    gets(c); // @@ [Using gets() is unsafe and deprecated; it can cause buffer overflow. Also, in many modern compilers/environments, gets() is removed entirely, which may lead to compilation errors.]
    for (int i = 0; c[i]; i++) {
        if (c[i] == '-') {
            if (('0' <= c[i - 1] && c[i - 1] <= '9' ) && ('0' <= c[i + 1] && c[i + 1] <= '9')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] + 1 < c[i + 1]; c[i - 1]++) { // @@ [Modifying c[i - 1] inside the loop alters the original string, which affects subsequent iterations and logic. Also, the loop condition and increment are logically flawed: it should use a temporary variable instead of modifying the input array.]
                        printf("%c", c[i - 1] + 1);
                    }
                }
            } else if (('a' <= c[i - 1] && c[i - 1] <= 'z' ) && ('a' <= c[i + 1] && c[i + 1] <= 'z')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] + 1 < c[i + 1]; c[i - 1]++) { // @@ [Same issue: modifying c[i - 1] corrupts the original string and breaks loop logic. Should use a separate loop variable.]
                        printf("%c", c[i - 1] + 1);
                    }
                }
            } else if (('A' <= c[i - 1] && c[i - 1] <= 'Z' ) && ('A' <= c[i + 1] && c[i + 1] <= 'Z')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] < c[i + 1]; c[i - 1]++) { // @@ [Again, modifying c[i - 1] is incorrect. Additionally, this loop condition differs from the others (uses < instead of +1 <), leading to inconsistent expansion behavior.]
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