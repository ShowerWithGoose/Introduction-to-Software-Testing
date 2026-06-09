#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct
{
    int x0=0; // @@ Initializers are not allowed in a struct definition in C (syntax error)
    int y0=0; // @@ Same as above
    int x1=0; // @@ Same as above
    int y1=0; // @@ Same as above
}coor;
coor p[101],max,tmax;
int cmp(const void *p,const void *q)
{
    coor *a=(coor *)p;
    coor *b=(coor *)q;
    if((*a).x0<(*b).x0)
    {
        return -1;
    }
    if((*a).x0>(*b).x0)
    {
        return 1;
    }
    return 0;
}
int f(int i,int n)
{
    int j;
    for(j=i;j<n;j++)
    {
        if((p[j].x0==p[i].x1)&&(p[j].y0=p[i].y1)) // @@ Should be '==' instead of '=' for equality check (logical error)
        {
            return j;
        }
    }
    return -1;
}
int main()
{
    
    int n,i,j,k,count=1,tem=1,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&p[i].x0,&p[i].y0,&p[i].x1,&p[i].y1);
    }
    qsort(p,n,sizeof(coor),cmp);
    for(i=0;i<n;i++)
    {
        k=i;
        tem=1;
        tmax.x0=p[i].x0;
        tmax.y0=p[i].y0;
        while((t=f(k,n))>-1)
        {
            k=t;
            tem++;    
        }
        if(tem>count)
        {
            count=tem;
            max.x0=tmax.x0;
            max.y0=tmax.y0;
        }
    }
    printf("%d %d %d",count,max.x0,max.y0);
    return 0;
}