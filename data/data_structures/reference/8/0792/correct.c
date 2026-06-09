#include<stdio.h>
int pic[500][500],visit[500]={0};
int que[500];
int n,m;
void DFS(int start)
{
	int t;
	printf("%d ",start);
	visit[start]=1;
	for(t=0;t<n;t++)
	{
		if(pic[start][t]==1&&visit[t]==0)
		{
			DFS(t);
		}
	}
}
void BFS(int start)
{
	int i,f=0,t=1,tmp;
	que[f]=start;
	while(f<=t)
	{
		tmp=que[f];
		f++;
		if(visit[tmp]==1)
		continue;
		else 
		{
			printf("%d ",tmp);
			visit[tmp]=1;
			for(i=0;i<n;i++)
			{
				if(pic[tmp][i]==1&&visit[i]==0)
				que[t++]=i;
			}
		 } 
	}
}
int main()
{
	int i,k;
	int p,q;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&p,&q);
		pic[p][q]=1;
		pic[q][p]=1;
	}
	DFS(0);;
	puts("");
	memset(visit,0,sizeof(visit));
	BFS(0);;
	puts("");
	memset(visit,0,sizeof(visit));
	scanf("%d",&k);
	visit[k]=1;
	DFS(0);;
	puts("");
	memset(visit,0,sizeof(visit));
	visit[k]=1;
	BFS(0);;
	puts("");
	return 0;
}

