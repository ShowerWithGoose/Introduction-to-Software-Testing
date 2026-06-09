#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[105];
    gets(s);
    int l = strlen(s);
    int n = 0, n1 = 0;
    if (s[0] == '0') {
        while (1) {
            if (s[n + 2] == '0')
                n++;
            else
                break;
        }
        printf("%c", s[n + 2]);
        if (s[n + 4] != '\n') // @@ out-of-bounds access for small numbers (e.g., "0.5"); also uses '\n' which is not present (string from gets does not contain newline); should check if there are remaining digits.

            printf(".");
        for (int k = n + 3; k < l; k++) {
            printf("%c", s[k]);

        }

        printf("e-");
        printf("%d\n", n + 1); // @@ extraneous newline; output should not include newline (reference program does not print newline)
    }
    if (s[0] != '0') {
        if (s[1] == '.') {
            printf("%c.", s[0]);
            for (int k1 = 2; k1 < l; k1++)
                printf("%c", s[k1]);
            printf("e0");
        } else {
            n1 = 0;
            while (1) {

                if (s[n1] != '.')
                    n1++;
                else
                    break;

            }
            printf("%c.", s[0]);
            for (int k2 = 1; k2 < l; k2++) {
                if (s[k2] == '.')
                    continue;
                else
                    printf("%c", s[k2]);
            }

            printf("e");
            printf("%d", n1 - 1);
        }
    }
    return 0;
}