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
    int j = 0, x = b[2], result = b[1]; // @@ [x is initialized to b[2], but if the expression has only one term or starts with an operator followed by fewer than 2 numbers, this leads to undefined behavior; more critically, the logic for grouping multiplication/division terms is flawed because it assumes at least two numbers exist and doesn't correctly handle the starting index]
    for (i = 0, j = 1; i < n;) {
        j = i + 1;
        x = b[j]; // @@ [This overwrites the previous x, but the real issue is that when i=0, j=1, x=b[1], which is correct for the first term, but later iterations may access beyond valid data or skip operators]
        while (a[j] == '*' || a[j] == '/') { // @@ [This loop checks a[j], which is the operator after b[j], but then uses b[j+1]. However, when j reaches n-1 (last number), a[j] is '=', and b[j+1] is uninitialized or garbage. Also, the loop condition should ensure j+1 <= n]
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