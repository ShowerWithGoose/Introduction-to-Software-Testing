#include<stdio.h>
#include<stdlib.h>
#define VMAXSIZE 108//顶点个数不超过 
#define EMAXSIZE 9999//边节点个数不超过 
typedef struct Edge{
	int eno;//边的序号
	int adjvex;//邻接顶点 
	int  weight;//边的权重
	struct node *next;
}edge,*pedge;//边节点 
typedef struct Ver{
	pedge link;
}ver,*pver;//顶点节点 
int cnt_edge;//边的个数 
int cnt_ver;//顶点个数 
int cnt_way;
int Dver;
int rear,front;
int way[VMAXSIZE];
int queue[VMAXSIZE];
int visited[VMAXSIZE];//标志顶点是否被访问 
edge E[EMAXSIZE];
ver G[VMAXSIZE];
int graph[VMAXSIZE][VMAXSIZE];

pedge insertEdge(pedge head,int avex);
void travelDFS(ver G_travelDFS[],int cnt_travelDFS);
void DFS(ver G_DFS[],int v_DFS);
void VISIT(ver G_v[],int v_v);
void deleteGraph(ver G_d[],int v_delete);
void travelBFS(ver G_travelBFS[],int v_travelDFS);
int main()
{
	int i,j,k;
	int g,e;
	scanf("%d%d",&cnt_ver,&cnt_edge);
	for(i=0;i<cnt_edge;i++){
		scanf("%d%d",&g,&e);
		graph[g][e]=graph[e][g]=1;
		G[g].link=insertEdge(G[g].link,e);
	}
	scanf("%d",&Dver);
	
	for(i=0;i<cnt_ver;i++)visited[i]=0;
	travelDFS(G,cnt_ver);
	for(i=0;i<cnt_ver;i++)printf("%d ",way[i]);
	putchar('\n');
	
	for(i=0;i<cnt_ver;i++)visited[i]=0;
	travelBFS(G,cnt_ver);
	for(i=0;i<cnt_ver;i++)printf("%d ",queue[i]);
	putchar('\n');
//	deleteGraph(G,Dver);
	cnt_way=0;
	for(i=0;i<cnt_ver;i++)visited[i]=0;
	visited[Dver]=1;
	travelDFS(G,cnt_ver);
	for(i=0;i<cnt_ver-1;i++)printf("%d ",way[i]);
	putchar('\n');
	
	rear=front=0;
	for(i=0;i<cnt_ver;i++)visited[i]=0;
	visited[Dver]=1;
	travelBFS(G,cnt_ver);
	for(i=0;i<cnt_ver-1;i++)printf("%d ",queue[i]);
	putchar('\n');
	return 0;
	
} 
pedge insertEdge(pedge head,int avex)
{
	pedge p_insertEdge,a_insertEdge;
	p_insertEdge=(pedge)malloc(sizeof(edge));
	p_insertEdge->adjvex=avex;
	p_insertEdge->next=NULL;
	if(head==NULL){
		head=p_insertEdge;
		return head;
	}
	a_insertEdge=head;
	while(a_insertEdge->next!=NULL)a_insertEdge=a_insertEdge->next;
	a_insertEdge->next=p_insertEdge;
	return head;
} 
void travelDFS(ver G_travelDFS[],int cnt_travelDFS)//开始dfs 
{
	int i_travelDFS;
	for(i_travelDFS=0;i_travelDFS<cnt_travelDFS;i_travelDFS++)way[i_travelDFS]=0;
	for(i_travelDFS=0;i_travelDFS<cnt_travelDFS;i_travelDFS++){
		if(!visited[i_travelDFS])DFS(G_travelDFS,i_travelDFS);
	}
	
	return;
}
void DFS(ver G_DFS[],int v_DFS)//访问某一个节点 
{
	int i_DFS;
	pedge p_DFS;
	visited[v_DFS]=1;
	VISIT(G_DFS,v_DFS);
	p_DFS=G_DFS[v_DFS].link;
	for(i_DFS=0;i_DFS<cnt_ver;i_DFS++){ 
		if(graph[v_DFS][i_DFS]&&!visited[i_DFS])DFS(G_DFS,i_DFS);
	}
	return;
}
void VISIT(ver G_v[],int v_v)
{
	way[cnt_way++]=v_v;
	return;
}
void deleteGraph(ver G_d[],int v_deleteGraph)
{
	int i_deleteGraph;
	pedge p_deleteGraph=G_d[v_deleteGraph].link,a_deleteGraph,q_deleteGraph;
	for(i_deleteGraph=v_deleteGraph+1;v_deleteGraph<cnt_ver+1;i_deleteGraph++){
		G[i_deleteGraph-1].link=G[i_deleteGraph].link;
	}
	while(p_deleteGraph!=NULL){
		a_deleteGraph=p_deleteGraph;
		p_deleteGraph=p_deleteGraph->next;
		free(a_deleteGraph);
	}
	
	for(i_deleteGraph=0;i_deleteGraph<cnt_ver;i_deleteGraph++){
		p_deleteGraph=G[i_deleteGraph].link;
		while(p_deleteGraph!=NULL){
			if(p_deleteGraph->adjvex==Dver){
				if(G[i_deleteGraph].link==p_deleteGraph)G[i_deleteGraph].link=p_deleteGraph->next;
				else q_deleteGraph->next=q_deleteGraph->next;
				a_deleteGraph=p_deleteGraph;
				p_deleteGraph=p_deleteGraph->next;
				free(a_deleteGraph);
			}
			else{
				q_deleteGraph=p_deleteGraph;
				p_deleteGraph=p_deleteGraph->next;
			}
		}
	}
	
	return;
}
void travelBFS(ver G_travelBFS[],int v_travelDFS)
{
	int i_travelBFS;
	for(i_travelBFS=0;i_travelBFS<cnt_ver;i_travelBFS++)way[i_travelBFS]=0;
	for(i_travelBFS=0;i_travelBFS<cnt_ver;i_travelBFS++){
		if(!visited[i_travelBFS])BFS(G_travelBFS,i_travelBFS);
	}
	
	
	return;
}
void BFS(ver G_BFS[],int v_BFS)
{
	int i_BFS;
	pedge p_BFS;
	visited[v_BFS]=1;
	queue[rear++]=v_BFS;
	while(front!=rear){
		v_BFS=queue[front++];
		VISIT(G_BFS,v_BFS);
		for(i_BFS=0;i_BFS<cnt_ver;i_BFS++){
			if(graph[v_BFS][i_BFS]&&!visited[i_BFS]){
				visited[i_BFS]=1;
				queue[rear++]=i_BFS;
			}
		}
	}
	
	return;
}

