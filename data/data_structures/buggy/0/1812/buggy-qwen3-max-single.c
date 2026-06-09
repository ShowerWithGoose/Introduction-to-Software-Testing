#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]); // @@ [Characters are printed immediately, so expansion logic that modifies the string later cannot affect already-printed output]
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]); // @@ [Same issue: printing characters as they are encountered prevents proper expansion handling]
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]); // @@ [This approach outputs valid characters before processing possible '-' expansions, leading to duplicated or incorrect output]
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
    return 0; // @@ [The program never prints the final expanded string; it only prints individual valid characters during traversal, and exits without outputting the result of expansions]
}