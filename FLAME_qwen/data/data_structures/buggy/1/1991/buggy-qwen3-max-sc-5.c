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
        return; // @@ [Missing return statement causes function to fall through into the loop after printing a permutation, leading to incorrect behavior and potential undefined behavior since the function is declared to return int but doesn't return a value in all paths]
    }
    for (int j = 1; j <= n; j++) {
        if (flag[j] == 0) {
            str[op] = j;
            flag[j] = 1;//标记
            result(op + 1);//递归下一个位置
            flag[j] = 0;
        }
    }
    return 0; // @@ [Function is declared to return int but lacks a return statement at the end; while this may not cause a compilation error in some compilers due to implicit int return, it's undefined behavior and inconsistent with the base case which also didn't return properly]

}

int main() {
    scanf("%d", &n);
    result(1);
    return 0;

}