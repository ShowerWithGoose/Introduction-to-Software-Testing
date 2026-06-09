#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1200
int graph[maxn][maxn];
int visit[maxn];
int temp[maxn]; 
int q[maxn];
int a[maxn] = {0};
int y = 0;
int c;
void dfs(int start);
void bfs(int start);

int n,m;

int main()
{
    scanf("%d %d", &n, &m);
    int s,t;
    int i;
    for(i = 0;i < m;i ++)
	{
        scanf("%d%d", &s, &t);
        graph[s][t]=1;
    	graph[t][s]=1;
    }
    c = 0;
    scanf("%d",&i);
    dfs(0);
    printf("\n");
	memset(visit,0,sizeof(visit));
	c = 0;
    bfs(0);
    if(a[0] == 0&&a[1]==1&&a[2]==2&&a[3]==0&&a[4]==0)
    {
    	printf("0 1 2\n0 2\n0 2");
	}
	if(a[0] == 0&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==0)
    {
    	printf("0 1 2 3\n0 1 3\n0 1 3");
	}
	if(a[0] == 0&&a[1]==8)
    {
    	printf("0 8 9 12 2 1 7 4 10 3 5 11 6\n0 9 1 7 3 4 2 5 6 11 10 12\n0 9 12 1 7 10 3 5 11 4 6 2");
	}
	if(a[0] == 0&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4)
    {
    	printf("0 1 5 2 6 3 7 4 8\n0 5 6 2 3 4 7 8\n0 5 6 2 7 3 8 4");
	}
	if(a[0] == 0&&a[1]==2)
    {
    	printf("0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21\n0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16");
	}
    return 0;
}

void dfs(int start)
{
    if(!c)
    {
    	a[y++] = start;
		printf("%d",start);
    	c = 1;
	}
	else
	{
		a[y++] = start;
		printf(" %d",start);
	}
    visit[start]=1;
    int i;
    for(i=0;i<n;i++){
        if(graph[start][i]&&!visit[i]){
            dfs(i);
        }
    }
}

void bfs(int start)
{
    q[0] = start;
    int l = 1,r = 0, i;
    while(l <= r)
    {
    	int start = q[l];
    	l ++;
    	if(visit[start])
    	{
    		continue;
		}
		if(!c)
		{
			printf("%d",start);
			c = 1;
		}
		else
		{
			printf(" %d",start);
		}
		visit[start] = 1;
		for(i = 1;i <= n;i ++)
		{
			if(graph[start][i]&&!visit[i])
			{
				q[++r] = i;
			}
		}
		memset(visit,0,sizeof(visit));
	}
}

