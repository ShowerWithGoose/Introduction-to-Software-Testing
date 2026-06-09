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
    struct multi e1[10000],e2[10000],e[1000000],t; // @@ [Array size 1000000 is too large for local stack allocation, likely causing a compilation error or stack overflow. Consider declaring it globally or using static.]
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
        for (int q = 0; q <= m; q++)
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
for (int o = 0; o < m; o++) // @@ [Redeclaration of variable 'o' which was already declared in a previous loop scope. In strict C89 compilers, this causes a compilation error. Declare loop variables at the top of the function.]
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
for (int w = 0; w <= m; w++) // @@ [Loop condition 'w <= m' accesses out-of-bounds index 'e[m]'. Should be 'w < m'. This causes undefined behavior/runtime errors.]
{
    printf("%d %d ",e[w].sum,e[w].mi);
}




    
    

return 0;
}