#include <stdio.h>

int main() {
    char c[101];//
    gets(c); // @@ gets is deprecated and removed in C11, causing compilation errors; use scanf("%s", c) or fgets instead.
    for (int i = 0; c[i]; i++) {
        if (c[i] == '-') {
            if (('0' <= c[i - 1] && c[i - 1] <= '9' ) && ('0' <= c[i + 1] && c[i + 1] <= '9')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] + 1 < c[i + 1]; c[i - 1]++) { // @@ Modifies original string c[i-1] corrupting data; uses < instead of <= missing the last expanded character.
                        printf("%c", c[i - 1] + 1); // @@ Prints based on modified c[i-1], leading to incorrect output.
                    }
                }
            } else if (('a' <= c[i - 1] && c[i - 1] <= 'z' ) && ('a' <= c[i + 1] && c[i + 1] <= 'z')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] + 1 < c[i + 1]; c[i - 1]++) { // @@ Same error: modifies original string and misses last character due to < condition.
                        printf("%c", c[i - 1] + 1); // @@ Same error: relies on modified array element.
                    }
                }
            } else if (('A' <= c[i - 1] && c[i - 1] <= 'Z' ) && ('A' <= c[i + 1] && c[i + 1] <= 'Z')) {
                if (c[i - 1] < c[i + 1]) {
                    for (c[i - 1]; c[i - 1] < c[i + 1]; c[i - 1]++) { // @@ Same error: modifies original string; condition < misses last character.
                        printf("%c", c[i - 1] + 1); // @@ Same error: relies on modified array element.
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