#include <stdio.h>
#include <stdlib.h>
#define VMAX 100

struct enode {
    int adj; //连接点编号
    struct enode *next;
};

struct vnode {
    struct enode *link;
};
struct vnode g[VMAX];
int Dvisited[VMAX] = {0}; //深度
int Bvisited[VMAX] = {0}; //广度

struct enode *insert(struct enode *head, int v) {
    struct enode *e;
    e = (struct enode *)malloc(sizeof(struct enode));
    e->adj = v;
    e->next = NULL;
    if (head == NULL) {
        return e;
    }
    struct enode *p = head, *prev = NULL;
    while (p != NULL && p->adj < e->adj) {
        prev = p;
        p = p->next;
    }
    e->next = p;
    if (prev == NULL) {
        return e;
    } else {
        prev->next = e;
    }
    return head;
}

void DFS(int v) {
    if (g[v].link == NULL) return; // @@ [Logical Error: This condition prevents visiting isolated vertices or vertices that have been disconnected but are still part of the traversal loop. In the second traversal, vertex 0 might have neighbors removed, but it should still be printed if visited. More critically, if a vertex has no links left (like the deleted vertex's neighbors might appear to have fewer links), this check is premature. However, the main issue is that `Dvisited` is not set before returning, but since it's checked in the caller, it's okay. The real bug is usually in how the deletion is handled or traversal start. Let's look closer. Actually, the standard DFS implementation should mark visited BEFORE recursing or printing. Here it prints then marks. Wait, `Dvisited[v]=1` is after printf. If there's a cycle, it might recurse infinitely? No, because it checks `!Dvisited`. But if `g[v].link` is NULL, it returns without marking visited? No, `Dvisited` is initialized to 0. If `DFS(0)` is called, and `g[0].link` is not NULL, it proceeds. If `g[0].link` becomes NULL after deletion? Vertex 0 is not deleted. But its edges to `vc` are removed. If 0 only connected to `vc`, then `g[0].link` becomes NULL. Then `DFS(0)` returns immediately without printing 0 or marking it visited. This causes 0 to be skipped in output.]
    printf("%d ", v);
    Dvisited[v] = 1;
    for (struct enode *p = g[v].link; p != NULL; p = p->next) {
        if (!Dvisited[p->adj])
            DFS(p->adj);
    }
}

void travelDFS(int n) {
    for (int i = 0; i < n; i++)
        Dvisited[i] = 0;
    for (int i = 0; i < n; i++)
        if (!Dvisited[i])
            DFS(i);
}

int q[VMAX];
int front = 0;
int rear = -1;

void BFS(int v) {
    printf("%d ", v);
    Bvisited[v] = 1;
    q[++rear] = v;
    while (front <= rear) {
        v = q[front++];
        for (struct enode *p = g[v].link; p != NULL; p = p->next) {
            if (!Bvisited[p->adj]) {
                printf("%d ", p->adj);
                Bvisited[p->adj] = 1;
                q[++rear] = p->adj;
            }
        }
    }
}

void travelBFS(int nv) {
    for (int i = 0; i < nv; i++)
        Bvisited[i] = 0;
    for (int i = 0; i < nv; i++)
        if (!Bvisited[i])
            BFS(i);
}

int main() {
    int nv, ne; //顶点个数，边的个数
    scanf("%d%d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        g[v1].link = insert(g[v1].link, v2);
        g[v2].link = insert(g[v2].link, v1);
    }
    travelDFS(nv);
    printf("\n");
    travelBFS(nv);
    printf("\n");

    // 处理一下
    front = 0;
    rear = -1;
    int vc; // v_canceled
    scanf("%d", &vc);
    // 移除所有与vc连接的边
    for (int i = 0; i < nv; i++) {
        struct enode *p = g[i].link, *prev = NULL;
        while (p != NULL) {
            if (p->adj == vc) {
                if (prev == NULL) {
                    g[i].link = p->next;
                } else {
                    prev->next = p->next;
                }
                free(p);
                p = (prev == NULL) ? g[i].link : prev->next;
                continue;
            }
            prev = p;
            p = p->next;
        }
    }
    free(g[vc].link); // @@ [Runtime Error/Logical Error: If g[vc].link is NULL, free(NULL) is safe in C, but logically we should just set it to NULL. However, the bigger issue is that the vertex `vc` itself is not "deleted" from the graph structure in terms of the array `g`. The traversal loops go from 0 to n-1. When `i == vc` in `travelDFS` or `travelBFS`, it will try to traverse `vc`. Since we removed all edges TO `vc`, `g[vc].link` is NULL (after `free` and presumably setting to NULL, though the code below sets `g[vc].link = NULL`). So `DFS(vc)` will hit the `if (g[v].link == NULL) return;` bug identified above. It will return without printing or marking visited. But `vc` should NOT be visited at all. The problem says "delete the specified vertex". This means `vc` should be treated as if it doesn't exist. The current code attempts to skip it by removing edges. But in `travelDFS`, the loop `for (int i = 0; i < n; i++)` will still call `DFS(vc)` if `Dvisited[vc]` is 0. Since `Dvisited` is reset to 0, `DFS(vc)` is called. Inside `DFS(vc)`, `g[vc].link` is NULL. It returns immediately. `Dvisited[vc]` remains 0. This is technically fine as long as it doesn't print. BUT, look at the expected output. The expected output for the second DFS is `0 2`. The buggy output is `0 2`. Wait, the provided buggy output in the prompt description says:
Buggy Output:
0 1 2 
0 1 2 
0 2 
0 2 1

Expected Output:
0 1 2
0 1 2
0 2
0 2

The last line differs. `0 2 1` vs `0 2`.
Why is `1` appearing in the BFS output?
In `travelBFS`, after deletion of vertex 1 (vc=1):
Vertices: 0, 1, 2.
Edges remaining: (0,2).
`Bvisited` reset.
Loop i=0: `!Bvisited[0]` is true. Call `BFS(0)`.
`BFS(0)`: Print 0. Mark 0. Queue: [0].
Dequeue 0. Neighbors of 0: `g[0].link` points to 2 (since edge to 1 was removed).
Neighbor 2: `!Bvisited[2]` is true. Print 2. Mark 2. Queue: [2].
Dequeue 2. Neighbors of 2: `g[2].link` points to 0.
Neighbor 0: `Bvisited[0]` is true. Skip.
Queue empty. `BFS(0)` returns.
Loop i=1: `!Bvisited[1]` is true (because `Bvisited[1]` was never set to 1). Call `BFS(1)`.
`BFS(1)`: Print 1. Mark 1. Queue: [1].
Dequeue 1. Neighbors of 1: `g[1].link` is NULL.
Queue empty. `BFS(1)` returns.
Loop i=2: `Bvisited[2]` is true. Skip.
Output: `0 2 1`.

The error is that vertex `vc` (1) is still considered unvisited and thus traversed, printing it. We must mark `vc` as visited BEFORE starting the traversal loops, or skip it explicitly. The reference program does `Dvisited[vc]=1;` before the loop.

    g[vc].link = NULL;
    travelDFS(nv);
    printf("\n");
    travelBFS(nv);
    printf("\n");
    return 0;
}