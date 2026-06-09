#include <stdio.h>
#include <string.h>

int main() {
    char s[105];
    gets(s); // @@ gets() is removed in modern C standards and causes compilation errors; should use scanf("%s", s) or fgets()
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
        for (int i = 0; i <= l + n - 2; i++) { // @@ Loop bound is off by one, causing the last significant digit to be omitted; should be i <= l + n - 1
            if (i == 1)
                printf(".");
            if (s[i] != '.') // @@ Incorrectly checks the loop index i instead of the actual character s[i + 1 - n], causing valid digits to be skipped
                printf("%c", s[i + 1 - n]);
        }
        printf("e%d", n);
    }

    return 0;
}