#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000

typedef struct edge
{
	int x1,x2,y1,y2,head;
}EDGE;

EDGE line[110]; 
int end[MAXN][MAXN],cnt[110];

int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		line[i].x1=x1;
		line[i].x2=x2;
		line[i].y1=y1;
		line[i].y2=y2;
		line[i].head=i;
		end[x2][y2]=i;
	}
	for(i=1;i<=n;i++)
	{
		int p=i,q;
		while(p!=0)
		{
			q=p;
			p=end[line[p].x1][line[p].y1];
		}
		line[i].head=q;
		cnt[q]++;
	}
	int max=0,max_i=1;
	for(i=1;i<=n;i++)
		if(cnt[i]>max)
		{
			max=cnt[i];
			max_i=i;
		}
	printf("%d %d %d",max,line[max_i].x1,line[max_i].y1);
	return 0;
}

