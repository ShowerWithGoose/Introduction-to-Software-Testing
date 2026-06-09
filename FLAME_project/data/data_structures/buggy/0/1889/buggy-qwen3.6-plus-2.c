#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    gets(s);
    printf("%c", s[0]);
    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == 45) {
            if (s[i - 1] >= 65 && s[i - 1] <= 90 && s[i + 1] >= 65 && s[i + 1] <= 90 && s[i - 1] < s[i + 1]) {
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) {
                    printf("%c", j);
                }
            } else if (s[i - 1] >= 97 && s[i - 1] <= 122 && s[i + 1] >= 97 && s[i + 1] <= 122 && s[i - 1] < s[i + 1]) {
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) {
                    printf("%c", j);
                }
            } else if (s[i - 1] >= 48 && s[i - 1] <= 57 && s[i + 1] >= 48 && s[i + 1] <= 57 && s[i - 1] < s[i + 1]) {
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) {
                    printf("%c", j);
                }
            } else { // @@ The code fails to output the '-' character and the following character when expansion conditions are not met (e.g., mixed case like B-e). It should print '-' and then continue to print the next character in the loop or handle it explicitly. Currently, it skips printing '-' and the next character is printed in the next iteration, but the logic flow is broken because the 'else' branch for non-expansion is missing entirely for the '-' case.
                printf("-");
            }
        } else
            printf("%c", s[i]);
    }
    return 0;
}