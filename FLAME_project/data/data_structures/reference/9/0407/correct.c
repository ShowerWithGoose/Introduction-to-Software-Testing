#include<stdio.h>
#include<string.h>

struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int count;
}; 

int cmp(const void *p1,const void *p2)
{
	struct line *a=(struct line*)p1;
	struct line *b=(struct line*)p2;
	if((*a).x1!=(*b).x1) 
	{
		return (*a).x1-(*b).x1;
	}
	else return (*a).y1-(*b).y2;
}

int main()
{
	int n,i,j,max;
	scanf("%d",&n);
	struct line a[n];
	
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		a[i].count=1;
	}
	qsort(a,n,sizeof(struct line),cmp);
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j].x1==a[i].x2&&a[j].y1==a[i].y2)
			{
				a[i].x2=a[j].x2;		
				a[i].y2=a[j].y2;     
				a[i].count+=a[j].count; 
				a[j].x1=0,a[j].y1=0;
				a[j].x2=0,a[j].y2=0;
				a[j].count=0;
			}	
		}
	}
	
	max=a[0].count;
	j=0;
	for(i=1;i<n;i++)
	{
		if(a[i].count>max)
		{
			max=a[i].count;
			j=i;
		}
	}
	printf("%d %d %d",max,a[j].x1,a[j].y1);
	
	return 0;
}



