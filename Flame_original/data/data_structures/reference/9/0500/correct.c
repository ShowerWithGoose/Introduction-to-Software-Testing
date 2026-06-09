#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct s
{
	int x0;
	int y0;
	int x1;
	int y1;
	int cnt;
};
int cmp(const void *a,const void *b)
{
	struct s *c=(struct s*)a;
	struct s *d=(struct s*)b;
	if(c->x0!=d->x0)
		return d->x0-c->x0;
	else
		return d->y0-c->y0;
}
int main()
{
	struct s sg[110];
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&sg[i].x0,&sg[i].y0,&sg[i].x1,&sg[i].y1);
		sg[i].cnt=1;
	}
	qsort(sg,n,sizeof(sg[0]),cmp);
	i=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(sg[i].x0==sg[j].x1&&sg[i].y0==sg[j].y1)
			{
				sg[j].cnt+=sg[i].cnt;
			}
		}
	}
	int cntmax=0;
	int flag=0;
	i=0;
	for(i=0;i<n;i++)
	{
		if(sg[i].cnt>cntmax){
			cntmax=sg[i].cnt;
			flag=i;
		}
	}
	printf("%d %d %d",cntmax,sg[flag].x0,sg[flag].y0);
	return 0;
	
	
	
	 } 

