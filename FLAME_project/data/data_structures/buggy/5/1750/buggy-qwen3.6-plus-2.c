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
        for (int q = 0; q <= m; q++) // @@ [Logic error: The loop condition q <= m and the check if (q==m) inside cause incorrect handling of new terms. When m=0, it checks index 0. If index 0 is empty/uninitialized, it might not match exponent, then hits q==m (0==0), initializes e[0], increments m to 1. This part is actually okay for insertion logic IF initialized properly, but the main issue is below]
        {
            if (e[q].mi==(e1[o].mi+e2[p].mi))
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
for (int w = 0; w <= m; w++) // @@ [Off-by-one error: The loop runs from 0 to m inclusive, printing m+1 elements. However, there are only m valid terms (indices 0 to m-1). This causes printing of an extra uninitialized or zero term.]
{
    printf("%d %d ",e[w].sum,e[w].mi);
}




    
    

return 0;
}