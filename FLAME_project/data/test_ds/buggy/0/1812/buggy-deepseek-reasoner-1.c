#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i]); @@ [Printing the character before processing expansion: The loop prints the current character immediately. However, if this character is part of an expansion (e.g., the start character of a range), the expansion block may later modify the string, and the newly inserted characters (like 'b' and 'C') will not be printed because the loop index has already advanced past them. This causes missing characters in the output.]
        if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i]); @@ [Same reason: printing the character before handling expansions leads to missing inserted characters.]
        if (s[i] >= '0' && s[i] <= '9') printf("%c", s[i]); @@ [Same reason: printing the character before handling expansions leads to missing inserted characters.]
        if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) {
            int n, j;
            n = s[i + 1] - s[i - 1] - 2;
            j = strlen(s);
            for (; j >= i + 1; j--) {
                s[j + n] = s[j];
            }
            int m = i;
            for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) { @@ [The fill loop condition `m <= i + n + 1` includes one extra index, causing the end character to be overwritten. Combined with the premature printing, this contributes to the incorrect output.]
                s[m] = c;
            }
        }
    }
    return 0;
}