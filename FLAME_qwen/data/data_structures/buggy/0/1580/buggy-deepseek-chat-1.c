#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100000
char a[N];
int get (char x) {
    if ('A' <= x && x <= 'Z') return 1;
    if ('a' <= x && x <= 'z') return 2;
    if ('1' <= x && x <= '9') return 3; // @@ Error: Should be '0' <= x && x <= '9' to include digit '0', not '1'
    return 4;
}
signed main() {
    scanf ("%s", a + 1);
    int n = strlen (a + 1);
    for (int i = 1; i <= n; ++i) {
        if (a[i] == '-' && i > 1 && i < n) {
            int x = get (a[i - 1]), y = get (a[i + 1]);
            if (x == y && x < 4) {
                if (a[i - 1] < a[i + 1]) {
                    for (int j = a[i - 1] + 1; j < a[i + 1]; ++j) putchar (j);
                } else putchar (a[i]); // @@ Error: When expansion condition fails (e.g., a[i-1] >= a[i+1]), the '-' should be output, but the code also needs to handle the case where the characters are not of the same type or x==4; the else branch here is correct for this subcase, but the logic for non-expansion cases is incomplete—see next line
            } else putchar (a[i]); // @@ Error: When characters are not of same type or x==4, the '-' should be output unchanged, but the code also outputs the '-' in the else branch of the inner if, which is correct; however, the outer else also outputs the '-' for cases where x==y but x==4 (e.g., other characters), which is correct. The main issue is the digit range error above.
        } else {
            putchar (a[i]);
        }
    }
    putchar ('\n');
    return 0;
}