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
        if (i < len - 1)k++; // @@ The logic for calculating the exponent for numbers less than 1 is incorrect. For "0.9", k remains 0, but the exponent should be -1. The condition `if (i < len - 1)` fails to account for the shift correctly when there are no leading zeros after the decimal point or miscounts the position. Specifically, for 0.d..., the exponent is -(number of zeros after decimal + 1). Here k counts zeros. If str[2] is not '0', loop breaks immediately, k=0. Then `i` is 2. `len` is 3. `2 < 2` is false. So k stays 0. But exponent should be -1.
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