#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100000
char a[N];
int get (char x) {
    if ('A' <= x && x <= 'Z') return 1;
    if ('a' <= x && x <= 'z') return 2;
    if ('1' <= x && x <= '9') return 3; @@ [The digit range should start from '0', not '1'. This causes digits like '0' to be misclassified as type 4 (invalid), so expansions like 0-3 will not work.]
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
                } else putchar (a[i]); @@ [When the left character is not less than the right one (e.g., d-a or 5-2), the '-' should be printed as-is, but the current code only prints the '-', skipping the surrounding characters which were already printed in prior iterations. However, the bigger issue is that the surrounding characters are handled correctly by the loop structure. The real problem is the missing '0' handling above.]
            } else putchar (a[i]);
        } else {
            putchar (a[i]);
        }
    }
    putchar ('\n');
    return 0;
}