#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]); // @@ [This prints valid lowercase letters immediately, but if the next character is '-', expansion should replace the '-' and possibly skip printing the next character. However, this approach prints characters as they are encountered without considering future '-' expansions, leading to duplication or incorrect output.]
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]); // @@ [Same issue as above: uppercase letters are printed immediately without deferring to possible expansion logic that may involve them.]
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]); // @@ [Same issue: digits are printed immediately, which interferes with correct expansion handling when a '-' follows.]
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) {
            int n, j;
            n = s[i + 1] - s[i - 1] - 2; // @@ [Incorrect calculation: the number of characters to insert between s[i-1] and s[i+1] should be (s[i+1] - s[i-1] - 1), not -2. For example, from 'a' to 'd', we need 'b','c' → 2 chars = 'd'-'a'-1 = 3-1=2. Using -2 gives 1, which is wrong.]
            j = strlen(s);
            for (; j >= i + 1; j--) {
                s[j + n] = s[j]; // @@ [This shifts part of the string to make room for expansion, but the loop condition and shifting logic may go out of bounds or corrupt data because 'n' might be negative or miscalculated, and the buffer size is fixed at 501. Also, modifying the input string while iterating over it leads to undefined behavior (e.g., skipping or reprocessing characters).]
            }
            int m = i;
            for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) { // @@ [Loop condition is flawed: it uses 'n' (which is already miscalculated) and writes into the string starting at position 'i', overwriting the '-' and subsequent characters. But since the outer loop continues scanning the modified string, it may process newly inserted characters again or skip others. Moreover, this modifies the source string during iteration, which breaks the sequential scan logic.]
                s[m] = c;
            }
        }
    }
    return 0;
}