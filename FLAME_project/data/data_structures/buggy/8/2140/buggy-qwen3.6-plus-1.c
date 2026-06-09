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
        if (visited[i]==0 && allvertex[i].edges!=NULL) // @@ The condition `allvertex[i].edges!=NULL` is incorrect. An isolated vertex (or the start vertex 0 if it has no edges after deletion, though problem says connected) should still be visited if not visited yet. More importantly, if a vertex is deleted, its edges are NULL, but we rely on `visited` array to skip it. However, the main issue here is that if vertex 0 is the start, it must be visited. The condition `allvertex[i].edges!=NULL` prevents visiting isolated vertices or vertices whose edges were removed. In the context of "deleting" a vertex, we usually mark it as visited in the init function or handle it separately. But looking at the `delete` function, it sets edges to NULL. If we don't visit a vertex because it has no edges, but it wasn't the deleted one, that's fine if it's unreachable. But vertex 0 always has edges in a connected graph with n>=3 unless n=1. Wait, if we delete a vertex, the graph remains connected. The real bug is likely in the BFS/DFS logic regarding the deleted vertex. The `init_depth` and `init_breadth` do not explicitly skip the deleted vertex. They rely on `visited`. But `visited` is reset. The deleted vertex still exists in `allvertex` array, just with `edges=NULL`. If `depth` is called on the deleted vertex, it will print it. We need to ensure the deleted vertex is marked as visited before traversal starts, or skipped. The current code does not do this.
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
        if (!visited[i] &&allvertex[i].edges!=NULL) // @@ Same error as init_depth. It skips vertices with no edges. Also, it doesn't skip the deleted vertex explicitly.
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
                p2->next=allvertex[start].edges; // @@ Error: Should be `allvertex[end].edges`. This links the reverse edge into the wrong list.
                allvertex[start].edges=p2; // @@ Error: Should be `allvertex[end].edges=p2`.
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
    // After deletion, the deleted vertex still exists in the array but has NULL edges.
    // The traversal functions `init_depth` and `init_breadth` iterate from 0 to vertexNum-1.
    // If they encounter the deleted vertex, and it hasn't been visited, they will call depth/breadth on it.
    // Since its edges are NULL, it will just print the vertex itself (in depth) or print and return (in breadth).
    // This is incorrect because the deleted vertex should not appear in the output.
    // We need to mark the deleted vertex as visited before calling the traversal functions after deletion.
    
    // To fix this properly without changing structure too much, we can modify init_depth/init_breadth to accept the deleted vertex
    // or manually mark it visited. Given the constraint "do not change original code structure", let's look closer.
    // Actually, the prompt asks to identify errors. The errors in insertion are critical.
    // The errors in traversal regarding the deleted vertex are also critical.
    
    // Let's look at the `init_depth` again.
    // If I call `init_depth`, it resets visited.
    // Then it loops i from 0.
    // If i == todelete, `allvertex[i].edges` is NULL. So `depth(i)` is NOT called due to the condition `allvertex[i].edges!=NULL`.
    // So the deleted vertex is NOT printed by `depth` directly.
    // HOWEVER, is it reachable from other nodes? No, because `delete` removed all edges pointing to it.
    // So `visited[todelete]` remains 0.
    // Does this matter? Only if the loop tries to start a new traversal from it.
    // The condition `allvertex[i].edges!=NULL` prevents starting traversal from it.
    // So, technically, the deleted vertex won't be printed IF the graph traversal logic is otherwise correct.
    
    // But wait, look at the BFS `breadth` function.
    // It prints `v` immediately.
    // If `init_breadth` calls `breadth(i)`, it prints `i`.
    // The condition `allvertex[i].edges!=NULL` prevents calling `breadth` on the deleted vertex.
    
    // So why is the output wrong?
    // Let's re-examine the insertion bug.
    // Input:
    // 3 3
    // 0 1
    // 1 2
    // 0 2
    // 1
    
    // Insert 0-1:
    // Start=0, End=1.
    // p1 (dest 1) added to 0's list. List 0: 1
    // p2 (dest 0) added to 1's list. List 1: 0
    
    // Insert 1-2:
    // Start=1, End=2.
    // p1 (dest 2) added to 1's list. List 1: 0 -> 2 (sorted: 0, 2)
    // p2 (dest 1) added to 2's list. List 2: 1
    
    // Insert 0-2:
    // Start=0, End=2.
    // p1 (dest 2) added to 0's list. List 0: 1 -> 2 (sorted: 1, 2)
    // p2 (dest 0) added to 2's list.
    // Here is the bug:
    // `p2->next=allvertex[start].edges;` which is `allvertex[0].edges`.
    // `allvertex[start].edges=p2;` which is `allvertex[0].edges=p2`.
    // This corrupts list 0! And list 2 gets nothing or wrong pointer.
    
    // So the adjacency lists are built incorrectly.
    
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