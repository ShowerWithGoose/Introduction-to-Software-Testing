#include <stdio.h> 
#include <string.h>
typedef struct edge{ 
    int adj;
    int wei;
    struct edge *next;
}ELink;
typedef struct ver{
    ELink *link;
}VLink;
VLink G[120];
int V,E; 
ELink *insertEdge(ELink *head, int avex){
   ELink *e,*p,*q=NULL;
   e =(ELink *)malloc(sizeof(ELink));
   e->adj= avex;
   e->wei=1;
   e->next=NULL;
   if(head==NULL) 
   { 
     head=e; 
     return head; 
   }
    for(p=head; p!=NULL&&p->adj<avex;q=p,p=p->next)
    {
    	;
	}
	if(p!=head)
	{
		q->next=e;
        e->next=p;
        return head;
	}else{
		e->next=p;
        return e;
	}
}
void createGraph(VLink graph[])//创建一个图 
{ 
    int v1,v2; 
    int i;
    for(i=0;i<E;i++)
  {
    scanf("%d%d",&v1, &v2);
    graph[v1].link=insertEdge(graph[v1].link, v2);
    graph[v2].link=insertEdge(graph[v2].link, v1);
  }
} 
int visited[120]={0};
void DFS(VLink G[ ], int v)//深度优先 
{
   ELink *p;
   visited[v]=1; //标识某顶点被访问过
   printf("%d ", v);
   for(p=G[v].link; p!=NULL;p=p->next)
   {
   	if(!visited[p->adj])
   {
   	   DFS(G, p->adj);
   }
   }
}
void travelDFS(int s,VLink G[ ], int n)
{
    int i;
    for(i=0;i<n;i++) 
    {
	  visited[i] = 0 ;	
	} 
	if(s>=0)
	{
		visited[s]=1;
	}
    for(i=0;i<n;i++)
    {
    	if(visited[i]==0)
        {
	       DFS(G,i);
        }
	}
	 printf("\n");
    
}
int q[500];
int  front=0, rear=499,cnt=0;
void enQueue(int queue[ ], int item)
{                
    if(cnt!=500)  
	{
		rear = (rear+1)%500;
        queue[rear]=item;
        cnt++;
	 }         
        
}
int  deQueue(int queue[ ])
{
	int e; 
	if(cnt!=0)
	{                
        e=queue[front];
        cnt--;
        front=(front+1)%500;
        return e;
	}
	return 0;
}
void BFS(VLink G[ ], int v)//广度优先 
{
     ELink *p;
     visited[v] = 1; //标识某顶点被访问过
     enQueue(q, v);
     while(cnt!=0){
     v = deQueue(q); //取出队头元素
     printf("%d ",v);
     p = G[v].link; //获取该顶点第一个邻接顶点
     /*访问该顶点的每个邻接顶点*/
     for(; p!=NULL;p=p->next)
     {
     	if(!visited[p->adj] ) 
		 {
         visited[p->adj] = 1; 
         enQueue(q, p->adj);
	     }

   }
  }
}
void travelBFS(int s,VLink G[ ], int n)
{
    int i;
    for(i=0;i<n;i++) 
    {
	  visited[i]=0 ;	
	} 
	if(s>=0)
	{
		visited[s]=1;
	}
    for(i=0;i<n;i++)
    {
    	if(visited[i]==0)
        {
	       BFS(G,i);
        }
	}
	 printf("\n");
    
}
int main()
{
	int z;
	scanf("%d%d",&V,&E);
	createGraph(G);
	travelDFS(-1,G,V);
    travelBFS(-1,G,V);
    scanf("%d",&z);
    travelDFS(z,G,V);
    travelBFS(z,G,V);
    return 0;
}

