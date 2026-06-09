#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[10000];
    scanf("%s", s);
    for (int i = 0; i <= strlen(s) - 1; i++) {
        if (s[i] == '-') {
            if (islower(s[i - 1]) && islower(s[i + 1])) { // @@ The condition does not check if the start character is strictly less than the end character (s[i-1] < s[i+1]). Also, it lacks logic to skip printing the hyphen and the end character when expansion occurs.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ The loop condition uses strict inequality (<), which excludes the end character. It should be <= to include the end character in the expansion.
                    printf("%c", j);
            }
            if (isupper(s[i - 1]) && isupper(s[i + 1])) { // @@ Similar to the lowercase check: missing s[i-1] < s[i+1] check, and no mechanism to suppress the hyphen and end character output upon successful expansion.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ The loop condition uses strict inequality (<), excluding the end character. It should be <=.
                    printf("%c", j);
            }
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) { // @@ Similar issues: missing s[i-1] < s[i+1] check and no suppression of hyphen/end character on expansion.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ The loop condition uses strict inequality (<), excluding the end character. It should be <=.
                    printf("%c", j);
            } else { // @@ This else block only attaches to the last if (isdigit). If a lowercase or uppercase expansion happens, this else is skipped, but the hyphen is still printed later because there's no flag or continue statement to skip the rest of the loop iteration for the current '-'. Furthermore, if none of the expansions happen, it prints '-', but the original hyphen will also be printed by the final else block of the outer loop if not handled correctly. The logic structure is fundamentally flawed for handling the "skip hyphen and end char" requirement.
                printf("-");
            }
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}