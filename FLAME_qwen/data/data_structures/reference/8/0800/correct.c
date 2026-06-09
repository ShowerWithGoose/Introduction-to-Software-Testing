#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define Max   256
 int flag;
typedef struct  edge{ 
       int number;
       struct edge  *next;
}ELink;
typedef struct ver{
	   int number;
       ELink *link;
}VLink;
VLink  G[Max];

//在链表尾插入一个节点
ELink  *insertEdge(ELink *head, int avex)
{
    ELink *e,*p;
    e =(ELink *)malloc(sizeof(ELink));
    e->number= avex;  e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    for(p=head; p->next != NULL; p=p->next)
        ;
    p->next = e;  
    return head;
}




int  Visited[Max]={0}; //标识顶点是否被访问过，N为顶点数
void  travelDFS1(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
}
void  travelDFS2(VLink  G[ ], int n)
{    

    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    Visited[flag]=1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
}

int DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    VISIT(G, v); //访问某顶点
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->number] )
             DFS(G, p->number);
}

int VISIT(VLink G[],int v){
	printf("%d ",v );
}
int num[256];
int cmp(const void *a,const void *b  ){
	int *p,*q;
	p=(int *)a;
	q=(int *)b;
	if(*p>*q) return 1;
	else return -1;
}

void  travelBFS1(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}
void  travelBFS2(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    Visited[flag]=1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}
int Q[256];
int front=0;
int rear=255;
int count=0;
int isempty(){
	return count==0;
}
int enQueue(int Q[],int item){
	rear=(rear+1)%256;
	Q[rear]=item;
	count++;
}
int deQueue(int Q[]){
	int e;
	e=Q[front];
	count--;
	front=(front+1)%256;
	return e;
}
int BFS(VLink G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q,v);
    while( !isempty()){
         v = deQueue(Q);  //取出队头元素
         VISIT(G, v); //访问当前顶点
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->number ] ) {
                    Visited[p->number] = 1; //标识某顶点入队
                    enQueue(Q,p->number);
           }
     }
}







int main(){
	int dian,bian;
	scanf("%d %d",&dian,&bian);
	int n=bian;
	int v1,v2;
 while(bian--)	{
 	scanf(" %d%d",&v1,&v2);
    G[v2].link=insertEdge(G[v2].link, v1);
    	G[v1].link=insertEdge(G[v1].link, v2);
 }
 scanf(" %d",&flag);
 
 int i=0,j=0;
 int k=0;
 for(i=0;i<dian;i++){
 	ELink *p,*q;
	 q=p=G[i].link ; 
 	for(j=0;p!=NULL;j++ ) 
 	{  
 		 num[j]=p->number; 
 		 p=p->next; 
	 }
    qsort(num,j,sizeof(num[0]),cmp);
    for(j=0;q!=NULL;j++ ) {
    	q->number=num[j];
    	q=q->next; 
		}
 }
 travelDFS1(G,dian);
 printf("\n");
travelBFS1(G,dian);
 printf("\n");
travelDFS2(G,dian);
 printf("\n");
travelBFS2(G,dian);
	return 0 ;
	
}

