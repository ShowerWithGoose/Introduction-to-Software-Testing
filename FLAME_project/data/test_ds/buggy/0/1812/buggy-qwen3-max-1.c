#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]); // @@ [This prints valid lowercase letters immediately, but later expansion may overwrite or duplicate output when '-' is processed. The logic should not print characters before handling possible expansions involving them.]
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]); // @@ [Same issue: uppercase letters are printed immediately, but if they are part of an expansion like B-F, they will be printed again during expansion, causing duplication or incorrect order.]
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]); // @@ [Same problem for digits: printing immediately prevents correct expansion handling and may cause duplication or missing characters.]
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) {
            int n, j;
            n = s[i + 1] - s[i - 1] - 2; // @@ [Incorrect calculation: number of characters to insert between s[i-1] and s[i+1] is (s[i+1] - s[i-1] - 1), not -2. For example, 'a' to 'd' needs 'b','c' → 2 chars = 'd'-'a'-1 = 3-1=2. Using -2 gives 1, which is wrong.]
            j = strlen(s);
            for (; j >= i + 1; j--) {
                s[j + n] = s[j]; // @@ [Modifying the input string while iterating over it leads to undefined behavior: the loop index `i` continues forward, but the string content shifts, possibly skipping characters or processing expanded parts again. Also, buffer overflow risk if s exceeds 501.]
            }
            int m = i;
            for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) { // @@ [Loop condition is flawed. It should run for (s[i+1] - s[i-1] - 1) iterations, but due to incorrect `n`, and because `m` starts at `i` (the '-' position), it overwrites more than needed. Also, after shifting, s[i-1] might have changed if previous expansions occurred.]
                s[m] = c;
            }
        }
    }
    return 0;
}