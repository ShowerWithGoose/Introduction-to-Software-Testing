#include <stdio.h>
char s[100000];

int main() {
    scanf("%s", s);
    int i = 0;
    for (i; s[i] != '\0'; i++) {
        if (s[i] != '-')
            printf("%c", s[i]);
        else {
            if ('a' <= s[i - 1] && s[i - 1] >= 'z') { // @@ Logical error: The condition `s[i - 1] >= 'z'` is incorrect. It should be `s[i - 1] <= 'z'` to correctly verify that the character falls within the lowercase letter range.
                if (('a' <= s[i + 1] && s[i + 1] >= 'z') && (s[i + 1] > s[i - 1])) { // @@ Logical error: The condition `s[i + 1] >= 'z'` is incorrect. It should be `s[i + 1] <= 'z'` to correctly verify that the character falls within the lowercase letter range.
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++)
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('A' <= s[i - 1] && s[i - 1] >= 'Z') { // @@ Logical error: The condition `s[i - 1] >= 'Z'` is incorrect. It should be `s[i - 1] <= 'Z'` to correctly verify that the character falls within the uppercase letter range.
                if (('A' <= s[i + 1] && s[i + 1] >= 'Z') && (s[i + 1] > s[i - 1])) { // @@ Logical error: The condition `s[i + 1] >= 'Z'` is incorrect. It should be `s[i + 1] <= 'Z'` to correctly verify that the character falls within the uppercase letter range.
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++)
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('0' <= s[i - 1] && s[i - 1] >= '9') { // @@ Logical error: The condition `s[i - 1] >= '9'` is incorrect. It should be `s[i - 1] <= '9'` to correctly verify that the character falls within the digit range.
                if (('0' <= s[i + 1] && s[i + 1] >= '9') && (s[i + 1] > s[i - 1])) { // @@ Logical error: The condition `s[i + 1] >= '9'` is incorrect. It should be `s[i + 1] <= '9'` to correctly verify that the character falls within the digit range.
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