#include <stdio.h>

int mark[10] = {0}; // @@ 数组大小应为11，因为需要索引1到10，当前大小导致越界访问
char stack[11];

void pl(int m, int n) {
    if (m == n) {
        stack[m] = '\0';
        puts(stack); // @@ 输出没有空格分隔数字，不符合题目要求
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            stack[m] = '0' + i;
            pl(m + 1, n);
            mark[i] = 0;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    pl(0, n);
    return 0;
}