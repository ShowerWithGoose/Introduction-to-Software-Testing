#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
char a[10000];
char b[1000];
char base[1000];

int main()
{
    gets(a);
    for (int i = 0; a[i] != '.'; i++)
    {
        b[i] = a[i];
    }
    //算出幂次
    int cloth = 0;
    if (b[0] != '0')
    {
        cloth = strlen(b) - 1;
    }
    else
    {
        cloth--;
        char *p = strstr(a, ".");
        p++;
        while (*p == '0')
        {
            cloth--;
            p++;
        }
    }
    //得到底数，以不带小数点的形式存储于字符数组base中
    if (b[0] == '0')
    {
        char *p = strstr(a, ".");
        p++;
        while (*p == '0')
        {
            p++;
        }
        int i = 0;
        while (*p != '\0')
        {
            base[i] = *p;
            p++, i++;
        }
    }
    else
    {
        int i = 0, j = 0;
        while (a[i] != '\0')
        {
            if (a[i] == '.')
            {
                i++;
                continue;
            }
            base[j] = a[i];
            i++, j++;
        }
    }
    //输出
    printf("%c", base[0]);
    if (base[1] != '\0')
    {
        printf(".");
    }
    for (int i = 1; base[i] != '\0'; i++)
    {
        printf("%c", base[i]);
    }
    printf("e%d", cloth);

    return 0;
}


