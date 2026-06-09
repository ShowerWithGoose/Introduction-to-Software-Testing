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
            n = s[i + 1] - s[i - 1] - 2; // @@ The calculation of n is incorrect. It should be s[i+1] - s[i-1] - 1 to account for the number of characters to insert (excluding the endpoints). The current value is one less than needed, causing the expansion to be too short.
            j = strlen(s);
            for (; j >= i + 1; j--) {
                s[j + n] = s[j];
            }
            int m = i;
            for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) { // @@ The loop condition m <= i + n + 1 is off by one due to the incorrect n. With the correct n, this should be m <= i + n to properly fill the expanded range.
                s[m] = c;
            }
        }
    }
    return 0;
}