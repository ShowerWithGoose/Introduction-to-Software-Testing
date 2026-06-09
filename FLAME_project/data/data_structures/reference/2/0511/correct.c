#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long stock[3];
char s[10005], temp[10005];
int main()
{
    gets(temp);
    long long now = 0;
    int i, j;
    
    for (i = 0, j = 0; temp[i] != '='; i++)
    {
        if (temp[i] != ' ')
        {
            s[j] = temp[i];
            j++;
        }
    }
    s[j] = '=';

    i = 0;
    while(s[i]!='=')
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            now = now * 10 + s[i] - '0';
            stock[2] = now;
        }
        else
        {
            now = 0;
        }
        if (s[i] == '-' || s[i] == '+')
        {
            if (stock[1] == 1||stock[1]==0)
            {
                stock[0] += stock[2];
                stock[2] = 0;
            }
            if (stock[1] == 2)
            {
                stock[0] -= stock[2];
                stock[2] = 0;
            }
            if(s[i]=='+')
            {
                stock[1] = 1;
            }
            else
            {
                stock[1] = 2;
            }
        }
        if (s[i] == '*')
        {
            i++;
            while(s[i]>='0'&&s[i]<='9')
            {
                now = now * 10 + s[i] - '0';
                i++;
            }
            i--;
            stock[2] *= now;
        }
        if(s[i]=='/')
        {
            i++;
            while(s[i]>='0'&&s[i]<='9')
            {
                now = now * 10 + s[i] - '0';
                i++;
            }
            i--;
            stock[2] /= now;
        }
        i++;
    }
    if (stock[1] == 1||stock[1]==0)
            {
                stock[0] += stock[2];
                stock[2] = 0;
            }
            if (stock[1] == 2)
            {
                stock[0] -= stock[2];
                stock[2] = 0;
            }
    printf("%lld", stock[0]);
    return 0;
}
