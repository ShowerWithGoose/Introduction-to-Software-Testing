#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]); // @@ [This prints valid lowercase letters immediately, but later expansion may overwrite or duplicate characters when '-' is processed. Characters should not be printed immediately if they might be part of an expansion pattern like 'a-u'.]
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]); // @@ [Same issue: uppercase letters are printed immediately, but if followed by '-', they should not be printed yet because the '-' handling may expand them. This leads to duplication or incorrect order.]
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]); // @@ [Same problem for digits: printing immediately prevents correct expansion and causes duplication.]
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) {
            int n, j;
            n = s[i + 1] - s[i - 1] - 2; // @@ [Incorrect calculation: number of characters to insert between s[i-1] and s[i+1] is (s[i+1] - s[i-1] - 1), not -2. For example, 'a' to 'd' needs 'b','c' → 2 chars = 'd'-'a'-1 = 3-1=2. Using -2 gives 1, which is wrong.]
            j = strlen(s);
            for (; j >= i + 1; j--) {
                s[j + n] = s[j]; // @@ [This shifts the string to make room, but only if n is correct. Since n is wrong, shifting amount is wrong, leading to corruption. Also, this modifies the input string while iterating, which can cause the loop to process inserted characters again or skip parts.]
            }
            int m = i;
            for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) { // @@ [Loop condition uses n+1, but due to wrong n, it writes incorrect number of chars. Also, this overwrites the '-' and following char, but the loop index 'i' continues forward, possibly reprocessing expanded characters or missing updates.]
                s[m] = c;
            }
        }
    }
    return 0;
}