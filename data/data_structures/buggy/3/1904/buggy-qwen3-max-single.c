#include <stdio.h>
#include <string.h>

int main() {
    char s[105];
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers due to security risks. Use 'fgets' instead.]
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
                printf("%c", s[i + 1 - n]);
        }
        printf("e%d", n);
    }

    return 0;
}