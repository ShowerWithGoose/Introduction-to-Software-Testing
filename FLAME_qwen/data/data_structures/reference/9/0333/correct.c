#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
struct line{
	int x[2];
	int y[2];
};

typedef struct line line;

int cmp(const void *p,const void *q)
{
	struct line *a=(struct line*)p;
	struct line *b=(struct line*)q;
	if(a->x[0]<b->x[0]) return -1;
	if(a->x[0]==b->x[0]) return 0;
	if(a->x[0]>b->x[0]) return 1;
}

int main()
{
	line point[100];
	
	int i,j,k;
	
	int n;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&point[i].x[0],&point[i].y[0],&point[i].x[1],&point[i].y[1]);
	}
	
	qsort(point,n,sizeof(line),cmp);
	
	int cnt;
	int max=0;
	int temp; 
	int flag;
	int beginx=0,beginy=0;
	
	for(i=0;i<n;i++)
	{
		flag=i;
		cnt=0;
		for(j=i+1;j<n;j++)
		{
			if(point[j].x[0]==point[flag].x[1]&&point[j].y[0]==point[flag].y[1])
			{
				cnt++;
				flag=j;
			}
		}
		if(cnt>=max)
		{
			max=cnt;
			beginx=point[i].x[0];
			beginy=point[i].y[0];
		}
	}
	
	printf("%d %d %d",max+1,beginx,beginy);
	return 0;
}
