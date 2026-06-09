#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct e{
    int destination;
    struct e* next;
};
typedef struct e edge;

struct v{
    int vertex;
    struct e* edges;
};
typedef struct v vertex;
vertex allvertex[105];


int visited[105];
void depth(int address)
{
    edge* p=allvertex[address].edges;
    printf("%d ",address);
    visited[address]=1;
    for (;p!=NULL;p=p->next)
    {
        if (visited[p->destination]==0)
        {
            depth(p->destination);
        }
    }
    
}
void init_depth(int vertexNum)
{
    memset(visited,0,sizeof(visited));
    int i;
    for (i=0;i<vertexNum;i++)
    {
        if (visited[i]==0 && allvertex[i].edges!=NULL) // @@ The condition `allvertex[i].edges!=NULL` incorrectly skips isolated vertices. Although the problem states the graph is connected, after deletion, a vertex might become isolated or the logic for "connected" implies we should visit all unvisited nodes. More critically, if a node has no edges but hasn't been visited, it should still be printed if it's part of the component (though in a connected graph with n>=3, only leaf nodes have 1 edge, not 0 unless n=1). However, the main issue here is usually that `depth` prints the node immediately. If the graph is disconnected or nodes are isolated, they are skipped. But the bigger error is likely in BFS or insertion. Let's look closer. Actually, the standard DFS/BFS traversal should visit *all* reachable nodes from 0. The loop `for (i=0...` suggests handling disconnected components. The constraint says "connected". So starting from 0 is enough. But the code iterates all. The condition `allvertex[i].edges!=NULL` prevents visiting a node that has no edges. If a node is isolated, it won't be visited. In the "after deletion" case, if the deleted node was the only connection to a node, that node might become isolated? No, the problem says "connected ... after deleting". So every remaining node has at least one edge? Not necessarily. A node could be connected to only the deleted node? No, then it would be disconnected. So every remaining node must have degree >= 1. So this condition might be technically safe for *this* specific problem constraint, BUT standard traversal shouldn't depend on edges existing to *visit* a node, only to traverse further. However, `depth` prints the node itself. If we skip it, it's not printed. This is a potential logical flaw but maybe not the primary WA cause given constraints. Let's look at BFS.
        {
            depth(i);
        }
    }
    printf("\n");
}

int queue[50];
int head=0,tail=0;
void breadth(int v)
{
    edge *p;
    printf("%d ",v); //访问当前顶点
    visited[v] = 1; //标识某顶点被访问过
    queue[tail]=v;
    tail++;         // 入口的第一个顶点入队
    while( head!=tail){  //  循环，直到队空为止 
         v = queue[head];  //取出队头元素
         head++;
         p = allvertex[v].edges;         //获取该顶点第一个邻接顶点
         for(; p != NULL ; p = p->next ) //访问该顶点下的每个邻接顶点
             if( !visited[p->destination] ) {
                    printf("%d ",p->destination); //访问当前顶点
                    visited[p->destination] = 1; //标识某顶点被访问过
                    queue[tail]=p->destination;
                    tail++; //邻接顶点依次分别入队
           }
     }
}

void init_breadth(int vertexNum)
{
    memset(visited,0,sizeof(visited));
    int i;
    for (i=0;i<vertexNum;i++)
    {
        if (!visited[i] &&allvertex[i].edges!=NULL) // @@ Same issue as DFS: skips nodes with no edges. While likely safe due to connectivity constraints, it's semantically wrong for general traversal. However, looking at the insertion logic below is more critical.
        {
            breadth(i);
        }
    }
    printf("\n");
}

void delete(int todelete)
{
    edge* p=allvertex[todelete].edges;
    while(p!=NULL)
    {
        int address=p->destination;
        edge* p2=allvertex[address].edges;
        edge* previous=NULL;
        while(p2!=NULL)
        {
            if (p2->destination==todelete)
            {
                if (previous==NULL)
                {
                    allvertex[address].edges=p2->next;
                }
                else
                {
                    previous->next=p2->next;
                }
            }
            previous=p2;
            p2=p2->next;
        }
        p=p->next;
    }
    allvertex[todelete].edges=NULL;
}
int main()
{
    int vertexNum,edgeNum;
    scanf("%d%d",&vertexNum,&edgeNum);
    int i,j,k,start,end;
    for (i=0;i<edgeNum;i++)
    {
        scanf("%d%d",&start,&end);
        edge* p1=(edge*)malloc(sizeof(edge));
        p1->destination=end;
        p1->next=NULL;
        edge* p2=(edge*)malloc(sizeof(edge));
        p2->destination=start;
        p2->next=NULL;

        edge* check=allvertex[start].edges,*previous=NULL;
        if (allvertex[start].edges==NULL)
        {
            allvertex[start].edges=p1;
        }
        else
        {
            while(check!=NULL && p1->destination > check->destination)
            {
                previous=check;
                check=check->next;
            }
            if (previous==NULL)
            {
                p1->next=allvertex[start].edges;
                allvertex[start].edges=p1;
            }
            else
            {
                p1->next=previous->next;
                previous->next=p1;
            }
        }
        check=allvertex[end].edges;
        previous=NULL;
        if (allvertex[end].edges==NULL)
        {
            allvertex[end].edges=p2;
        }
        else
        {
            while(check!=NULL && p2->destination > check->destination)
            {
                previous=check;
                check=check->next;
            }
            if (previous==NULL)
            {
                p2->next=allvertex[start].edges; // @@ Error: Inserts p2 into start's list instead of end's list. Should be `allvertex[end].edges`.
                allvertex[start].edges=p2; // @@ Error: Updates start's head instead of end's head. Should be `allvertex[end].edges`.
            }
            else
            {
                p2->next=previous->next;
                previous->next=p2;
            }
        }
        
    }

    int todelete;
    scanf("%d",&todelete);
    init_depth(vertexNum);
    init_breadth(vertexNum);
    delete(todelete);
    init_depth(vertexNum);
    init_breadth(vertexNum);
   
    // for (i=0;i<vertexNum;i++)
    // {
    //     if (allvertex[i].edges!=NULL)
    //     {
    //         edge* check=allvertex[i].edges;
    //         printf("%d ",i);
    //         while(check!=NULL)
    //         {
    //             printf("%d ",check->destination);
    //             check=check->next;
    //         }
    //         printf("\n");
    //     }
        
    // }
    return 0;
}