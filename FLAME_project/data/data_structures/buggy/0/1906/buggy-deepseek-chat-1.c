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
                    && a[i] < a[i + 2]) { // @@ [The condition incorrectly checks if a[i+2] is within the entire range (e.g., <= '9') instead of checking if both characters are in the same category (e.g., both digits). This causes incorrect expansion for mixed types like 'u' and 'F'.]
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ [The loop condition uses b[j] which is uninitialized at the start, and the loop increments j incorrectly, overwriting the previously stored character. It should use a separate variable to generate and store the expanded characters.]
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