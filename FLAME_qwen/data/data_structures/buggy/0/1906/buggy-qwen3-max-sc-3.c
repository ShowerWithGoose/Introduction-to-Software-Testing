#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[1000];
    gets(a); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, missing #include <stdlib.h> or <ctype.h> if needed, but primary issue is 'gets']
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
                    && a[i] < a[i + 2]) { // @@ [Incorrect range checks: e.g., 'a[i] >= '0'' alone doesn't ensure it's a digit; should check both ends are same type and valid]
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ [Logic error: b[j] is uninitialized in condition; should use a loop variable based on a[i]+1 to a[i+2]-1]
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