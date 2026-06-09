#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define maxint 2147483647
#define eps 1e-10
#define ll long long
int main()
{
    char str[100];
    int prelen , i, bool = 0, j;
    scanf("%s", str);
    prelen = strlen(str);
    if(str[0] == '0' && prelen == 1)
    {
        printf("0e0");
        return 0;
    }
    for(i = 0; i < prelen; ++i)
    {
        if(str[i] == '.')
        {
            bool = 1;
            break;
        }
    }
    if(bool)
    {
        if(str[0] != '0')
        {
            for(j = 0; j < prelen; ++j)
            {
                if(str[j] != '.')
                    printf("%c", str[j]);
                if(j == 0)
                    printf(".");
            }
            printf("e%d", i-1);
        }
        else
        {
            for(j = 0; j < prelen; j++)
            {
                if(str[j] != '0' && str[j] != '.')
                    break;
            }
            int i = j;
            if(j == prelen-1)
                printf("%ce-%d", str[j], j-1);
            else
            {
                int i = j;
                while(j < prelen)
                {
                    if(str[j] != '.')
                        printf("%c", str[j]);
                    if(j == i)
                    {
                        printf(".");
                    }
                    j++;
                }
                printf("e-%d", i-1);
            }
        }
    }
    else
    {
        for(i = prelen-1; i >= 0; i--)
        {
            if(str[i] != '0')
                break;
        }
        for(j = 0; j <= i; ++j)
        {
            if(str[j] != '.')
                printf("%c", str[j]);
            if(j == 0 && i != 0)
                printf(".");
        }
        printf("e%d", prelen-1);
    }
    return 0;
}
