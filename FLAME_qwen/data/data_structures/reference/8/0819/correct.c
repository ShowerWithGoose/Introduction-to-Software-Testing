#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct edgeVer{
	int verNum;
	struct edgeVer *next;
};

struct ver{
	int verNum;
	struct edgeVer *link;
};

struct ver vertex[110];
struct edgeVer *p, *q;
int subs[110];

void resetVer()
{
	int i;
	for(i = 0; i <110; i++){
		vertex[i].link=NULL;
	}
}

int insertVer(int ver1, int ver2)
{
	q = (struct edgeVer *)malloc(sizeof(struct edgeVer));
	q->verNum = ver2;q->next = NULL;
	if(vertex[ver1].link == NULL)
		vertex[ver1].link = q;
	else{
		p = vertex[ver1].link;
		if(q->verNum < p->verNum){
			q->next = p;
			vertex[ver1].link = q;
			return 0;
		}
		while(q->verNum > p->verNum){
			if(p->next==NULL)
				p->next = q;
			else{
				if(q->verNum < p->next->verNum){
					q->next = p->next;
					p->next = q;
				}
				else
					p = p->next;
			}			
		}
	}
}

int Visited[110];

void visitClear()
{
	int i;
	for(i = 0; i <110; i++)
		Visited[i] = 0;
}

int queue[110];
int front, rear;

void queueClear()
{
	int i;
	for(i = 0; i <110; i++)
		queue[i] = 0;
	rear = front = 0;
}

void enQueue(int v)
{
	queue[rear] = v;
	rear++;
}

int deQueue()
{
	return queue[front++];
}

void BFS(int v)
{
	struct edgeVer *p;
	enQueue(v);
	Visited[v] = 1;
	while(front != rear){
		v = deQueue();
		printf("%d ",v);
		for(p = vertex[v].link; p!=NULL; p=p->next){
			if(!Visited[p->verNum]){
				Visited[p->verNum] = 1;
				enQueue(p->verNum);			
			}

		}
	}
}


void DFS(int v)
{
	struct edgeVer *p;
	Visited[v] = 1;
	printf("%d ",v);
	for(p = vertex[v].link; p!=NULL; p=p->next){
		if(!Visited[p->verNum])
			DFS(p->verNum);
	}
}

void deleteVer(int v)
{
	struct edgeVer *p2;
	int i;
	for(i = 0; i < 110; i++){
		if(vertex[i].link!=NULL){
			p2 = vertex[i].link;
			if(p2->verNum == v){
				vertex[i].link = p2->next;
			}
			while(p2->next!=NULL){
				if(p2->next->verNum == v){
					p2->next = p2->next->next;
					break;
				}
				p2 = p2->next;
			}
		}	
	}
}


int main()
{
	int Nver, Nedge, i, verDelete;
	int ver1, ver2;
	resetVer();
	scanf("%d%d",&Nver,&Nedge);
	for(i = 1; i <= Nedge; i++){
		scanf("%d %d",&ver1, &ver2);
		insertVer(ver1, ver2);
		insertVer(ver2, ver1);
	}
	scanf("%d",&verDelete);
	DFS(0);
	printf("\n");
	visitClear();
	BFS(0);
	queueClear();
	visitClear();
	printf("\n");
	deleteVer(verDelete);
	DFS(0);
	printf("\n");
	visitClear();
	BFS(0);
	queueClear();
	visitClear();
	
	
	
return 0;
}

