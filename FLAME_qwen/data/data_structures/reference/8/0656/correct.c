#include <stdio.h>
#include <stdlib.h>

#define MAXVERNUM 105

void dfs(int visitver,int vernum,int adj[][MAXVERNUM],int book[])
{
	printf("%d ", visitver);
	book[visitver] = 1;
	for (int i = 0; i < vernum; i++)
	{
		if (1==adj[visitver][i]&&0==book[i])
		{
			dfs(i, vernum, adj, book);
		}
	}
}

void wfs(int vernum, int adj[][MAXVERNUM], int book[])
{
	int queue[MAXVERNUM], front = 0, rear = 0;
	queue[rear++] = 0;
	while (front != rear)
	{
		book[queue[front]] = 1;
		printf("%d ", queue[front]);
		for (int i = 0; i < vernum; i++)
		{
			if (1==adj[queue[front]][i]&&0 == book[i])
			{
				book[i] = 1;
				queue[rear++] = i;
			}
		}
		front++;
	}
}

int main()
{
	int book[MAXVERNUM] = { 0 };
	int adj[MAXVERNUM][MAXVERNUM] = { 0 };
	int vernum, egnum, egnum_count;
	int from, to;
	int todelete;
	memset(adj, 0, sizeof(adj));
	scanf("%d%d", &vernum, &egnum);
	egnum_count = egnum;
	while (egnum_count--)
	{
		scanf("%d%d", &from, &to);
		adj[from][to] = adj[to][from] = 1;
	}
	memset(book, 0, sizeof(book));
	dfs(0,vernum,adj,book);
	printf("\b\n");
	memset(book, 0, sizeof(book));
	wfs(vernum, adj, book);
	printf("\b\n");
	scanf("%d", &todelete);
	for (int i = 0; i < vernum; i++)
	{
		adj[todelete][i] = adj[i][todelete] = 0;
	}
	memset(book, 0, sizeof(book));
	dfs(0, vernum, adj, book);
	printf("\b\n");
	memset(book, 0, sizeof(book));
	wfs(vernum, adj, book);
	printf("\b\n");
	return 0;
}
