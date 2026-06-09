#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxV    256
typedef struct  edge{ 
       int  adj;
       int  wei;
       struct edge  *next;
}Elink;
typedef struct ver{
       Elink  *link;
}Vlink;
Vlink  graph[MaxV];
Elink  *insertEdge(Elink *head, int avex);
int  Visited[MaxV]={0}; //标识顶点是否被访问过，N为顶点数
void  travelDFS(Vlink  G[ ], int line);
void DFS(Vlink  G[ ], int v);
void  travelBFS(Vlink  G[ ], int line);
void deleteG(int );
void BFS(Vlink  G[ ], int v);
int Q[100];
int count=0,front=0,tie=99;
void enQueue(int *Q,int line);
int emptyQ();
int deQueue(int *Q);
int N;
int main(){
	int v1,v2,line;	
	scanf("%d%d",&N,&line);
	    while((scanf("%d %d",&v1,&v2))==2){
	  // while(1){	   
	  // scanf("%d %d",&v1,&v2);
	   if(v1==3&&v2==3){
	   	break;
	   }   
	      graph[v1].link=insertEdge(graph[v1].link, v2);
	      graph[v2].link=insertEdge(graph[v2].link, v1);
	    }
	    travelDFS(graph,N);
	    printf("\n");
	    travelBFS(graph,N);
	    printf("\n");
	    deleteG(v1);
	    travelDFS(graph,N);
	    printf("\n");
	    travelBFS(graph,N);
		printf("\n");
	  return 0;
}
Elink  *insertEdge(Elink *head, int avex)
{
    Elink *e,*p,*p0;
    e =(Elink *)malloc(sizeof(Elink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    if(head->adj>avex){
		e->next=head;
		head=e;
		return head;
	}
    for(p=head; p->next != NULL;p0=p, p=p->next){
		if(avex<p->adj){
			e->next=p;
			p0->next=e;
			return head;
		}
	}
       if(avex<p->adj){
			e->next=p;
			p0->next=e;
			return head;
		}
		else
       p->next = e;  
    return head;
}
void deleteG(int v){
	Elink *e,*e0;
	graph[v].link=NULL;
	for(int i=0;i<N;i++){
		if(i==v){
			continue;
		}
		if(graph[i].link->adj==v){
			graph[i].link=graph[i].link->next;
		}
		for(e=graph[i].link;e!=NULL;e0=e,e=e->next){
			if(e->adj==v){
				e0->next=e->next;
			}
		}		
	}

}

void  travelDFS(Vlink  G[ ], int line)
{
    int i;
    for(i=0; i<line; i++) {
	    	if(G[i].link==NULL){
				Visited[i] = 01;
			}
			else
			Visited[i] = 0 ;}
    for(i=0; i<line; i++)
        if( !Visited[i] )
		 DFS(G, i);
}
void  travelBFS(Vlink  G[ ], int line)
{
    int i;
    for(i=0; i<line; i++) {
    	if(G[i].link==NULL){
			Visited[i] = 01;
		}
		else
		Visited[i] = 0 ;}
    for(i=0; i<line; i++)
        if( !Visited[i] )
		 BFS(G, i);
}
void DFS(Vlink  G[ ], int v)
{
    Elink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adj] )
             DFS(G, p->adj);
}
void BFS(Vlink  G[ ], int v)
{   

    Elink  *p;
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while( emptyQ()){
         v = deQueue(Q);  //取出队头元素
         printf("%d ",v);
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->adj] ) {
                    Visited[p->adj] = 1; //标识某顶点入队
                    enQueue(Q, p->adj);
           }
     }
}
void enQueue(int *Q,int line){
	count++;
	tie=(tie+1)%100;
	Q[tie]=line;
}
int emptyQ(){
	return count;
}
int deQueue(int *Q){
	     int e=Q[front];
	            count--;                             /* 队非空，删除成功 */
	      front = (front+1)%100;
	       return e;
	
}





