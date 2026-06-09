#include <stdio.h>
#include <string.h>
char a[1000];//×Ö·û
int b[1000];//Êý×Ö

int main() {
    int i = 1;
    a[0] = '+';
    b[0] = 0;
    scanf("%d", &b[i]);
    scanf(" %c", &a[i]);
    while (a[i] != '=') {
        i++;
        scanf("%d", &b[i]);
        scanf(" %c", &a[i]);
    }
    int n = i;
    int j = 0, x = b[2], result = b[1]; // @@ [x is initialized to b[2], but if the expression has only one number (e.g., "5 ="), b[2] is uninitialized, leading to undefined behavior. Also, result assumes at least one number exists, but indexing starts incorrectly for expressions with only one term.]
    for (i = 0, j = 1; i < n;) {
        j = i + 1;
        x = b[j]; // @@ [If j exceeds the valid index (e.g., when i = n-1, then j = n, and b[j] is out of bounds), this causes undefined behavior. The loop condition does not prevent accessing beyond the last valid operand.]
        while (a[j] == '*' || a[j] == '/') {
            if (a[j] == '*')
                x *= b[j + 1];
            else
                x /= b[j + 1];
            j++;
        }
        if (a[i] == '+')
            result += x;
        else
            result -= x;
        i = j;

    }
    printf("%d", result);
}