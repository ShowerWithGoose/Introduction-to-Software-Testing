#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]); // @@ [Characters are printed immediately, so when expansion happens later, already-printed characters cannot be modified; also, non-alphanumeric characters like '-' are skipped entirely, breaking output]
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]); // @@ [Same issue: printing before processing expansion leads to incorrect output order and missing expanded sequences]
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]); // @@ [Same issue: digits are printed immediately, preventing correct in-place expansion]
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) {
            int n, j;
            n = s[i + 1] - s[i - 1] - 2; // @@ [Incorrect calculation: should be s[i+1] - s[i-1] - 1 characters to insert, not -2; e.g., a-d needs b,c → 2 chars, but 'd'-'a'-2 = 1]
            j = strlen(s);
            for (; j >= i + 1; j--) {
                s[j + n] = s[j]; // @@ [Buffer overflow risk: s is size 501, but shifting by n may exceed bounds; also, logic flawed due to prior immediate printing]
            }
            int m = i;
            for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) { // @@ [Loop condition uses n which is too small; should run while c < s[i+1], not based on flawed n]
                s[m] = c;
            }
        }
    }
    return 0; // @@ [No final printf of the result string; all output done mid-loop, causing incomplete/misordered output]
}