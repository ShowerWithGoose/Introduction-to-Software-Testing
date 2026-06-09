#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long
char *sh;
int t;
int len;
int main()
{
    sh = (char *)malloc(sizeof(char) * 200);
    gets(sh);
    if (sh[0] == '-')
    {
        putchar('-');
        sh = sh + 1;
    }
    len = strlen(sh);
    for (t = 0; t < len; t++)
        if (sh[t] == '.')
            break;
    if (t == len)
    {
        int j = len - 1;
        if (len == 1)
        {
            puts(sh);
            return 0;
        }
        while (sh[j] == '0')
            sh[j--] = '\0';
        putchar(sh[0]);
        if (j != 0)
            putchar('.');
        printf("%se%d", sh + 1, len - 1);
    }
    else if (sh[0] != '0')
    {
        while (sh[len - 1] == '0')
        {
            sh[len - 1] = '\0';
            len--;
        }
        putchar(sh[0]);
        putchar('.');
        for (int i = 1; i < len; i++)
            if (sh[i] != '.')
                putchar(sh[i]);
        printf("e%d", t - 1);
    }
    else
    {
        while (sh[len - 1] == '0')
        {
            sh[len - 1] = '\0';
            len--;
        }
        int j = t + 1;
        while (sh[j] == '0')
            j++;
        putchar(sh[j]);
        if (len - j == 1)
            printf("e-%d", len - 2);
        else if (j == 1)
            printf(".%s", sh + j + 1);
        else
        {
            printf(".%se-%d", sh + j + 1, j - 1);
        }
    }
    return 0;
}
