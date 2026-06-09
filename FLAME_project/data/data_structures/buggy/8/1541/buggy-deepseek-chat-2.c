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
    scanf("%d%d", &m, &n);
    int i;
    int a,b;
    for(i=0;i<m;i++)
    {
        BTNode[i]=(struct node*)malloc(sizeof(struct node));
        BTNode[i]->adjvex=i;
        BTNode[i]->link=NULL;
    }
    for(i=0;i<n;i++)
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
    printf("%d ", G[v]->adjvex);
}
void  travelDFS(struct node* G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    Visited[delate]=1; // @@ [Error: This line marks the deleted vertex as visited before the first traversal (before deletion), causing it to be skipped in the initial DFS and BFS. The visited array should only be set for the deleted vertex after the first two traversals are complete.]
    for(i=0; i<n; i++)
        if( !Visited[i] ) 
        DFS(G, i);
} 
void  travelBFS(struct node*G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    Visited[delate]=1; // @@ [Error: Same issue as in travelDFS; this marks the vertex as visited before the first BFS traversal, causing it to be omitted from the initial output.]
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
        Visited[delate]=1; // @@ [Error: This line incorrectly sets Visited[delate] inside the loop, but it should only be set once. More critically, this function is called after the first two traversals, but the Visited array is reset in travelDFS and travelBFS, so this assignment has no effect. The real issue is that the deletion logic does not actually remove the vertex from the adjacency lists properly; it only removes edges from other vertices' lists but does not mark the vertex itself as deleted in the graph structure (e.g., setting G[delate]->link to NULL or using a separate flag). As a result, the vertex still appears in traversals after deletion.]
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