#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[1000];
    gets(a); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, missing #include <stdlib.h> or <stdio.h> might not be the issue but 'gets' itself is problematic and often leads to compilation warnings or errors in modern compilers]
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
                    && a[i] < a[i + 2]) { // @@ [Incorrect range checks: e.g., 'a[i] >= '0'' alone doesn't ensure it's a digit unless also 'a[i] <= '9'', similarly for letters; also, mixing types like '0' and 'z' can pass condition incorrectly]
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ [Logic error: b[j] is uninitialized in the loop condition; should iterate from a[i]+1 to a[i+2]-1 and assign directly, not based on b[j]]
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