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
        puts(re); // @@ [Using puts() outputs the string followed by a newline, but the problem requires each integer in the permutation to be separated by a space and no extra spaces at the end. Also, puts() prints characters as-is, so digits like '1' are printed as characters, which is correct, but the format does not match expected output due to missing spaces between digits and incorrect line formatting.]
        return;
    }
    int i;
    for (int i = 1; i <= N; i++) {
        if (num[i] == 0) {
            num[i] = 1;
            re[m] = '0' + i;
            func(m + 1, n - 1);//进行递归
            num[i] = 0;
        }
    }
}