#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]); // @@ [This prints valid lowercase letters immediately, but later expansion may overwrite or duplicate output when '-' is processed. Characters should not be printed here unconditionally because they might be part of a range like 'a-u'.]
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]); // @@ [Same issue: uppercase letters are printed immediately, but if followed by '-', they should not be printed yet because the range expansion will handle them. This causes duplication or incorrect ordering.]
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]); // @@ [Same problem for digits: printing immediately breaks correct expansion logic.]
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) {
            int n, j;
            n = s[i + 1] - s[i - 1] - 2; // @@ [Incorrect calculation: number of characters to insert between s[i-1] and s[i+1] is (s[i+1] - s[i-1] - 1), not -2. For example, from 'a' to 'd', we need 'b','c' → 2 chars = 'd'-'a'-1 = 3-1=2. Using -2 gives 1, which is wrong.]
            j = strlen(s);
            for (; j >= i + 1; j--) {
                s[j + n] = s[j]; // @@ [Modifying the input string while iterating over it leads to undefined behavior: the loop index 'i' continues forward, but the string content shifts, possibly skipping or reprocessing characters. Also, buffer overflow risk if s exceeds 501.]
            }
            int m = i;
            for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) { // @@ [Loop condition is flawed. It writes too many characters due to incorrect 'n', and overwrites the next character (s[i+1]). Should only fill positions from i to i + (s[i+1]-s[i-1]-2), but logic is broken. Also, after shifting, s[i-1] and s[i+1+n] are the endpoints, but code uses original indices.]
                s[m] = c;
            }
        }
    }
    return 0;
}