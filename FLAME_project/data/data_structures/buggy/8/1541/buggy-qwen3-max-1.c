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
    scanf("%d%d", &m, &n); // @@ [The input order is wrong: first integer is number of vertices (n), second is edges (m). But code reads into m,n as if m=vertices, n=edges. This causes all subsequent logic to use wrong graph size.]
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
    printf("%d ", G[v]->adjvex); // @@ [This prints the vertex label stored in G[v]->adjvex, which was set to 'i' during initialization. However, after deletion, some nodes may have been removed or relabeled incorrectly. More critically, traversal should print the actual vertex index 'v', not G[v]->adjvex. Because G[v]->adjvex is just the vertex number stored at that array position, but when we call DFS(G, i), 'i' is the vertex index, and we should print 'i' (or 'v'), not G[v]->adjvex. In fact, G[v]->adjvex == v always, so this works before deletion, but becomes problematic if structure is altered. However, the real issue is that during BFS/DFS, we are passing vertex indices (like 0,1,2), and should print those indices directly.]
}
void  travelDFS(struct node* G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    Visited[delate]=1; // @@ [This marks the deleted vertex as visited BEFORE traversal, preventing it from being traversed. However, this only works if the deleted vertex hasn't been physically removed from adjacency lists. But in Delate(), the adjacency lists ARE modified to remove edges to 'delate'. So marking Visited[delate]=1 here is redundant and harmless, BUT the bigger issue is that in the first traversal (before deletion), 'delate' hasn't been read yet! So 'delate' is uninitialized during the first travelDFS/BFS calls, leading to undefined behavior.]
    for(i=0; i<n; i++)
        if( !Visited[i] ) 
        DFS(G, i);
} 
void  travelBFS(struct node*G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    Visited[delate]=1; // @@ [Same issue: 'delate' is uninitialized during first call to travelBFS (before scanf("%d",&delate)), so Visited[delate]=1 writes to random memory location, causing undefined behavior and incorrect traversal.]
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}
void BFS(struct node*G[ ], int v)
{
    struct node*p;
    Visited[v] = 1; //标识某顶点已入队
    rear++;
    queue[rear]=G[v]->adjvex; // @@ [Should store the vertex index 'v', not G[v]->adjvex. Although they are equal initially, consistency and clarity demand using 'v'. More importantly, when retrieving from queue later, 'v = queue[front]' sets v to G[v]->adjvex value, which is correct only if no corruption. But the real bug is elsewhere.]
    count++;
    while( !empty()){
         v = queue[front]; // @@ [Here, 'v' is assigned the value stored in queue, which is G[original_v]->adjvex = original_v. So it's okay, but confusing. However, the critical error is that during BFS, when accessing G[v], if 'v' is the deleted vertex, it might still be in queue? But Visited[delate] was set, so it shouldn't be enqueued. However, the uninitialized 'delate' during first traversal is catastrophic.]
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
        Visited[delate]=1; // @@ [This line inside the loop is unnecessary and misplaced. It should be outside, but more importantly, Visited array is reset in travelDFS/BFS anyway. However, the real issue is that this function correctly removes edges to 'delate' from all adjacency lists, which is good. But note: it does NOT remove the vertex itself from the graph array, which is fine since we use Visited to skip it. However, combined with uninitialized 'delate' in first traversal, this causes major issues.]
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