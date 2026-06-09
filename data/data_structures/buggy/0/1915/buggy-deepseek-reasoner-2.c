#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[10000];
    scanf("%s", s);
    for (int i = 0; i <= strlen(s) - 1; i++) { // @@ potential out-of-bounds access at i=0 (s[i-1]) and i=len-1 (s[i+1] may be null, but isdigit etc. return false for null)
        if (s[i] == '-') {
            if (islower(s[i - 1]) && islower(s[i + 1])) {
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            }
            if (isupper(s[i - 1]) && isupper(s[i + 1])) { // @@ should be else if, otherwise after a successful lowercase expansion, this and the next if are still evaluated, leading to extra '-' being printed.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            }
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) { // @@ should be else if, same reason.
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
                    printf("%c", j);
            } else {
                printf("-"); // @@ This else is attached only to the last if, so after a successful lowercase or uppercase expansion, this else will also execute, printing an extra '-'. Should be part of an if-else if-else chain.
            }
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}