#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[10000];
    scanf("%s", s);
    for (int i = 0; i <= strlen(s) - 1; i++) { // @@ compilation error: variable declaration inside for loop not allowed in C89/C90; also potential out-of-bounds when i is first or last
        if (s[i] == '-') {
            if (islower(s[i - 1]) && islower(s[i + 1])) { // @@ out-of-bounds access if i==0 or i==len(s)-1; should be chained with else if to avoid spurious '-' output
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            }
            if (isupper(s[i - 1]) && isupper(s[i + 1])) { // @@ out-of-bounds access; should be else if
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            }
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) { // @@ out-of-bounds access; should be else if
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            } else { // @@ else is attached only to the last if; incorrect control flow causes missing '-' for digit left>=right and extra '-' for lower/upper expansions
                printf("-");
            }
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}