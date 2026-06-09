#include <stdio.h>
#include <string.h>

int main() {
    char s[105];
    gets(s);
    int l = strlen(s), n;
    if (s[0] != '0') {
        for (int i = 0; i <= l - 1; i++) {
            if (i == 1)
                printf(".");
            if (s[i] != '.')
                printf("%c", s[i]);
        }
        printf("e%d", n);
    } else {
        for (int i = 0; i <= l + n - 2; i++) {
            if (i == 1)
                printf(".");
            if (s[i] != '.') // @@ [Error: This condition incorrectly skips printing the character when i equals the index of the decimal point in the original string, causing the first digit after the decimal point to be omitted. It should check s[i+1-n] or simply remove the condition.]
                printf("%c", s[i + 1 - n]);
        }
        printf("e%d", n);
    }

    return 0;
}