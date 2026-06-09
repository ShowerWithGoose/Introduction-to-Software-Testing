#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]);
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]);
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]);
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) { // @@ If the condition is false, the '-' character is not printed, violating the requirement to output unchanged input for non-expanding cases.
            int n, j;
            n = s[i + 1] - s[i - 1] - 2;
            j = strlen(s);
            for (; j >= i + 1; j--) {
                s[j + n] = s[j];
            }
            int m = i;
            for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) {
                s[m] = c;
            }
        } // @@ After expanding the string in-place, the loop index i increments in the next iteration, skipping the newly inserted characters starting at s[i]. Consequently, the expanded characters are never printed.
    }
    return 0;
}