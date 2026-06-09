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
        return; // @@ [Missing return statement causes function to fall through into the loop after printing a permutation, leading to incorrect behavior and potential undefined behavior since the function is declared to return int but doesn't return a value in all paths. Also, output format requires space-separated integers, but this prints without spaces.]
    }
    for (int j = 1; j <= n; j++) {
        if (flag[j] == 0) {
            str[op] = j;
            flag[j] = 1;//标记
            result(op + 1);//递归下一个位置
            flag[j] = 0;
        }
    }
    return 0; // @@ [Function result is declared to return int, but control may reach end of non-void function without a return in some paths (though logically it shouldn't due to recursion base case), which is undefined behavior. However, more critically, the output lacks spaces between numbers as required.]

}

int main() {
    scanf("%d", &n);
    result(1);
    return 0;

}