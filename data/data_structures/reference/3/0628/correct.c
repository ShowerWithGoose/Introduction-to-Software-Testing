#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
char s[110];
int len;
int main()
{
    scanf("%s", s);
    len = strlen(s);
    int fn = -1, p = -1;
    for (int i = 0; i < len; ++i)
    {
        if (fn < 0 && isdigit(s[i]) && s[i] != '0')
            fn = i;
        else if (p < 0 && s[i] == '.')
            p = i;
    }
    printf("%c", s[fn]);
    if (fn + 1 < len)
        putchar('.');
    for (int i = fn + 1; i < len; ++i)
        if (isdigit(s[i]))
            printf("%c", s[i]);
    if (fn < p)
        printf("e%d\n", p - fn - 1);
    else
        printf("e%d\n", p - fn);
    return 0;
}
