#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[105];
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause buffer overflow. Also, in some environments, 'gets' is not available, leading to compilation error.]
    int l = strlen(s);
    int n = 0, n1 = 0;
    if (s[0] == '0') {
        while (1) {
            if (s[n + 2] == '0')
                n++;
            else
                break;
        } // @@ [Potential out-of-bounds access: if input is "0.0", then n+2 may exceed string length, causing undefined behavior or crash.]
        printf("%c", s[n + 2]);
        if (s[n + 4] != '\n') // @@ [Incorrect boundary check: '\n' may not be in the string (e.g., if input ends with '\0' only), and n+4 can easily go out of bounds.]

            printf(".");
        for (int k = n + 3; k < l; k++) {
            printf("%c", s[k]);

        }

        printf("e-");
        printf("%d\n", n + 1);
    }
    if (s[0] != '0') { // @@ [This should be 'else if' to avoid processing both branches when s[0]=='0'; leads to incorrect double output for numbers starting with '0'.]
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

            } // @@ [If there's no '.' in the string (though problem says there is), this loop runs forever. But more critically, after loop, n1 is index of '.', so exponent should be n1-1, but printing logic includes all digits including those after decimal without proper handling.]
            printf("%c.", s[0]);
            for (int k2 = 1; k2 < l; k2++) {
                if (s[k2] == '.')
                    continue;
                else
                    printf("%c", s[k2]);
            } // @@ [This prints all non-decimal-point digits after the first, which may include trailing zeros or too many digits; violates requirement that base has only one digit before decimal and rest after without trailing zeros.]

            printf("e");
            printf("%d", n1 - 1);
        }
    }
    return 0;
}