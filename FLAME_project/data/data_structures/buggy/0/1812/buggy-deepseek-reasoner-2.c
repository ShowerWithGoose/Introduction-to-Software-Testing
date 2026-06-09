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
            n = s[i + 1] - s[i - 1] - 2; // @@ The number of characters to insert should be (s[i+1]-s[i-1]-1), not -2. Using -2 leads to an off-by-one error, although it may still produce the correct sequence because the fill loop includes the right endpoint.
            j = strlen(s);
            for (; j >= i + 1; j--) {
                s[j + n] = s[j];
            }
            int m = i;
            for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) {
                s[m] = c;
            }
        } // @@ After the in-place expansion, the first inserted character (at index i) is not printed because the loop has already passed index i when it encountered the hyphen. The code does not print the inserted characters, skipping the first character of each expansion.
    }
    return 0;
}