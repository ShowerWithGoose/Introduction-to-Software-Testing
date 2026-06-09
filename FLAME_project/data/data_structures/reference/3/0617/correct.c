#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define mian main
typedef long long ll;
typedef unsigned long long ull;
#define forsx(i, a, b) for (int i = (a); i < (b); ++i)
#define forjx(i, a, b) for (int i = (a); i > (b); --i)

#define ElementType int
ElementType max(ElementType a, ElementType b)
{
    return a > b ? a : b;
}

ElementType min(ElementType a, ElementType b)
{
    return a < b ? a : b;
}
int main(int argc, const char *argv[])
{
    char num[105];
    int flagDot = -1, flagNum = -1, flagNega = 0;
    gets(num);
    int len = strlen(num);
    if (num[0] == '-')
    {
        flagNega = 1;
    }
    for (int i = 0; i < len; ++i)
    {
        if (num[i] == '.')
        {
            flagDot = i;
            break;
        }
    }
    for (int i = 0; i < len; ++i)
    {
        if (isdigit(num[i]) && (num[i] - '0'))
        {
            flagNum = i;
            break;
        }
    }
    if (flagNum == -1)
    {
        printf("0e0\n");
    }
    else
    {
        if (flagNega)
            printf("-");
        if (flagNum > flagDot)
        {
            printf("%c", num[flagNum]);
            if (flagNum < len - 1)
            {
                printf(".");
                for (int i = flagNum + 1; i < len; ++i)
                    printf("%c", num[i]);
            }
            printf("e-%d\n", flagNum - flagDot);
        }
        else
        {
            printf("%c", num[flagNum]);
            printf(".");
            for (int i = flagNum + 1; i < len; ++i)
            {
                if (i == flagDot)
                    continue;
                printf("%c", num[i]);
            }
            printf("e%d\n", flagDot - flagNum - 1);
        }
    }
    return 0;
}
