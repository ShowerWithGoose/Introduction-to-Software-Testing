#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[1000];
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow. Also, some compilers reject it, leading to compilation error.]
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
                    && a[i] < a[i + 2]) { // @@ [Condition logic is flawed: it checks lower bound on left and upper bound on right independently, e.g., 'a' >= '0' is true and '9' <= 'z' is true, so 'a-9' would incorrectly pass. Should check both ends belong to same category.]
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ [Loop condition uses uninitialized b[j]; also, loop increments j before assignment in body, causing out-of-sync indexing and potential undefined behavior.]
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