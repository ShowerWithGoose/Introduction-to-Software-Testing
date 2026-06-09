#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#define MaxV    256
#define ElemType int
typedef struct edge{ //存边 
       int  adj;
       int  wei;
       struct edge *next;
} ELink;
typedef struct ver{//存顶点 
       ELink *link;
} VLink;
VLink G[MaxV];

struct node{
	int V1;
	int V2;
};
struct node td[MaxV];
int cmp(const void*a,const void*b);
ELink  *insertEdge(ELink *head, int avex);
void  travelDFS(VLink  G[ ], int v,int del);
void DFS(VLink  G[ ], int v);
void  travelBFS(VLink  G[ ], int n,int del);
void BFS(VLink  G[ ], int v);
ElemType  deQueue(ElemType queue[ ]);
void enQueue(ElemType queue[ ], ElemType item);
int createGraph(VLink graph[]);
int isEmpty();
int isFull();
int Front = 0;
int Rear = MaxV-1;
int Count = 0; 
int Q[MaxV];
int main()
{
	int del;
	int i;	
	int n;
	n=createGraph(G); 
	scanf("%d",&del);
	travelDFS(G,n,-1);
	printf("\n");
	travelBFS(G,n,-1);
	printf("\n");
	travelDFS(G,n,del);
	printf("\n");
	travelBFS(G,n,del);
 return 0;
}

int createGraph(VLink graph[]){  
  int i,v1,v2;
  int n,e;
  scanf("%d%d",&n,&e);
  for(i=0; i<e; i++){
    scanf("%d %d",&v1,&v2);  
    graph[v1].link=insertEdge(graph[v1].link, v2);
    graph[v2].link=insertEdge(graph[v2].link, v1);   
  }
  return n;
} 

//在链表尾插入一个节点
ELink  *insertEdge(ELink *head, int avex)
{
    ELink *e=NULL,*p=NULL,*q=NULL;
    e =(ELink *)malloc(sizeof(ELink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    for(p=head; p!= NULL && avex > p->adj; q=p,p=p->next)
        ;  
	if(head==p){//插入头结点前 
		e->next=head;
		return e;
	} 
	else{//插入中间
		 e->next=p;
		 q->next=e;
		 return head;
	}
}

/*
ELink  *insertEdge(ELink *head, int avex)
{
    ELink *e,*p;
    e =(ELink *)malloc(sizeof(ELink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    for(p=head; p->next != NULL; p=p->next)
        ;
    p->next = e;  
    return head;
}
*/
int  Visited[MaxV]={0}; //标识顶点是否被访问过，下标为顶点数
void  travelDFS(VLink  G[ ], int v,int del)
{
    int i;
    for(i=0; i<v; i++) Visited[i] = 0 ;
    if(del>=0)
	Visited[del]=1; 
    for(i=0; i<v; i++)
        if( !Visited[i] ) DFS(G, i);
}
void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    //VISIT(G, v); //访问某顶点
    printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adj] )
             DFS(G, p->adj);
}
int cmp(const void* a,const void* b){
	struct node* pa=(struct node*)a;
	struct node* pb=(struct node*)b;
	int num1=pa->V1;
	int num2=pb->V1;
	if(num1!=num2)
	return num1-num2;//sheng
	else{
		int num3=pa->V2;
		int num4=pb->V2;
		return num3-num4;
	}
}
int  Vis[MaxV]={0}; //标识顶点是否被访问守，N为顶点数
void  travelBFS(VLink  G[ ], int n,int del)
{
    int i;
    for(i=0; i<n; i++) Vis[i] = 0 ;
    if(del>=0)
	Vis[del]=1; 
    for(i=0; i<n; i++)
        if( !Vis[i] ) BFS(G, i);
}

void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    Vis[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while( !isEmpty(Q)){
         v = deQueue(Q);  //取出队头元素
        // VISIT(G, v); //访问当前顶点
         printf("%d ",v);
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Vis[p->adj] ) {
                    Vis[p->adj] = 1; //标识某顶点入队
                    enQueue(Q, p->adj);
           }
     }
}

ElemType  deQueue(ElemType queue[ ])
{ 
   ElemType e;
       if(isEmpty())
             printf("Empty queue!");     /* 队空，删除失败 */
       else{
             e=queue[Front];
             Count--;                             /* 队非空，删除成功 */
       Front = (Front+1)%MaxV;
       return e;
       }
}

void enQueue(ElemType queue[ ], ElemType item)
{
       if(isFull())                       /* 队满，插入失败 */  
             printf("Full queue!");
       else{
             Rear = (Rear+1) % MaxV; 
             queue[Rear]=item;
             Count++;
                                             /* 队未满，插入成功 */ 
       }
 }
 int  isEmpty( )
{
        return Count == 0;
}
int  isFull( )
{
        return Count == MaxV;
}


