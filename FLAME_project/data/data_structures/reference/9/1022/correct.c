#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
};
struct line l[100];
int cmp(const void*p1, const void*p2);
int main()
{
	int i,j,a,b;
	int k=0,max=0;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		l[i].num=1;
	}
	for(i=0;i<n;i++)
	{
		scanf(" %d %d %d %d", &l[i].x1, &l[i].y1, &l[i].x2, &l[i].y2);
	}
	//第一次排序，按照起点的横坐标升序，如果相同按纵坐标
	qsort(l,n,sizeof(struct line),cmp); 

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==i)
			continue;
			else
			{
				if(l[j].x1==l[i].x2 && l[j].y1==l[i].y2)
				{
					l[i].x2=l[j].x2;
					l[i].y2=l[j].y2;
					l[i].num+=l[j].num;
					l[j].x1=0;
					l[j].y1=0;
					l[j].x2=0;
					l[j].y2=0;
					l[j].num=0;
				}
				else
				continue;
			}
		}
	}

	
	max=l[0].num;
	for(i=0;i<n;i++)
	{
		if(max<l[i].num)
		{
			k=i;
			max=l[i].num; 
		}
		
	}
	printf("%d %d %d\n",l[k].num,l[k].x1,l[k].y1);
	return 0;
	
	
	
	
	
	
	
	
	
	
	
}
int cmp(const void*p1, const void*p2)
{
	struct line *a=(struct line*)p1;
	struct line *b=(struct line*)p2;
	if(a->x1 != b->x1)
	return a->x1-b->x1;
	else
	return a->y1-b->y1;
}


