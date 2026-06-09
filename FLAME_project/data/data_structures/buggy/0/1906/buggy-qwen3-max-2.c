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
            if (((a[i] >= '0' && a[i + 2] <= '9') || (a[i] >= 'a' && a[i + 2] <= 'z') || (a[i] >= 'A' && a[i + 2] <= 'Z'))
                    && a[i] < a[i + 2]) { @@ // Condition is incorrect: it checks only lower bounds for the first char and upper bounds for the second, without ensuring both chars are of the same type and within valid ranges. Should check both ends belong to same category.
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++)
                    b[j] = b[j - 1] + 1; @@ // Logic error: loop condition uses b[j] which is uninitialized on first iteration; also overwrites one character beyond a[i+2]
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