#include <stdio.h>
char s[100000];

int main() {
    scanf("%s", s);
    int i = 0;
    for (i; s[i] != '\0'; i++) {
        if (s[i] != '-')
            printf("%c", s[i]);
        else {
            if ('a' <= s[i - 1] && s[i - 1] >= 'z') { // @@ The condition is logically incorrect; it should check if s[i-1] is between 'a' and 'z', but the second part uses >= 'z' which is always false for lowercase letters. Correct condition: s[i-1] >= 'a' && s[i-1] <= 'z'
                if (('a' <= s[i + 1] && s[i + 1] >= 'z') && (s[i + 1] > s[i - 1])) { // @@ Same logical error here; should be s[i+1] >= 'a' && s[i+1] <= 'z'
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++) // @@ The loop condition should be <= to include all characters between, e.g., for '0' to '8', need x from 1 to 8, but s[i+1]-s[i-1] = 8, so x < 8 prints only 7 characters. Should be x <= s[i+1] - s[i-1] - 1? Actually correct: for (int x = s[i-1]+1; x < s[i+1]; x++) printf("%c", x);
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('A' <= s[i - 1] && s[i - 1] >= 'Z') { // @@ Same logical error; should be s[i-1] >= 'A' && s[i-1] <= 'Z'
                if (('A' <= s[i + 1] && s[i + 1] >= 'Z') && (s[i + 1] > s[i - 1])) { // @@ Same logical error; should be s[i+1] >= 'A' && s[i+1] <= 'Z'
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++) // @@ Same loop condition error
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('0' <= s[i - 1] && s[i - 1] >= '9') { // @@ Same logical error; should be s[i-1] >= '0' && s[i-1] <= '9'
                if (('0' <= s[i + 1] && s[i + 1] >= '9') && (s[i + 1] > s[i - 1])) { // @@ Same logical error; should be s[i+1] >= '0' && s[i+1] <= '9'
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++) // @@ Same loop condition error
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else
                printf("-");
        }
    }
    return 0;
}