#include<stdio.h>
#include<string.h>


int a[200][200],visit[200]={0},que[200];
int n,m;

void tBFS(int x)
{
	int i,head=0,tail=1,tmp;
	que[head]=x;
	while(head<=tail)
	{
		tmp=que[head];
		head++;
		if(visit[tmp])	continue;
		else
		{
			printf("%d ",tmp);
			visit[tmp]=1;
			for(i=0;i<n;i++)
				if (a[tmp][i] && !visit[i])
					que[tail++]=i;
		}
	}
}

void tDFS(int x)
{
	int i;
	printf("%d ",x);
	visit[x]=1;
	for(i = 0; i < n; i++)
		if (a[x][i] && !visit[i])
		{
			tDFS(i);
		}
}
int main()
{	
	int x,y,i,v;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	tDFS(0);
	puts("");
	memset(visit,0,sizeof(visit));
	tBFS(0);
	puts("");
	scanf("%d",&v);
	memset(visit,0,sizeof(visit));
	visit[v]=1;	
	tDFS(0);
	puts("");
	memset(visit,0,sizeof(visit));memset(que,0,sizeof(que));
	visit[v]=1;
	tBFS(0);
	puts("");
	return 0;
}
