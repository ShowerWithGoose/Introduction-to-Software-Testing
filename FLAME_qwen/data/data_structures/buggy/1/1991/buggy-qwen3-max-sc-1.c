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
            printf("%d", str[i]);
        }
        printf("\n");
        return; // @@ [Missing return statement causes function to fall through into the loop after printing a permutation, leading to incorrect behavior and potential undefined behavior since op may exceed array bounds]
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