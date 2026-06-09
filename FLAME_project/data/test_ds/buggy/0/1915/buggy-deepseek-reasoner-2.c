#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[10000];
    scanf("%s", s);
    for (int i = 0; i <= strlen(s) - 1; i++) { // @@ loop bound causes out-of-bounds when i is last index; should be i < strlen(s)-1
        if (s[i] == '-') {
            if (islower(s[i - 1]) && islower(s[i + 1])) { // @@ possible out-of-bounds when i=0 (s[i-1]) and when i=last (s[i+1])
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            }
            if (isupper(s[i - 1]) && isupper(s[i + 1])) { // @@ same out-of-bounds issue
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            }
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) { // @@ same out-of-bounds issue
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            } else { // @@ logical error: else only attached to the last if, prints '-' when previous if conditions were true, causing extra '-'
                printf("-");
            }
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}