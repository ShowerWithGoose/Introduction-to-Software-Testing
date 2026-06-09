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
for (int o = 0; o < i; o++) // @@ [C89 does not allow variable declaration inside for loop initializer; this may cause compilation error]
{
    for (int p = 0; p < j; p++) // @@ [Same C89 issue]
    {
        for (int q = 0; q <= m; q++) // @@ [Same C89 issue]
        {
            if (e[q].mi==(e1[o].mi+e2[p].mi)) // @@ [When m == 0, e[0] is uninitialized; accessing its mi causes undefined behavior]
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
for (int o = 0; o < m; o++) // @@ [Same C89 issue]
{
    for (int p = o+1; p < m; p++) // @@ [Same C89 issue]
    {
    if (e[o].mi<e[p].mi)
    {
        t=e[o];
        e[o]=e[p];
        e[p]=t;
    }
    }
}
for (int w = 0; w <= m; w++) // @@ [C89 issue and logical error: should be w < m to avoid printing an uninitialized extra term]
{
    printf("%d %d ",e[w].sum,e[w].mi);
}




    
    

return 0;
}