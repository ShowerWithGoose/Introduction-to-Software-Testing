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
        for (int i = 0;i < len - 1;i++) // @@ [Loop condition should be `i < len` instead of `i < len - 1`; this causes incorrect count of digits before decimal point when last character is not '.'. For example, in "0.9", this branch isn't taken, but in numbers like "87899.999...", it may miss the last digit before '.']
        {
            if (str[i] == '.')break;
            else k++;
        }
        k--; // @@ [This decrements k after counting digits before '.', which is correct for scientific notation exponent calculation only if there's more than one digit before '.', but logic is flawed due to earlier loop issue and inconsistent handling]
    }
    else
    {
        int i = 0;
        for (i = 2;;i++) // @@ [Infinite loop risk if input doesn't have non-zero digit after zeros; also assumes at least two characters before starting (i=2), which fails for inputs like "0.9" where first non-zero is at index 2, but loop starts correctly. However, the increment logic for k is wrong: it counts leading zeros after decimal, but then adds an extra k++ unconditionally if i < len - 1]
        {
            if (str[i] == '0')k++;
            else break;
        }
        if (i < len - 1)k++; // @@ [This line incorrectly increments k again. For "0.9", i=2, str[2]='9', so loop breaks with k=0, then since i(2) < len-1(2? len=3 → len-1=2 → 2<2 false), so k remains 0. But expected exponent is -1, so k should be 0 here and printed as e-1. However, later code prints k as exponent magnitude without adjusting for actual position. The real issue is that k should represent number of places moved, which for "0.9" is 1 place right → exponent -1, but current logic sets k=0 and prints e-0]
    }
    int j = 0;
    while (str[j] == '0' || str[j] == '.')j++; // @@ [This skips all leading zeros and the decimal point, which works for "0.9" (j becomes 2), but fails if there are no non-zero digits (though problem states all digits are significant). However, combined with previous logic errors, it leads to wrong exponent]
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
    printf("%d", k); // @@ [For input "0.9", k is 0, so outputs "e-0", but expected is "e-1". The exponent calculation in the else block is incorrect: it should set k = (number of leading zeros after decimal + 1), but currently for "0.9", there are 0 leading zeros, so k should be 1, not 0. The error stems from not counting the position shift correctly: moving from 0.9 to 9 requires shifting decimal 1 place right → exponent -1, so k must be 1 in magnitude]
    return 0;
}