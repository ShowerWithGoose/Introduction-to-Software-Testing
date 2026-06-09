#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
	int vertex;
	struct node* next;
};
int  visit[100] = { 0 }, line[100] = { 0 };
void DFS(struct node* G[], int v,int t)
{
	struct node* p;
	visit[v] = 1; //标识某顶点被访问过
	if(v != t)printf("%d ", v); //访问某顶点
	for (p = G[v]; p != NULL; p = p->next)
		if (visit[p->vertex] != 1)
			DFS(G, p->vertex,t);
}

void BFS(struct node *G[], int v,int t)
{
	int  i, j;
	struct node * p;
	i = 0;
	j = 0;
	visit[v] = 1; //标识某顶点已入队
	line[i++] = v;
	while (i > j) {
		v = line[j++];  //取出队头元素
		if (v != t)printf("%d ", v); //访问当前顶点
		for (p = G[v]; p != NULL; p = p->next) //访问该顶点的每个邻接顶点
			if (!visit[p->vertex]) {
				visit[p->vertex] = 1; //标识某顶点入队
				line[i++]=p->vertex;
			}
	}
}

void  travelDFS(struct node  *G[], int n,int t)
{
	int i;
	for (i = 0;i < 100;i++)line[i] = 0;
	for (i = 0; i < n; i++) visit[i] = 0;
	for (i = 0; i < n; i++)
		if (visit[i] != 1) DFS(G, i,t);
}

void  travelBFS(struct node *G[], int n,int t)
{
	int i;
	for (i = 0; i < n; i++) visit[i] = 0;
	for (i = 0; i < n; i++)
		if (!visit[i]) BFS(G, i,t);
}


int main() {
	int n, m, a, b, i, j, t;
	struct node* graph[100], * first = NULL, * last = NULL, * p = NULL, * q = NULL;
	for (i = 0;i < 100;i++) graph[i] = NULL;
	scanf("%d%d", &n, &m);
	for (i = 0;i < n;i++) {
			graph[i] == NULL;
			graph[i] = (struct node*)malloc(sizeof(struct node));
			graph[i]->vertex = 0;
			graph[i]->next = NULL;
	}
	for (i = 1;i <= m;i++) {
		scanf("%d%d", &a, &b);
		p = (struct node*)malloc(sizeof(struct node));
		p->vertex = b;
		first = graph[a];
		last = graph[a]->next;
		if (first->next == NULL) {
			first->next = p;
			first->next->next = NULL;
		}
		else {
			while (first->next->vertex < b) {
				first = first->next;
				if (first->next == NULL) {
					first->next = p;
					first->next->next = NULL;
				}
			}
			if (first->next->vertex > b) {
				last = first->next;
				first->next = p;
				p->next = last;
			}
		}


		q = (struct node*)malloc(sizeof(struct node));
		q->vertex = a;
		first = graph[b];
		last = graph[b]->next;
		if (first->next == NULL) {
			first->next = q;
			first->next->next = NULL;
		}
		else {
			while (first->next->vertex < a) {
				first = first->next;
				if (first->next == NULL) {
					first->next = q;
					first->next->next = NULL;
				}
			}
			if (first->next->vertex > a) {
				last = first->next;
				first->next = q;
				q->next = last;
			}
		}
	}
	travelDFS(graph, n,101);
	printf("\n");
	for (i = 0;i < n;i++)visit[i] = 0;
	travelBFS(graph, n,101);
	printf("\n");
	scanf("%d", &t);
	for (i = 0;i < t;i++) {
		first = graph[i];
			while (first->next != NULL&& first->next->vertex != t)first = first->next;
			if (first->next != NULL) {
				p = first->next;
				last = p->next;
				first->next = last;
			}
	}
	for (i = t + 1;i < n;i++) {
		first = graph[i];
		while (first->next != NULL && first->next->vertex != t)first = first->next;
		if (first->next != NULL) {
			p = first->next;
			last = p->next;
			first->next = last;
		}
	}
	for (i = 0;i < n;i++)visit[i] = 0;
	travelDFS(graph, n,t);
	printf("\n");
	for (i = 0;i < n;i++)visit[i] = 0;
	travelBFS(graph, n,t);
	printf("\n");
		return 0;
}

