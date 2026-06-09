#include<stdio.h>

struct zb
{
    int x1;
    int y1;
    int x2;
    int y2;
}xd[100];

int cmp(const void *a,const void *b)
{
    return (*(struct zb *)a).x1>(*(struct zb *)b).x1?1:-1;
}

int xjxds(struct zb *xd,int *m,int n)
{
    int i,j,s=1,k=0,max=1;
    int *t;
    t=m;
    for(j=0;j<n-1;j++)
    {
        for(i=k+1;i<n;i++)
        {
            if(xd[i].x1==xd[j].x2&&xd[i].y1==xd[j].y2)
            {
                j=i;
                s++;
            }
        }
        if(s>max)
        {
            max=s;
            s=1;
            *t=k;
        }
        else
        {
            s=1;
        }
        j=k;
        k++;
    }
    return max;
}

int main()
{
    int n,i,m=0,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&xd[i].x1,&xd[i].y1,&xd[i].x2,&xd[i].y2);
    }
    qsort(xd,n,sizeof(xd[0]),cmp);
    k=xjxds(xd,&m,n);
    printf("%d %d %d",k,xd[m].x1,xd[m].y1);
    return 0;
}



