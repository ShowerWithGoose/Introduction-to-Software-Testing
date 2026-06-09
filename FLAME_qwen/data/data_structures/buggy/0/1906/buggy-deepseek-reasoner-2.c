#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[1000];
    gets(a); // @@ Use of gets is deprecated and unsafe; may cause buffer overflow. Prefer fgets or scanf.
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
                    && a[i] < a[i + 2]) { // @@ Condition does not correctly check that both characters are of the same type (digit, lowercase, uppercase). It just checks that the first is in a range and the second is <= the max of that range, allowing mismatched types. Also does not verify that the second is actually in the same specific range.
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ Loop uses uninitialized b[j] as condition; undefined behavior. Also does not correctly expand intermediate characters and does not output the second character of the range after expansion.
                    b[j] = b[j - 1] + 1; // @@ This line is part of the erroneous loop.
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