#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int a=0;
struct xianduan{
	int x1;
	int y1;
	int x2;
	int y2;
};
int dfp(const struct xianduan now ,const struct xianduan *op,int n)
{	
	a++;
	int i;
	for(i=0;i<n;i++)
	{	
		if(now.x2==op[i].x1&&now.y2==op[i].y1)
		{
			dfp(op[i],op,n);
		}
	}
	return a;
}
int main()
{	
	struct xianduan xian[101];
	struct xianduan *ps;
	int x,y,i,j;
	int count[101];
	int n;
	int max=0;
	int flag;
	int tongji[101];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&(xian[i].x1),&(xian[i].y1),&(xian[i].x2),&(xian[i].y2));
	}
	for(i=0;i<n;i++)
	{	
		ps=&xian;
		count[i]=dfp(xian[i],ps,n);
		a=0;
	}
	for(i=0;i<n;i++)
	{
		if(count[i]>max)
		{
		max=count[i];
		flag=i;
		}
	}
	printf("%d %d %d",max,xian[flag].x1,xian[flag].y1);
	return 0;
 } 




