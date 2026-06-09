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
                    && a[i] < a[i + 2]) { // @@ [Condition does not properly ensure same type; it mixes range checks, leading to incorrect expansion detection.]
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ [Loop condition uses uninitialized b[j]; should use a separate variable to generate characters until a[i+2] inclusive.]
                    b[j] = b[j - 1] + 1;
                i = i + 2; // @@ [Incorrect index increment; should be i = i + 3 to skip the last character and prevent duplication.]
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