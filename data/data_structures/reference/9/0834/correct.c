#include<stdio.h>
#include<stdlib.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
};
struct line l[105];
int cmp(const void *pa,const void *pb)
 {
 	struct line a=*((struct line *)pa);
 	struct line b=*((struct line *)pb);
 	return a.x1-b.x1;
 }
int main()
{
	int i,j,n,num[105];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	num[i]=1; 
	for(i=0;i<n;i++)
	scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	qsort(l,n,sizeof(l[0]),cmp);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			 if(l[i].x2==l[j].x1)
			 {
			 	if(l[i].y2==l[j].y1)
			 	{
			 		l[i].x2=l[j].x2;
			 		l[i].y2=l[j].y2;
			 	num[i]++;
				 }
			 }
		}
	}
	int max=0,mi=0;
	for(i=0;i<n;i++)
	if(num[i]>max)
	max=num[i],mi=i;
	printf("%d ",max);
	printf("%d %d",l[mi].x1,l[mi].y1);
	return 0;
 } 

