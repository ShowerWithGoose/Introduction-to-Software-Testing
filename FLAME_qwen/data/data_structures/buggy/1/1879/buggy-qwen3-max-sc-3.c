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
        puts(re); // @@ [The output format requires each integer in a line to be separated by a space, but puts(re) prints the string as-is without spaces between digits. Also, the digits are stored as characters like '1', '2', etc., so "123" is printed instead of "1 2 3".]
        return;
    }
    int i;
    for (int i = 1; i <= N; i++) { // @@ [Variable 'i' is declared again inside the for loop, which shadows the outer 'i'. While this is allowed in C99+, it's redundant and may cause confusion, but not a compilation error. However, the real issue is output formatting, not this line.]
        if (num[i] == 0) {
            num[i] = 1;
            re[m] = '0' + i;
            func(m + 1, n - 1);//进行递归
            num[i] = 0;
        }
    }
}