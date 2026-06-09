#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[10000];
    scanf("%s", s);
    for (int i = 0; i <= strlen(s) - 1; i++) {
        if (s[i] == '-') {
            if (islower(s[i - 1]) && islower(s[i + 1])) {
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ Loop condition should be <= to include the end character.
                    printf("%c", j);
            }
            if (isupper(s[i - 1]) && isupper(s[i + 1])) { // @@ Should be else if to prevent multiple checks and the else branch from incorrectly executing.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ Same loop condition issue: should be <=.
                    printf("%c", j);
            }
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) { // @@ Should be else if; also, after a successful expansion, the code needs to skip the second character (increment i) and not print it again.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ Same loop condition issue: should be <=.
                    printf("%c", j);
            } else {
                printf("-"); // @@ This else prints a '-' even when an expansion from the first if or second if has just occurred, because those are not chained with else if.
            }
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}