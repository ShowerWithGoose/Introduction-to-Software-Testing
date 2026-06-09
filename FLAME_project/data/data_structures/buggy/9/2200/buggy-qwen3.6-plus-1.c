#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct  _lq
{
    int x1,y1,x2,y2;
} lq,*llq;
lq a[101];
int b[101]={1}; // @@ The initialization {1} only sets b[0]=1, leaving b[1]...b[n-1] as 0. This causes incorrect segment counting for segments that are not the first in a chain or standalone, leading to wrong max calculation. It should be initialized to 1 for all active segments.
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
    for(j=i;j<n;j++)
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
w=0; // @@ Variable 'w' is used uninitialized if b[0] is the maximum. It must be initialized to 0 to ensure a valid index is printed.
for(i=0;i<n;i++)
{
 if(b[i]>max)
 {
     w=i;
     max=b[i];
 }
     
}
printf("%d ",b[w]+1); // @@ Since b[w] counts the number of *additional* segments merged into segment w (starting at 1 for the base segment), the total number of segments is b[w]. Adding 1 results in an off-by-one error (e.g., outputting 3 instead of 2 for a 2-segment chain).
printf("%d %d ",a[w].x1,a[w].y1);

return 0;
}