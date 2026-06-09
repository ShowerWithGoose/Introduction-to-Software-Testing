#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[105];
    gets(s); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    int l = strlen(s);
    int n = 0, n1 = 0;
    if (s[0] == '0') {
        while (1) {
            if (s[n + 2] == '0')
                n++;
            else
                break;
        } // @@ [Potential out-of-bounds access: if input is "0.0", then n+2 may exceed string length, leading to undefined behavior or crash]
        printf("%c", s[n + 2]);
        if (s[n + 4] != '\n') // @@ [Incorrect boundary check: strings from gets() are null-terminated, not newline-terminated; also n+4 may be out of bounds]

            printf(".");
        for (int k = n + 3; k < l; k++) {
            printf("%c", s[k]);

        }

        printf("e-");
        printf("%d\n", n + 1);
    }
    if (s[0] != '0') { // @@ [Should be 'else if' to avoid reprocessing cases already handled by the first 'if'; leads to incorrect output for numbers starting with '0']
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

            } // @@ [If there's no '.' in the string (though problem says there is), this loop runs forever; but more critically, assumes '.' exists without validation]
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