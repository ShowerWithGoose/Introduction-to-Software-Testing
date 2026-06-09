#include <stdio.h>

int main() {
    char c[101];//
    gets(c); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow and is removed in C11. Also, many compilers (like GCC) no longer support it by default, leading to compilation errors.]
    for (int i = 0; c[i]; i++) {
        if (c[i] == '-') {
            if (('0' <= c[i - 1] && c[i - 1] <= '9' ) && ('0' <= c[i + 1] && c[i + 1] <= '9')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] + 1 < c[i + 1]; c[i - 1]++) { // @@ [The loop initializer 'c[i - 1]' does nothing; it should declare a loop variable. Also, modifying 'c[i - 1]' corrupts the original string, affecting subsequent iterations.]
                        printf("%c", c[i - 1] + 1);
                    }
                }
            } else if (('a' <= c[i - 1] && c[i - 1] <= 'z' ) && ('a' <= c[i + 1] && c[i + 1] <= 'z')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] + 1 < c[i + 1]; c[i - 1]++) { // @@ [Same issue: invalid for-loop syntax and modifies original string data.]
                        printf("%c", c[i - 1] + 1);
                    }
                }
            } else if (('A' <= c[i - 1] && c[i - 1] <= 'Z' ) && ('A' <= c[i + 1] && c[i + 1] <= 'Z')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] < c[i + 1]; c[i - 1]++) { // @@ [Same problem: incorrect for-loop structure and destructive modification of input array.]
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