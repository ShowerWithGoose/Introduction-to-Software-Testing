#include<stdio.h>
#include<string.h>

typedef struct lo
{
    int bx;
    int by;
    int ex;
    int ey;
    int k;
}lo[150];

int order(const void *a,const void *b)
{
    struct lo *c = (lo *)a;
    struct lo *d = (lo *)b;
    if(c->bx != d->bx)
        return d->bx - c->bx;
    else
        return d->by - c->by;
}

int main ()
{
    int p=-1;
    int q=0;
    int n;
    scanf("%d",&n);
    struct lo lo[150];
    for(int i=0;i<n;i++)
    {
        lo[i].k=1;
        scanf("%d%d%d%d",&lo[i].bx,&lo[i].by,&lo[i].ex,&lo[i].ey);
    }
    qsort(lo,n,sizeof(lo[0]),order);
    for (int i=0;i<n-1;i++)
    {
        for(int j=i;j<n-1;j++)
        {
            if(lo[i].bx==lo[j+1].ex && lo[i].by == lo[j+1].ey)
            {
                lo[j+1].k=lo[i].k+1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(lo[i].k>p)
        {
            p=lo[i].k;
            q=i;
        }
    }
    printf("%d %d %d",p,lo[q].bx,lo[q].by);
    return 0;
}

