#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 105

int line[MAXN][4], flag[MAXN], ans = -1, cnt = 0, n, win;

int max(int x, int y)
{
	return x > y ? x : y;
}
void dfs(int tar, int time)
{
	cnt = max(cnt, time);
	if (time == n)
	{
		return;
	}
	int i;
	for (i = 1; i <= n; i++)
	{
		if(flag[i] && line[tar][2] == line[i][0] && line[tar][3] == line[i][1])
		{
			flag[i] = 0;
			dfs(i, time + 1);
			flag[i] = 1;
		}
	}
}
int main()
{
	//freopen("line.in", "r", stdin);
	int i; //x1, y1, x2, y2;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		flag[i] = 1;
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", &line[i][0], &line[i][1], &line[i][2], &line[i][3]);
	} 
	for (i = 1; i <= n; i++)
	{
		flag[i] = 0;
		dfs(i, 1);
		if (cnt > ans)
		{
			ans = cnt;
			win = i;	
		}
		cnt = 0;
		flag[i] = 1;
	}
	printf("%d %d %d\n", ans, line[win][0], line[win][1]);
	//fclose(stdin);
	return 0;
}

