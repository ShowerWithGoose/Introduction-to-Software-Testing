#include <stdio.h>
char s[100000];

int main() {
    scanf("%s", s);
    int i = 0;
    for (i; s[i] != '\0'; i++) {
        if (s[i] != '-')
            printf("%c", s[i]);
        else {
            if ('a' <= s[i - 1] && s[i - 1] >= 'z') { // @@ The condition s[i-1] >= 'z' is logically incorrect for checking the lowercase range; it should be s[i-1] <= 'z'.
                if (('a' <= s[i + 1] && s[i + 1] >= 'z') && (s[i + 1] > s[i - 1])) { // @@ The condition s[i+1] >= 'z' is logically incorrect for checking the lowercase range; it should be s[i+1] <= 'z'.
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++)
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('A' <= s[i - 1] && s[i - 1] >= 'Z') { // @@ The condition s[i-1] >= 'Z' is logically incorrect for checking the uppercase range; it should be s[i-1] <= 'Z'.
                if (('A' <= s[i + 1] && s[i + 1] >= 'Z') && (s[i + 1] > s[i - 1])) { // @@ The condition s[i+1] >= 'Z' is logically incorrect for checking the uppercase range; it should be s[i+1] <= 'Z'.
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++)
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('0' <= s[i - 1] && s[i - 1] >= '9') { // @@ The condition s[i-1] >= '9' is logically incorrect for checking the digit range; it should be s[i-1] <= '9'.
                if (('0' <= s[i + 1] && s[i + 1] >= '9') && (s[i + 1] > s[i - 1])) { // @@ The condition s[i+1] >= '9' is logically incorrect for checking the digit range; it should be s[i+1] <= '9'.
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++)
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else
                printf("-");
        }
    }
    return 0;
}