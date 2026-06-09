#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[1000];
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. Also, may lead to compilation error with modern compilers that remove 'gets'.]
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
                    && a[i] < a[i + 2]) { // @@ [Incorrect range checks: e.g., 'a[i] >= '0'' and 'a[i+2] <= '9'' does not ensure both are digits; should check both ends belong to same category. Also, accessing a[i+2] without ensuring i+2 is within bounds leads to undefined behavior.]
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ [Logic error: b[j] is uninitialized in the loop condition; should use a temporary variable or different loop structure. Also, this loop writes one character too many (includes a[i+2]).]
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