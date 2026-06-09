#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct  _lq
{
    int x1,y1,x2,y2;
} lq,*llq;
lq a[101];
int b[101]={1}; // @@ [Initialization of array 'b' with {1} only sets b[0]=1, rest are zero; should initialize all elements to 1 to represent each segment initially having length 1]
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
    for(j=i;j<n;j++) // @@ [Loop starts at j=i, but should start at j=i+1 to avoid comparing segment with itself]
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
printf("%d ",b[w]+1); // @@ [If b[w] already counts number of segments in chain, adding 1 is incorrect; also, if b was initialized incorrectly, this compounds the error]
printf("%d %d ",a[w].x1,a[w].y1);

return 0;
}