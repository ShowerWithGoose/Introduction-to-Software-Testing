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
        if (s[n + 4] != '\n') // @@ The condition checks for a specific character at an incorrect offset to determine if there are remaining significant digits. It should check if there are any non-zero or valid digits remaining after the first significant digit found at s[n+2]. For input "0.9", n=0, s[2]='9'. The loop breaks. Then it checks s[4]. s[4] is likely '\0' or garbage, not necessarily '\n'. The logic for determining if a decimal point is needed is flawed. It should check if there are more significant digits after the first one. In "0.9", there are no digits after '9', so no decimal point. In "0.09", n becomes 1 (s[2]='0'), then s[3]='9'. Print '9'. Check s[5]. If s[5] is end of string, no dot. The current logic `s[n+4] != '\n'` is unreliable and incorrect for determining trailing digits.
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