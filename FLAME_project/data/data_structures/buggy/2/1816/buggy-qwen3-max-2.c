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
        num[d[x]] = f(a[c[x]], num[d[x]], num[d[x] + 1]);
        num[d[x] + 1] = num[d[x]]; // @@ [This line incorrectly propagates the result of a multiplication/division to the next operand slot, which corrupts subsequent operations. For example, in "24/4/3", after computing 24/4=6, it sets num[2]=6, but then when processing "/3", it uses num[2] (now 6) and num[3] (original 3), which is correct for left-to-right, BUT the issue is that later additions/subtractions use `num[d[x]+1]` which may now refer to an overwritten value. More critically, the algorithm assumes all operators are processed in order of appearance, but doesn't respect operator precedence correctly when mixing * / with + -, and the indexing via `d` array is flawed because `d` stores cumulative operator counts, not operand indices aligned with current state.]

    }
    int sum = num[1];
    for (int x = 1; x <= m; x++) {
        sum = f(a[b[x]], sum, num[d[x] + 1]); // @@ [The index `d[x] + 1` does not correctly map to the intended operand after prior overwrites in the multiplication/division loop. The `d` array was built during initial parsing and doesn't reflect the collapsing of operands during * / evaluation. Thus, `num[d[x]+1]` may refer to a stale or overwritten value, leading to incorrect addition/subtraction results.]

    }
    printf("%d", sum);
    return 0;
}