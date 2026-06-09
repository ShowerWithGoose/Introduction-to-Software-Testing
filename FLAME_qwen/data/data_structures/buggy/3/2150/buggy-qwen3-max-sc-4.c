#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[105];
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, 'gets' is removed entirely, leading to a compilation error.]
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
        if (s[n + 4] != '\n') // @@ [This condition is incorrect: the input string does not necessarily contain '\n' as part of the string read by 'gets'; 'gets' discards the newline. Also, accessing s[n+4] may go out of bounds if the string is short (e.g., "0.1").]
            printf(".");
        for (int k = n + 3; k < l; k++) {
            printf("%c", s[k]);

        }

        printf("e-");
        printf("%d\n", n + 1);
    }
    if (s[0] != '0') { // @@ [This should be 'else if' or 'else', because the two conditions (s[0]=='0' and s[0]!='0') are mutually exclusive. Using two separate 'if's causes both blocks to potentially execute if the first block modifies s[0], but more importantly, after handling s[0]=='0', we should not re-check. However, the real issue is logic duplication and possible double-output, but the immediate compilation error is due to 'gets'.]
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