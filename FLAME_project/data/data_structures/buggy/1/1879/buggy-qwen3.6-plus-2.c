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
        puts(re); // @@ The output format is incorrect. The problem requires integers separated by spaces, but this code outputs characters without spaces (e.g., "12" instead of "1 2"). Additionally, using char array limits digits to 0-9 correctly for N<=10 but the formatting is wrong.
        return;
    }
    int i;
    for (int i = 1; i <= N; i++) {
        if (num[i] == 0) {
            num[i] = 1;
            re[m] = '0' + i; // @@ Storing as character makes it difficult to print with spaces later. It should store integers or handle printing differently to match "1 2" format.
            func(m + 1, n - 1);//进行递归
            num[i] = 0;
        }
    }
}