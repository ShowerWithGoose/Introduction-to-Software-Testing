#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int visit[100];
struct link{
    int vertex;
    struct link *next;
}*Vertex[100];
struct{
    int rear;
    int front;
    struct link *queue[100];
}que;
void DFS(struct link* p)
{
    if(p!=NULL)
    {
    if(visit[p->vertex]==0)
    {
    printf("%d ",p->vertex);
    visit[p->vertex]=1;
    struct link* t;
        t=p->next;
        while(t!=NULL)
        {
            DFS(Vertex[t->vertex]); // @@ The DFS recursion should traverse the adjacency list of the current node's neighbor, but here it incorrectly accesses Vertex[t->vertex] which is the head of the neighbor's list. However, the standard DFS implementation usually passes the neighbor node directly or iterates through the adjacency list. The critical error here is that `DFS` is called on `Vertex[t->vertex]`, which is the head pointer for the adjacency list of vertex `t->vertex`. This effectively restarts DFS from the beginning of that vertex's list, potentially causing issues if not handled correctly with visited flags, but more importantly, the logic `DFS(Vertex[t->vertex])` assumes `Vertex` array holds the start of the list for each vertex. While this might work for traversal if `visit` is checked, the structure of `DFS` here is slightly non-standard. Let's look closer. Actually, the main issue in many such student codes is how deletion affects the structure. But let's look at the output difference.
            // Wait, looking at the provided "Buggy Output" vs "Expected Output":
            // Buggy: 0 1 2 \n 0 1 2 \n 0 2 \n 0 2
            // Expected: 0 1 2 \n 0 1 2 \n 0 2 \n 0 2
            // They are identical except for trailing spaces or newlines?
            // Buggy Output in prompt:
            // 0 1 2 
            // 0 1 2 
            // 0 2 
            // 0 2 
            // Expected Output in prompt:
            // 0 1 2
            // 0 1 2
            // 0 2
            // 0 2
            // The difference is likely trailing spaces. The printf("%d ", ...) adds a space after every number including the last one.
            // Many online judges are strict about trailing spaces.
            // However, the instruction asks to identify logical/semantic errors based on failed test cases.
            // If the only difference is trailing whitespace, the "error" is the format string.
            
            // Let's re-read carefully. "Wrong Answer".
            // Often, trailing spaces are ignored by diff tools unless specified.
            // Is there a logical error?
            
            // Let's look at `deletVertex`.
            // It sets `Vertex[i]=NULL` if `i==goal`.
            // It removes edges pointing to `goal`.
            
            // Let's look at `DFS` again.
            // `DFS(Vertex[0])` starts at vertex 0.
            // Inside `DFS`: `printf("%d ", p->vertex)`. This prints the vertex stored in the link node.
            // Note: The `link` struct stores `vertex` (the neighbor) and `next`.
            // The `Vertex` array stores pointers to the *head* of the adjacency list.
            // The head node itself contains data!
            // In `main`, when creating the list:
            // `p->vertex=vertex1; p->next=q; q->vertex=vertex2; q->next=NULL; Vertex[vertex1]=p;`
            // So the head node `p` has `vertex = vertex1` (the source vertex itself??).
            // And `q` has `vertex = vertex2` (the neighbor).
            // This is a very strange adjacency list implementation.
            // Usually, the head node is a dummy or points to the first neighbor.
            // Here, the head node contains the source vertex ID.
            
            // Let's trace `DFS(Vertex[0])` for vertex 0.
            // `p` is the head node for 0. `p->vertex` is 0.
            // `visit[0]` is 0.
            // Prints "0 ". `visit[0]=1`.
            // `t = p->next` (which is `q`, the node for neighbor 2 or 1 depending on insertion order).
            // Loop `while(t!=NULL)`:
            // `DFS(Vertex[t->vertex])`.
            // If `t->vertex` is 1, it calls `DFS(Vertex[1])`.
            // Inside `DFS(Vertex[1])`:
            // `p` is head node for 1. `p->vertex` is 1.
            // `visit[1]` is 0.
            // Prints "1 ". `visit[1]=1`.
            // `t = p->next`.
            // Recurses on neighbors of 1.
            
            // This logic seems to work for printing the vertex itself when entering its list head.
            
            // Now consider `deletVertex(goal)`.
            // `Vertex[goal] = NULL`.
            // If we call `DFS(Vertex[goal])` later, it passes NULL. `if(p!=NULL)` fails. Returns. Correct.
            
            // What if `goal` is a neighbor?
            // `deletVertex` iterates all `i`.
            // If `i != goal`, it scans `Vertex[i]` list.
            // `t` starts at `Vertex[i]` (the head node).
            // `while(t->next != NULL)`: checks `t->next->vertex == goal`.
            // If found, `t->next = t->next->next`.
            // This removes the node containing `goal` from the adjacency list of `i`.
            
            // However, notice the structure of the list again.
            // Head node: `vertex` = self. `next` -> first neighbor.
            // Neighbor node: `vertex` = neighbor ID. `next` -> next neighbor.
            
            // In `DFS`, when we are at node `u` (head node for u), we print `u`.
            // Then we iterate `t = p->next` (first neighbor).
            // We call `DFS(Vertex[t->vertex])`.
            
            // If vertex `v` (neighbor) is deleted:
            // 1. `Vertex[v]` is set to NULL.
            // 2. Edges to `v` are removed from other lists.
            
            // So if `u` has neighbor `v`, and `v` is deleted:
            // The node for `v` in `u`'s list is removed by `deletVertex`.
            // So `t` will never point to a node with `vertex == v`.
            // So `DFS(Vertex[v])` is never called.
            // This seems correct logically.
            
            // So why Wrong Answer?
            // Let's look at the BFS.
            // `BFS(Vertex[0])`.
            // `que.rear==0`. `que.queue[0] = p` (Head node of 0). `rear++`.
            // Calls `BFS(que.queue[front])` i.e., `BFS(p)`.
            // Inside `BFS(p)` where `p` is Head Node of 0.
            // `else` branch (rear != 0).
            // `if(visit[que.queue[front]->vertex] == 0)`.
            // `que.queue[front]` is Head Node of 0. `->vertex` is 0.
            // `visit[0]` is 0.
            // Sets `visit[0]=1`. Prints "0 ".
            // `t = que.queue[front]->next` (First neighbor of 0).
            // While `t!=NULL`:
            // If `visit[t->vertex]==0`:
            // `que.queue[rear] = Vertex[t->vertex]`. Enqueues the HEAD NODE of the neighbor.
            // `rear++`.
            // `t=t->next`.
            // `front++`.
            // `BFS(que.queue[front])`.
            
            // This BFS enqueues Head Nodes.
            // When processing a Head Node, it prints the vertex ID stored in that head node (which is the vertex itself).
            // It enqueues Head Nodes of neighbors.
            
            // This logic also seems consistent with the weird data structure.
            
            // Let's check the deletion impact on BFS.
            // If vertex `v` is deleted:
            // `Vertex[v] = NULL`.
            // Edges to `v` removed.
            // So `v`'s head node is never enqueued (because no neighbor points to it anymore, or rather, the node representing `v` in neighbor's list is gone).
            // Wait, if `Vertex[v]` is NULL, and somehow it was enqueued?
            // It can't be enqueued because the edge leading to it is removed from the predecessor's list.
            // So `Vertex[t->vertex]` is never accessed for `t->vertex == v`.
            
            // So logic seems fine.
            
            // Is it possible the error is simply the trailing space?
            // "0 1 2 " vs "0 1 2"
            // In C, `printf("%d ", val)` always adds a space.
            // To fix this, one usually prints the first element separately or uses a separator variable.
            // Given the strict "Expected Output" often doesn't have trailing spaces, this is the most likely candidate for "Wrong Answer" on automated judges if the logic is otherwise correct.
            
            // Let's mark the printf lines.
            
            t=t->next;
        }
    }
    }
}
void BFS(struct link* p)
{
    if(p!=NULL)
    {
    if(que.rear==0)
    {
        que.queue[que.rear]=p;
        que.rear++;
        BFS(que.queue[que.front]);
    }
    else
    {
        if(visit[que.queue[que.front]->vertex]==0)
        {
        visit[que.queue[que.front]->vertex]=1;
        printf("%d ",que.queue[que.front]->vertex); // @@ Trailing space causes Wrong Answer if judge expects no trailing whitespace. Should handle spacing carefully (e.g., print space before number except for the first one).
        struct link* t;
        t=que.queue[que.front]->next;
        while(t!=NULL)
        {
            if(visit[t->vertex]==0)
            {
            que.queue[que.rear]=Vertex[t->vertex];
            que.rear++;
            }
            t=t->next;
        }
            que.front++;
            BFS(que.queue[que.front]);
        }
        else
        {
            que.front++;
            BFS(que.queue[que.front]);    
        }
    }
    }
}
void deletVertex(int goal,int n)
{
    for(int i=0;i<n;i++)
    {
        if(i==goal)
        {
            Vertex[i]=NULL;
        }
        else
        {
        struct link* t=Vertex[i];
        while(t->next!=NULL)
        {
            if(t->next->vertex==goal)
            {
                t->next=t->next->next;
                break;
            }
            t=t->next;
        }
        }
    }
}
int main()
{
    que.rear=0;
    que.front=0;
    struct link *p,*q,*temp;
    int numOfvertex;//顶点
    int numOfside;
    int vertex1,vertex2;
    int goal;
    scanf("%d%d",&numOfvertex,&numOfside);
    for(int i=0;i<numOfside;i++)
    {
        scanf("%d%d",&vertex1,&vertex2);
        if(Vertex[vertex1]==NULL)
        {
            p=(struct link*)malloc(sizeof(struct link));
            q=(struct link*)malloc(sizeof(struct link));
            q->vertex=vertex2;
            q->next=NULL;
            p->vertex=vertex1;
            p->next=q;
            Vertex[vertex1]=p;
        }
        else
        {
            temp=Vertex[vertex1];
            while(temp->next!=NULL)
            {
                if(temp->next->vertex>vertex2)
                {
                    p=(struct link*)malloc(sizeof(struct link));
                    p->vertex=vertex2;
                    p->next=temp->next;
                    temp->next=p;
                    break;
                }
                temp=temp->next;
            }
            if(temp->next==NULL)
            {
                p=(struct link*)malloc(sizeof(struct link));
                p->vertex=vertex2;
                p->next=NULL;
                temp->next=p;
            }
        }
        if(Vertex[vertex2]==NULL)
        {
            p=(struct link*)malloc(sizeof(struct link));
            q=(struct link*)malloc(sizeof(struct link));
            q->vertex=vertex1;
            q->next=NULL;
            p->vertex=vertex2;
            p->next=q;
            Vertex[vertex2]=p;
        }
        else
        {
            temp=Vertex[vertex2];
            while(temp->next!=NULL)
            {
                if(temp->next->vertex>vertex1)
                {
                    p=(struct link*)malloc(sizeof(struct link));
                    p->vertex=vertex1;
                    p->next=temp->next;
                    temp->next=p;
                    break;
                }
                temp=temp->next;
            }
            if(temp->next==NULL)
            {
                p=(struct link*)malloc(sizeof(struct link));
                p->vertex=vertex1;
                p->next=NULL;
                temp->next=p;
            }
        }
    }
    scanf("%d",&goal);
    DFS(Vertex[0]);
    printf("\n");
    for(int i=0;i<numOfvertex;i++)
    {
        visit[i]=0;
    }
    BFS(Vertex[0]);
    printf("\n");
    deletVertex(goal,numOfvertex);
    for(int i=0;i<numOfvertex;i++)
    {
        visit[i]=0;
    }
    DFS(Vertex[0]);
    printf("\n");
    for(int i=0;i<numOfvertex;i++)
    {
        visit[i]=0;
        que.queue[i]=NULL;
    }
    que.front=0;
    que.rear=0;
    BFS(Vertex[0]);
    return 0;
}