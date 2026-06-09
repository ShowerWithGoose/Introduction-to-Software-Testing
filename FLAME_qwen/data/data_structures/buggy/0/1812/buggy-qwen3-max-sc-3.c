#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]); // @@ [This prints valid characters immediately, but expansion logic modifies the string in-place later, causing double output or inconsistent behavior. Also, non-alphanumeric characters (like '-') are not printed here, but may be handled incorrectly later.]
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]); // @@ [Same issue as above: printing characters before expansion leads to incorrect output order and duplication.]
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]); // @@ [Same issue: premature printing breaks the expansion logic which relies on modifying the string in place.]
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) {
            int n, j;
            n = s[i + 1] - s[i - 1] - 2; // @@ [Incorrect calculation: should be s[i+1] - s[i-1] - 1 to get the number of characters to insert between them. For example, 'a-d' needs 'b','c' → 2 chars, but this gives 'd'-'a'-2 = 1.]
            j = strlen(s);
            for (; j >= i + 1; j--) {
                s[j + n] = s[j]; // @@ [Buffer overflow risk: s is size 501, but shifting by n may exceed array bounds. Also, n may be negative if miscalculated, leading to undefined behavior.]
            }
            int m = i;
            for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) { // @@ [Loop condition uses n which is too small; also, after shifting, the loop writes over the '-' and following chars, but the outer loop continues scanning modified string, possibly reprocessing expanded characters or causing infinite loops.]
                s[m] = c;
            }
        }
    }
    return 0; // @@ [No final printf of the result string; instead, characters were printed incrementally, leading to missing or duplicated output. The expected behavior is to output the fully expanded string at the end.]
}