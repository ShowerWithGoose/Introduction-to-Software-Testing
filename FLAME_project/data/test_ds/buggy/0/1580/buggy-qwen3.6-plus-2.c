#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100000
char a[N];
int get (char x) {
    if ('A' <= x && x <= 'Z') return 1;
    if ('a' <= x && x <= 'z') return 2;
    if ('1' <= x && x <= '9') return 3; // @@ The digit range check starts from '1' instead of '0', causing '0' to be misclassified as type 4, which fails the type matching condition for expansions involving '0'.
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
                    for (int j = a[i - 1] + 1; j < a[i + 1]; ++j) putchar (j); // @@ The loop condition uses '<' which excludes the end character of the expansion. It should be '<=' to correctly include the character after the '-' symbol.
                } else putchar (a[i]);
            } else putchar (a[i]);
        } else {
            putchar (a[i]);
        }
    }
    putchar ('\n');
    return 0;
}