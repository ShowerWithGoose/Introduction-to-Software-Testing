#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MaxVertexNum 200
int Visited1[100];
int Visited2[100];
int queue[100];
int front=0,rear=0;

typedef struct ENode *PtrToENode;
struct ENode
{
    int V1, V2;
    int Weight;
};
typedef PtrToENode Edge;

typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode
{
    int AdjV;
    int Weight;
    PtrToAdjVNode Next;
};

typedef struct Vnode
{
    PtrToAdjVNode FirstEdge;
    char Data;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode
{  
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph CreateGraph( int VertexNum )
{
    int V;
    LGraph Graph;
    Graph=(LGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
       for (V=0;V<Graph->Nv;V++)
        Graph->G[V].FirstEdge = NULL;
    return Graph; 
}

void InsertEdge( LGraph Graph, Edge E )
{
    PtrToAdjVNode NewNode;
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    int Nv,i;
    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);
    scanf("%d",&(Graph->Ne));
    if (Graph->Ne!=0)
	{ 
        E=(Edge)malloc(sizeof(struct ENode));
        for (i=0; i<Graph->Ne; i++)
		{
            scanf("%d %d",&E->V1,&E->V2);
            E->Weight=1;
            InsertEdge(Graph,E);
        }
    }
    return Graph;
}

//void Visit(int V)
//{
//    printf("%d ",V);
//}

void DFS(LGraph Graph,int V)
{
    PtrToAdjVNode W,P;
    printf("%d ",V);
    Visited1[V]=1;
    for(P=Graph->G[V].FirstEdge;P;P=P->Next)
    {
    	for(W=P->Next;W;W=W->Next)
    	{
    		if(P->AdjV>W->AdjV)
	    	{
	    		int tmp;
	    		tmp=P->AdjV;
	    		P->AdjV=W->AdjV;
	    		W->AdjV=tmp;
			}
		}
	}
	for(W=Graph->G[V].FirstEdge;W;W=W->Next)
        if (Visited1[W->AdjV]==0)
            DFS(Graph,W->AdjV);
}

void BFS(LGraph Graph,int V)
{
	PtrToAdjVNode W,P;
	Visited2[V]=1;
	printf("%d ",V);
	front++;
	for(P=Graph->G[V].FirstEdge;P;P=P->Next)
	{
    	for(W=P->Next;W;W=W->Next)
    	{
    		if(P->AdjV>W->AdjV)
	    	{
	    		int tmp;
	    		tmp=P->AdjV;
	    		P->AdjV=W->AdjV;
	    		W->AdjV=tmp;
			}
		}
	}
//	printf("--!--");
	for(P=Graph->G[V].FirstEdge;P;P=P->Next)
	{
		queue[++rear]=P->AdjV;
	}
//	printf("--?--");
//	for(int i=front,j=rear;i<=j;i++)
//	{
//		printf("%d ",queue[i]);
//	}
	while(Visited2[queue[front]]==1&&front<=rear)
	{
		front++;
	}
//	printf("--$--");
	if(front<=rear)
	{
		BFS(Graph,queue[front]);
	}
}

int main()
{
	int alt;
	LGraph G;
	G=BuildGraph();
	scanf("%d",&alt);
	DFS(G,0);
	printf("\n");
	BFS(G,0);
	printf("\n");
	for(int i=0;i<100;i++)
	{
		Visited1[i]=0;
		Visited2[i]=0;
	}
	Visited1[alt]=1;
	Visited2[alt]=1;
	front=0;
	rear=0;
	DFS(G,0);
	printf("\n");
	BFS(G,0);
	printf("\n");
	return 0; 
} 



