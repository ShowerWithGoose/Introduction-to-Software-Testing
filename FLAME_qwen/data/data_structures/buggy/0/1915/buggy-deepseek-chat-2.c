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
            if (isupper(s[i - 1]) && isupper(s[i + 1])) { // @@ Missing else before this if; when the first condition is true, this and subsequent conditions are still evaluated, causing the else to attach only to the last if, leading to incorrect output for valid expansions.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            }
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) { // @@ Missing else before this if; same issue as above, the else on line 18 only applies to this if, so when a valid expansion occurs, the else may incorrectly print '-'.
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