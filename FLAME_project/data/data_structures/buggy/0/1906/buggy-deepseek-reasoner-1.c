#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[1000];
    gets(a);
    int i, j;
    j = 0;
    i = 0;
    while (a[i] != '\0') {
        if (a[i + 1] != '-') {
            b[j] = a[i];
            j++;
            i++;
        } else {
            if (((a[i] >= '0' && a[i + 2] <= '9') || (a[i] >= 'a' && a[i + 2] <= 'z') || (a[i] >= 'A' && a[i + 2] <= 'Z')) // @@ Condition incorrectly checks only one end of the range; should ensure both characters are in the same category and within the same range.
                    && a[i] < a[i + 2]) {
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ The loop uses b[j] before it is assigned, causing undefined behavior; also does not correctly generate the expansion characters.
                    b[j] = b[j - 1] + 1; // @@ This line is part of the flawed loop; b[j] is uninitialized on the first iteration.
                i = i + 2; // @@ Skips the right character without copying it; the right character should be included after expansion.
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