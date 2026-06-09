#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
    int adjvex;
    struct node* link;
};
int  Visited[105]={0}; 
void DFS(struct node* G[ ], int v);
void VISIT(struct node *G[],int v);
void  travelDFS(struct node* G[ ], int n);
void insert(int,int);
struct node *BTNode[105];
void  travelBFS(struct node* G[ ], int n);
int queue[105];
void BFS(struct node*G[ ], int v);
int empty();
int rear=-1;
int front=0;
int count=0;
int delate;
void Delate(int delate,struct node* G[],int m);
int main()
{
    int m,n;
    scanf("%d%d", &m, &n); // @@ The input format is "number of vertices n and number of edges m", but the variable names are swapped here. 'm' reads vertices count, 'n' reads edges count. This causes the loop bounds to be incorrect.
    int i;
    int a,b;
    for(i=0;i<m;i++) // @@ Since m holds the number of vertices (due to swap above), this loop initializes adjacency list heads for vertices. This part is logically okay if m is vertices, but the variable naming is confusing. However, the next loop uses n for edges.
    {
        BTNode[i]=(struct node*)malloc(sizeof(struct node));
        BTNode[i]->adjvex=i;
        BTNode[i]->link=NULL;
    }
    for(i=0;i<n;i++) // @@ Since n holds the number of edges (due to swap above), this loop reads edges. This is consistent with the swap error in scanf.
    {
        scanf("%d%d", &a, &b);
        insert(a,b);
        insert(b,a);
    }
    travelDFS(BTNode, m);
    printf("\n");
    travelBFS(BTNode, m);
    scanf("%d",&delate);
    Delate(delate,BTNode,m);
 rear=-1;
 front=0;
 count=0;
 printf("\n");
    travelDFS(BTNode, m);
    printf("\n");
    travelBFS(BTNode, m);
    return 0;
}
void insert(int a,int b){
    struct node* p;
    p=(struct node *)malloc(sizeof(struct node));
    p->adjvex=b;
    p->link=NULL;
    if(BTNode[a]->link==NULL)
    {
        BTNode[a]->link=p;
    }
    else{
        struct node *q,*k;
        k=BTNode[a];
        q=BTNode[a]->link;
        while((q!=NULL)&&(q->adjvex<b))
        {
            q=q->link;
            k=k->link;
        }
        if(q==NULL)
        k->link=p;
        else{
            k->link=p;
            p->link=q;
    }
    }
return ;
}
void DFS(struct node* G[ ], int v)
{
    struct node *p;
    Visited[v] = 1; //标识某顶点被访问过
    VISIT(G, v); //访问某顶点
    for(p = G[v]->link; p !=NULL;  p=p->link)
         if( !Visited[p->adjvex] )
             DFS(G, p->adjvex);
}
void VISIT(struct node *G[],int v)
{
    printf("%d ", G[v]->adjvex); // @@ This prints the vertex label stored in the head node of the adjacency list. For vertex v, G[v]->adjvex is v. This is correct for printing the current vertex.
}
void  travelDFS(struct node* G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    Visited[delate]=1; // @@ The global variable 'delate' is used here. Before the deletion vertex is read from input, 'delate' is uninitialized (or 0). This causes vertex 0 to be marked as visited initially, preventing it from being printed in the first traversal. It should only be marked after reading the input.
    for(i=0; i<n; i++)
        if( !Visited[i] ) 
        DFS(G, i);
} 
void  travelBFS(struct node*G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    Visited[delate]=1; // @@ Same error as in travelDFS. 'delate' is not yet set correctly during the first call, causing vertex 0 (default value) to be skipped.
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}
void BFS(struct node*G[ ], int v)
{
    struct node*p;
    Visited[v] = 1; //标识某顶点已入队
    rear++;
    queue[rear]=G[v]->adjvex;
    count++;
    while( !empty()){
         v = queue[front];
         front++;
         count--;  //取出队头元素
         VISIT(G, v); //访问当前顶点
         for(p=G[v]->link; p!=NULL; p=p->link ) //访问该顶点的每个邻接顶点
             if( !Visited[p->adjvex] ) {
                    Visited[p->adjvex] = 1; //标识某顶点入队
                rear++;
                queue[rear]=p->adjvex;
                count++;
           }
     }
}
int empty()
{
    return count==0;
}
void Delate(int delate,struct node* G[],int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        Visited[delate]=1; // @@ This line is unnecessary inside Delate and potentially harmful if Visited is used elsewhere, but primarily it's just redundant logic for deletion. The main issue is that it doesn't actually remove the vertex from the graph structure effectively for traversal if the traversal checks Visited. However, the traversal functions DO check Visited[delate]=1. So this marks the deleted vertex as visited. But wait, the traversal functions reset Visited array. So setting Visited[delate]=1 here has no effect on subsequent traversals because travelDFS/travelBFS reset Visited. The deletion logic below removes edges TO the deleted vertex. But what about edges FROM the deleted vertex? The traversal starts from 0. If 0 is connected to delate, the edge 0->delate is removed by this loop when i=0. But the edge delate->0 is NOT removed from G[delate]'s list. Since we never start traversal from delate (it's marked visited or skipped), this might be okay. HOWEVER, the critical bug is that the traversal functions rely on `Visited[delate]=1` being set BEFORE the loop. In `travelDFS`, `Visited` is reset to 0, then `Visited[delate]=1` is set. This works IF `delate` has the correct value. The problem is `delate` is global and uninitialized during the FIRST calls.
        struct node *p=G[i]->link;
        struct node *q=G[i];
        while(p!=NULL)
        {
            if(p->adjvex==delate)
            {
                q->link=p->link;
                break;
            }
            p=p->link;
            q=q->link;
        }
    }
}