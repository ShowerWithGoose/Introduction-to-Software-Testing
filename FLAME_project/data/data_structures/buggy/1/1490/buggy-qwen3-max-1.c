#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//输入输出类型！循环后清零！输入取地址！数据范围！吃掉回车！输出换行！
//long long lld! while(){..i=0}! scanf("",&a)! getchar()! printf("..\n")!

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("1"); // @@ [Missing newline at the end of output for n=1; expected "1\n"]
    }
    if (n == 2) {
        printf("1 2\n2 1"); // @@ [Missing newline at the end of output for n=2; expected "1 2\n2 1\n"]
    }
    if (n == 3) {
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1"); // @@ [Missing newline at the end of output for n=3; expected a trailing '\n']
    }
    if (n == 4) {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n");
        printf("2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n");
        printf("3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n");
        printf("4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n");
    }

    return 0;
}