#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MaxV    150
int nver=0;int nedge=0;int shan=-1;int last=0; 
int dui[MaxV],a2[MaxV],b1[MaxV],b2[MaxV];
int  Visited[MaxV]; //标识顶点是否被访问过
typedef struct edge{ 
       int  adj;
       int  wei;
       struct edge *next;
}ELink;
typedef struct ver{
       ELink  *link;
}VLink;
VLink  G[MaxV];
//在链表内插入一个节点（有序 从小到大） 
ELink *insertEdge(ELink *head, int avex){
    ELink *e,*p,*q=NULL;
    e=(ELink *)malloc(sizeof(ELink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head==NULL)  { head=e; return head; }
    for(p=head;p->next!=NULL&&p->adj<avex;q=p,p=p->next);
    if(p->adj>avex){
    		if(p==head) {e->next=head; return e;}
    		else {e->next=p; q->next=e; return head;}
		}
    else{p->next= e;  return head;}
}
//创建邻接表 
void createGraph(VLink graph[]){ 
  int v1,v2,i;
  scanf("%d%d",&nver,&nedge);
  for(i=0; i<nedge; i++){
    scanf("%d %d",&v1,&v2);
      graph[v1].link=insertEdge(graph[v1].link, v2);
      graph[v2].link=insertEdge(graph[v2].link, v1); 
  }
} 
//深度优先遍历DFS
void DFS(VLink G[],int v,int a[])
{   
  if(v!=shan){
	  ELink  *p;
      Visited[v] = 1; //标识某顶点被访问过
      a[last++]=v;//访问某顶点
      for(p = G[v].link; p!=NULL;  p=p->next)
         if( !Visited[p->adj] )
             DFS(G, p->adj, a);
    }
}
void  travelDFS(VLink G[],int n,int a[])
{
	last=0;
	int i=0;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if(!Visited[i]) DFS(G,i,a);//完成一个连通分量的遍历 
}

//广度优先遍历 BFS
int front=0,rear=0,count=0;
void enqueue(int queue[],int item){
		queue[rear]=item;
		rear=(rear+1)%MaxV;
		count++;
}
int outqueue(int queue[]){
	int item=queue[front];
		count--;
		front=(front+1)%MaxV;
		return item;
}
void BFS(VLink G[],int v,int a[])
{
    ELink *p;
    Visited[v] = 1; //标识某顶点已入队
    enqueue(a,v);
    while(count!=0){
         v=outqueue(a);  //取出队头元素
         a[last++]=v;
         for(p=G[v].link;p!=NULL;p=p->next) //访问该顶点的每个邻接顶点
             if(Visited[p->adj]==0&&p->adj!=shan) {
                    Visited[p->adj]=1; //标识某顶点入队
                    enqueue(a,p->adj);
           }
     }
}
void  travelBFS(VLink G[],int n,int a[])
{
    last=0;
	int i;
    for(i=0;i<n;i++) Visited[i] = 0 ;
    for(i=0;i<n;i++)
        if(!Visited[i]) BFS(G, i, a);
}

int main(){
	createGraph(G);
	travelDFS(G,nver,dui);
	travelBFS(G,nver,a2);
	scanf("%d",&shan);
	travelDFS(G,nver,b1);
	travelBFS(G,nver,b2);
	int i=0;
	for(i=0; i<nver-1; i++) printf("%d ",dui[i]);
    printf("%d\n",dui[i]);
    for(i=0; i<nver-1; i++) printf("%d ",a2[i]);
    printf("%d\n",a2[i]);
    for(i=0; i<nver-2; i++) printf("%d ",b1[i]);
    printf("%d\n",b1[i]);
    for(i=0; i<nver-2; i++) printf("%d ",b2[i]);
    printf("%d\n",b2[i]);
	return 0;
}

