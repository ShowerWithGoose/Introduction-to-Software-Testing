#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[10000];
    scanf("%s", s);
    for (int i = 0; i <= strlen(s) - 1; i++) {
        if (s[i] == '-') {
            if (islower(s[i - 1]) && islower(s[i + 1])) { // @@ Accessing s[i-1] when i=0 causes out-of-bounds error; should check i > 0.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            }
            if (isupper(s[i - 1]) && isupper(s[i + 1])) { // @@ Should be 'else if' to form a proper conditional chain and prevent multiple blocks from executing.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            }
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) { // @@ Should be 'else if' to correctly chain the conditions.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            } else { // @@ This else only pairs with the isdigit check, causing '-' to be printed incorrectly when islower or isupper conditions are met.
                printf("-");
            }
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}