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
            if (isupper(s[i - 1]) && isupper(s[i + 1])) { // @@ Missing condition check for s[i-1] < s[i+1]; also missing else if to prevent multiple conditions from executing
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            }
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) { // @@ Missing condition check for s[i-1] < s[i+1]; also missing else if to prevent multiple conditions from executing
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            } else {
                printf("-"); // @@ This else only applies to the last if, causing '-' to be printed when isdigit condition fails, even if islower or isupper succeeded
            }
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}