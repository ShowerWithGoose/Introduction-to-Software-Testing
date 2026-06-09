#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, a[105][105];
int vis[105], ok, q[105];
void dfs(int x)
{
	if (!ok)
		printf("%d", x), ok = 1;
	else
		printf(" %d", x);
	vis[x] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (a[x][i])
		{
			if (!vis[i])
			{
				dfs(i);
			}
		}
}
void bfs(int t)
{
	q[1] = t;

	int l = 1, r = 1, i;
	while (l <= r)
	{
		int x = q[l];
		l++;
		if (vis[x])
			continue;
		if (!ok)
			printf("%d", x), ok = 1;
		else
			printf(" %d", x);

		vis[x] = 1;
		for (i = 1; i <= n; i++)
			if (a[x][i])
			{
				if (!vis[i])
					q[++r] = i;
			}
	}
	memset(vis, 0, sizeof(vis));
}
int main()
{
	scanf("%d%d", &n, &m);
	int i;
	for (i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	ok = 0;
	dfs(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	ok = 0;
	bfs(0);
	printf("\n");
	scanf("%d", &i);
	vis[i] = 1;
	ok = 0;
	dfs(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	vis[i] = 1;
	ok = 0;
	bfs(0);
	printf("\n");
	return 0;
}
/*
#include<string.h>
#include<stdlib.h>
#define MaxV 
int Visited[MaxV];
typedef struct  edge{ 
       int  adjvex;
       int  weight;
       struct edge *next;
}ELink;
typedef struct ver{
       int  vertex;
       ELink  *link;
}VLink;
void travelDFS(VLink  G[ ], int n);
void DFS(VLink  G[ ], int v);
void travelBFS(VLink  G[ ], int n);
void BFS(VLink  G[ ], int v);
void enQueue(VLink queue[ ], int item);
int deQueue(VLink Q[]);
int emptyQ(VLink Q[]);
VLink  G[MaxV],Q[MaxV];
int main()
{
	int en,pn;
	scanf("%d%d",&en,&pn);
	return 0;
}
void travelDFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
}
void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; 
    VISIT(G, v); 
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adjvex] )
             DFS(G, p->adjvex);
}
void travelBFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}
void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; 
    enQueue(Q, v);
    while( !emptyQ(Q))
	{
        v = deQueue(Q);
        VISIT(G, v);
        for(p=G[v].link; p!=NULL; p=p->next ) 
            if( !Visited[p->adjvex] ) {
                Visited[p->adjvex] = 1;
                enQueue(G, p->adjvex);
    }
}
int deQueue(VLink Q[])
{
	return Q[0].vertex ;
}
void enQueue(VLink queue[ ], int item)
{
	
}
int emptyQ(VLink Q[])
{
	return 0;
}*/

