#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define eps 1e-20; // @@ 宏定义末尾不应有分号，可能导致编译警告或意外替换
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
        for (int i = 0;i < len - 1;i++) // @@ 对于无小数点的整数，循环条件 i<len-1 导致漏算最后一位，同时应特殊处理整数输出不带小数点
        {
            if (str[i] == '.')break;
            else k++;
        }
        k--; // @@ 在无小数点时，k-- 多减1，导致指数偏小1
    }
    else
    {
        int i = 0;
        for (i = 2;;i++) // @@ 缺少边界检查 i < len，访问可能越界（如输入"0."或"0.0"时）
        {
            if (str[i] == '0')k++;
            else break;
        }
        if (i < len - 1)k++; // @@ 条件应为 i < len，否则对于 "0.1" 此类输入，k 少加1，导致指数错误
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