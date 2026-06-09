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
        puts(re); // @@ [The output uses puts(), which prints the string as a sequence of characters without spaces between numbers. For N=2, "12" is printed instead of "1 2". The problem requires space-separated integers.]
        return;
    }
    int i;
    for (int i = 1; i <= N; i++) {
        if (num[i] == 0) {
            num[i] = 1;
            re[m] = '0' + i; // @@ [Storing digits as characters in a char array leads to concatenated digits (e.g., '1' followed by '2' becomes "12"), but the expected output requires space-separated integers like "1 2".]
            func(m + 1, n - 1);//进行递归
            num[i] = 0;
        }
    }
}