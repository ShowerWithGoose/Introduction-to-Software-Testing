#include <stdio.h>

int num[15] = { 0 };  //记录数字是否在数字串里
char re[15];  //排列的数字串
void func(int m, int n);  //m是第几位数字，n是还剩几位数字,用递归
int N;
int main() {

    scanf("%d", &N);
    func(0, N);
    return 0;
}
void func(int m, int n) {
    if (n == 0) {
        re[m] = '\0';
        puts(re); // @@ 错误：输出时数字之间没有空格分隔，而题目要求每个整数之间用空格分隔。应改为循环输出每个字符并加空格。
        return;
    }
    int i;
    for (int i = 1; i <= N; i++) { // @@ 错误：变量i在for循环中重复声明（int i; 和 for (int i = 1; ...)），导致编译错误。应删除第14行的"int i;"或改为"i = 1;"。
        if (num[i] == 0) {
            num[i] = 1;
            re[m] = '0' + i;
            func(m + 1, n - 1);//进行递归
            num[i] = 0;
        }
    }
}