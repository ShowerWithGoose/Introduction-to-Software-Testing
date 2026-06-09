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
Vlink  G[MaxV];
Elink  *insertEdge(Elink *head, int avex);
int  visited[MaxV]={0}; //标识顶点是否被访问过，N为顶点数
void  travelDFS(Vlink  G[ ], int m);
void DFS(Vlink  G[ ], int k);
void  travelBFS(Vlink  G[ ], int m);
void deleteG(int );
void BFS(Vlink  G[ ], int k);
int Q[100];
int count=0,head=0,tie=99;
void enQueue(int *Q,int m);
int emptyQ();
int deQueue(int *Q);
int n;
int main(){
	int v1,v2,m;	
	scanf("%d%d",&n,&m);
	    while((scanf("%d %d",&v1,&v2))==2){
	  // while(1){	   
	  // scanf("%d %d",&v1,&v2);
	   if(v1==3&&v2==3){
	   	break;
	   }   
	      G[v1].link=insertEdge(G[v1].link, v2);
	      G[v2].link=insertEdge(G[v2].link, v1);
	    }
	    travelDFS(G,n);
	    printf("\n");
	    travelBFS(G,n);
	    printf("\n");
	    deleteG(v1);
	    travelDFS(G,n);
	    printf("\n");
	    travelBFS(G,n);
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
void deleteG(int k){
	Elink *e,*e0;
	G[k].link=NULL;
	for(int i=0;i<n;i++){
		if(i==k){
			continue;
		}
		if(G[i].link->adj==k){
			G[i].link=G[i].link->next;
		}
		for(e=G[i].link;e!=NULL;e0=e,e=e->next){
			if(e->adj==k){
				e0->next=e->next;
			}
		}		
	}

}

void  travelDFS(Vlink  G[ ], int m)
{
    int i;
    for(i=0; i<m; i++) {
	    	if(G[i].link==NULL){
				visited[i] = 01;
			}
			else
			visited[i] = 0 ;}
    for(i=0; i<m; i++)
        if( !visited[i] )
		 DFS(G, i);
}
void  travelBFS(Vlink  G[ ], int m)
{
    int i;
    for(i=0; i<m; i++) {
    	if(G[i].link==NULL){
			visited[i] = 01;
		}
		else
		visited[i] = 0 ;}
    for(i=0; i<m; i++)
        if( !visited[i] )
		 BFS(G, i);
}
void DFS(Vlink  G[ ], int k)
{
    Elink  *p;
    visited[k] = 1; //标识某顶点被访问过
    printf("%d ",k);
    for(p = G[k].link; p !=NULL;  p=p->next)
         if( !visited[p->adj] )
             DFS(G, p->adj);
}
void BFS(Vlink  G[ ], int k)
{   

    Elink  *p;
    visited[k] = 1; //标识某顶点已入队
    enQueue(Q, k);
    while( emptyQ()){
         k = deQueue(Q);  //取出队头元素
         printf("%d ",k);
         for(p=G[k].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !visited[p->adj] ) {
                    visited[p->adj] = 1; //标识某顶点入队
                    enQueue(Q, p->adj);
           }
     }
}
void enQueue(int *Q,int m){
	count++;
	tie=(tie+1)%100;
	Q[tie]=m;
}
int emptyQ(){
	return count;
}
int deQueue(int *Q){
	     int e=Q[head];
	            count--;                             /* 队非空，删除成功 */
	      head = (head+1)%100;
	       return e;
	
}





