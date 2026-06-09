#include <stdio.h>
#include <string.h>

int main() {
    char s[105];
    gets(s);
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
            if (s[i] != '.') // @@ This condition checks the original string index i instead of the character to be printed (s[i+1-n]); it should be 'if (s[i+1-n] != '.')' to avoid skipping digits when i corresponds to the original decimal point.
                printf("%c", s[i + 1 - n]);
        }
        printf("e%d", n);
    }

    return 0;
}