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
while (getchar()!='\n') // @@ [Logical error: getchar() consumes a character before the condition check, which misaligns with scanf if there are multiple spaces or trailing spaces, causing incorrect input parsing]
{
    scanf("%d %d",&e1[i].sum,&e1[i].mi);
    i++;
}
scanf("%d %d",&e2[j].sum,&e2[j].mi);
j++;
while (getchar()!='\n') // @@ [Same logical error as above for reading the second polynomial]
{
    scanf("%d %d",&e2[j].sum,&e2[j].mi);
    j++;
}
for (int o = 0; o < i; o++) // @@ [Compilation error in C89/C90 standard: declaring loop variable inside for() is not allowed; should declare 'o' before the loop]
{
    for (int p = 0; p < j; p++) // @@ [Same C89/C90 compilation error]
    {
        for (int q = 0; q <= m; q++) // @@ [Same C89/C90 compilation error]
        {
            if (e[q].mi==(e1[o].mi+e2[p].mi)) // @@ [Logical error: array 'e' is uninitialized, so e[q].mi contains garbage values, leading to undefined behavior and incorrect term matching]
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
for (int o = 0; o < m; o++) // @@ [Same C89/C90 compilation error]
{
    for (int p = o+1; p < m; p++) // @@ [Same C89/C90 compilation error]
    {
    if (e[o].mi<e[p].mi)
    {
        t=e[o];
        e[o]=e[p];
        e[p]=t;
    }
    }
}
for (int w = 0; w <= m; w++) // @@ [Logical error: loop condition should be w < m, otherwise it accesses uninitialized e[m] and prints garbage output; also C89/C90 compilation error]
{
    printf("%d %d ",e[w].sum,e[w].mi);
}




    
    

return 0;
}