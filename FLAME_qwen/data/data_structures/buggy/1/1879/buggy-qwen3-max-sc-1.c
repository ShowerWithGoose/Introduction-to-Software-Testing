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
        puts(re); // @@ [Using puts() outputs the string followed by a newline, but the problem requires each integer in the permutation to be separated by a space and no extra space at the end. Also, puts() prints characters as-is, so digits '1'-'9' are printed correctly, but for N=10, '0'+10 is not a valid single character representation of "10", causing incorrect output for N>=10. Additionally, the output format requires space-separated integers, not a raw character string.]
        return;
    }
    int i;
    for (int i = 1; i <= N; i++) {
        if (num[i] == 0) {
            num[i] = 1;
            re[m] = '0' + i; // @@ [This only works for i from 1 to 9. When i is 10, '0' + 10 equals ':', which is not the digit "10". The program cannot represent two-digit numbers like 10 as a single char, so it fails for N=10. The approach of storing permutations as a char array is fundamentally flawed for N>=10.]
            func(m + 1, n - 1);//进行递归
            num[i] = 0;
        }
    }
}