#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>
#define ll long long
#define MAXSIZE 1000
#define vertype int
#define MaxV    256//最大结点数
typedef struct  edge{ 
       int  adj;
       int  wei;
       struct edge  *next;
}ELink;//边结点
typedef struct ver{
       vertype  vertex;//顶点信息
        ELink *link;
}VLink;//表头结点
VLink  G[MaxV];//表头结点构成的数组
int Front=0,Rear=MAXSIZE-1,Count;
int Q[MAXSIZE];
int  Visited[MaxV]={0}; //标识顶点是否被访问过，N为顶点数
void  travelBFS(VLink  G[ ], int n);
void BFS(VLink  G[ ], int v);
int  deQueue(int queue[ ]);
void enQueue(int queue[ ], int item);
int isEmpty();
int isFull();
void  travelDFS(VLink  G[ ], int n);
void DFS(VLink  G[ ], int v);
void createGraph(VLink graph[]);
ELink  *insertEdge(ELink *head, int avex);
int n,vertex=-1,flag=1;
int main()
{
    ELink *p;
    int i;
    createGraph(G);
    scanf("%d",&vertex);
    travelDFS(G,n);
    printf("\n");
    travelBFS(G,n);
    flag=0;
    printf("\n");
    travelDFS(G,n);
    printf("\n");
    travelBFS(G,n);
    return 0;
}
ELink  *insertEdge(ELink *head, int avex)
{
    ELink  *e,*p;
    e =(ELink *)malloc(sizeof(ELink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL) 
     { 
         head=e; 
         return head; 
    }
    if(e->adj<head->adj)
    {
        e->next=head;
        head=e;
        return head;
    }
    for(p=head; p->next != NULL; p=p->next)
    {
        if(p->next->adj>e->adj)
        {
            e->next=p->next;
             p->next=e;
             break;
        }
    }
    if(p->next==NULL)p->next=e;
    return head;
}
void createGraph(VLink graph[])
{     
  int i,v1,v2,en;
  scanf("%d %d",&n,&en);
  for(i=0; i<en; i++){
    scanf("%d %d",&v1,&v2);
    graph[v1].link=insertEdge(graph[v1].link, v2);
    graph[v2].link=insertEdge(graph[v2].link, v1);
    }
}
void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adj] )
        {
             DFS(G, p->adj);
        }
            
}
void  travelDFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    if(!flag)Visited[vertex]=1;
    for(i=0; i<n; i++)
        if( !Visited[i] )
            DFS(G, i);
}

int isFull()
{
    return Count==MAXSIZE;
}
int isEmpty()
{
    return Count==0;
}
void enQueue(int queue[ ], int item)
{
       if(isFull())                       /* ����������ʧ�� */  
             printf("Full queue!");
       else{
             Rear = (Rear+1) % MAXSIZE; 
             queue[Rear]=item;
             Count++;
       }
 }
int  deQueue(int queue[ ])
{ 
  int e;
       if(isEmpty())
             printf("Empty queue!");     /* �ӿգ�ɾ��ʧ�� */
       else{
             e=queue[Front];
             Count--;                             /* �ӷǿգ�ɾ���ɹ� */
       Front = (Front+1)%MAXSIZE;
       return e;
       }
}
void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while( !isEmpty(Q)){
         v = deQueue(Q);  //取出队头元素
         printf("%d ",v);
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->adj] ) {
                    Visited[p->adj] = 1; //标识某顶点入队
                    enQueue(Q, p->adj);
           }
     }
}
void  travelBFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    if(!flag)Visited[vertex]=1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}

