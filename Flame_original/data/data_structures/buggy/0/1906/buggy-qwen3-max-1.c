#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[1000];
    gets(a); // @@ [Use of unsafe and deprecated function 'gets' which can cause buffer overflow; also, the problem expects input via scanf or similar safe method]
    int i, j;
    j = 0;
    i = 0;
    while (a[i] != '\0') {
        if (a[i + 1] != '-') {
            b[j] = a[i];
            j++;
            i++;
        } else {
            if (((a[i] >= '0' && a[i + 2] <= '9') || (a[i] >= 'a' && a[i + 2] <= 'z') || (a[i] >= 'A' && a[i + 2] <= 'Z'))
                    && a[i] < a[i + 2]) { // @@ [Incorrect range checks: e.g., 'a[i] >= '0'' does not guarantee it's a digit unless also <= '9'; same for letters. Also, condition mixes types incorrectly (e.g., '0' to 'z' includes non-digit/letter chars)]
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ [Logic error: b[j] is uninitialized in loop condition; should iterate from a[i]+1 to a[i+2]-1 and assign directly]
                    b[j] = b[j - 1] + 1;
                i = i + 2;
            } else {
                b[j] = a[i];
                j++;
                i++;
            }
        }
    }
    b[j] = '\0';
    printf("%s", b);
    return 0;
}