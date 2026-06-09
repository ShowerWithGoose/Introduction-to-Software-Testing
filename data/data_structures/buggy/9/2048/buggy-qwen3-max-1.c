#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct
{
    int x0=0; // @@ [C does not allow initialization of struct members at declaration; this is a C++ feature]
    int y0=0; // @@ [C does not allow initialization of struct members at declaration; this is a C++ feature]
    int x1=0; // @@ [C does not allow initialization of struct members at declaration; this is a C++ feature]
    int y1=0; // @@ [C does not allow initialization of struct members at declaration; this is a C++ feature]
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
        if((p[j].x0==p[i].x1)&&(p[j].y0=p[i].y1)) // @@ [Assignment operator '=' used instead of equality operator '=='; causes logical error and unintended assignment]
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