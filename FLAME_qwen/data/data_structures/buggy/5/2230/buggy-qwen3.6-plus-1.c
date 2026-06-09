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
struct math k[200]; // @@ Array size 200 is insufficient for polynomial multiplication results which can have up to (n+1)*(m+1) terms, causing buffer overflow.
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
    for(b=0;b<=t;b++) // @@ Loop bound 'b<=t' causes out-of-bounds access when evaluating 'k[b+1]' at the last iteration.
    {
        if(k[b].index ==k[b+1].index) // @@ Merging logic is flawed; it only handles adjacent pairs and fails for three or more terms with the same exponent.
        {
            k[b].index=-1;
            k[b+1].coefficient=k[b].coefficient+k[b+1].coefficient;
            k[b].coefficient=-1; // @@ Using -1 as a flag to mark merged terms is incorrect because polynomial coefficients can legitimately be negative.
        }
    }
    for(i=0;i<=t+1;i++) // @@ Loop bound 'i<=t+1' exceeds the valid index range of array k (0 to t-1), causing out-of-bounds memory access.
    {
        if(k[i].coefficient>0) // @@ Condition should be '!= 0' to correctly handle negative coefficients and skip zero terms as required.
        {
            printf("%d ",k[i].coefficient); // @@ Output format is incorrect; coefficient and exponent must be printed together as a single pair per term.
        }
        if(k[i].index>=0) // @@ Decoupling exponent printing from coefficient printing violates the output format and may print exponents for skipped terms.
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