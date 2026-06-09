#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100000
char a[N];
int get (char x) {
    if ('A' <= x && x <= 'Z') return 1;
    if ('a' <= x && x <= 'z') return 2;
    if ('1' <= x && x <= '9') return 3; // @@ [Error: Should be '0' <= x && x <= '9' to include digit '0'. Currently '0' returns 4 (other), causing expansion to fail for cases like "0-8".]
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
                } else putchar (a[i]);
            } else putchar (a[i]);
        } else {
            putchar (a[i]);
        }
    }
    putchar ('\n');
    return 0;
}