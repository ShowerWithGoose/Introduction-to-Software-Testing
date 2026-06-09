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
        if (s[n + 4] != '\n') @@ // This condition is incorrect: it assumes there are at least 5 characters and checks for '\n' which may not be present; also, it forces a decimal point even when unnecessary (e.g., only one significant digit remains).
            printf(".");
        for (int k = n + 3; k < l; k++) {
            printf("%c", s[k]);

        }

        printf("e-");
        printf("%d\n", n + 1);
    }
    if (s[0] != '0') {
        if (s[1] == '.') {
            printf("%c.", s[0]); @@ // Incorrectly prints a decimal point even when the normalized form should be an integer (only one digit total); e.g., "5.0" should become "5e0", not "5.e0".
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
            printf("%c.", s[0]); @@ // Always prints a decimal point, but scientific notation should omit the decimal point if there's only one significant digit (e.g., "123.45" -> "1.2345e2", but "5" -> "5e0", not "5.e0").
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