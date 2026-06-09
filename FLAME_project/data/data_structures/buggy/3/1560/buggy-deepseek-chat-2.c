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
        if (i < len - 1)k++; // @@ [Error: For input "0.9", when i=2, str[2]='9' which is not '0', so the loop breaks immediately with k=0. Then i=2, and len=3, so i < len-1 (2 < 2) is false, so k remains 0. However, the exponent should be -1 (since 0.9 = 9e-1), but k is 0, leading to output "e-0" instead of "e-1". The logic for counting leading zeros after the decimal point is incorrect; it should count the number of zeros before the first non-zero digit, and the exponent should be -(number of zeros + 1).]
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