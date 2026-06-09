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
                    && a[i] < a[i + 2]) { @@ [The condition checks only one side of the range (e.g., a[i] >= '0' but doesn't ensure a[i] <= '9'), so it may incorrectly allow mixed-type expansions like 'a'-'9'. Also, it doesn't verify that both characters are of the same category.]
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) @@ [This loop condition uses b[j], which is uninitialized on first iteration; it should use a loop variable or compare against a[i+2] differently. Also, it overwrites one character beyond the intended range because it includes a[i+2] in the output via incrementing after assignment, leading to duplication or overflow.]
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