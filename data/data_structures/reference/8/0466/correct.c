#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int n,id;
int e[105][105], vis[105];
int q[100005], q_front=1, q_back=0;

void dfs(int num)
{
	int i,j,k;
	if(vis[num])	
		return;
	vis[num] = 1;
	printf("%d ", num);
	for(i = 0; i < n; i++)
		if(!vis[i] && e[num][i])
			dfs(i);
}
void bfs()
{
	int i,j,k;
	memset(q, 0, sizeof(q));
	memset(vis, 0, sizeof(vis));
	q[++q_back] = 0;
	while(q_back >= q_front)
	{
		int cur = q[q_front++];
		if(vis[cur])
			continue;
		vis[cur] = 1;
		printf("%d ", cur);
		for(i = 0; i < n; i++)
		{
			if(e[cur][i] && !vis[i])
				q[++q_back] = i;
		}
	}
	printf("\n");
}

int main()
{
	int i,j,k,num,a,b;
	scanf("%d%d", &n, &num);
	for(i = 1; i <= num; i++)
	{
		scanf("%d%d", &a, &b);
		e[a][b] = e[b][a] = 1;
	}
	scanf("%d", &id);
	
	dfs(0);
	printf("\n");
	bfs();
	
	for(i = 0; i < n; i++)
		e[i][id] = e[id][i] = 0;
	
	memset(vis, 0, sizeof(vis));
	dfs(0);
	printf("\n");
	bfs();
	
	
	return 0;
}

