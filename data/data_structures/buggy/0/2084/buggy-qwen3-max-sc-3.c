#include <stdio.h>

int main() {
    char c[101];//
    gets(c); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings. It should be replaced with 'fgets'.]
    for (int i = 0; c[i]; i++) {
        if (c[i] == '-') {
            if (('0' <= c[i - 1] && c[i - 1] <= '9' ) && ('0' <= c[i + 1] && c[i + 1] <= '9')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] + 1 < c[i + 1]; c[i - 1]++) { // @@ [The loop initializer 'c[i - 1]' does nothing; also, modifying 'c[i - 1]' inside the loop alters the original string, which can lead to incorrect behavior in subsequent iterations or comparisons.]
                        printf("%c", c[i - 1] + 1);
                    }
                }
            } else if (('a' <= c[i - 1] && c[i - 1] <= 'z' ) && ('a' <= c[i + 1] && c[i + 1] <= 'z')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] + 1 < c[i + 1]; c[i - 1]++) { // @@ [Same issue as above: modifying 'c[i - 1]' corrupts the original string and leads to undefined behavior.]
                        printf("%c", c[i - 1] + 1);
                    }
                }
            } else if (('A' <= c[i - 1] && c[i - 1] <= 'Z' ) && ('A' <= c[i + 1] && c[i + 1] <= 'Z')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] < c[i + 1]; c[i - 1]++) { // @@ [Same issue: modifying 'c[i - 1]' changes the input string during iteration, causing logic errors. Also, this loop condition differs from the others and may produce off-by-one errors.]
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