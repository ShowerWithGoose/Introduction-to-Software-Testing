#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MaxNum 200
int traverse1[100];
int traverse2[100];
int Gquene[100];
int front=0,rear=0;

struct ENode
{
    int Tr1;
    int Tr2;
    int Weight;
};
typedef struct ENode* Edge;

typedef struct AdjVNode *ANodePtr; 
struct AdjVNode
{
    int AdjV;
    int Weight;
    ANodePtr Next;
};

typedef struct Vnode
{
    ANodePtr FirEdge;
    char Data;
} AdjList[MaxNum];

struct GNode
{  
    int vertex;
    int edge;
    AdjList graph;
};
typedef struct GNode* LGraph;
void DFS(LGraph Graph,int V)
{
    ANodePtr p,P;
    printf("%d ",V);
    traverse1[V]=1;
    for(P=Graph->graph[V].FirEdge;P;P=P->Next)
    {
    	for(p=P->Next;p;p=p->Next)
    	{
    		if(P->AdjV>p->AdjV)
	    	{
	    		int tmp;
	    		tmp=P->AdjV;
	    		P->AdjV=p->AdjV;
	    		p->AdjV=tmp;
			}
		}
	}
	for(p=Graph->graph[V].FirEdge;p;p=p->Next)
	{
        if (traverse1[p->AdjV]==0)
		{
            DFS(Graph,p->AdjV);
		}
	}
}

void BFS(LGraph Graph,int V)
{
	ANodePtr p,P;
	traverse2[V]=1;
	printf("%d ",V);
	front++;
	for(P=Graph->graph[V].FirEdge;P;P=P->Next)
	{
    	for(p=P->Next;p;p=p->Next)
    	{
    		if(P->AdjV>p->AdjV)
	    	{
	    		int tmp;
	    		tmp=P->AdjV;
	    		P->AdjV=p->AdjV;
	    		p->AdjV=tmp;
			}
		}
	}
	for(P=Graph->graph[V].FirEdge;P;P=P->Next)
	{
		Gquene[++rear]=P->AdjV;
	}
	while(traverse2[Gquene[front]]==1&&front<=rear)
	{
		front++;
	}
	if(front<=rear)
	{
		BFS(Graph,Gquene[front]);
	}
}
int main()
{
	int deletvertex;
	LGraph graph;
    LGraph Graph;
    Edge E;
    int vertex,i;
    scanf("%d",&vertex);
    int V;
    Graph=(LGraph)malloc(sizeof(struct GNode));
    Graph->vertex=vertex;
    Graph->edge=0;
    for (V=0;V<Graph->vertex;V++)
	{
        Graph->graph[V].FirEdge = NULL;
	}
    scanf("%d",&(Graph->edge));
    if (Graph->edge!=0)
	{ 
        E=(Edge)malloc(sizeof(struct ENode));
        for (i=0; i<Graph->edge; i++)
		{
            scanf("%d %d",&E->Tr1,&E->Tr2);
            E->Weight=1;
		    ANodePtr New_Node;
		    New_Node = (ANodePtr)malloc(sizeof(struct AdjVNode));
		    New_Node->AdjV = E->Tr2;
		    New_Node->Weight = E->Weight;
		    New_Node->Next = Graph->graph[E->Tr1].FirEdge;
		    Graph->graph[E->Tr1].FirEdge = New_Node;
		    New_Node = (ANodePtr)malloc(sizeof(struct AdjVNode));
		    New_Node->AdjV = E->Tr1;
		    New_Node->Weight = E->Weight;
		    New_Node->Next = Graph->graph[E->Tr2].FirEdge;
		    Graph->graph[E->Tr2].FirEdge = New_Node;
        }
    }
    graph=Graph;
	scanf("%d",&deletvertex);
	DFS(graph,0);
	printf("\n");
	BFS(graph,0);
	printf("\n");
	for(int i=0;i<100;i++)
	{
		traverse1[i]=0;
		traverse2[i]=0;
	}
	traverse1[deletvertex]=1;
	traverse2[deletvertex]=1;
	front=0;
	rear=0;
	DFS(graph,0);
	printf("\n");
	BFS(graph,0);
	printf("\n");
	return 0; 
} 

