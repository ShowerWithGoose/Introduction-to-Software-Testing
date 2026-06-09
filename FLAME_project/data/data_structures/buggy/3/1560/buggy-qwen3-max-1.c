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
        k--; // @@ [This decrements k unnecessarily; for numbers like "8.7", k should be 0 (since exponent is 0), but this makes it -1. However, the main bug is in the else branch handling of k for numbers like "0.9".]
    }
    else
    {
        int i = 0;
        for (i = 2;;i++)
        {
            if (str[i] == '0')k++;
            else break;
        }
        if (i < len - 1)k++; // @@ [This extra increment is incorrect. For input "0.9", i starts at 2, str[2] is '9' (not '0'), so loop breaks with k=0. Then i=2, len=3, so i < len-1 → 2 < 2 is false, so k remains 0. But exponent should be -1, not 0. The correct logic should set exponent to -(number of leading zeros after decimal + 1). Here, no leading zeros, so exponent = -1, but k=0 leads to e0 or e-0. Also, the condition `if (i < len - 1)` is flawed.]
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
    printf("%d", k); // @@ [For input "0.9", k is 0, so output is "9e-0", but expected is "9e-1". The value of k is computed incorrectly in the else block. The exponent for 0.d1d2... should be -(position of first non-zero digit after decimal). For "0.9", first non-zero is at position 1 (after decimal), so exponent = -1. The code counts leading zeros correctly (0 in this case) but fails to add 1 to get the correct exponent magnitude.]
    return 0;
}