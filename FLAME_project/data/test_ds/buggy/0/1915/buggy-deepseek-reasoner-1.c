#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[10000];
    scanf("%s", s);
    for (int i = 0; i <= strlen(s) - 1; i++) {
        if (s[i] == '-') {
            if (islower(s[i - 1]) && islower(s[i + 1])) { // @@ missing check s[i-1] < s[i+1] to ensure proper expansion order
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ loop condition should be j <= s[i+1] to include the end character
                    printf("%c", j);
            } // @@ missing i++ and continue to skip printing the hyphen and the next character (s[i+1]) after expansion
            if (isupper(s[i - 1]) && isupper(s[i + 1])) { // @@ missing check s[i-1] < s[i+1]
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ loop condition should be j <= s[i+1]
                    printf("%c", j);
            } // @@ missing i++ and continue
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) { // @@ missing check s[i-1] < s[i+1]
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ loop condition should be j <= s[i+1]
                    printf("%c", j);
            } else { // @@ else clause is attached only to the isdigit condition; it causes a hyphen to be printed even when islower or isupper expansion occurred
                printf("-"); // @@ this hyphen should only be printed if none of the expansion conditions are met
            }
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}