#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]); // @@ [Characters are printed immediately, so when expansion occurs later, already-printed characters cannot be modified; also causes duplicate output when '-' is processed]
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]); // @@ [Same issue: printing characters as they are read prevents in-place expansion from working correctly]
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]); // @@ [Same issue: immediate output breaks the expansion logic which relies on modifying the string in place]
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) {
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
    }
    return 0; // @@ [No final output of the expanded string; the program prints characters during traversal but never prints the result after expansion, and may miss parts or print duplicates]
}