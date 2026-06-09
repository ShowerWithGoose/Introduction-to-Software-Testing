//格式化输入和输出函数
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define eps 1e-20;
typedef long long ll;
int main()
{
    char str[101000] = { '0' };
    char str1[101000] = { '0' };
    char format[100] = { '0' };
    gets(str);
    int len = strlen(str);
    int k = 0;
    int sign = -1;
    for (int i = 0;i < len;i++)
    {
        if (str[i] == '.')break;
        if (str[i] >= '1' && str[i] <= '9')sign = 1;
    }
    if (sign == 1)
    {
        for (int i = 0;i < len - 1;i++)
        {
            if (str[i] == '.')break;
            else k++;
        }
        k--;
    }
    else
    {
        int i = 0;
        for (i = 2;;i++)
        {
            if (str[i] == '0')k++;
            else break;
        }
        if (i < len - 1)k++; // @@ [Error: For input "0.9", when i=2, str[2]='9' is not '0', loop breaks with i=2, k=0. Then condition i < len-1 (2 < 2) is false, so k remains 0. But the exponent should be -1, so k should be incremented to 1. The logic incorrectly handles the case where the first non-zero digit is immediately after the decimal point.]
    }
    int j = 0;
    while (str[j] == '0' || str[j] == '.')j++;
    if (j == len - 1)printf("%c", str[j]);
    else printf("%c.", str[j]);
    j++;
    for (int i = j;i < len;i++)
    {
        if (str[i] == '.')continue;
        printf("%c", str[i]);
    }
    printf("e");
    if (sign == -1)printf("-");
    printf("%d", k);
    return 0;
}