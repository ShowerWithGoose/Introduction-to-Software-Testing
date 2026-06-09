#include<stdio.h>
#include<string.h>
#include<malloc.h>
int visit[1005]={0};
typedef struct  edge{ 
       int  adj;
       int wei;
       struct edge *next;
}Elink;
typedef struct ver{
	int adj;
       Elink *link;
}Vlink;
Vlink G[1005];
Vlink graph[1005];

void DFS(Vlink  G[ ], int v)
{
    Elink  *p;
    visit[v] = 1; 
  
    printf("%d ",v);
    for(Elink *p = G[v].link; p !=NULL;  p=p->next)
         if( visit[p->adj]==0)
             DFS(G, p->adj);
}
void  travelDFS(Vlink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) visit[i] = 0 ;
    for(i=0; i<n; i++)
        if(!visit[i]) 
		DFS(G, i);
}
Elink* insertEdge(Elink* head, int avex)
{
    Elink *e,*p,*r=head;
    e =(Elink *)malloc(sizeof(Elink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    for(p=head; p->next != NULL&&p->adj<=avex; )
        {
			r=p;
			p=p->next;
		}
    
    if(p->adj>avex){
    	e->next=r->next;
		r->next=e;
	}
	else{
		p->next=e;
	}
    return head;
}
void createGraph(Vlink graph[]){ 
  int i,v1,v2,m;
  scanf("%d",&m);
  for(i=0; i<m; i++){
    scanf("%d %d",&v1,&v2);
      graph[v1].link=insertEdge(graph[v1].link, v2);
      graph[v2].link=insertEdge(graph[v2].link, v1);
    
  }
} 
int Q[1005];
int he=0,ta=-1;
void enQueue(int Q[],int v){
	Q[++ta]=v;
}
int emptyQ(){
	if(he<=ta)
	return 0;
	return 1;
}
int deQueue(int Q[]){
	return Q[he++];
}
void  travelBFS(Vlink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) 
	visit[i] = 0 ;
    BFS(G, 0);
}
void BFS(Vlink  G[ ], int v)
{
    Elink  *p;
    visit[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while( !emptyQ(Q)){
         v = deQueue(Q);  //取出队头元素
        
         printf("%d ",v);
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !visit[p->adj] ) {
                    visit[p->adj] = 1; //标识某顶点入队
                    enQueue(Q, p->adj);
           }
     }}


int main(){
	int n,del;
	scanf("%d",&n);
	createGraph(graph);
	scanf("%d",&del);
	travelDFS(graph,n);
	printf("\n");
	travelBFS(graph,n);
	printf("\n");
	for(int i=0;i<n;i++)
	    {
	        visit[i]=0;
	    }
	    visit[del]=1;
	for(int i=0; i<n; i++)
	        if(!visit[i]) 
	   		DFS(graph, i);
	    
	    printf("\n");
	    for(int i=0;i<n;i++)
	    {
	        visit[i]=0;
	    }
	    visit[del]=1;
	    BFS(graph,0);
	return 0;
	
}



