#include <stdio.h>
#include <string.h>

int main() {
    char s[105];
    gets(s); // @@ use of deprecated/removed function 'gets' may cause compilation error in C11 or with strict flags.
    int l = strlen(s), n;
    if (s[0] != '0') {
        for (int i = 0; i <= l - 1; i++) { // @@ variable declaration inside for loop is not allowed in C89, causing compilation error.
            if (s[i] == '.') {
                n = i - 1;
                break;
            }
        }
        for (int i = 0; i <= l - 1; i++) { // @@ same as above.
            if (i == 1)
                printf(".");
            if (s[i] != '.')
                printf("%c", s[i]);
        }
        printf("e%d", n);
    } else {
        for (int i = 0; i <= l - 1; i++) { // @@ same as above.
            if (s[i] != '0' && s[i] != '.') {
                n = 1 - i;
                break;
            }
        }
        for (int i = 0; i <= l + n - 2; i++) { // @@ same as above.
            if (i == 1)
                printf(".");
            if (s[i] != '.')
                printf("%c", s[i + 1 - n]);
        }
        printf("e%d", n);
    }

    return 0;
}