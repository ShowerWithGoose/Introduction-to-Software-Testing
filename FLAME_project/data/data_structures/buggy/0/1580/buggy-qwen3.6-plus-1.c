#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100000
char a[N];
int get (char x) {
    if ('A' <= x && x <= 'Z') return 1;
    if ('a' <= x && x <= 'z') return 2;
    if ('0' <= x && x <= '9') return 3; // @@ The original code excluded '0' by checking '1' to '9', causing digits starting with 0 or ranges involving 0 to be misclassified or not expanded correctly. It should include '0'.
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
                    for (int j = a[i - 1] + 1; j <= a[i + 1]; ++j) putchar (j); // @@ The original loop condition was j < a[i+1], which excluded the end character of the range. It should be j <= a[i+1] to include it.
                } else putchar (a[i]);
            } else putchar (a[i]);
        } else {
            putchar (a[i]);
        }
    }
    putchar ('\n');
    return 0;
}