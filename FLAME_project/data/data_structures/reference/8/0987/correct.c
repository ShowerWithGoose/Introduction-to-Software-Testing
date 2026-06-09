#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct edge{
	int adjvex;
	struct edge *next;
}ELink;

typedef struct ver{
	int vertex;
	ELink *link;
}VLink;

struct node{
	int ver1;
	int ver2;
}Ver[105];

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
	int ver,edge,i,v1,v2,del;
	scanf("%d%d",&ver,&edge);
	for(i=0;i<edge;i++){
		scanf("%d%d",&v1,&v2);
		Ver[i].ver1=(v1<v2)?v1:v2;
		Ver[i].ver2=(v1>v2)?v1:v2;
	}
	qsort(Ver,edge,sizeof(struct node),cmp);
	for(i=0;i<edge;i++){
		G[Ver[i].ver1].link=insertEdge(G[Ver[i].ver1].link,Ver[i].ver2);
		G[Ver[i].ver2].link=insertEdge(G[Ver[i].ver2].link,Ver[i].ver1);
	}
	scanf("%d",&del);
	travelDFS(G,ver);
	travelBFS(G,ver);
	G[del].vertex=1;
	travelDFS(G,ver);
	travelBFS(G,ver);
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

