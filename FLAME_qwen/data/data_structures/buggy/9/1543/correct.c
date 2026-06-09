#include <stdio.h> 
#include<string.h>
#include <stdlib.h>
struct book{
	int x1;
	int y1;
	int x2;
	int y2;
	int l;
};
struct book a[500];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		a[i].l=1;
	}
	int check;
	for(;;)
	{	
		check=0;
		for(int j=0;j<n;j++)
		{
			if(a[j].l==0) continue;
			for(int k=0;k<n;k++)
			{
				if(a[j].l==0) continue;
				if(a[k].l==0) continue;
				if(a[j].x2==a[k].x1&&a[j].y2==a[k].y1)
				{
					a[j].x2=a[k].x2;
					a[j].y2=a[k].y2;
					a[j].l=a[j].l+a[k].l;
					a[k].l=0;
					check=1;
				}
				else if(a[k].x2==a[j].x1&&a[k].y2==a[j].y1)
				{
					a[k].x2=a[j].x2;
					a[k].y2=a[j].y2;
					a[k].l=a[j].l+a[k].l;
					a[j].l=0;
					check=1;
				}
			}	
		}
		if(check==0)
		{
			break;
		}
	}
	int max_long=0,max;
	for(int m=0;m<n;m++)
	{
		if(a[m].l>max_long)
		{
			max=m;
			max_long=a[m].l;
		}
	}
	printf("%d %d %d",max_long,a[max].x1,a[max].y1);
	return 0;
}




