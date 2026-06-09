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
        if (s[n + 4] != '\n') // @@ [The condition checks for a character at an incorrect offset to determine if there are significant digits after the first non-zero digit. For input "0.9", l=3, s[3]='\0'. The loop finds n=0. s[2]='9'. The code prints '9'. Then it checks s[4] which is out of bounds or garbage, potentially printing a decimal point when it shouldn't. More importantly, the logic for determining if there are trailing digits to print after the decimal point is flawed. It should check if there are any non-zero digits remaining after the first significant digit found. For "0.9", there are no digits after '9', so no decimal point should be printed. The current logic `s[n+4] != '\n'` is arbitrary and incorrect for detecting the end of significant digits.]

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