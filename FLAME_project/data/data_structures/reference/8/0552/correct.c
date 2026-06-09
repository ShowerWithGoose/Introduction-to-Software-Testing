#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define Max 100
#define LEN sizeof(ELink)
typedef struct edge
{
	int adjvex;/*该边的终止结点在顶点结点中的位置*/
	int weight;/*该边的权值*/
	struct edge* next;/*指向下一个边结点*/
}ELink; 
typedef struct ver/*顶点结构体*/
{
	int vertex;/*顶点数据信息*/
	ELink* link;
}VLink;
int visited[Max];/*标记结点是否被访问过*/
int A[Max][Max];/*图的邻接矩阵*/
int Q[Max*Max], front = 0, rear = 0;/*广度优先搜索辅助队列*/
VLink D[Max];/*输入的图*/
void Adjlist1(VLink G[], int n, int e)/*n为顶点个数,e为边的个数*/
{
	/*G为无向图*/
	int k, vi, vj, i;
	ELink* p, * q;
	for (k = 0; k < n; k++)
	{
		G[k].vertex = k;
		G[k].link = NULL;
	}
	for (k = 0; k < e; k++)
	{
		scanf("%d%d", &vi, &vj);
		A[vi][vj] = 1;
		A[vj][vi] = 1;
	}
	for (k = 0; k < n; k++)/*k指向顶点下标*/
		for (i = 0; i < n; i++)
			if (A[k][i] == 1)
			{
				p = (ELink*)malloc(LEN);
				p->adjvex = i;
				p->weight = 0;
				p->next = NULL;
				if (G[k].link == NULL)
					G[k].link = p;
				else
				{
					for (q = G[k].link; q->next != NULL; q = q->next);
					q->next = p;
				}
			}
}

void Delete(VLink G[], int n, int del)/*在图G中删除编号为del的结点*/
{
	int i;
	ELink* p = NULL, * q = NULL;
	for (i = 0; i < n; i++)
		if (i != del)
		{
			for (p = G[i].link; p!=NULL && p->adjvex != del; p = p->next)
				q = p;
			if (p == G[i].link)
			{
				G[i].link = p->next;
				free(p);
			}
			else if (p != NULL)
			{
				q->next = p->next;
				free(p);
			}
		}
		else if (i == del)
		{
			for (p = G[i].link; p != NULL;)
			{
				q = p;
				p = p->next;
				free(q);
			}
			G[i].link = NULL;
		}
}

void DFS(VLink G[], int v)/*深读优先搜索递归算法*/
{
	int w;
	ELink* p;
	if (G[v].link != NULL)
	{
		printf("%d ", G[v].vertex);/*访问该结点*/
		visited[v] = 1;
		p = G[v].link;/*求v的第一个邻接点,若无邻接点则返回-1*/
		w = p == NULL ? -1 : p->adjvex;
		while (w != -1)
		{
			if (visited[w] == 0)
				DFS(G, w);
			p = p->next;
			w = p == NULL ? -1 : p->adjvex;
		}
	}
}
void Travel_DFS(VLink G[], int n)/*深读优先搜索主算法*/
{
	int i;
	for (i = 0; i < n; i++)
		visited[i] = 0;
	for (i = 0; i < n; i++)
		if (visited[i] == 0)
			DFS(G, i);
}

void BFS(VLink G[], int v)/*广度优先搜索递归算法*/
{
	int w;
	ELink* p;
	if (G[v].link != NULL)
	{
		printf("%d ", G[v].vertex);
		visited[v] = 1;
		Q[rear++] = v;/*入队*/
		while (front != rear)
		{
			v = Q[front++];/*取出队头元素*/
			p = G[v].link;/*求v的第一个邻接点,若无邻接点则返回-1*/
			w = p == NULL ? -1 : p->adjvex;
			while (w != -1)
			{
				if (visited[w] == 0)
				{
					printf("%d ", G[w].vertex);
					Q[rear++] = w;
					visited[w] = 1;
				}
				p = p->next;
				w = p == NULL ? -1 : p->adjvex;
			}
		}
	}
}
void Travel_BFS(VLink G[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		visited[i] = 0;
	for (i = 0; i < n; i++)
		if (visited[i] == 0)
			BFS(G, i);
}

int main()
{
	int n, e;
	int del;/*要删除的结点编号*/
	scanf("%d%d", &n, &e);
	Adjlist1(D, n, e);
	scanf("%d", &del);
	Travel_DFS(D, n);
	printf("\n");
	Travel_BFS(D, n);
	printf("\n");
	Delete(D, n, del);
	Travel_DFS(D, n);
	printf("\n");
	Travel_BFS(D, n);
	printf("\n");
	return 0 ;
} 

