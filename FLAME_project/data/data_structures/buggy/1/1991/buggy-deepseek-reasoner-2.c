#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int str[11];
int flag[11];
int n;

int result(int op) {
    if (op == n + 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d", str[i]); // @@ Missing spaces between numbers; should print "%d " for i<n and "%d\n" for i==n, or use a loop with spaces.
        }
        printf("\n"); // @@ After printing a permutation, the function should return to avoid executing the following loop unintentionally.
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