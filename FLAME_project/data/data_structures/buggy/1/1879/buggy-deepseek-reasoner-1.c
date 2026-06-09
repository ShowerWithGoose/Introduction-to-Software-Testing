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
        puts(re); // @@ [This outputs the string without spaces between numbers. The required output format requires spaces, e.g., "1 2" instead of "12".]
        return;
    }
    int i;
    for (int i = 1; i <= N; i++) {
        if (num[i] == 0) {
            num[i] = 1;
            re[m] = '0' + i; // @@ [This stores the digit as a single character without a space. For numbers 1-9 it's fine but for 10 it would be a non-digit character. More critically, it does not add a space between numbers, causing concatenated output like "12".]
            func(m + 1, n - 1);//进行递归
            num[i] = 0;
        }
    }
}