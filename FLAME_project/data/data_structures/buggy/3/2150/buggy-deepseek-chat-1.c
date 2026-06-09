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
        if (s[n + 4] != '\n') // @@ This condition incorrectly checks for newline instead of checking if there are more digits after the first non-zero digit. For input "0.9", n=0, s[4] is '\0', so the condition fails and no decimal point is printed, but the output should be "9e-1" without a decimal point. However, the logic for printing the decimal point is flawed; it should only print a decimal point if there are additional digits after the first significant digit.

            printf(".");
        for (int k = n + 3; k < l; k++) {
            printf("%c", s[k]);

        }

        printf("e-");
        printf("%d\n", n + 1);
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