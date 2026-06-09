#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct xian
{
	int x1;
	int y1;
	int x2;
	int y2;
};
int compare(struct xian *x,struct xian *y)
{
	return x->x1-y->x1; 
}
int main()
{
	int n,i,j;
	int l,k,x,y;
	int max=0;
	scanf("%d",&n);
	struct xian a[150];
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	qsort(a,n,sizeof(struct xian),compare);
	for(i=0;i<n;i++)
	{
		l=1;
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j].x1==a[k].x2&&a[j].y1==a[k].y2)
			{
				l++;
				k=j;
			}
		}
		if(l>max)
		{
			max=l;
			x=a[i].x1;
			y=a[i].y1;
		}
	}
	printf("%d %d %d",max,x,y);
	return 0;
}
  


		
 
	
	
		


