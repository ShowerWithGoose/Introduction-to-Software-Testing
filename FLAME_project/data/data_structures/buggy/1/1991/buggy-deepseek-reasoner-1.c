#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int str[11];
int flag[11];
int n;

int result(int op) { // @@ [function should be void; no return value]
    if (op == n + 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d", str[i]); // @@ [missing space between numbers; should be printf("%d ", str[i]) for all except last]
        }
        printf("\n"); // @@ [missing return statement after printing to prevent further recursion]
    }
    for (int j = 1; j <= n; j++) {
        if (flag[j] == 0) {
            str[op] = j;
            flag[j] = 1;//标记
            result(op + 1);//递归下一个位置
            flag[j] = 0;
        }
    }

}

int main() {
    scanf("%d", &n);
    result(1);
    return 0;

}