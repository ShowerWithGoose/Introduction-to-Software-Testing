#include <stdio.h>
char s[100000];

int main() {
    scanf("%s", s);
    int i = 0;
    for (i; s[i] != '\0'; i++) {
        if (s[i] != '-')
            printf("%c", s[i]);
        else {
            if ('a' <= s[i - 1] && s[i - 1] >= 'z') { // @@ The condition is logically incorrect; it should check if s[i-1] is between 'a' and 'z', but the second part uses >= instead of <=, so it will never be true for lowercase letters.
                if (('a' <= s[i + 1] && s[i + 1] >= 'z') && (s[i + 1] > s[i - 1])) { // @@ Same logical error: the second condition should be s[i+1] <= 'z', not >= 'z'.
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++) // @@ The loop condition should be x <= s[i+1] - s[i-1] to include all intermediate characters, or start from 0 and use <.
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('A' <= s[i - 1] && s[i - 1] >= 'Z') { // @@ Same logical error: should check s[i-1] <= 'Z'.
                if (('A' <= s[i + 1] && s[i + 1] >= 'Z') && (s[i + 1] > s[i - 1])) { // @@ Same logical error: should check s[i+1] <= 'Z'.
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++) // @@ Same loop boundary issue.
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('0' <= s[i - 1] && s[i - 1] >= '9') { // @@ Same logical error: should check s[i-1] <= '9'.
                if (('0' <= s[i + 1] && s[i + 1] >= '9') && (s[i + 1] > s[i - 1])) { // @@ Same logical error: should check s[i+1] <= '9'.
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++) // @@ Same loop boundary issue.
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else
                printf("-");
        }
    }
    return 0;
}