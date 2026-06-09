#include<stdio.h>
#include<string.h>
int n,m;
int t[500][500],s[500]={0};
void dfs(int v)
{
	printf("%d ",v);
	s[v]=1;
	for(int i=0;i<n;i++)
		if(t[v][i]==1&&s[i]!=1)
			dfs(i);
}	

void bfs(int v)
{
	int q[500];
	memset(q,0,sizeof(q));
	int head=0,tail=1;
	q[head]=v;
	while(head<=tail)
	{
		int temp;
		temp=q[head++];
		if(s[temp]==1)
			continue;
		else
		{
			printf("%d ",temp);
			s[temp]=1;
			for(int i=0;i<n;i++)
				if(t[temp][i]==1&&s[i]!=1)
					q[tail++]=i;
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		t[y][x]=t[x][y]=1;
	}
	dfs(0);	printf("\n"); memset(s,0,sizeof(s));
	bfs(0);	printf("\n"); memset(s,0,sizeof(s));
	int del;
	scanf("%d",&del);
	s[del]=1;
	dfs(0); printf("\n"); memset(s,0,sizeof(s));
	s[del]=1; 
	bfs(0);
	return ;
}


