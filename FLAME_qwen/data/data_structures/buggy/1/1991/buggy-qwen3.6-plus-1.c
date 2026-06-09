#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int str[11];
int flag[11];
int n;

int result(int op) { // @@ Function is declared to return int but does not return a value. It should be void.
    if (op == n + 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d", str[i]); // @@ Missing space separator between integers. Should be printf("%d ", str[i]);
        }
        printf("\n");
    } // @@ Missing return statement after base case. Without it, execution falls through to the loop, causing out-of-bounds array access and infinite recursion.
    for (int j = 1; j <= n; j++) {
        if (flag[j] == 0) {
            str[op] = j;
            flag[j] = 1;//标记
            result(op + 1);//递归下一个位置
            flag[j] = 0;
        }
    }

} // @@ Missing return 0; at the end of the function, or change return type to void.

int main() {
    scanf("%d", &n);
    result(1);
    return 0;

}