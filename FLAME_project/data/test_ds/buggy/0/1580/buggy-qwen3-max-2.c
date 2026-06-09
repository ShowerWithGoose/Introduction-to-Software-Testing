#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100000
char a[N];
int get (char x) {
    if ('A' <= x && x <= 'Z') return 1;
    if ('a' <= x && x <= 'z') return 2;
    if ('1' <= x && x <= '9') return 3; // @@ [The condition should include '0' as well, since digits range from '0' to '9'. Excluding '0' causes inputs like "0-8" to be treated as invalid.]
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
                    for (int j = a[i - 1] + 1; j < a[i + 1]; ++j) putchar (j); // @@ [The loop condition should be j <= a[i + 1] to include the ending character in the expansion. The current code stops before it, so "0-8" becomes "1234567" instead of "012345678".]
                } else putchar (a[i]);
            } else putchar (a[i]);
        } else {
            putchar (a[i]);
        }
    }
    putchar ('\n');
    return 0;
}