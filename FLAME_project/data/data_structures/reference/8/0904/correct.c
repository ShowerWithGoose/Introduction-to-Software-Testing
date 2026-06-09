#include<stdio.h>
#include<string.h>
int s[500][500],vis[200]={0},queue[500];
int n,m;
void visit(int q)
{
	int i;
	printf("%d ",q);
	vis[q]=1;
	for(i=0;i<n;i++)
	{
		if(s[q][i]&&vis[i]==0)
		{
			visit(i);
		}
	}
}
void visit2(int q)
{
	int o,head=0,tail=1,temp;
	queue[head]=q;
	while(head<=tail)
	{
		temp=queue[head];
		head++;
		if(vis[temp]==0)
		{
			printf("%d ",temp);
			vis[temp]=1;
			for(o=0;o<n;o++)
			{
				if(s[temp][o]==1&&vis[o]==0)
				{
					queue[tail++]=o;
				}
			}
		}
	}
}
int main()
{
	int u,v,i,d;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		s[u][v]=1;
		s[v][u]=1;
	}
	visit(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	visit2(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	scanf("%d",&d);
	vis[d]=1;
	visit(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	memset(queue,0,sizeof(queue));
	vis[d]=1;
	visit2(0);
	return 0;
}



