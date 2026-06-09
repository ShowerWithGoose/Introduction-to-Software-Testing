#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))
typedef long long ll;
struct node {
	int id;
	struct node * next;
};
struct vnode {
	int id;
	struct node *link;
} v[105];
struct node* insert(struct node* head, int v);
int dfs_queue[105], bfs_queue[105];
int top_dfs = -1;
int front = -1, rear = -1;
int visit[105];
int empty(int queue[]);
void dfs(struct vnode*root);
void bfs(struct vnode*root);
void output(int n);
void sort(int n);
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i <m;i++)
	{
		v[i].id = i;
	}
	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		v[v1].link = insert(v[v1].link, v2);
		v[v2].link = insert(v[v2].link, v1);
	}
	output(n);
	int del;
	scanf("%d", &del);
	for (int i = 0 ; i < n; i++) {
		if (del == i) v[i].link = NULL;
		struct node*tmp = v[i].link;
		while (tmp != NULL) {
			if (tmp->id == del) {
				struct node*tmp1 = v[i].link;
				if(v[i].link->id == del)
				{
					v[i].link = v[i].link->next;
					tmp = tmp->next;
					continue;
				}
				for(;tmp1->next != NULL && tmp1->next->id != del;tmp1 = tmp1->next);
				tmp1->next = tmp->next;
			}
			tmp = tmp->next;
		}
	}
	output(n-1);
	return 0;
}
struct node* insert(struct node* head, int id) {
	struct node* tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->id = id;
	tmp->next = NULL;
	if (head == NULL) {
		head = tmp;
		return head;
	}
	struct node*tmp1 = head,*prev;
	for(prev = tmp1; tmp1 != NULL && id > tmp1->id ; prev = tmp1, tmp1 = tmp1->next);
	if(tmp1 == head)
	{
		head = tmp;
		tmp->next = tmp1;
		return head;
	}
	prev->next = tmp;
	tmp->next = tmp1;
	return head;
};
void dfs(struct vnode*root) {
	dfs_queue[++top_dfs] = root->id;
	visit[root->id] = 1; 
	struct node* tmp = root->link;
	while (tmp != NULL) {
		if (visit[tmp->id] == 0)
			dfs(&v[tmp->id]);
		tmp = tmp->next;
	}
	return;
}

int empty(int queue[])
{
	if(front == rear+1) return 1;
	if(front == -1 && rear == -1) return 1;
	return 0;
}

void bfs(struct vnode*root)
{
	if(front == -1 && rear == -1)
	{
		front = rear = 0;
		bfs_queue[rear] = root->id;
		visit[root->id] = 1;
	}
	while(!empty(bfs_queue))
	{
		int node = bfs_queue[front++];
		for(struct node*tmp = v[node].link;tmp != NULL;tmp = tmp->next)
		{
			if(visit[tmp->id] == 0)
			{
				bfs_queue[++rear] = tmp->id;
				visit[tmp->id] = 1;
			}
		}
	}
}
void output(int n)
{
	dfs(&v[0]);
	for(int i = 0; i < n; i++)
	{
		printf("%d ",dfs_queue[i]);
	}
	printf("\n");
	top_dfs = -1;
	memset(dfs_queue,0,sizeof(dfs_queue));
	memset(visit,0,sizeof(visit));
	bfs(&v[0]);
	for(int i = 0; i < n; i++)
	{
		printf("%d ",bfs_queue[i]);
	}
	printf("\n");
	memset(bfs_queue,0,sizeof(bfs_queue));
	memset(visit,0,sizeof(visit));
	front = rear = -1;
}


