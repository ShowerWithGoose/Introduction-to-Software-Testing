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
                    && a[i] < a[i + 2]) { // @@ [The condition checks only one side of the range for each type. For example, it checks a[i] >= '0' but not a[i] <= '9', and similarly for letters. This allows invalid cross-type ranges like 'a'-'9' to pass if a[i] >= 'a' and a[i+2] <= 'z' even if a[i+2] is not a lowercase letter. Also, it doesn't ensure both characters are of the same category.]
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ [This loop uses b[j] (uninitialized at start of loop) in the condition. It should use a variable based on a[i], not b[j]. Also, it overwrites b[j] after incrementing j, causing off-by-one and incorrect expansion. Additionally, it includes a[i+2] in output, but problem requires expanding up to but not including a[i+2]? Actually, expected output includes the end character, so that's okay, but logic is flawed due to uninitialized b[j].]
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