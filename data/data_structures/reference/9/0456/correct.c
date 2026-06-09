#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct xd
{ int bx,by,ex,ey,cnt;
}xd[135];

int cmpfuc(const void *a, const void *b) {
 struct xd *c = (struct xd*)a;
 struct xd *d = (struct xd*)b;
 if(c->bx!=d->bx)
 {
    return d->bx - c->bx;
 }
    else
 {
    return d->by - c->by;
 }
 }

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&xd[i].bx,&xd[i].by,&xd[i].ex,&xd[i].ey);
        xd[i].cnt=1;
    }
    qsort(xd,n,sizeof(xd[0]),cmpfuc);

 for(int i=0;i<n-1;i++)
 {
     for(int j=i;j<n-1;j++)
     {
         if(xd[i].bx==xd[j+1].ex&&xd[i].by==xd[j+1].ey)
         {
             xd[j+1].cnt+=xd[i].cnt;
         }
     }
 }
    int max=-100;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(xd[i].cnt>max)
        {
            max=xd[i].cnt;
            flag=i;
        }
    }
    printf("%d %d %d",max,xd[flag].bx,xd[flag].by);
    return 0;
 }









