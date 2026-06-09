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
Vlink  Head[MaxV];
Elink  *insertEdge(Elink *head, int avex);
int  Visited[MaxV]={0}; //标识顶点是否被访问过，N为顶点数
void  travelDFS(Vlink  G[ ], int side);
void DFS(Vlink  G[ ], int aim);
void  travelBFS(Vlink  G[ ], int side);
void deleteG(int );
void BFS(Vlink  G[ ], int aim);
int Q[100];
int count=0,front=0,tie=99;
void enQueue(int *Q,int side);
int emptyQ();
int deQueue(int *Q);
int point;
int main(){
	int v1,v2,side;	
	scanf("%d%d",&point,&side);
	    while((scanf("%d %d",&v1,&v2))==2){
	  // while(1){	   
	  // scanf("%d %d",&v1,&v2);
	   if(v1==3&&v2==3){
	   	break;
	   }   
	      Head[v1].link=insertEdge(Head[v1].link, v2);
	      Head[v2].link=insertEdge(Head[v2].link, v1);
	    }
	    travelDFS(Head,point);
	    printf("\n");
	    travelBFS(Head,point);
	    printf("\n");
	    deleteG(v1);
	    travelDFS(Head,point);
	    printf("\n");
	    travelBFS(Head,point);
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
void deleteG(int aim){
	Elink *e,*e0;
	Head[aim].link=NULL;
	for(int i=0;i<point;i++){
		if(i==aim){
			continue;
		}
		if(Head[i].link->adj==aim){
			Head[i].link=Head[i].link->next;
		}
		for(e=Head[i].link;e!=NULL;e0=e,e=e->next){
			if(e->adj==aim){
				e0->next=e->next;
			}
		}		
	}

}

void  travelDFS(Vlink  G[ ], int side)
{
    int i;
    for(i=0; i<side; i++) {
	    	if(G[i].link==NULL){
				Visited[i] = 01;
			}
			else
			Visited[i] = 0 ;}
    for(i=0; i<side; i++)
        if( !Visited[i] )
		 DFS(G, i);
}
void  travelBFS(Vlink  G[ ], int side)
{
    int i;
    for(i=0; i<side; i++) {
    	if(G[i].link==NULL){
			Visited[i] = 01;
		}
		else
		Visited[i] = 0 ;}
    for(i=0; i<side; i++)
        if( !Visited[i] )
		 BFS(G, i);
}
void DFS(Vlink  G[ ], int aim)
{
    Elink  *p;
    Visited[aim] = 1; //标识某顶点被访问过
    printf("%d ",aim);
    for(p = G[aim].link; p !=NULL;  p=p->next)
         if( !Visited[p->adj] )
             DFS(G, p->adj);
}
void BFS(Vlink  G[ ], int aim)
{   

    Elink  *p;
    Visited[aim] = 1; //标识某顶点已入队
    enQueue(Q, aim);
    while( emptyQ()){
         aim = deQueue(Q);  //取出队头元素
         printf("%d ",aim);
         for(p=G[aim].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->adj] ) {
                    Visited[p->adj] = 1; //标识某顶点入队
                    enQueue(Q, p->adj);
           }
     }
}
void enQueue(int *Q,int side){
	count++;
	tie=(tie+1)%100;
	Q[tie]=side;
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





