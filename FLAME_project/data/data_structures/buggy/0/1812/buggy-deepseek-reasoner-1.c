#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]); // @@ This prints characters before handling expansion, causing the first character of each expansion (which overwrites the '-' at position i) to be lost because the loop has already passed that index.
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]); // @@ Same issue.
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]); // @@ Same issue.
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) { // @@ Potential out-of-bounds access when i is 0 or i is the last index; also the condition is correct but the subsequent expansion logic is flawed.
            int n, j;
            n = s[i + 1] - s[i - 1] - 2; // @@ Incorrect calculation; the number of characters to insert should be s[i+1]-s[i-1]-1, not -2. This causes n to be one less than needed, leading to overwriting the right endpoint.
            j = strlen(s);
            for (; j >= i + 1; j--) {
                s[j + n] = s[j];
            }
            int m = i;
            for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) { // @@ The loop condition m <= i+n+1 is wrong; it writes one extra character (the right endpoint), overwriting it. Also, starting at m = i overwrites the '-' but that character is never printed because the loop has already passed index i.
                s[m] = c;
            }
        }
    }
    return 0;
}