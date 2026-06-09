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
    int j = 0, x = b[2], result = b[1]; // @@ The initialization of x to b[2] is incorrect because if the expression has only one number or starts with operations that don't involve b[2] immediately in the first pass, it uses uninitialized or wrong data. More importantly, the logic inside the loop recalculates x, but the initial value here is suspicious and potentially unused or misleading. However, the critical error is in the loop logic below.
    for (i = 0, j = 1; i < n;) {
        j = i + 1;
        x = b[j]; // @@ This line sets x to the operand at index j. If the operator at a[i] is '+' or '-', we want to accumulate terms. The logic attempts to handle precedence by scanning ahead for * and /.
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