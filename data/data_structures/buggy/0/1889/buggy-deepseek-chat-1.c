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
            } // @@ Missing handling for cases where expansion should not occur (e.g., a-R, D-e, 0-b, 4-B). The program should output the '-' character unchanged in such cases, but here it simply does nothing, causing the '-' to be omitted from output.
        } else
            printf("%c", s[i]);
    }
    return 0;
}