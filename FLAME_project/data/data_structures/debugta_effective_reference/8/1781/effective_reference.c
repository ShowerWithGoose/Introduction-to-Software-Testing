#include<stdio.h>
#include<stdlib.h>
#define MaxV    100
typedef struct  edge{ 
       int  adj;
       struct edge  *next;
}Elink;

typedef struct ver{
	    Elink  *link;
}Vlink;

int Q[MaxV]={0};
int Q_first=0,Q_last=-1;
int Visited[MaxV]={0}; //标识顶点是否被访问过
int Deleted[MaxV]={0};
//
void  insertEdge(Vlink *head, int avex)
{
    Elink *e,*p;
    e =(Elink *)malloc(sizeof(Elink));
    e->adj= avex; 
	e->next = NULL;
    if(head->link == NULL){
	    head->link=e; 
	}
    else {
    	p=head->link;
		if(e->adj<p->adj){
			e->next=p;
			head->link=e;
		}
		else {
			while(p->next!= NULL&&e->adj>p->next->adj){
				p=p->next;
			} 
            e->next=p->next;
		    p->next = e;  
		}    	
	}     
} 
//
void deleteNode(Vlink G[],int v)
{
	Elink *e,*p,*t;
	Deleted[v]=1;
	while(G[v].link!=NULL){
		e=G[v].link;	
		//
		//printf("\n%d",e->adj);
		p=G[e->adj].link;		
		if(p->adj==v){
			G[e->adj].link=p->next;			
			free(p);
		} 
		else {
		//	printf(" %d",p->adj);
			for(;p->next->adj!=v;p=p->next) ;//printf("-%d",p->next->adj);
		    t=p->next;
		    p->next=t->next;
		    free(t);
		}		
		//
		G[v].link=e->next;
		free(e);
	}
}
//
void DFS(Vlink  G[], int v)
{
    Elink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v); //访问某顶点
    for(p = G[v].link; p!=NULL;  p=p->next)
         if( !Visited[p->adj] )
             DFS(G,p->adj);
}

void  travelDFS(Vlink  G[], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if(!Visited[i]&&!Deleted[i]) DFS(G, i);
}

//
void enQueue(int Q[], int v)
{
	Q[++Q_last]=v;
}
int emptyQ(int Q[])
{
	return Q_first>Q_last;
}
int  deQueue(int Q[])
{
	return Q[Q_first++];
}
//
void BFS(Vlink G[], int v)
{
    Elink  *p;
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while( !emptyQ(Q)){
         v = deQueue(Q);  //取出队头元素
         printf("%d ",v); //访问当前顶点
         for(p=G[v].link; p!=NULL; p=p->next) //访问该顶点的每个邻接顶点
             if( !Visited[p->adj] ) {
                    Visited[p->adj] = 1; //标识某顶点入队
                    enQueue(Q,p->adj);
           }
     }
}
void  travelBFS(Vlink  G[], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if(!Visited[i]&&!Deleted[i]) BFS(G, i);
}
//
int main()
{
	int num_node,num_edge,del_num,v2;
	scanf("%d %d",&num_node,&num_edge);
	Vlink *G=(Vlink *)malloc(sizeof(Vlink)*num_node);
	int i;
	for(i=0;i<num_edge;i++) G[i].link=NULL;
	for(i=0;i<num_edge;i++){
		scanf("%d %d",&del_num,&v2);
		insertEdge(&G[del_num], v2);
        insertEdge(&G[v2], del_num);		
	}
	
//	for(i=0;i<g_len;i++){
//		printf("\n%d:",i);
//		Elink *p=G[i].link;
//		while(p!=NULL){
//			printf(" %d",p->adj);
//			p=p->next;
//		}
//	}
	
	scanf("%d",&del_num);	
	travelDFS(G,num_node);
	printf("\n");
	travelBFS(G,num_node);
		
	deleteNode(G,del_num);
	
	printf("\n");
	travelDFS(G,num_node);
	printf("\n");
	travelBFS(G,num_node);
	
	return 1;
}

