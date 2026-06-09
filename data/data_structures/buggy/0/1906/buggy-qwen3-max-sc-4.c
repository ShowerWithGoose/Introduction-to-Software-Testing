#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[1000];
    gets(a); // @@ [Using gets() is unsafe and deprecated; it can cause buffer overflow. Also, may lead to compilation error with modern compilers that remove gets().]
    int i, j;
    j = 0;
    i = 0;
    while (a[i] != '\0') {
        if (a[i + 1] != '-') { // @@ [This condition checks the next character for '-', but when i is at the last character, a[i+1] is '\0', which is safe, but logic is inverted: should check if current char is part of a pattern like X-Y, so better to check a[i]=='-' in context of surrounding chars. However, main issue is below.]
            b[j] = a[i];
            j++;
            i++;
        } else {
            if (((a[i] >= '0' && a[i + 2] <= '9') || (a[i] >= 'a' && a[i + 2] <= 'z') || (a[i] >= 'A' && a[i + 2] <= 'Z')) // @@ [Incorrect range checking: e.g., a[i] >= '0' alone doesn't ensure it's a digit; should also check a[i] <= '9'. Similarly for letters. Also, mixing types: e.g., '0' <= a[i] <= '9' AND same for a[i+2], but here it's cross-checked incorrectly. This causes wrong expansion decisions.]
                    && a[i] < a[i + 2]) {
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ [b[j] is uninitialized in the loop condition; should use a counter variable starting from a[i]+1 up to a[i+2]-1. Also, this loop writes beyond intended because condition uses b[j] which was just set in previous line only once. Logic is flawed.]
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