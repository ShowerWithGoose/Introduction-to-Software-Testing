#include <stdio.h>
#include <stdlib.h>
struct line
{
	int x1,y1,x2,y2,length;
	struct line* p;
}a[100];
int main()
{
	int i,j,n,max=0,max_n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		a[i].p=&a[i];
		a[i].length=1;
	}
	for(i=0;i<n;i++)
	{
loop:		for(j=0;j<n;j++)
		{
			if(a[i].p->x2==a[j].x1&&a[i].p->y2==a[j].y1)
			{
				a[i].p=a[j].p;
				a[i].length+=a[j].length;
				goto loop;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(a[i].length>max)
		{
			max=a[i].length;;
			max_n=i;
		}
	}
	printf("%d %d %d",max,a[max_n].x1,a[max_n].y1);
	return 0;
}

