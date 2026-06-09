#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[1000];
    gets(a); // @@ unsafe input function; should use scanf instead
    int i, j;
    j = 0;
    i = 0;
    while (a[i] != '\0') {
        if (a[i + 1] != '-') {
            b[j] = a[i];
            j++;
            i++;
        } else {
            if (((a[i] >= '0' && a[i + 2] <= '9') || (a[i] >= 'a' && a[i + 2] <= 'z') || (a[i] >= 'A' && a[i + 2] <= 'Z')) // @@ condition incorrectly checks only one side; must verify both characters are of same type (e.g., isdigit(a[i]) && isdigit(a[i+2]))
                    && a[i] < a[i + 2]) {
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ loop uses uninitialized b[j] as condition; should iterate from start+1 to end-1
                    b[j] = b[j - 1] + 1; // @@ incorrect index management; does not correctly fill expansion characters
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