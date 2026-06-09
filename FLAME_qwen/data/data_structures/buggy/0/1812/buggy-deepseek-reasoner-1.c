#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]); @@ [Prints characters during loop, but string is later modified; misses non-letter/digit characters and causes incorrect output order]
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]); @@ [Same issue as above]
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]); @@ [Same issue as above]
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) { @@ [Potential out-of-bounds access when i=0 (s[i-1] invalid); also expansion modifies string while printing, leading to incorrect output]
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