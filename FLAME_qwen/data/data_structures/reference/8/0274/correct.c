#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct edge{
    int adjvex;
    struct edge *next;
}Elink;//定义边节点类型
typedef struct ver{
    int vertex;
    Elink *link;
}Vlink;//定义顶点节点类型
Vlink graph[100];
int Graph[100][100];
int Visited[100];//标识顶点是否被访问
Elink *insertEdge(Elink *head,int avex){
    Elink *e,*p;
    e=(Elink *)malloc(sizeof(Elink));
    e->adjvex=avex;
    e->next=NULL;
    if(head==NULL){
        head=e;
        return head;
    }
    for(p=head;p->next!=NULL;p=p->next);
    p->next=e;
    return head;
}
void createGraph(Vlink G[],int n){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<Visited[i];j++)
            G[i].link=insertEdge(G[i].link,Graph[i][j]);
}
void reset(int visited[],int n){
    for(int i=0;i<n;i++)
        visited[i]=0;
}
void DFS(Vlink G[],int v){
    Elink *p;
	Visited[v]=1;
	printf("%d ",v);
	for(p=G[v].link;p!=NULL;p=p->next ){
		if(Visited[p->adjvex]==0){
			DFS(G,p->adjvex);
		}
	}	
}
void travelDFS(Vlink G[],int n){
	int i;
	for(i=0;i<n;i++){
		if(Visited[i]==0){
			DFS(G,i);
		}
	}
}
int Queue[100];
int front=0,rear=-1,count=0;
void BFS(Vlink G[],int v){
    Elink *p;
    printf("%d ",v);
    Visited[v]=1;
    Queue[++rear]=v;
	count++;
    while(count>=0){
        v=Queue[front++];
        count--;
        p=G[v].link;
        for(;p!=NULL;p=p->next){
            if(Visited[p->adjvex]!=1){
                printf("%d ",p->adjvex);
                Visited[p->adjvex]=1;
                Queue[++rear]=p->adjvex;
                count++;
            }
        }
    }
}
void travelBFS(Vlink G[],int n){
    int i;
    front=0,rear=-1,count=0;
    for(i=0;i<n;i++){
		if(Visited[i]==0){
			BFS(G,i);
		}
	}
}
int cmp(const void *p1,const void *p2){
    int *a=(int *)p1;
    int *b=(int *)p2;
    return *a-*b;
}
int main(){
    int number,edge,del;
    int i,a,b;
    scanf("%d%d",&number,&edge);
    reset(Visited,number);
    for(i=0;i<edge;i++){
        scanf("%d%d",&a,&b);
        Graph[a][Visited[a]++]=b;
        Graph[b][Visited[b]++]=a;
    }
    for(i=0;i<number;i++)
        qsort(Graph[i],Visited[i],sizeof(Graph[0][0]),cmp);
    createGraph(graph,number);

    reset(Visited,number);
    travelDFS(graph,number);
    printf("\n");

    reset(Visited,number);
    travelBFS(graph,number);
    printf("\n");

    scanf("%d",&del);
    reset(Visited,number);
    Visited[del]=1;
    travelDFS(graph,number);
    printf("\n");

    reset(Visited,number);
    Visited[del]=1;
    travelBFS(graph,number);
    return 0;
}
