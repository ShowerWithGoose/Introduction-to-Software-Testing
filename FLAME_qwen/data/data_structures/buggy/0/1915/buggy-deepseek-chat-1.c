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
            if (isupper(s[i - 1]) && isupper(s[i + 1])) { // @@ Error: This should be 'else if' instead of 'if' to avoid printing '-' when the first condition is true but the second is false.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            }
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) { // @@ Error: This should be 'else if' instead of 'if' to avoid printing '-' when the first or second condition is true but the third is false.
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