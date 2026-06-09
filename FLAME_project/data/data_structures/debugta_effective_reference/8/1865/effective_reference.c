#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include <ctype.h>
#define MaxVertexNum 1000
#define MaxSize 1000
 
typedef int WeightType;
typedef int Vertex;
typedef int ElementType;
int visited[MaxVertexNum]; /* 顶点的访问标记 */
int Visited_BFS[MaxVertexNum];
 
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
    int data[100];
};
typedef struct GNode *PtrToGNode;
typedef PtrToGNode MGraph;
 
struct ENode{
    Vertex V1,V2;
    WeightType Weight;
};
typedef struct ENode *PtrToENode;
typedef PtrToENode Edge;
 
struct Node{
    ElementType Data;
    struct Node *Next;
};
 
struct QNode{
    struct Node *front;
    struct Node *rear;
};
typedef struct QNode *Queue;
MGraph Graph;
MGraph CreateGraph(int VertexNum);
void InsertEdge(MGraph,Edge E);
MGraph BuildGraph();
void Visit( Vertex V );
void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) );
void BFS ( MGraph Graph, Vertex S, void (*Visit)(Vertex) );
void ListComponents_DFS(MGraph Graph);
void ListComponents_BFS(MGraph Graph);
Queue CreateQueue();
void AddQ(Queue Q,Vertex S);
ElementType DeleteQ(Queue Q);
MGraph Delete(MGraph Graph,int i);
int main(void){
    
    Vertex V;int del;
    Graph=BuildGraph();
    scanf("%d",&del);
    // DFS(Graph,V,Visit);
    ListComponents_DFS(Graph);
    // BFS(Graph,V,Visit);
    ListComponents_BFS(Graph);
    memset(visited,0,sizeof(visited));
    memset(Visited_BFS,0,sizeof(Visited_BFS));
    visited[del]=1;
    Visited_BFS[del]=1;
    //Graph=Delete(Graph,num);
    // DFS(Graph,V,Visit);
    ListComponents_DFS(Graph);
    // BFS(Graph,V,Visit);
    ListComponents_BFS(Graph);
    return 0;
}
/*MGraph初始化*/
MGraph CreateGraph(int VertexNum){
    Vertex V,W;
    MGraph Graph;
    //需加（MGraph）
    Graph=(MGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
 
    for(V=0;V<Graph->Nv;V++)
    {
    	Graph->data[V]=V;
    	for(W=0;W<Graph->Nv;W++)
        Graph->G[V][W]=0; 
	}
       
    
    return Graph;
}
/*MGraph插入边*/
void InsertEdge(MGraph Graph,Edge E){
    Graph->G[E->V1][E->V2]=E->Weight;
    Graph->G[E->V2][E->V1]=E->Weight;
}
/*完整建立MGraph*/
MGraph BuildGraph(){
    MGraph Graph;
    Edge E; Vertex V; int Nv, i;
    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);
    scanf("%d",&(Graph->Ne));
    if(Graph->Ne != 0){
        //需加(Edge)
        E=(Edge)malloc(sizeof(struct ENode));
        for(i=0; i<Graph->Ne; i++){
            scanf("%d %d",&E->V1, &E->V2);
            E->Weight=1;
            InsertEdge(Graph, E);
        }
    }
    for(V=0; V<Graph->Nv; V++){
        Visited_BFS[V]=0;
        visited[V]=0;
    }
    return Graph;
}
/*访问节点*/
void Visit( Vertex V ){
    printf("%d ", Graph->data[V]); 
}
/*DFS连通*/
void ListComponents_DFS(MGraph Graph){
    Vertex i;
    for(i=0; i<Graph->Nv; i++){
        if(!visited[i]){//节点i未被访问过
           // printf("{");
            DFS(Graph, i, Visit);
           // printf(" }");
            
        }
    }printf("\n");
}
/*BFS连通*/
void ListComponents_BFS(MGraph Graph){
    Vertex i;
    for(i=0; i<Graph->Nv; i++){
        if(!Visited_BFS[i]){
           // printf("{");
            BFS(Graph, i, Visit);
            //printf(" }");
           
        }
    } printf("\n");

}
/*
进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。How??
按照"{v1v2...vk}"的格式，每行输出一个连通集。
*/
/*DFS*/
void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex V) ){
    Vertex W;
    visited[V] = 1;
    // printf("{");
    Visit(V);
    for(W = 0; W < Graph->Nv ; W++)
    {
        if(Graph->G[V][W] ==1 && !visited[W])
        {
           DFS(Graph, W, Visit);
        }
    }
    // printf("}");
    return;
}
/*BFS*/
void BFS ( MGraph Graph, Vertex S, void (*Visit)(Vertex) ){
    Queue Q;
    Vertex V,W;
    Q=CreateQueue();//MaxSize
    Visit(S);
    Visited_BFS[S]=1;
    AddQ(Q,S);
 
    while(Q->front!=NULL){
        V=DeleteQ(Q);
        for(W=0; W<Graph->Nv; W++){
            if(Graph->G[V][W]==1 && !Visited_BFS[W]){
                Visit(W);
                Visited_BFS[W]=1;
                AddQ(Q,W);
            }
        }
    }
}
/*建队列，假定为空*/
Queue CreateQueue(){
    Queue Q;
    Q=(Queue)malloc(sizeof(struct QNode));
    Q->front=Q->rear=NULL;
    return Q;
}
/*进队列*/
void AddQ(Queue Q,Vertex S){
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->Data=S;
    temp->Next=NULL;
    if(Q->front==NULL){
        Q->front=temp;
        Q->rear=temp;
    }
    else{
        Q->rear->Next=temp;
        Q->rear=temp;
    }
    // return Q;
}
/*出队列*/
ElementType DeleteQ(Queue Q){
    struct Node *FrontCell;
    ElementType FrontElem;
    if(Q->front==NULL){
        return -1;
    }
    FrontCell=Q->front;
    if(Q->front==Q->rear)
        Q->front=Q->rear=NULL;
    else Q->front=Q->front->Next;
    FrontElem=FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}
MGraph Delete(MGraph Graph,int i)
{
	int t = i;int j,x,y;
	for ( j = t + 1; j <  Graph->Nv; j++)
		Graph->data[t++] = Graph->data[j];
	for ( x = 0; x <Graph->Nv; x++)//删除邻接矩阵中对应的行和列，实质是后一行（列）覆盖原有的值（依次覆盖）
		for ( y = i; y < Graph->Nv; y++)
		{
			if (y == Graph->Nv - 1)
			{
				Graph->G[x][y] = 0;
				Graph->G[y][x] = 0;
			}
			
			Graph->G[x][y] = Graph->G[x][y+1];
			Graph->G[y][x] = Graph->G[y+1][x];
		}
		Graph->Nv--;
		return Graph; 
}

