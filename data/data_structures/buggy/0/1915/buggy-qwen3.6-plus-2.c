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
            if (isupper(s[i - 1]) && isupper(s[i + 1])) { // @@ Should be 'else if' to correctly chain the conditions; otherwise, the final 'else' block executes incorrectly when earlier conditions are true, causing duplicate '-' output.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            }
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) { // @@ Should be 'else if' for the same reason; using independent 'if' statements causes the 'else' to attach only to the last 'if', leading to logical errors in control flow.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            } else {
                printf("-");
            }
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}