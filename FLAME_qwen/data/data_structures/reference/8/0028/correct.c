#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
int n,m,a[105][105];
int vis[105],ok,q[105];
void dfs(int x)
   {if (!ok)
		printf("%d",x),ok=1;
	else
		printf(" %d",x);
	vis[x]=1;
	int i=1;
	while (i<=n)
	   {if (a[x][i])
		   {if (!vis[i])
				dfs(i);
		   }
		i++;
	   }		
   }

void bfs(int t)
   {q[1]=t;
	int l=1,r=1,i;
	for (l=1;l<=r;l++)
	   {int x=q[l];
		if (vis[x])
			continue;
		if (!ok)
			printf("%d",x),ok=1;
		else
			printf(" %d",x);
		vis[x]=1;
		i=1;
		while (i<=n)
		   {if (a[x][i])
			   {if (!vis[i])
					q[++r] = i;
			   }
			i++;
		   }
	   }
	memset(vis,0,sizeof(vis));
   }

int main()
   {scanf("%d%d",&n,&m);
	int i=1;
	while (i<=m)
	   {int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	    i++;
	   }
	ok=0;
	dfs(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	ok=0;
	bfs(0);
	printf("\n");
	scanf("%d",&i);
	vis[i]=1;
	ok=0;
	dfs(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	vis[i]=1;
	ok=0;
	bfs(0);
	printf("\n");
	return 0;
   }

