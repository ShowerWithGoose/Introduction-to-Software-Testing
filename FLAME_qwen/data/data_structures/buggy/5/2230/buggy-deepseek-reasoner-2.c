#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *e1,const void *e2);
struct math
{
    int coefficient;
    int index;
    char c;
};
struct math a[200];
struct math y[200];
struct math k[200];
int main()
{
    int n=0,m=0;
    char c;
    for(n=0;;n++)
    {
        scanf("%d%d%c",&a[n].coefficient ,&a[n].index,&a[n].c );
        if(a[n].c=='\n')
        {
            break;
        }
    } 

    for(m=0;;m++)
    {
        scanf("%d%d%c",&y[m].coefficient ,&y[m].index,&y[m].c );
        if(y[m].c=='\n')
        {
            break;
        }
    } 
    //for(int i=0;i<=n;i++)
    //printf("%d %d ",a[i].coefficient ,a[i].index);
    //printf("\n");
    //for(int i=0;i<=m;i++)
    //printf("%d %d ",b[i].coefficient ,b[i].index);
    int i,j,t=0;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            k[t].coefficient=a[i].coefficient*y[j].coefficient;
            k[t].index=a[i].index+y[j].index;
            t++;
        }
    }
    qsort(k, t, sizeof(k[0]), cmp);
    int b;
    for(b=0;b<=t;b++)   @@ // Error: loop condition should be b < t-1 to avoid out-of-bounds access on k[b+1] when b == t
    {
        if(k[b].index ==k[b+1].index)   @@ // Error: k[b+1] accesses element beyond the sorted array when b == t, causing undefined behavior
        {
            k[b].index=-1;
            k[b+1].coefficient=k[b].coefficient+k[b+1].coefficient;
            k[b].coefficient=-1;
        }
    }
    for(i=0;i<=t+1;i++)   @@ // Error: loop runs up to t+1, but valid indices are 0 to t-1; accesses out-of-bounds elements
    {
        if(k[i].coefficient>0)   @@ // Error: should check for non-zero coefficient (k[i].coefficient != 0), not just positive; negative coefficients are valid
        {
            printf("%d ",k[i].coefficient);
        }
        if(k[i].index>=0)   @@ // Error: printing exponent separately from coefficient may produce incomplete output (e.g., exponent without coefficient when coefficient is zero/negative)
        {
            printf("%d ",k[i].index);
        }
    }
    
    return 0;
}
int cmp(const void *e1,const void *e2)
{
    return  (((struct math*)e2)->index-((struct math*)e1)->index);
}