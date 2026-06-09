//格式化输入和输出函数
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define eps 1e-20; // @@ [Trailing semicolon in macro definition is incorrect and may cause compilation errors when used in expressions]
typedef long long ll;
int main()
{
    char str[101000] = { '0' };
    char str1[101000] = { '0' };
    char format[100] = { '0' };
    gets(str); // @@ [Use of deprecated and unsafe function 'gets'; many modern compilers reject it, causing compilation failure]
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
        for (int i = 0;i < len - 1;i++) // @@ [Loop condition may skip last digit unnecessarily; logic flaw but not compilation error]
        {
            if (str[i] == '.')break;
            else k++;
        }
        k--;
    }
    else
    {
        int i = 0;
        for (i = 2;;i++) // @@ [Infinite loop risk if input has no non-zero digit after "0."; also, if input length is <=2, out-of-bounds access occurs — but primary issue is unsafe assumptions leading to undefined behavior, which may cause compile-time rejection in strict modes]
        {
            if (str[i] == '0')k++;
            else break;
        }
        if (i < len - 1)k++; // @@ [This line assumes i < len, but loop above may run past string end if all digits are zero — undefined behavior, possibly caught by compiler with bounds checking]
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