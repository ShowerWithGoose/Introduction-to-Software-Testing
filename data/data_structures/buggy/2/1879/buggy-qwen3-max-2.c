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
    int j = 0, x = b[2], result = b[1]; // @@ [Using b[2] before ensuring it exists; if expression has only one number, b[2] is uninitialized]
    for (i = 0, j = 1; i < n;) {
        j = i + 1;
        x = b[j];
        while (a[j] == '*' || a[j] == '/') {
            if (a[j] == '*')
                x *= b[j + 1];
            else
                x /= b[j + 1]; // @@ [May access b[j+1] beyond valid input range when j+1 > n]
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