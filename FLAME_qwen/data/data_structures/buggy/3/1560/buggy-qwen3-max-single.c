//格式化输入和输出函数
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define eps 1e-20; // @@ [Trailing semicolon in macro definition causes syntax error when used in expressions; also, 'eps' is unused]
typedef long long ll;
int main()
{
    char str[101000] = { '0' };
    char str1[101000] = { '0' };
    char format[100] = { '0' };
    gets(str); // @@ [Use of unsafe function 'gets' which is deprecated and removed in C11; may cause compilation error depending on compiler settings]
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
        for (int i = 0;i < len - 1;i++) // @@ [Loop condition 'i < len - 1' may skip last digit before decimal if no decimal exists; logic flaw but not compilation error]
        {
            if (str[i] == '.')break;
            else k++;
        }
        k--;
    }
    else
    {
        int i = 0;
        for (i = 2;;i++) // @@ [Infinite loop risk if input has no non-zero digit after "0."; also assumes at least two characters exist (e.g., "0.x"), which may not hold]
        {
            if (str[i] == '0')k++;
            else break;
        }
        if (i < len - 1)k++; // @@ [Potential out-of-bounds access if loop breaks at i == len or beyond]
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