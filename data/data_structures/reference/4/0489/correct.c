#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vocab
{
    char c[30];
    int count;
} x[1000], y;

int i, j, k, n, type;
char a[1026];

void tolowercase(struct vocab x[1000], int acount)
{
    for (i = 0; i < acount; i++)
    {
        for (j = 0; j < strlen(x[i].c); j++)
        {
            if (x[i].c[j] < 97)
                x[i].c[j] += 32;
        }
    }
}

void redone_position(struct vocab x[1000], struct vocab y, int acount)
{
    for (int i = 0; i < acount; i++)
    {
        for (int j = i + 1; j < acount; j++)
        {
            if (strcmp(x[i].c, x[j].c) == 0)
            {
                strcpy(x[j].c, "\0");
                x[i].count += x[j].count;
            }
            if (strcmp(x[i].c, x[j].c) > 0)
            {
                y = x[i];
                x[i] = x[j];
                x[j] = y;
            }
        }
    }
}
int main()
{
    FILE *in = fopen("article.txt", "r");
    i = 0, j = 0;
    type = 0;
    while (fgets(a, 1025, in) != NULL)
    {
        for (k = 0; k < strlen(a); k++)
        {
            if ((a[k] < 91 && a[k] > 64) || (a[k] > 96 && a[k] < 123))
            {
                x[i].c[j++] = a[k];
                type = 1;
            }
            else if (type != 0)
            {
                x[i].c[j] = '\0';
                x[i++].count = 1;
                j = type = 0;
            }
        }
    }
    n = i;
    tolowercase(x, n); // for(i=0;i<n;i++)printf("%s %d\n",x[i].c,x[i].count);
    redone_position(x, y, n);
    for (i = 0; i < n; i++)
    {
        if (strlen(x[i].c) != 0)
            printf("%s %d\n", x[i].c, x[i].count);
    }
    return 0;
}

