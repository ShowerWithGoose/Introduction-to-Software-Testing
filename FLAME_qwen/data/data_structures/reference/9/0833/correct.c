#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
#define mod 100007
typedef struct
{
	int x1,y1,x2,y2,count;
}line;
int compare(const void *arg1, const void *arg2);

int main()
{
int n,i,j=0,k=0,si=1,max,ma;
line l[200],lz[200];
scanf("%d",&n);
for(i=0;i<n;i++)
	scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
qsort(l,n,sizeof(l[0]),compare);
for(i=0;i<n;i++)
   {si=1;
   for(j=0;j<k;j++)
    {
    	if(l[i].x1==lz[j].x2&&l[i].y1==lz[j].y2)
    	{lz[j].x2=l[i].x2,lz[j].y2=l[i].y2,lz[j].count++,si=-1;break;}
	}
	if(si==-1) continue;
	lz[k].x1=l[i].x1,lz[k].x2=l[i].x2,lz[k].y1=l[i].y1,lz[k].y2=l[i].y2,lz[k].count=1,k++;
              }
ma=0,max=lz[0].count;
for(i=1;i<k;i++)
	if(max<lz[i].count)
	{
		ma=i;
		max=lz[i].count;
	}
printf("%d %d %d",max,lz[ma].x1,lz[ma].y1);
	return 0;
}

 int compare(const void *arg1, const void *arg2) {
     line *a = (line*)arg1;
     line *b = (line*)arg2;
     int xa,xb;
     xa=a->x1;
     xb=b->x1;
     return(xa-xb);
 }


