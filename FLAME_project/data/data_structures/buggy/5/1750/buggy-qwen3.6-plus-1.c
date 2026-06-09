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
        for (int q = 0; q <= m; q++) // @@ The loop condition `q <= m` is incorrect when `m` represents the count of elements. If `m` is the number of valid elements, indices are 0 to m-1. If `m` is initialized to 0 and represents "next empty slot" or similar logic needs careful handling. However, the bigger issue is below.
        {
            if (e[q].mi==(e1[o].mi+e2[p].mi))
            {
                e[q].sum=e[q].sum+e1[o].sum*e2[p].sum;
                break;
            }
            if (q==m) // @@ This logic assumes that if we reach index `m`, it's a new term. But `m` is incremented inside. If `m` starts at 0, and we have 1 element, `m` becomes 1. Next time, `q` goes 0 to 1. If `q==1` (which is `m`), we add. This part is logically tricky but might work for insertion if sorted later. However, the array `e` is not initialized, so `e[q].mi` contains garbage values for unused slots, causing the first `if` to potentially fail randomly or succeed incorrectly.
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
for (int w = 0; w <= m; w++) // @@ The loop should be `w < m`. `m` is the count of terms. Indices are 0 to m-1. Accessing `e[m]` accesses an uninitialized or invalid element, leading to extra output like "0 0".
{
    printf("%d %d ",e[w].sum,e[w].mi);
}




    
    

return 0;
}