#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long ans[10000];
int a1, a2;
char op[10000];
int main()
{
    char s[10000];
    int i;
    gets(s);
    int len = strlen(s);
    long long temp = 0;
    for (i = 0; i < len; i++)
    {
        if (s[i] == '=')
        {
            s[i] = ' ';
        }
        temp = 0;
        if (s[i] == ' ')
            continue;
        if (s[i] >= '0' && s[i] <= '9')
        {
            while (s[i] >= '0' && s[i] <= '9')
            {
                temp = temp * 10 + s[i] - '0';
                i++;
            }
            ans[++a1] = temp;
            i--;
        }
        else
        {
            char ops = s[i];
            if ((op[a2] == '*' || op[a2] == '/') && a1 >= 2 && a2 >= 1)
            {
                if (op[a2] == '*')
                    temp = ans[a1 - 1] * ans[a1];
                else
                    temp = ans[a1 - 1] / ans[a1];
                a1--;
                a2--;
                ans[a1] = temp;
            }
            op[++a2] = ops;
        }
    }
    if ((op[a2] == '*' || op[a2] == '/') && a1 >= 2 && a2 >= 1)
    {
        if (op[a2] == '*')
            temp = ans[a1 - 1] * ans[a1];
        else
            temp = ans[a1 - 1] / ans[a1];
        a1--;
        a2--;
        ans[a1] = temp;
    }
    temp = ans[1];
    for (i = 1; i < a1; i++)
    {
        if (op[i] == '+')
        {
            temp += ans[i + 1];
        }
        else
            temp -= ans[i + 1];
    }
    printf("%lld", temp);
    return 0;
}


