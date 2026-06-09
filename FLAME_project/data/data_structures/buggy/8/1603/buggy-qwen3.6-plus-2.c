#include<stdio.h>
#include<stdlib.h>
int visited[105] = {0};
int deletever;

int Q[105] = {-1};
int top = 0;
int end = 0;

void enQueue(int Q[], int b)
{
    Q[end++] = b;
}
int deQueue(int Q[])
{
    int a;
    a = Q[top++];
    Q[top - 1] = -1;
    return a;
}

typedef struct _edge
{
    int flag;
    int adjver;
    struct _edge *next;
} edge,*Pedge;


typedef struct _ver
{
    int flag;
    edge *link;
} ver,*Pver;

ver G[105];

void visit(ver G[], int v)
{
    printf("%d ",v);
}

void DFS(ver G[], int v)
{
    Pedge p;
    visited[v] = 1; //标识某顶点被访问过
    visit(G,v);
    for (p = G[v].link; p != NULL; p = p->next)
    {
        if (!visited[p->adjver])
        {
            DFS(G, p->adjver);
        }
    }

}

void DFS1(ver G[], int v,int deletever)
{
    Pedge p;
    Pedge k;
    visited[v] = 1; //标识某顶点被访问过
    p = G[v].link;
    if(p != NULL && p->adjver == deletever)
    {
        k = p->next;
        G[v].link = k;
    }
    //visit(G,v);
    for (p = G[v].link; p != NULL; p = p->next)
    {
        if(p->next != NULL && p->next->adjver == deletever)
        {
            k = p->next->next;
            p->next = k;
        }

        if (!visited[p->adjver])
        {
            DFS1(G, p->adjver,deletever);
        }

    }

}


void BFS(ver G[], int v)
{
    Pedge p;

    visit(G, v); //访问当前顶点
    visited[v] = 1; //标识某顶点被访问过
    enQueue(Q, v);
    while (top < end)
    {
        v = deQueue(Q); //取出队头元素
        p = G[v].link; //获取该顶点第一个邻接顶点

        for (; p != NULL; p = p->next)
        {
            if (!visited[p->adjver])
            {
                visit(G,p->adjver);//访问当前顶点
                visited[p->adjver] = 1; //标识某顶点被访问过
                enQueue(Q, p->adjver);
            }
        }
    }
}


Pedge create(int a)
{
    Pedge p;
    p = (Pedge)malloc(sizeof(edge));
    p->flag = 1;
    p->adjver = a;
    p->next = NULL;
    return p;
}

void insert(ver G[], Pedge p, int a)
{

    Pedge k, q ;
    if(G[a].link == NULL)
    {
        G[a].link = p;
    }
    else
    {
        k = G[a].link;
        while(k != NULL)
        {
            if(k->adjver > p->adjver)
            {
                q = k;
                k = q->next;
                break;
            }
            if(k->next != NULL && k->next->adjver > p->adjver)
            {
                q = k;
                k = q->next;
                break;
            }
            q = k;
            k = q->next;
        }
        p->next = k;
        q->next = p;
    }

    /*int i;
    for(i = 0 ; i < 9 ;i++)//
    {
        printf("%d ",i);
        q = G[i].link;
        while(q != NULL)
        {
            printf("%d ",q->adjver);
            p = q;
            q = p->next;
        }
        printf("\n");
    }*/
}

int main ()
{
    int i;
    int a, b;
    int vetn,edgen;

    Pedge p,  k;
    scanf("%d %d",&vetn,&edgen);

    for(i = 0 ; i < vetn ; i++)
    {
        G[i].flag = 1;
    }
    for(i = 0 ; i < edgen ; i++)
    {
        scanf("%d %d",&a, &b);

        p = create(b);
        //printf("aaaaaaaaaaaaaaaa%d",p->adjver);
        insert(G, p, a);


        k = create(a);
        //printf("aaaaaaaaaaaaaaaa%d",k->adjver);
        insert(G, k, b);

    }

    /*for(i = 0 ; i < vetn ;i++)
    {
        printf("%d ",i);
        q = G[i].link;
        while(q != NULL)
        {
            printf("%d ",q->adjver);
            p = q;
            q = p->next;
        }
        printf("\n");
    }*/

    scanf("%d",&deletever);

    DFS(G,0);
    printf("\n");
    for(i = 0 ; i < 105 ; i++)
    {
        visited[i] = 0;
    }
    BFS(G,0);
    printf("\n");
    for(i = 0 ; i < 105 ; i++)
    {
        visited[i] = 0;
    }

    DFS1(G,0,deletever); // @@ The function DFS1 attempts to modify the graph structure during traversal but fails to correctly remove all edges connected to the deleted vertex, and it does not skip the deleted vertex itself if encountered. More importantly, the subsequent calls to DFS and BFS rely on the graph structure being modified or flags being set. However, DFS1 modifies the linked lists in place. The main issue is that DFS1 is called, which modifies the graph by removing edges pointing to 'deletever'. But it doesn't mark the vertex as deleted in a way that BFS/DFS checks (like a flag). Instead, it physically removes edges. However, the vertex 'deletever' still exists in the array G. If DFS or BFS encounters 'deletever' via another path (which shouldn't happen if edges are removed correctly), it might visit it. The bigger issue is that DFS1 is recursive and modifies the list while iterating, which can be buggy. But looking at the output, the second DFS/BFS should be on the graph WITHOUT the vertex. The current code calls DFS1, then resets visited, then calls DFS(G,0). DFS does not check if a vertex is "deleted". It only checks visited. So if the edges to 'deletever' are removed, DFS won't reach it. BUT, DFS1 only removes edges FROM the current vertex TO deletever. It does not remove edges FROM other vertices TO deletever properly if they are not visited in the DFS1 traversal order or if the logic is flawed. Actually, DFS1 tries to remove edges as it traverses. This is incorrect. We should remove all edges connected to 'deletever' from ALL vertices before traversing. The reference solution uses a flag. This solution tries to modify links. The modification in DFS1 is incomplete and risky. However, the most obvious error causing WA is likely that DFS1 doesn't prevent visiting the deleted vertex if it's still reachable or if the removal logic is flawed. Let's look closer. DFS1 removes edges pointing to deletever. If it works correctly, 'deletever' becomes isolated. Then DFS(G,0) won't visit it. But DFS1 starts at 0. If the graph is 0-1-2 and delete 1. DFS1(0, 1). Edge 0->1 is removed. Then it goes to next neighbor of 0. If 0->2 exists, it visits 2. At 2, it removes edge 2->1. So edges to 1 are removed. Then DFS(G,0) runs. It visits 0, then 2. Correct. What if the graph is 0-2, 0-1, 1-2. Delete 1. DFS1(0,1). Removes 0->1. Visits 2 (via 0->2). At 2, removes 2->1. Then DFS(G,0) visits 0, 2. Correct. Why WA? Look at BFS. BFS also doesn't check for deleted vertices, it relies on edges being removed. If DFS1 fails to remove an edge, BFS might visit the deleted vertex. In DFS1, the removal logic: `if(p->next != NULL && p->next->adjver == deletever)`. This only removes the NEXT node if it matches. It doesn't handle the case where the HEAD of the list matches (except for the initial check before the loop). Wait, the initial check `if(p != NULL && p->adjver == deletever)` handles the head. Inside the loop, it checks `p->next`. This seems okay for removal. HOWEVER, there is a subtle bug in `insert`. The `insert` function is supposed to keep the adjacency list sorted. Let's trace `insert` for 0-1, 1-2, 0-2. Insert 1 into 0's list. List 0: 1. Insert 2 into 1's list. List 1: 2. Insert 0 into 1's list. List 1: 0->2. Insert 2 into 0's list. List 0: 1->2. Insert 0 into 2's list. List 2: 0. Insert 1 into 2's list. List 2: 0->1. Graph: 0:1->2, 1:0->2, 2:0->1. Delete 1. DFS1(0, 1). p=G[0].link (points to 1). Head is 1. Matches deletever. G[0].link becomes 2. Loop p=G[0].link (points to 2). p->next is NULL. Loop ends. DFS1 recurses to 2. visited[2]=1. p=G[2].link (points to 0). Head 0 != 1. Loop p=0. p->next points to 1. p->next->adjver == 1. Match. k = p->next->next (NULL). p->next = NULL. List 2 becomes 0. Loop p=p->next (NULL). Ends. DFS1 finishes. Graph: 0:2, 1:0->2, 2:0. Note that edges FROM 1 were NOT removed. DFS(G,0) starts at 0. Visits 0. Neighbor 2. Visits 2. Neighbor 0 (visited). Done. Output: 0 2. Correct. BFS(G,0). Visits 0. Queue 0. Dequeue 0. Neighbor 2. Visits 2. Queue 2. Dequeue 2. Neighbor 0 (visited). Done. Output: 0 2. Correct. So why WA? Look at the output format. "0 1 2 " vs "0 1 2". The problem expects no trailing space? Or newline? The code prints `printf("%d ",v);`. This adds a space after every number. The expected output usually tolerates trailing spaces or requires exact matching. The provided "Buggy Output" has trailing spaces. The "Expected Output" in the description doesn't explicitly show trailing spaces but standard judges often ignore them or require strict matching. However, there is a more critical logical error. The problem states: "output the vertex sequences... before and after deleting". The code calls `DFS1` which modifies the graph. Then it calls `DFS` and `BFS`. This assumes `DFS1` correctly removes all traces of the vertex. But `DFS1` only removes edges incident to `deletever` that are reachable from 0 via DFS1 traversal. If the graph was disconnected after deletion (though problem says it remains connected), or if `DFS1` doesn't traverse all nodes because it marks visited, it might miss removing edges from unvisited nodes? No, the graph is connected. DFS1 visits all nodes reachable from 0. Since the graph is connected before deletion, DFS1 visits all nodes except possibly the deleted one if it gets isolated early? No, it visits neighbors. If it removes edges to deletever, it just doesn't go there. It still visits all other nodes. So all edges from valid nodes to deletever should be removed. What about edges FROM deletever? They remain in G[deletever].link. But since no valid node points to deletever anymore, and we start DFS/BFS from 0, we never reach deletever. So this should work. Is there an error in `insert`? The `insert` logic is complex. `q` is used to track the previous node. If the new node `p` is smaller than the head `k`, `q` is uninitialized? `if(k->adjver > p->adjver) { q = k; k = q->next; break; }`. Here `q` becomes `k` (the head). Then `p->next = k` (which is `q->next`, the old head's next? No, `k` was updated to `q->next`). Wait. `k = G[a].link`. If `k->adjver > p->adjver`, we want to insert `p` before `k`. `q = k`. `k = q->next` (so `k` is now the second node, or NULL). Then `break`. After loop: `p->next = k`. `q->next = p`. So `p` points to the old second node (or NULL), and `q` (old head) points to `p`. This effectively inserts `p` between head and second node? No, it inserts `p` AFTER `q` (old head). But we wanted to insert BEFORE old head because `p->adjver < k->adjver` (old head). This logic is WRONG. It inserts in the wrong position or corrupts the list if the new element is the smallest. It should update `G[a].link` to `p` if `p` is the new head. The current code sets `q->next = p` where `q` is the old head. So the old head remains the head. This means the list is NOT sorted correctly if the inserted element is smaller than the first element. This violates requirement 3: "visit them in ascending order". This is the error.

    DFS(G,0); // @@ The insert function fails to correctly maintain the sorted order of the adjacency list when inserting a vertex smaller than the current head, leading to incorrect traversal order.
    printf("\n");
    for(i = 0 ; i < 105 ; i++)
    {
        visited[i] = 0;
    }
    BFS(G,0);
    printf("\n");
    for(i = 0 ; i < 105 ; i++)
    {
        visited[i] = 0;
    }

    DFS1(G,0,deletever);
    //Pedge q;
    for(i = 0 ; i < 105 ; i++)
    {
        visited[i] = 0;
    }
    /*for(i = 0 ; i < 9 ;i++)//
    {
        printf("%d ",i);
        q = G[i].link;
        while(q != NULL)
        {
            printf("%d ",q->adjver);
            p = q;
            q = p->next;
        }
        printf("\n");
    }*/



    DFS(G,0);
    printf("\n");
    for(i = 0 ; i < 105 ; i++)
    {
        visited[i] = 0;
    }

    BFS(G,0);
    printf("\n");
    for(i = 0 ; i < 105 ; i++)
    {
        visited[i] = 0;
    }


    return 0;
}