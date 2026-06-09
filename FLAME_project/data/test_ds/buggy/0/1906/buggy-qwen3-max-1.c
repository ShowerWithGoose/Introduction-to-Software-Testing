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
                    && a[i] < a[i + 2]) { // @@ [The condition checks only one side of the range for each type. For example, it checks a[i] >= '0' but not a[i] <= '9', and similarly for letters. This allows invalid cross-type ranges like '0-z' to pass.]
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ [This loop condition uses b[j] which is uninitialized on first iteration of the loop; it should use a variable based on a[i] instead. Also, it writes one character too many because it includes a[i+2] in the output, but the expansion should stop before a[i+2].]
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