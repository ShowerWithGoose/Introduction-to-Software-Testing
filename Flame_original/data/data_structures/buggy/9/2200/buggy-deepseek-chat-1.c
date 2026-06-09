#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct  _lq
{
    int x1,y1,x2,y2;
} lq,*llq;
lq a[101];
int b[101]={1}; // @@ Error: Only b[0] is initialized to 1; all other elements are initialized to 0, but the problem expects each segment to start with count 1. Should be int b[101] = {0}; and then set b[i]=1 in the loop.
int cmp(const void* p,const void*q)
{
    lq* p1=(lq *)p;
    lq* q1=(lq *)q;
    if(p1->x1<q1->x1)
    {
        return -1;
         
     } 
     else if(p1->x1>q1->x1)
     {
         return 1;
     }
     else return 0;
}
int main()
{int i,n,j,w,max;
scanf("%d",&n);
for(i=0;i<n;i++)
   {
         scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
   }
qsort(a,n,sizeof(lq),cmp);
for(i=0;i<n;i++)
{
    for(j=i;j<n;j++) // @@ Error: j should start from i+1, not i, to avoid comparing a segment with itself. Also, the logic should allow merging in both directions (i.e., a[i] can be extended by a[j] where a[j] starts at a[i]'s end, but also a[j] could be extended by a[i] if a[i] starts at a[j]'s end). The current loop only checks one direction.
    {
        if((a[i].x2==a[j].x1)&&(a[i].y2==a[j].y1)&&(b[i]!=-1))
        {
            b[i]++;
            b[j]=-1;
            a[i].x2=a[j].x2;
            a[i].y2=a[j].y2;
            //printf("%d %d\n",a[i].x2,a[i].y2);
        }
     } 
     
}
max=b[0];
for(i=0;i<n;i++)
{
 if(b[i]>max)
 {
     w=i;
     max=b[i];
 }
     
}
printf("%d ",b[w]+1); // @@ Error: b[w] already counts the number of segments merged into w, so adding 1 is incorrect. Should be printf("%d ", b[w]);
printf("%d %d ",a[w].x1,a[w].y1);

return 0;
}