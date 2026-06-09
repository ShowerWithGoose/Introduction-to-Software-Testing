#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct edge{
	int adj;
	struct edge *next;
};

struct ver{
	struct edge *link;
};

struct edge *insert(struct edge *head, int v);
int comb[MAX];

int visited[MAX];
int queue[MAX];
int front = 0, rear = -1;
void DFS(struct ver head[], int n);
void BFS(struct ver head[], int n);
void DFS2(struct ver head[], int n, int delnum);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct ver verhead[MAX];
	struct edge *q, *r, *t;
	int cnt, n, v1, v2, i, delnum, j;
	scanf("%d %d", &cnt, &n);
	for(i = 0;i < cnt;i++){
		verhead[i].link = NULL;
	}
	for(i = 0;i < n;i++){
		scanf("%d %d", &v1, &v2);
		verhead[v1].link = insert(verhead[v1].link, v2);
		verhead[v2].link = insert(verhead[v2].link, v1);
	}
	scanf("%d", &delnum);
	DFS(verhead, 0);
	printf("\n");
	for(i = 0;i < cnt;i++){
		visited[i] = 0;
	}
	BFS(verhead, 0);
	printf("\n");
	for(i = 0;i < cnt;i++){
		visited[i] = 0;
	}
	for(j = 0;j < cnt;j++){
		if(j == delnum){
			//verhead[j].link = NULL;
		} 
		else{
			t = verhead[j].link;
			if(t == NULL){
				continue;
			}
			else if(t != NULL && t->adj == delnum){
				verhead[j].link = t->next;
				free(t);
			}
			else{
				for(q = t;q != NULL && q->adj != delnum;r = q, q = q->next)
				;
				if(q == NULL){
					continue;
				}
				else if(q != NULL && q->adj == delnum){
					r->next = q->next;
					
				}
			}
		}
	}
	visited[delnum] = 1;
	DFS(verhead, 0);
	printf("\n");
	for(i = 0;i < cnt;i++){
		visited[i] = 0;
	}
	BFS(verhead, 0);
	printf("\n");
	return 0;
}

struct edge *insert(struct edge *head, int v){
	struct edge *p, *q, *r;
	p = (struct edge*)malloc(sizeof(struct edge));
	p->adj = v;
	p->next = NULL;
	if(head == NULL){
		head = p;
		return p;
	}
	else if(head != NULL && head->adj > p->adj){
		p->next = head;
		return p;
	}
	else{
		for(q = head;q->next != NULL&&q->adj < p->adj;r = q, q = q->next)
		;
		if(q->next == NULL && q->adj < p->adj){
			q->next = p;
			return head;
		}
		else{
			p->next = q;
			r->next = p;
			return head;
		}
	}
}

void DFS(struct ver head[], int n){
	struct edge *p;
	visited[n] = 1;
	printf("%d ", n);
	for(p = head[n].link;p != NULL;p = p->next){
		if(!visited[p->adj]){
			DFS(head, p->adj);
		}
	}
}

void BFS(struct ver head[], int n){
	struct edge *p;
	int v;
	visited[n] = 1;
	rear++;
	queue[rear] = n;
	while(rear >= front){
		v = queue[front];
		front++;
		printf("%d ", v);
		for(p = head[v].link;p != NULL;p = p->next){
			if(!visited[p->adj]){
				rear++;
				queue[rear] = p->adj;
				visited[p->adj] = 1;
			}
		}
	}
}




