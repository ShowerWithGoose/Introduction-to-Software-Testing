#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct line 
{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
}; 
struct line lines[105],key;
int compare(const void *p1,const void *p2)
{
	struct line *a=(struct line *)p1;
	struct line *b=(struct line *)p2;
	if(a->x1<=b->x1 ) return -1;
	else return 1;
}
int main()
{
	int n,j,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
	}
	qsort(lines,n,sizeof(lines[0]),compare);
	for(i=0;i<n;i++) lines[i].num=1; 
	for(i=n-1;i>0;i--)
	{
		for(j=i;j>0;j--) 
		{
			if(lines[i].x1==lines[j-1].x2&&lines[i].y1==lines[j-1].y2) lines[j-1].num=lines[i].num+1;
		}
	}
	int max=-1;
	for(i=0;i<n;i++)
	{
		if(lines[i].num>max)
		{
			max=lines[i].num;
			key=lines[i];
		}
	}
	printf("%d %d %d\n",max,key.x1,key.y1);
} 

