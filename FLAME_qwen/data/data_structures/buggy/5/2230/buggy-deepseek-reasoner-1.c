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
    for(b=0;b<=t;b++) // @@ Loop condition causes out-of-bounds access when b==t because k[b+1] is accessed.
    {
        if(k[b].index ==k[b+1].index)
        {
            k[b].index=-1;
            k[b+1].coefficient=k[b].coefficient+k[b+1].coefficient;
            k[b].coefficient=-1;
        }
    }
    for(i=0;i<=t+1;i++) // @@ Loop condition i<=t+1 accesses out-of-bounds; should be i<t.
    {
        if(k[i].coefficient>0) // @@ Condition should be !=0 to include negative coefficients; also, if coefficient is zero, index should not be printed.
        {
            printf("%d ",k[i].coefficient);
        }
        if(k[i].index>=0)
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