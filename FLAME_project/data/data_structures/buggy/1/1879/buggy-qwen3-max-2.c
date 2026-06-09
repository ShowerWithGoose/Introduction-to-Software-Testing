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
        puts(re); // @@ [The output uses puts() which prints characters without spaces between digits, but the problem requires space-separated integers. Also, lexicographical order is achieved by the recursion order, but the format is wrong.]
        return;
    }
    int i;
    for (int i = 1; i <= N; i++) {
        if (num[i] == 0) {
            num[i] = 1;
            re[m] = '0' + i; // @@ [This stores the digit as a character (e.g., '1', '2'), but the problem expects integer output with spaces, not concatenated digits.]
            func(m + 1, n - 1);//进行递归
            num[i] = 0;
        }
    }
}