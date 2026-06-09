#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char in[105];
char num[105];
int power; //记录幂指数
int main()
{
    gets(in);
    int len1 = strlen(in);
    int i, j;
    if (in[0] == '0') //是负数幂, 如0.001
    {
        for (i = 2; i < len1; i++)
        {
            if (in[i] != '0')
            {
                strcpy(num, &in[i]); //把数字部分输出，加个点
                break;
            }
        }
        power = (-1) * (i - 1);
    }
    else //是大于1的数, 如345.66
    {
        strcpy(num, in);
        for (i = j = 0; num[i] != '\0'; i++)
            if (num[i] != '.')
                num[j++] = num[i]; //清除.
            else
                power = i - 1; //记录指数
        num[j] = '\0';
    }
    int len2 = strlen(num);
    printf("%c", num[0]);
    if (len2 != 1)
        printf(".");
    for (int j = 1; j < len2; j++)
    {
        printf("%c", num[j]);
    }
    printf("e%d\n", power);
}
