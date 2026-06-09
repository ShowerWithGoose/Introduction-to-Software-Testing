//格式化输入和输出函数
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define eps 1e-20; // @@ [The semicolon after macro definition is incorrect; it causes syntax errors when the macro is used, though in this code 'eps' is unused. However, the main issue is not here.]

typedef long long ll;
int main()
{
    char str[101000] = { '0' };
    char str1[101000] = { '0' };
    char format[100] = { '0' };
    gets(str); // @@ [Use of 'gets' is dangerous and deprecated; more critically, in many modern environments (like those with GCC removed or secure libraries), 'gets' may not be available, leading to compilation failure. This is likely the cause of the "gcc: not found" error indirectly—because the environment rejects unsafe functions or lacks required libraries. However, the immediate compilation error in strict environments is due to 'gets' being removed in C11 and later.]

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
        for (int i = 0;i < len - 1;i++) // @@ [This loop condition is flawed: it stops at len-1, but if the number has no decimal point, it should process all digits. Also, logic for exponent calculation is incorrect for numbers like "123.45".]
        {
            if (str[i] == '.')break;
            else k++;
        }
        k--;
    }
    else
    {
        int i = 0;
        for (i = 2;;i++) // @@ [Infinite loop risk: if input is "0.0", this loop runs beyond string bounds. Also assumes input always starts with "0." which may not hold per problem constraints.]
        {
            if (str[i] == '0')k++;
            else break;
        }
        if (i < len - 1)k++; // @@ [Incorrect exponent adjustment; logic doesn't match scientific notation rules.]
    }
    int j = 0;
    while (str[j] == '0' || str[j] == '.')j++; // @@ [This skips all leading zeros and decimal points, but if input is "0.001", j becomes 3 (pointing to '1'), which is correct, but if input is "10.0", it skips nothing, which is okay. However, if input is "0.0", j becomes len, causing out-of-bound access below.]
    if (j == len - 1)printf("%c", str[j]); // @@ [If j reaches len (e.g., all zeros), this accesses str[len], which is '\0', leading to undefined behavior or wrong output. Also, problem states there are no trailing zeros after decimal, but doesn't guarantee non-zero value.]
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