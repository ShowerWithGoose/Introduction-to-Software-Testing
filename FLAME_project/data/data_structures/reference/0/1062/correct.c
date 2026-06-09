#include <ctype.h>
#include <iso646.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void putout(char a, char b)
{
    char c;
    if (b <= a)
        printf("%c", a);
    for (c = a; c < b; c++)
    {
        printf("%c", c);
    }
}
void judge(char *a)
{
    int i;
    for (i = 0; i < strlen(a) - 2; i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z' && a[i + 1] == '-' && a[i + 2] > a[i] && a[i + 2] <= 'z')
        {
            putout(a[i], a[i + 2]);
            i++;
        }
        else if (a[i] >= 'A' && a[i] <= 'Z' && a[i + 1] == '-' && a[i + 2] > a[i] && a[i + 2] <= 'Z')
        {
            putout(a[i], a[i + 2]);
            i++;
        }
        else if (a[i] >= '0' && a[i] <= '9' && a[i + 1] == '-' && a[i + 2] > a[i] && a[i + 2] <= '9')
        {
            putout(a[i], a[i + 2]);
            i++;
        }
        else
            printf("%c", a[i]);
    }
    printf("%s", &a[i]);
}
int main(void)
{
    char a[100] = "";
    char *p = a;
    gets(p);
    judge(p);
    return 0;
}
