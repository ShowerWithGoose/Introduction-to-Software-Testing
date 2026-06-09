//格式化输入和输出函数
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define eps 1e-20; // @@ Macro definitions should not end with a semicolon, which causes syntax errors when expanded.
typedef long long ll;
int main()
{
    char str[101000] = { '0' };
    char str1[101000] = { '0' };
    char format[100] = { '0' };
    gets(str); // @@ 'gets' is removed in C11 and causes compilation errors in modern compilers; use 'fgets' instead.
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
        k--; // @@ Logical error: for single-digit inputs like "5", k becomes -1 instead of 0, yielding an incorrect exponent.
    }
    else
    {
        int i = 0;
        for (i = 2;;i++)
        {
            if (str[i] == '0')k++;
            else break;
        }
        if (i < len - 1)k++; // @@ Logical error: for inputs like "0.5", k remains 0 instead of 1, yielding an incorrect exponent.
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