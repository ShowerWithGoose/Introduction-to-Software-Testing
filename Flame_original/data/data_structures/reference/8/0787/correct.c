#include<stdio.h>
#include<stdlib.h>
struct edge {
	int end;
	struct edge* next;
};
struct point {
	int start;
	struct edge* next;
};
struct point pList[50];
int visited[50];
void dfs(int x)
{
	if (visited[x] == 0)
		printf("%d ", x);
	visited[x] = 1;
	struct edge* p = pList[x].next;
	while (p)
	{
		if (visited[p->end] == 0)
			dfs(p->end);
		p = p->next;
	}
}
void bfs(int x)
{
	int head = 0, tail = 0;
	int queue[50] = { 0 };
	queue[tail++] = x;
	while (head < tail)
	{
		if(visited[queue[head]]==0){
			visited[queue[head]] = 1;
			printf("%d ", queue[head]);
		}
		struct edge* p = pList[queue[head]].next;
		while (p)
		{
			if (visited[p->end] == 0)
				queue[tail++] = p->end;
			p = p->next;
		}
		head++;
	}
}
void insert(int p, int q);
int main()
{
	int pNUm = 0, eNum = 0, p = 0;
	scanf("%d %d", &pNUm, &eNum);
	char c;
	while (scanf("%d%c", &p, &c), c != '\n')
	{
		int q = 0;
		scanf("%d", &q);
		insert(p, q);
		insert(q, p);
	}
	dfs(0);
	memset(visited, 0, sizeof(visited));
	printf("\n");
	bfs(0);
	memset(visited, 0, sizeof(visited));
	printf("\n");
	int target = p;
	visited[target] = 1;
	dfs(0);
	memset(visited, 0, sizeof(visited));
	printf("\n");
	visited[target] = 1;
	bfs(0);
	memset(visited, 0, sizeof(visited));
	printf("\n");
	return 0;
}
void insert(int p,int q)
{
	struct edge* r = (struct edge*)malloc(sizeof(struct edge));
	r->end = q;
	r->next = NULL;
	if (!pList[p].next)
		pList[p].next = r;
	else {
		struct edge* s = pList[p].next;
		if (s->end > r->end){
			r->next = s;
			pList[p].next = r;
		}
		else {
			while (s->next)
			{
				if (s->next->end >= r->end)
					break;
				s = s->next;
			}
			if (s->next == NULL)
				s->next = r;
			else {
				r->next = s->next;
				s->next = r;
			}
		}
	}
}
/*
12 16
6 11
5 6
7 5
10 11
7 1
7 9
3 7
10 1
9 1
12 1
3 4
4 2
9 0
9 8
2 8
12 0
8 0
8
*/


