#include <stdio.h>
#include <string.h>

int main() {
    char s[105];
    gets(s); // @@ [gets() is unsafe and may cause buffer overflow; also, it is removed from C11 standard, but the main issue is that the problem expects input via scanf, and gets() may not work correctly in all environments]
    int l = strlen(s), n;
    if (s[0] != '0') {
        for (int i = 0; i <= l - 1; i++) {
            if (s[i] == '.') {
                n = i - 1;
                break;
            }
        }
        for (int i = 0; i <= l - 1; i++) {
            if (i == 1)
                printf(".");
            if (s[i] != '.')
                printf("%c", s[i]);
        }
        printf("e%d", n);
    } else {
        for (int i = 0; i <= l - 1; i++) {
            if (s[i] != '0' && s[i] != '.') {
                n = 1 - i;
                break;
            }
        }
        for (int i = 0; i <= l + n - 2; i++) {
            if (i == 1)
                printf(".");
            if (s[i] != '.')
                printf("%c", s[i + 1 - n]); // @@ [When n is negative, i + 1 - n may access out-of-bounds indices of s, leading to undefined behavior]
        }
        printf("e%d", n);
    }

    return 0;
}