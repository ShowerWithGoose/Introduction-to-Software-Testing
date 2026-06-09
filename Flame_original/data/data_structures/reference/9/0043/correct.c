#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
	int x1;
	int y1;
	int x2;
	int y2;
};
int n,i,j,store,maxx;
int count[1000];
struct node a[200];
int cmp(const void *a,const void *b)
{
	return (*(struct node *)a).x1 - (*(struct node *)b).x1;
}
int main()
{
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
	scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	qsort(a,n,sizeof(struct node),cmp);
	for(i=0;i<n;i++)
	{
	count[i]=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i].x2==a[j].x1 && a[i].y2==a[j].y1 && a[j].x1!=9999999 && a[j].x2!=9999999 && a[j].y1!=9999999 && a[j].y2!=9999999)
			{
				a[i].x2=a[j].x2;
				a[i].y2=a[j].y2;
				a[j].x1=9999999;
				a[j].x2=9999999;
				a[j].y1=9999999;
				a[j].y2=9999999;
				count[j]=0;
				count[i]++;
			}
		}
//		if(count[i]>maxx)
//		{
//			maxx=count[i];
//			store=i;
//		}
	}
	for(i=0;i<n;i++)
	{
	if(count[i]>maxx)
		{
			maxx=count[i];
			store=i;
		}
	}

	printf("%d %d %d",maxx,a[store].x1,a[store].y1);
	

return 0;
}


