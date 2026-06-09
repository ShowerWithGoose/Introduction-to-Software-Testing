#include <stdio.h>
#include <string.h>
int i,n,m,flag;
int s[105],c[105],a[105][105];
void bfs(int t);
void dfs(int t);
int main()
{
	scanf("%d%d", &n, &m);
	int i;
	for (i=1;i<=m;i++)
	{
		int o,p;
		scanf("%d%d",&o,&p);
		a[o][p]=1;
		a[p][o]=1;
	}
	flag = 0;
	dfs(0);
	printf("\n");
	memset(s, 0, sizeof(s));
	flag =0;
	bfs(0);
	printf("\n");
	scanf("%d",&i);
	s[i]=1;
	flag=0;
	dfs(0);
	printf("\n");
	memset(s,0,sizeof(s));
	s[i]=1;
	flag=0;
	bfs(0);
	printf("\n");
	return 0;
}
void bfs(int t)
{
	c[1] = t;
	int l = 1, r = 1;
	while (l <= r)
	{
		int x=c[l];
		l++;
		if (s[x])
			continue;
		if (flag==0)
		{
			printf("%d", x);
			flag = 1;
		}
		else
			printf(" %d", x);

		s[x] = 1;
		for (i = 1; i <= n; i++)
			if (a[x][i])
			{
				if (s[i]==0)
				{
					r++;
					c[r] = i;
				}
			}
	}
	memset(s, 0, sizeof(s));
}
void dfs(int t)
{
	if (flag==0)
	{
		printf("%d", t);
		flag = 1;
	}
	else
		printf(" %d", t);
	s[t] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (a[t][i])
		{
			if (s[i]==0)
			{
				dfs(i);
			}
		}
}



