#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int x1;
	int y1;
	int x2;
	int y2;
};
struct node line[200];
int cmp(const void *p1,const void *p2)
{
	struct node* a=(struct node *)p1;
	struct node* b=(struct node *)p2;
	return a->x1 - b->x1;
}
int main()
{
	int n,num=1,max=1,x,y,z;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		
	}
	qsort (line,n,sizeof(line[0]),cmp);
	
	for(int j=0;j<n;j++)
	{
		z=j;
		num=1;
		for(int k=j+1;k<n;k++)
		{
			if(line[z].x2==line[k].x1)
			{
				if(line[z].y2==line[k].y1)
				num++;
				z=k;
			}
		}
		if(num>max)
		{
			max=num;
			x=line[j].x1;
			y=line[j].y1;
		}
		
	}
	printf("%d %d %d",max,x,y);
	return 0;
}

