#include <stdio.h>
char s[100000];

int main() {
    scanf("%s", s);
    int i = 0;
    for (i; s[i] != '\0'; i++) {
        if (s[i] != '-')
            printf("%c", s[i]);
        else {
            if ('a' <= s[i - 1] && s[i - 1] >= 'z') { // @@ The condition 'a' <= s[i-1] && s[i-1] >= 'z' is logically incorrect. It checks if the character is greater than or equal to 'a' AND greater than or equal to 'z'. This effectively only matches characters >= 'z'. It should be 'a' <= s[i-1] && s[i-1] <= 'z' to check if it's a lowercase letter. Because of this error, the code falls through to the final else block and prints '-', failing to expand valid ranges like 0-8.
                if (('a' <= s[i + 1] && s[i + 1] >= 'z') && (s[i + 1] > s[i - 1])) {
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++)
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('A' <= s[i - 1] && s[i - 1] >= 'Z') { // @@ Similar logical error. 'A' <= s[i-1] && s[i-1] >= 'Z' only matches characters >= 'Z'. It should be 'A' <= s[i-1] && s[i-1] <= 'Z'.
                if (('A' <= s[i + 1] && s[i + 1] >= 'Z') && (s[i + 1] > s[i - 1])) {
                    for (int x = 1; x < s[i + 1] - s[i - 1]; x++)
                        printf("%c", s[i - 1] + x);
                } else
                    printf("-");
            } else if ('0' <= s[i - 1] && s[i - 1] >= '9') { // @@ Similar logical error. '0' <= s[i-1] && s[i-1] >= '9' only matches characters >= '9'. It should be '0' <= s[i-1] && s[i-1] <= '9'. This prevents the expansion of digit ranges like 0-8.
                if (('0' <= s[i + 1] && s[i + 1] >= '9') && (s[i + 1] > s[i - 1])) {
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