#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[10000];
    scanf("%s", s);
    for (int i = 0; i <= strlen(s) - 1; i++) {
        if (s[i] == '-') {
            if (islower(s[i - 1]) && islower(s[i + 1])) {
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            }
            if (isupper(s[i - 1]) && isupper(s[i + 1])) {
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            }
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) {
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            } else {
                printf("-"); @@ [The 'else' only applies to the last 'if' (isdigit), not the entire group. This causes '-' to be printed even when one of the earlier conditions (like islower or isupper) was true, leading to duplicate output or incorrect behavior. Additionally, no bounds checking for i-1 or i+1 may cause out-of-bounds access when '-' is at the start or end of the string.]
            }
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}