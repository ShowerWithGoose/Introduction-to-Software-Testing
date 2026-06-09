#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a,b,m,n;
int c[105][105],cnt[105],que[105];
void DFS(int k);
void BFS(int k);
int main()
{
	int j,op;
	scanf("%d%d",&m,&n);
	for(j=0;j<n;j++)
	{
		scanf("%d%d",&a,&b);
		c[a][b]=1;
		c[b][a]=1; 
	}
	DFS(0);
	printf("\n");
	memset(cnt,0,sizeof(cnt));
	BFS(0);
	printf("\n");
	memset(cnt,0,sizeof(cnt));
	scanf("%d",&op);
	cnt[op]=1;
	DFS(0);
	printf("\n");
	memset(cnt,0,sizeof(cnt));
	cnt[op]=1;
	BFS(0);
	printf("\n");
	memset(cnt,0,sizeof(cnt));
	return 0;
}
void DFS(int k)
{
	printf("%d ",k);
	int i;
	cnt[k]=1;
	for(i=0;i<m;i++)
	{
		if(c[k][i]==1&&cnt[i]==0)
		DFS(i);
	}
}
void BFS(int k)
{
	int i,head=0,tail=1,num;
	que[head]=k;
	while(head<=tail)
	{
		num=que[head];
		head++;
		if(cnt[num]==0)
		{
			printf("%d ",num);
			cnt[num]=1;
			for(i=0;i<m;i++)
			{
				if(c[num][i]==1&&cnt[i]==0)
				que[tail++]=i;
			}
		}
	}
}


