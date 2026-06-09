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
    char s[105];
    int num = -1, flag = -1, flagNega = 0;
    gets(s);
    int len = strlen(s);
    if (s[0] == '-')
    {
        flagNega = 1;
    }
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == '.')
        {
            num = i;
            break;
        }
    }
    for (int i = 0; i < len; ++i)
    {
        if (isdigit(s[i]) && (s[i] - '0'))
        {
            flag = i;
            break;
        }
    }
    if (flag == -1)
    {
        printf("0e0\n");
    }
    else
    {
        if (flagNega)
            printf("-");
        if (flag > num)
        {
            printf("%c", s[flag]);
            if (flag < len - 1)
            {
                printf(".");
                for (int i = flag + 1; i < len; ++i)
                    printf("%c", s[i]);
            }
            printf("e-%d\n", flag - num);
        }
        else
        {
            printf("%c", s[flag]);
            printf(".");
            for (int i = flag + 1; i < len; ++i)
            {
                if (i == num)
                    continue;
                printf("%c", s[i]);
            }
            printf("e%d\n", num - flag - 1);
        }
    }
    return 0;
}
