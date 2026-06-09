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
            if (((a[i] >= '0' && a[i + 2] <= '9') || (a[i] >= 'a' && a[i + 2] <= 'z') || (a[i] >= 'A' && a[i + 2] <= 'Z')) // @@ The condition for same type is too loose; it must ensure both characters are within the same range (e.g., both digits, both lowercase, or both uppercase). This allows mixing types, leading to false expansions.
                    && a[i] < a[i + 2]) {
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ The loop condition uses an uninitialized b[j] (b[j] is garbage). Additionally, the loop should iterate only while the generated character is strictly less than the ending character, not including it. This causes undefined behavior and incorrect expansion.
                    b[j] = b[j - 1] + 1;
                i = i + 2; // @@ After the loop, the end character (a[i+2]) was already written (because the loop condition was <=), but i is set to the index of that end character. This causes the end character to be output again in the next iteration, resulting in duplication.
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