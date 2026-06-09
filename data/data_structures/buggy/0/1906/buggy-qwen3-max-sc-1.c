#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[1000];
    gets(a); // @@ [Use of unsafe and deprecated function 'gets' which may cause buffer overflow; also, 'gets' is removed in C11 standard, leading to compilation error if compiler enforces strict standards]
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
                    && a[i] < a[i + 2]) { // @@ [Incorrect range checks: e.g., 'a[i] >= '0'' alone doesn't ensure it's a digit without also checking 'a[i] <= '9'', same for letters; also logic mixes types (e.g., '0' and 'z') leading to invalid expansions]
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ [Loop condition uses uninitialized b[j]; also, loop increments j before assignment in body, causing out-of-order writes and potential infinite loop]
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