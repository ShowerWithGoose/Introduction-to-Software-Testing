#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vocab
{
    char c[30];
    int count;
} x[1000], y;

int i=0, j=0, k=0,type=0;
char a[1050];

void tolowercase(struct vocab x[1000], int acount)
{
    
}

void redone_position(struct vocab x[1000], struct vocab y, int acount)
{
    
}
int main()
{
    FILE *in = fopen("article.txt", "r");
    i = 0, j = 0;
    type = 0;
    while (fgets(a, 1049, in) != NULL)
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
    for (int m = 0; m < i; m++)
    {
        for (int n = 0; n < strlen(x[m].c); n++)
        {
            if (x[m].c[n] < 97)
                x[m].c[n] += 32;
        }
    }
    for (int m = 0; m < i; m++)
    {
        for (int n = m + 1; n < i; n++)
        {
            if (strcmp(x[m].c, x[n].c) == 0)
            {
                strcpy(x[n].c, "\0");
                x[m].count += x[n].count;
            }
            if (strcmp(x[m].c, x[n].c) > 0)
            {
                y = x[m];
                x[m] = x[n];
                x[n] = y;
            }
        }
    }
    for (int m = 0; m < i; m++)
    {
        if (strlen(x[m].c) != 0)
            printf("%s %d\n", x[m].c, x[m].count);
    }
    return 0;
}

