#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]); // @@ Printing characters during iteration causes incorrect output because the string is modified in-place, leading to skipped or duplicated characters. The entire string should be processed first and printed at the end.
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]); // @@ Same as above: premature printing interferes with in-place string expansion logic.
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]); // @@ Same as above: premature printing interferes with in-place string expansion logic.
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) { // @@ Accessing s[i-1] when i=0 causes undefined behavior. Additionally, modifying the string in-place while iterating corrupts the loop index i, causing incorrect processing of subsequent characters.
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
        }
    }
    return 0;
}