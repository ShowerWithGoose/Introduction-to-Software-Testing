#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n{
	int adjvex;
	struct n *next;
}ELink;

typedef struct m{
	int vertex;
	ELink *link;
}VLink;

struct node{
	int ver1;
	int ver2;
}BTNode[105];

int Visited[105],Queue[105];
int rear,front;
VLink G[105];
ELink *insertEdge(ELink *head, int avex);
void  travelDFS(VLink  G[ ], int n);
void  travelBFS(VLink  G[ ], int n);
void DFS(VLink  G[ ], int v);
void BFS(VLink  G[ ], int v);
int cmp(const void *a,const void *b);

int main(){
	int m,n,i,a,b,delate;
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		BTNode[i].ver1=(a<b)?a:b;
		BTNode[i].ver2=(a>b)?a:b;
	}
	qsort(BTNode,n,sizeof(struct node),cmp);
	for(i=0;i<n;i++){
		G[BTNode[i].ver1].link=insertEdge(G[BTNode[i].ver1].link,BTNode[i].ver2);
		G[BTNode[i].ver2].link=insertEdge(G[BTNode[i].ver2].link,BTNode[i].ver1);
	}
	scanf("%d",&delate);
	travelDFS(G,m);
	travelBFS(G,m);
	G[delate].vertex=1;
	travelDFS(G,m);
	travelBFS(G,m);
	return 0;
}

ELink  *insertEdge(ELink *head, int avex)
{
    ELink *e,*p;
    e =(ELink *)malloc(sizeof(ELink));
    e->adjvex= avex;
	e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    for(p=head; p->next != NULL; p=p->next)
        ;
    p->next = e;  
    return head;
}

void  travelDFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i]&&!G[i].vertex ) DFS(G, i);
    printf("\n");
	memset(Visited,0,sizeof(Visited));
}

void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1;
    printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adjvex]&&!G[p->adjvex].vertex )
             DFS(G, p->adjvex);
}

void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点已入队
    Queue[rear]=v;
    rear=(rear+1)%105;
    while(front!=rear){
         v = Queue[front];  //取出队头元素
         printf("%d ",v);
         front=(front+1)%105;
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->adjvex]&&!G[p->adjvex].vertex ) {
                    Visited[p->adjvex] = 1; //标识某顶点入队
                    Queue[rear]=p->adjvex;
                    rear=(rear+1)%105;
           }
     }
}

void  travelBFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i]&&!G[i].vertex ) BFS(G, i);
    printf("\n");
	memset(Visited,0,sizeof(Visited));
}

int cmp(const void *a,const void *b){
	struct node *c=(struct node *)a;
	struct node *d=(struct node *)b;
	if(c->ver1!=d->ver1) return (c->ver1>d->ver1)?1:-1;
	else return (c->ver2>d->ver2)?1:-1;
}

