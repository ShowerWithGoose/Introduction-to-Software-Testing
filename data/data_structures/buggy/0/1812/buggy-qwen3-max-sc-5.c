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
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) {
            int n, j;
            n = s[i + 1] - s[i - 1] - 2; @@ [This calculation is incorrect: it should be s[i+1] - s[i-1] - 1 to get the number of characters to insert between s[i-1] and s[i+1]. For example, 'a-d' needs 'b','c' → 2 chars, but d-a-2 = 100-97-2=1, which is wrong.]
            j = strlen(s);
            for (; j >= i + 1; j--) {
                s[j + n] = s[j]; @@ [If n is negative or zero due to miscalculation, this may cause buffer underflow or no shift, leading to incorrect insertion or memory corruption. Also, when n is computed incorrectly, shifting by wrong amount breaks string structure.]
            }
            int m = i;
            for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) { @@ [Loop condition uses n+1 which compounds the earlier error. Should run while c < s[i+1], not based on flawed n. Also, modifying s while iterating over it causes skipped or reprocessed characters.]
                s[m] = c;
            }
        }
    }
    return 0; @@ [Program never prints the final expanded string if expansion occurs, because characters are printed before expansion logic. Also, non-alphanumeric characters (like unexpanded '-') are never printed, violating requirement to output input unchanged in invalid cases.]
}