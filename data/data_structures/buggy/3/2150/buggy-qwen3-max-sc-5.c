#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[105];
    gets(s); @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard. Also, the test environment may not have gcc installed, but the primary code issue is use of gets().]
    int l = strlen(s);
    int n = 0, n1 = 0;
    if (s[0] == '0') {
        while (1) {
            if (s[n + 2] == '0')
                n++;
            else
                break;
        } @@ [Infinite loop possible if all characters after "0." are zeros or if input ends before n+2; also accesses beyond string length without bounds check.]
        printf("%c", s[n + 2]);
        if (s[n + 4] != '\n') @@ [Incorrect index: should check for end of string ('\0'), not '\n'; also n+4 may be out of bounds.]

            printf(".");
        for (int k = n + 3; k < l; k++) {
            printf("%c", s[k]);

        }

        printf("e-");
        printf("%d\n", n + 1);
    }
    if (s[0] != '0') { @@ [Should be 'else if' to avoid reprocessing numbers starting with '0' that already entered first block.]
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

            } @@ [Infinite loop if there's no '.' in the string; no bounds check against 'l'.]
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