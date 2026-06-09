#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    struct multi 
    {
        int sum;
        int mi;
        
    };
    struct multi e1[10000],e2[10000],e[1000000],t;
int i=0,j=0,m=0;

scanf("%d %d",&e1[i].sum,&e1[i].mi);
i++;
while (getchar()!='\n')
{
    scanf("%d %d",&e1[i].sum,&e1[i].mi);
    i++;
}
scanf("%d %d",&e2[j].sum,&e2[j].mi);
j++;
while (getchar()!='\n')
{
    scanf("%d %d",&e2[j].sum,&e2[j].mi);
    j++;
}
for (int o = 0; o < i; o++)
{
    for (int p = 0; p < j; p++)
    {
        for (int q = 0; q <= m; q++) @@ // Error: loop condition should be q < m, otherwise it accesses uninitialized e[q] when q == m
        {
            if (e[q].mi==(e1[o].mi+e2[p].mi)) @@ // Error: when q == m, e[q].mi is uninitialized, causing potential false match
            {
                e[q].sum=e[q].sum+e1[o].sum*e2[p].sum;
                break;
            }
            if (q==m)
            {
                e[q].sum=e1[o].sum*e2[p].sum;
                e[q].mi=e1[o].mi+e2[p].mi;
                m++;
                break;
            }
        }
    }
}
for (int o = 0; o < m; o++)
{
    for (int p = o+1; p < m; p++)
    {
    if (e[o].mi<e[p].mi)
    {
        t=e[o];
        e[o]=e[p];
        e[p]=t;
    }
    }
}
for (int w = 0; w <= m; w++) @@ // Error: loop condition should be w < m, otherwise it prints an extra term with uninitialized data
{
    printf("%d %d ",e[w].sum,e[w].mi);
}
return 0;
}