#include <stdio.h>
#include <string.h>
char s[1000];
char str[1000];
int num[100];
char sign[100];
int end[100];
int main()
{

    gets(str);
    int len = strlen(str);
    int istr = 0; //计数str
    int is = 0;   //计数s
    while (str[istr] != '\0')
    {
        if (str[istr] != ' ')
            s[is++] = str[istr++];
        else
            istr++;
    }
    int k = 0, l = 0, sl = 0;
    if (s[0] == '+' || s[0] == '-')
    {
        sl++;
        k++;
        num[0] = 0;
        sign[0] = s[0];
        l++;
    }
    for (; sl < len; sl++)
    {
        if (s[sl] >= '0' && s[sl] <= '9') //放数字
        {
            num[k] = s[sl] - '0';
            while (s[sl + 1] >= '0' && s[sl + 1] <= '9')
            {
                num[k] = num[k] * 10 + s[sl + 1] - '0';
                sl++;
            }
            k++;
        }
        else //放符号
            sign[l++] = s[sl];
    }
    for (int n = 0; n < strlen(sign); n++)
    {
        if (sign[n] == '*')
        {
            num[n + 1] = num[n] * num[n + 1];
            num[n] = -1;
        }
        else if (sign[n] == '/')
        {
            num[n + 1] = num[n] / num[n + 1];
            num[n] = -1;
        }
    }
    int sum = 0, h = 0, g = 1;

    for (int n = 0; n < strlen(s); n++)
    {
        if (num[n] != -1)
            end[h++] = num[n];
    }
    sum = end[0];
    for (int m = 0; m < strlen(sign); m++)
    {
        if (sign[m] == '-')
        {
            sum -= end[g++];
        }
        else if (sign[m] == '+')
            sum += end[g++];
    }
    printf("%d\n", sum);
    // puts(s);
    return 0;
}

