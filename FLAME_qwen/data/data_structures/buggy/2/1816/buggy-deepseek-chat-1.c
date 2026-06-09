/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2024-02-27 22:28
    说明:

*********************************************************************/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char a[100001];
int b[10001], c[10001], num[10001], d[10001];
int f(char a, int b, int c) {
    switch (a) {
        case '+':
            return b + c;
        case '-':
            return b - c;
        case '*':
            return b * c;
        case '/':
            return b / c;
    }
}

int main() {
    gets(a);
    int i, j;
    for (i = j = 0; a[i] != '\0'; i++)
        if (a[i] != ' ')
            a[j++] = a[i];
    a[j] = '\0';
    int m = 0, n = 0, p = 1, f1 = 0;
    for (int x = 0; x < j; x++) {
        if (a[x] == '+' || a[x] == '-') {
            m++;
            p++;
            f1++;
            b[m] = x;
            d[m] = f1;

        } else if (a[x] == '*' || a[x] == '/') {
            n++;
            p++;
            f1++;
            c[n] = x;
            d[n] = f1;

        } else if (a[x] == '=')
            break;
        else
            num[p] = num[p] * 10 + a[x] - '0';
    }

    for (int x = 1; x <= n; x++) {
        num[d[x]] = f(a[c[x]], num[d[x]], num[d[x] + 1]); // @@ [Error: The index d[x] may be out of bounds or incorrect because d[x] is not properly aligned with the num array indices. The logic for tracking positions with d[] is flawed, leading to incorrect operand access.]
        num[d[x] + 1] = num[d[x]]; // @@ [Error: This line overwrites the next operand incorrectly, causing subsequent calculations to use wrong values. The approach of copying the result to the next position is not valid for all cases, especially when multiple operators are involved.]

    }
    int sum = num[1];
    for (int x = 1; x <= m; x++) {
        sum = f(a[b[x]], sum, num[d[x] + 1]); // @@ [Error: Similar indexing issue with d[x] + 1; the operand positions are not correctly tracked, leading to incorrect addition/subtraction results.]
    }
    printf("%d", sum);
    return 0;
}