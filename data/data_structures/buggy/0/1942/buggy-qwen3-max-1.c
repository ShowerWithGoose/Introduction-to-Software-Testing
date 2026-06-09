#include <stdio.h>
char s[100000];

int main() {
    scanf("%s", s);
    int i = 0;
    for (i; s[i] != '\0'; i++) {
        if (s[i] != '-')
            printf("%c", s[i]);
        else {
            if ('a' <= s[i - 1] && s[i - 1] >= 'z') { // @@ [The condition is logically incorrect: it should be 'a' <= s[i-1] && s[i-1] <= 'z', but here it uses >= 'z', which is always false for lowercase letters. Same error applies to uppercase and digit checks below.]
                if (('a' <= s[i + 1] && s[i + 1] >= 'z') && (s[i + 1] > s[i - 1])) { // @@ [Same issue: should be <= 'z', not >= 'z'. This prevents correct detection of lowercase ranges.]
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++)
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('A' <= s[i - 1] && s[i - 1] >= 'Z') { // @@ [Incorrect condition: should be <= 'Z', not >= 'Z'. This makes the uppercase check always fail.]
                if (('A' <= s[i + 1] && s[i + 1] >= 'Z') && (s[i + 1] > s[i - 1])) { // @@ [Same error: should use <= 'Z' to correctly identify uppercase letters.]
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++)
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('0' <= s[i - 1] && s[i - 1] >= '9') { // @@ [Incorrect condition: should be <= '9', not >= '9'. Digits will never satisfy this condition.]
                if (('0' <= s[i + 1] && s[i + 1] >= '9') && (s[i + 1] > s[i - 1])) { // @@ [Same mistake: must use <= '9' to validate digit characters.]
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