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
    int j = 0, x = b[2], result = b[1]; // @@ [Error: The initialization of x and result is incorrect. x is set to b[2] which may be uninitialized or out of bounds if n < 2, and result is set to b[1] which assumes the first number is always positive, but the first operator is stored in a[0] as '+', so the logic should start from i=0 and j=1 properly.]
    for (i = 0, j = 1; i < n;) {
        j = i + 1;
        x = b[j];
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