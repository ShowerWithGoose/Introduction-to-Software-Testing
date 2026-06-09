#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define MaxV    120
typedef struct edge{ 
       int  adjvex;
       struct edge * next;
}Elink;
typedef struct ver{
       Elink * link;
}Vlink;
Vlink  g[MaxV];

int  Visited[MaxV]={0}; //标识顶点是否被访问过，N为顶点数
int q[MaxV];
int front=0,rear=-1,count=0;
void enQueue(int v){
	q[++rear]=v;
	count++;
	return;
}
int deQueue(){
	count--;
	return q[front++];
}

void  travelDFS(Vlink  G[ ], int n,int del);

void DFS(Vlink  G[ ], int v);


void  travelBFS(Vlink  G[ ], int n,int del);

void BFS(Vlink  G[ ], int v);

Elink  *insertEdge(Elink *head, int avex)
{
    Elink *e,*p,*q;
    e =(Elink *)malloc(sizeof(Elink));
    e->adjvex= avex;  e->next = NULL;
    if(head == NULL)  { return e; }
    for(p=q=head;p!= NULL&&avex>=p->adjvex; q=p,p=p->next);
    if(p==head){e->next=head;return e;	}
	else {
		e->next=p;
		q->next=e;
	}
    return head;
}

int main(int argc, char *argv[]) {
	int  nv,ne,i,v1,v2,del;
  	scanf("%d%d",&nv,&ne);
  	for(i=0; i<ne; i++){
    scanf("%d %d",&v1,&v2);
      g[v1].link=insertEdge(g[v1].link, v2);
      g[v2].link=insertEdge(g[v2].link, v1);
	}
	travelDFS(g, nv,nv+1);
	puts("");
	travelBFS(g, nv,nv+1);
	puts("");
	scanf("%d",&del);
	travelDFS(g, nv,del);
	puts("");
	travelBFS(g, nv,del);
	puts("");
  
		return 0;
}
void  travelDFS(Vlink  G[ ], int n,int del)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    Visited[del]=1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
}
void DFS(Vlink  G[ ], int v)
{
    Elink  *p;
    Visited[v] = 1; 	//标识某顶点被访问过
    printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adjvex] )
             DFS(G, p->adjvex);
}

void  travelBFS(Vlink  G[ ], int n,int del)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    Visited[del]=1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}
void BFS(Vlink  G[ ], int v)
{
    Elink  *p;
   printf("%d ",v);
    Visited[v] = 1; //标识某顶点被访问过
    enQueue(v);         // 入口的第一个顶点入队
    while(count!=0){  //  循环，直到队空为止 
         v = deQueue();  //取出队头元素
         p = G[v].link;         //获取该顶点第一个邻接顶点
         for(; p != NULL ; p = p->next ) //访问该顶点下的每个邻接顶点
             if( !Visited[p->adjvex] ) {
                    printf("%d ",p->adjvex);
                    Visited[p->adjvex] = 1; //标识某顶点被访问过
                    enQueue(p->adjvex); //邻接顶点依次分别入队
           }
     }
}

