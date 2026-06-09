#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[1000];
    gets(a);
    int i, j;
    j = 0;
    i = 0;
    while (a[i] != '\0') {
        if (a[i + 1] != '-') { // @@ Logical error: checks the next character instead of the current one. Should check `a[i] != '-'` to correctly process normal characters, otherwise the '-' symbol will be skipped for expansion.
            b[j] = a[i];
            j++;
            i++;
        } else {
            if (((a[i] >= '0' && a[i + 2] <= '9') || (a[i] >= 'a' && a[i + 2] <= 'z') || (a[i] >= 'A' && a[i + 2] <= 'Z')) // @@ Logical error: type checking is incorrect. `a[i] >= '0' && a[i+2] <= '9'` does not ensure both characters are of the same type. Both `a[i]` and `a[i+2]` must be verified to fall within the same specific range.
                    && a[i] < a[i + 2]) {
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ Semantic error: `b[j]` is uninitialized when used in the loop condition, causing undefined behavior. A temporary variable should be used to track the expanding character.
                    b[j] = b[j - 1] + 1; // @@ Logical error: relies on uninitialized values and incorrect loop structure. Should directly assign the next character in the sequence.
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