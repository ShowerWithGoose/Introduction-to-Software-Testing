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
            } else {
                printf("%c", s[i]); // @@ [When the '-' should not be expanded (e.g., mixed case like 'B-e'), the program fails to output the '-' character because there is no else clause to handle printing it. The current code only prints expanded characters or skips '-', leading to missing '-' in output.]
            }
        } else
            printf("%c", s[i]);
    }
    return 0;
}