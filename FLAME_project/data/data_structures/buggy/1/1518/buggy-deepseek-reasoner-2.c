#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int Mark[10] = { 0 };
char s[11];
void rank(int m, int n);
int x;
int main()
{
    scanf("%d", &x);
    rank(0, x);
    return 0;
}
void rank(int m, int n)
{
    int i;
    if (n == 0) {
        s[m] = '\0';
        puts(s); // @@ 错误: 应逐个输出字符并加空格，如 printf("%c ", s[j])，最后换行，否则输出缺少空格分隔且不符合格式要求
        return;
    }
    for (i = 1; i <= x; i++)
        if (Mark[i] == 0) {
            Mark[i] = 1;     
            s[m] = '0' + i;      
            rank(m + 1, n - 1);     
            Mark[i] = 0;    
        }
}