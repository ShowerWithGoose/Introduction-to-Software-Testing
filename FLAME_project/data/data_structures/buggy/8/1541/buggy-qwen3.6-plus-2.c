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
    printf("%d ", G[v]->adjvex); // @@ This prints the vertex label stored in the head node. For vertex v, G[v]->adjvex is v. This is correct for printing the current vertex.
}
void  travelDFS(struct node* G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    Visited[delate]=1; // @@ This marks the deleted vertex as visited before traversal starts, effectively skipping it. This is a valid strategy for "deletion" if the graph structure isn't modified, but Delate function also modifies links. Mixing both might cause issues if not careful, but marking visited is safer. However, the problem requires outputting sequences BEFORE deletion first. The global `delate` is uninitialized during the first call to travelDFS in main.
    for(i=0; i<n; i++)
        if( !Visited[i] ) 
        DFS(G, i);
} 
void  travelBFS(struct node*G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    Visited[delate]=1; // @@ Same issue: `delate` is uninitialized during the first BFS call in main. It contains garbage or 0. If it's 0, vertex 0 is skipped, causing wrong output. If it's garbage, it might crash or skip random vertex.
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
        Visited[delate]=1; // @@ This line is unnecessary and potentially harmful if Visited is used elsewhere, but here it just sets a flag. The main logic is removing edges.
        struct node *p=G[i]->link;
        struct node *q=G[i];
        while(p!=NULL)
        {
            if(p->adjvex==delate)
            {
                q->link=p->link;
                break; // @@ This only removes the FIRST occurrence of the edge to `delate`. If there were multiple edges (not possible in simple graph) or if the list wasn't sorted, it might miss others. But more importantly, it doesn't free the memory, which is fine for competitive programming. However, the logic `q->link=p->link` skips `p`. If `p` is the first node, `q` is head, so `G[i]->link` becomes `p->link`. This is correct for singly linked list removal.
            }
            p=p->link;
            q=q->link;
        }
    }
}