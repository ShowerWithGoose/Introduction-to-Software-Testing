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
    }
    for (int j = 1; j <= n; j++) {
        if (flag[j] == 0) {
            str[op] = j;
            flag[j] = 1;//标记
            result(op + 1);//递归下一个位置
            flag[j] = 0;
        }
    }
@@ [The function 'result' is declared to return an int but does not return a value in all paths. This causes undefined behavior and may lead to compilation warnings or errors depending on compiler settings. Additionally, the output format is incorrect: numbers should be separated by spaces, but this code prints them without spaces.]

}

int main() {
    scanf("%d", &n);
    result(1);
    return 0;

}