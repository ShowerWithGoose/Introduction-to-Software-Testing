#include <stdio.h>
char s[100000];

int main() {
    scanf("%s", s);
    int i = 0;
    for (i; s[i] != '\0'; i++) {
        if (s[i] != '-')
            printf("%c", s[i]);
        else {
            if ('a' <= s[i - 1] && s[i - 1] >= 'z') { // @@ The condition is logically incorrect. It should check if s[i-1] is between 'a' and 'z', but the second part s[i-1] >= 'z' is wrong; it should be s[i-1] <= 'z'. Also, the order of comparison is reversed; typically written as s[i-1] >= 'a' && s[i-1] <= 'z'.
                if (('a' <= s[i + 1] && s[i + 1] >= 'z') && (s[i + 1] > s[i - 1])) { // @@ Same logical error: should be s[i+1] >= 'a' && s[i+1] <= 'z'.
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++)
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('A' <= s[i - 1] && s[i - 1] >= 'Z') { // @@ Same logical error: should be s[i-1] >= 'A' && s[i-1] <= 'Z'.
                if (('A' <= s[i + 1] && s[i + 1] >= 'Z') && (s[i + 1] > s[i - 1])) { // @@ Same logical error: should be s[i+1] >= 'A' && s[i+1] <= 'Z'.
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++)
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('0' <= s[i - 1] && s[i - 1] >= '9') { // @@ Same logical error: should be s[i-1] >= '0' && s[i-1] <= '9'.
                if (('0' <= s[i + 1] && s[i + 1] >= '9') && (s[i + 1] > s[i - 1])) { // @@ Same logical error: should be s[i+1] >= '0' && s[i+1] <= '9'.
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