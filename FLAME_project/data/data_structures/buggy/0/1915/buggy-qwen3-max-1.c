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
            if (isupper(s[i - 1]) && isupper(s[i + 1])) {
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            }
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) {
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            } else {
                printf("-"); @@ [The 'else' only applies to the last 'if' (isdigit), not the whole block. So if the '-' matches lowercase or uppercase condition, it still prints '-' due to falling through to this else. Also, missing check that s[i-1] < s[i+1]. Additionally, after expansion, the next character (s[i+1]) is printed again in the main loop, causing duplication.]
            }
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}