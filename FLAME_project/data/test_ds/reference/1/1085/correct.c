#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define check(VAR, CONV) printf("check:" #VAR "=%" #CONV "\n", VAR)
typedef long long ll;
typedef double db;
void write(char a, char b)
{
    char x;
    for (x = a; x <= b; x++)
    {
        printf("%c", x);
    }
}
int main(void)
{
    int i, n;
    char str[10000];
    int toke[10000];
    int toked = 0;
    memset(toke, 0, sizeof(toke));
    gets(str);
    n = strlen(str);
    for (i = 0; i < n; i++)
    {
        if (str[i] == '-')
            toke[i] = 1;
    }
    for (i = 0; i < n; i++)
    {
        if (toke[i + 1] == 1)
        {
            if (str[i] >= 'a' && str[i] <= 'z' && str[i + 2] >= 'a' && str[i + 2] <= 'z' && str[i] < str[i + 2])
            {
                write(str[i] + toked, str[i + 2]);
                i += 1;
                toked = 1;
            }
            else if (str[i] >= 'A' && str[i] <= 'Z' && str[i + 2] >= 'A' && str[i + 2] <= 'Z' && str[i] < str[i + 2])
            {
                write(str[i] + toked, str[i + 2]);
                i += 1;
                toked = 1;
            }
            else if (str[i] >= '0' && str[i] <= '9' && str[i + 2] >= '0' && str[i + 2] <= '9' && str[i] < str[i + 2])
            {
                write(str[i] + toked, str[i + 2]);
                i += 1;
                toked = 1;
            }
            else if (toked == 1)
            {
                toked = 0;
            }
            else
                printf("%c", str[i]);
        }
        else
        {
            if (toked == 1)
            {
                toked = 0;
            }
            else
                printf("%c", str[i]);
        }
    }
    return 0;
}
