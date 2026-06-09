#include <stdio.h>
char s[100000];

int main() {
    scanf("%s", s);
    int i = 0;
    for (i; s[i] != '\0'; i++) {
        if (s[i] != '-')
            printf("%c", s[i]);
        else {
            if ('a' <= s[i - 1] && s[i - 1] >= 'z') { // @@ The condition is logically incorrect; it should check if s[i-1] is between 'a' and 'z', but the second part s[i-1] >= 'z' is wrong. It should be s[i-1] <= 'z'.
                if (('a' <= s[i + 1] && s[i + 1] >= 'z') && (s[i + 1] > s[i - 1])) { // @@ Same issue: the condition for s[i+1] should be s[i+1] <= 'z', not >= 'z'.
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++) // @@ The loop condition is off by one; it should be x <= s[i+1] - s[i-1] - 1 or x < s[i+1] - s[i-1] to correctly print all intermediate characters.
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('A' <= s[i - 1] && s[i - 1] >= 'Z') { // @@ Same logical error: should be s[i-1] <= 'Z'.
                if (('A' <= s[i + 1] && s[i + 1] >= 'Z') && (s[i + 1] > s[i - 1])) { // @@ Same issue: should be s[i+1] <= 'Z'.
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++) // @@ Same off-by-one error in loop condition.
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('0' <= s[i - 1] && s[i - 1] >= '9') { // @@ Same logical error: should be s[i-1] <= '9'.
                if (('0' <= s[i + 1] && s[i + 1] >= '9') && (s[i + 1] > s[i - 1])) { // @@ Same issue: should be s[i+1] <= '9'.
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++) // @@ Same off-by-one error in loop condition.
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else
                printf("-");
        }
    }
    return 0;
}