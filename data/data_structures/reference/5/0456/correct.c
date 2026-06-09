#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct dxs
{
    int xs;
    int zs;
}a[100005],b[100005],p[100005];


int cmpare(const void *a,const void*b)
{
    struct dxs *c=(struct dxs *)a;
    struct dxs *d=(struct dxs *)b;
    return d->zs-c->zs;
}
int main()
{
    int num1=0,num2=0;
    char c='!';

    for(num1=0;c !='\n';num1++)
    {
      scanf("%d%d%c",&a[num1].xs,&a[num1].zs,&c);
    }
    c='!';
    for(num2=0;c !='\n';num2++)
    {
      scanf("%d%d%c",&b[num2].xs,&b[num2].zs,&c);
    }
    c='!';

    int m=0;
    for(int i=0;i<num1;i++)
    {
        for(int j=0;j<num2;j++)
        {
            p[m].xs=a[i].xs*b[j].xs;
            p[m].zs=a[i].zs+b[j].zs;
            m++;
        }
    }
    qsort(p,m,sizeof(p[0]),cmpare);
    for(int i=0;i<m;i++)
    {
        if(p[i].zs==p[i+1].zs&&p[i].zs!=0)
        {
            p[i+1].xs=p[i+1].xs+p[i].xs;
            p[i].xs=0;
        }
    }

     for(int i=0;i<m;i++)
    {
        if(p[i].xs!=0)
        {
            printf("%d %d ",p[i].xs,p[i].zs);
        }
    }


  return 0;




}


