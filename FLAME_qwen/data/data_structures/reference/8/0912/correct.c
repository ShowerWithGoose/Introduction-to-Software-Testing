#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int a, b, str[102][102], temp[1002], tempp[1002], judge;
void fk(int p);
void fku(int p);
int main()
{
    int x, y,i,k;
    scanf("%d%d", &a, &b);
    for (i = 1; i <= b; i++) 
    {
        scanf("%d%d", &x, &y);
        str[x][y] = 1;
        str[y][x] = 1;
    }
    fk(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        temp[k] = 0;
        judge = 0;
    }
    fku(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        temp[k] = 0;
        judge = 0;
    }
    scanf("%d",&x);
    temp[x] = 1;
    fk(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        temp[k] = 0;
        judge = 0;
    }
    temp[x] = 1;
    fku(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        temp[k] = 0;
        judge = 0;
    }
}

void fk(int p)
{
	int i;
    if (judge == 0)
    {
        printf("%d", p);
        judge = 1;
    }
    else
    {
        printf(" %d", p);
    }
    temp[p] = 1;
    for (i = 1; i <= a; i++)
    {
        if (str[p][i] == 1 && temp[i] == 0)
        {
            fk(i);
        }
    }
}

void fku(int p)
{
    int t,j,r,i;
    tempp[1] = p;
    for (j = 1, r = 1; j <= r;)
    {
        t = tempp[j++];
        if (temp[t] == 1)
        {
            continue;
        }
        if (judge == 0)
        {
            printf("%d", t);
            judge = 1;
        }
        else
        {
            printf(" %d", t);
        }

        temp[t] = 1;
        for (i = 1; i <= a; i++)
        {
            if (str[t][i] == 1 && temp[i] == 0)
            {
                tempp[++r] = i;
            }
        }
    }
}


