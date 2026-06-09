#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[10000];
    scanf("%s", s);
    for (int i = 0; i <= strlen(s) - 1; i++) {
        if (s[i] == '-') {
            if (islower(s[i - 1]) && islower(s[i + 1])) { // @@ Missing bounds check for i==0 or i==len-1; missing s[i-1] < s[i+1] condition
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ Loop condition should be j <= s[i+1] to include end character; also missing i++ to skip next char
                    printf("%c", j);
            }
            if (isupper(s[i - 1]) && isupper(s[i + 1])) { // @@ Missing bounds check; missing s[i-1] < s[i+1] condition; should be else if
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ Same loop condition error; missing skip
                    printf("%c", j);
            }
            if (isdigit(s[i - 1]) && isdigit(s[i + 1])) { // @@ Missing bounds check; missing s[i-1] < s[i+1] condition; should be else if
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) // @@ Same loop condition error; missing skip
                    printf("%c", j);
            } else {
                printf("-"); // @@ Prints '-' incorrectly for cases where expansion did occur but isdigit condition was false
            }
        } else {
            printf("%c", s[i]);
        }
    }
    return 0;
}