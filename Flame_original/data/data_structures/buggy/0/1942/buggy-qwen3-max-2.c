#include <stdio.h>
char s[100000];

int main() {
    scanf("%s", s);
    int i = 0;
    for (i; s[i] != '\0'; i++) {
        if (s[i] != '-')
            printf("%c", s[i]);
        else {
            if ('a' <= s[i - 1] && s[i - 1] >= 'z') { @@ // Condition is logically incorrect: should be 'a' <= s[i-1] && s[i-1] <= 'z', not >= 'z'
                if (('a' <= s[i + 1] && s[i + 1] >= 'z') && (s[i + 1] > s[i - 1])) { @@ // Same error: should use <= 'z', not >= 'z'
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++)
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('A' <= s[i - 1] && s[i - 1] >= 'Z') { @@ // Same error: should be <= 'Z', not >= 'Z'
                if (('A' <= s[i + 1] && s[i + 1] >= 'Z') && (s[i + 1] > s[i - 1])) { @@ // Same error: should be <= 'Z', not >= 'Z'
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++)
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('0' <= s[i - 1] && s[i - 1] >= '9') { @@ // Same error: should be <= '9', not >= '9'
                if (('0' <= s[i + 1] && s[i + 1] >= '9') && (s[i + 1] > s[i - 1])) { @@ // Same error: should be <= '9', not >= '9'
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