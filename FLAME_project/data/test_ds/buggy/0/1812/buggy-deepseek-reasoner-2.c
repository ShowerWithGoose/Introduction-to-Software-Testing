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
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) { // @@ Potential out‑of‑bounds access for s[i-1] and s[i+1] when i is 0 or the last index.
            int n, j;
            n = s[i + 1] - s[i - 1] - 2; // @@ Incorrect calculation: should be -1, not -2. This causes missing one character and later loop issues.
            j = strlen(s);
            for (; j >= i + 1; j--) {
                s[j + n] = s[j];
            }
            int m = i;
            for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) { // @@ Loop condition should be m <= i + n - 1 (or m < i + n) to insert the correct number of characters. Additionally, the first inserted character (at position i) is never printed because the loop increments i before reaching it.
                s[m] = c;
            }
        }
    }
    return 0;
}