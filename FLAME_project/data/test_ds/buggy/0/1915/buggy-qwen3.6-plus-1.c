#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[10000];
    scanf("%s", s);
    for (int i = 0; i <= strlen(s) - 1; i++) {
        if (s[i] == '-') {
            if (islower(s[i - 1]) && islower(s[i + 1])) { // @@ Missing condition `s[i-1] < s[i+1]` per requirements, and should be `else if` to prevent falling through to the incorrect `else` block.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ Loop condition `j < s[i + 1]` excludes the end character; should be `j <= s[i + 1]`. Also, `i` should be incremented after the loop to skip printing `s[i+1]` again.
                    printf("%c", j);
            }
            if (isupper(s[i - 1]) && isupper(s[i + 1])) { // @@ Should be `else if` to form a mutually exclusive chain with the previous condition.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ Same loop condition error; should be `j <= s[i + 1]`.
                    printf("%c", j);
            }
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) { // @@ Should be `else if`.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ Same loop condition error; should be `j <= s[i + 1]`.
                    printf("%c", j);
            } else { // @@ This `else` is incorrectly bound to the `isdigit` check instead of the entire expansion condition chain, causing `-` to be printed even when expansion happens.
                printf("-");
            }
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}