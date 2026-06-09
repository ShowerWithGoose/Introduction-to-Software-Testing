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
    int j = 0, x = b[2], result = b[1]; // @@ Error: result should be initialized to 0 (or b[0]) instead of b[1] to avoid double-counting the first number. The subsequent loop uses a[0]='+' to add the first term, so starting with result=b[1] leads to adding it twice.
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