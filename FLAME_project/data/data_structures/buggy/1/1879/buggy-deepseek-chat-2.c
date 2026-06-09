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
        puts(re); // @@ [Error: puts() outputs the string without spaces between digits, but the expected output requires spaces between each integer (e.g., "1 2" not "12"). Also, the output should end with a newline, but puts() adds a newline anyway, so the format is wrong.]
        return;
    }
    int i;
    for (int i = 1; i <= N; i++) { // @@ [Error: The variable 'i' is declared twice (once as 'int i;' above and once as 'int i' in the for loop), causing a compilation error in C. Remove the redundant 'int i;' declaration.]
        if (num[i] == 0) {
            num[i] = 1;
            re[m] = '0' + i;
            func(m + 1, n - 1);//进行递归
            num[i] = 0;
        }
    }
}