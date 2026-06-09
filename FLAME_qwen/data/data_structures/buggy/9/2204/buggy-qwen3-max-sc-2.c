#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct zuobiao
{
    int x1;
    int y1;
    int x2;
    int y2;
};
struct zuobiao t[10009];


int cmp(const struct zuobiao p,const struct zuobiao q)

{

if(p.x1>q.x1) return 1;
else if(p.x1<q.x1 ) return -1;
else if(p.y1 > q.y1) return 1;
else return -1;
} // @@ [The comparison function for qsort must take pointers as arguments, not values. This causes undefined behavior and likely a compilation or runtime error because qsort passes pointers to elements, not the elements themselves.]


int main()
{
int a,l,k=0,c=0,d=0,max=0;
scanf("%d",&a);
for (int i=0;i<a;i++)
{
scanf("%d%d%d%d",&t[i].x1,&t[i].y1,&t[i].x2,&t[i].y2);

}

qsort(t,a,sizeof(t[0]),cmp); // @@ [Due to incorrect signature of cmp, this call to qsort is invalid and may cause a crash or incorrect sorting.]

   for(int i=0;i<a;i++)
    {
        l=1; 
        k=i;
        for(int j=i+1;j<a;j++)
        {
            if(t[j].x1==t[k].x2&&t[j].y1==t[k].y2)
            {
                l++;
                k=j;
            }

       
}
 if(l>max)
{
            max=l;
            c=t[i].x1;
            d=t[i].y1;

}   
}
    printf("%d %d %d",max,c,d);

return 0;
}