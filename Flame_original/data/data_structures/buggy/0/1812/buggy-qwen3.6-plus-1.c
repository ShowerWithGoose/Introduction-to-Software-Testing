#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]); // @@ Printing characters during iteration is incorrect because the string is modified in-place later, causing skipped or duplicated output. The expanded string should be printed after the loop.
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]); // @@ Same error: immediate printing conflicts with in-place expansion logic.
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]); // @@ Same error: immediate printing conflicts with in-place expansion logic.
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) { // @@ Accessing s[i-1] when i=0 causes out-of-bounds memory access. Also lacks bounds check for s[i+1].
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
    } // @@ Missing printf("%s\n", s); after the loop to output the fully expanded string.
    return 0;
}