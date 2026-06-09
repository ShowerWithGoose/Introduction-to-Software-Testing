#include <stdio.h>
char s[100000];

int main() {
    scanf("%s", s);
    int i = 0;
    for (i; s[i] != '\0'; i++) {
        if (s[i] != '-')
            printf("%c", s[i]);
        else {
            if ('a' <= s[i - 1] && s[i - 1] >= 'z') { // @@ The condition 'a' <= s[i-1] && s[i-1] >= 'z' is logically incorrect. It checks if the character is greater than or equal to 'z' AND less than or equal to 'a', which is impossible for standard ASCII letters. It should be s[i-1] >= 'a' && s[i-1] <= 'z'. This causes the lowercase check to fail, falling through to the final else, printing '-' instead of expanding.
                if (('a' <= s[i + 1] && s[i + 1] >= 'z') && (s[i + 1] > s[i - 1])) { // @@ Similarly, this condition is logically incorrect for the same reason. It should be s[i+1] >= 'a' && s[i+1] <= 'z'.
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++)
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('A' <= s[i - 1] && s[i - 1] >= 'Z') { // @@ The condition 'A' <= s[i-1] && s[i-1] >= 'Z' is logically incorrect. It should be s[i-1] >= 'A' && s[i-1] <= 'Z'.
                if (('A' <= s[i + 1] && s[i + 1] >= 'Z') && (s[i + 1] > s[i - 1])) { // @@ Similarly, this condition is logically incorrect. It should be s[i+1] >= 'A' && s[i+1] <= 'Z'.
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++)
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('0' <= s[i - 1] && s[i - 1] >= '9') { // @@ The condition '0' <= s[i-1] && s[i-1] >= '9' is logically incorrect. It should be s[i-1] >= '0' && s[i-1] <= '9'. Because of this error, the digit case is not detected, leading to the final else block executing and printing '-' instead of expanding "0-8".
                if (('0' <= s[i + 1] && s[i + 1] >= '9') && (s[i + 1] > s[i - 1])) { // @@ Similarly, this condition is logically incorrect. It should be s[i+1] >= '0' && s[i+1] <= '9'.
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