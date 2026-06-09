#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int str[11];
int flag[11];
int n;

int result(int op) { // @@ Function declared as int but lacks a return statement, causing a compilation error. It should be void.
    if (op == n + 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d", str[i]); // @@ Missing space separator between integers. The output format requires each integer to be separated by a space.
        }
        printf("\n"); // @@ Missing return statement after printing a complete permutation. Without it, execution falls through to the loop, causing out-of-bounds array access and infinite recursion.
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