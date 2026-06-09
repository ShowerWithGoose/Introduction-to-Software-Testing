#include <stdio.h>
#include <string.h>
#include <math.h>

void op1(char s[])
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != ' ')
            s[j++] = s[i];
    s[j] = '\0';
    return;
}

int power(int n)
{
    int i, sum = 1;
    for (i = 0; i < n; i++)
    {
        sum *= 10;
    }
    return sum;
}
int main()
{
    char s[100];
    gets(s);
    op1(s);
    int i, j, k, x1, x2, x3, ans, point, cnt, sum = 0;
    while (s[i] != '\0')
    {
        x1 = x2 = x3 = i = 0;
        for (i = 0; s[i] != '*' && s[i] != '/' && s[i] != '\0'; i++)
            ;
        if (s[i] == '*')
        {
            for (k = i - 1; s[k] <= '9' && s[k] >= '0'; k--)
                ;
            point = k + 1;
            for (k++; s[k] != '*'; k++)
            {
                x1 = 10 * x1 + s[k] - '0';
            }
            for (k = i + 1; s[k] <= '9' && s[k] >= '0'; k++)
            {
                x2 = 10 * x2 + s[k] - '0';
            }
            x3 = x1 * x2;
            while (x3)
            {
                if (x3 >= 10)
                {
                    cnt = 1;
                    ans = x3 / 10;
                    while (ans >= 10)
                    {
                        ans = ans / 10;
                        cnt++;
                    }
                    s[point] = ans + '0';
                    x3 = x3 - ans * power(cnt);
                    if (x3 == 0 && cnt != 0)
                    {
                        for (j = 1; j <= cnt; j++)
                        {
                            s[point + j] = '0';
                        }
                        point+=j-1;
                    }
                }
                else
                {
                    s[point] = x3 % 10 + '0';
                    x3 = 0;
                }
                point++;
            }
            for (; s[k] != '\0'; k++, point++)
            {
                s[point] = s[k];
            }
            s[point] = '\0';
        }
        else if (s[i] == '/')
        {
            for (k = i - 1; s[k] <= '9' && s[k] >= '0'; k--)
                ;
            point = k + 1;
            for (k++; s[k] != '/'; k++)
            {
                x1 = 10 * x1 + s[k] - '0';
            }
            for (k = i + 1; s[k] <= '9' && s[k] >= '0'; k++)
            {
                x2 = 10 * x2 + s[k] - '0';
            }
            x3 = x1 / x2;
            while (x3)
            {
                if (x3 >= 10)
                {
                    cnt = 1;
                    ans = x3 / 10;
                    while (ans >= 10)
                    {
                        ans = ans / 10;
                        cnt++;
                    }
                    s[point] = ans + '0';
                    x3 = x3 - ans * power(cnt);
                    if (x3 == 0 && cnt != 0)
                    {
                        for (j = 1; j <= cnt; j++)
                        {
                            s[point + j] = '0';
                        }
                        point+=j-1;
                    }
                }
                else
                    s[point] = x3 % 10 + '0';
                point++;
                x3 /= 10;
            }
            for (; s[k] != '\0'; k++, point++)
            {
                s[point] = s[k];
            }
            s[point] = '\0';
        }
    }
    //printf("%s\n", s);
    for (i = 0; s[i] != '+' && s[i] != '-' && s[i] != '\0' && s[i] != '='; i++)
    {
        sum = sum * 10 + s[i] - '0';
    }
    for (i = 0; s[i] != '\0'; i++)
    {
        x2 = 0;
        if (s[i] == '+')
        {
            for (k = i + 1; s[k] <= '9' && s[k] >= '0'; k++)
            {
                x2 = 10 * x2 + s[k] - '0';
            }
            sum += x2;
        }
        else if (s[i] == '-')
        {
            for (k = i + 1; s[k] <= '9' && s[k] >= '0'; k++)
            {
                x2 = 10 * x2 + s[k] - '0';
            }
            sum -= x2;
        }
    }
    printf("%d", sum);
    return 0;
}
