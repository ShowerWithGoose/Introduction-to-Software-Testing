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
    if (g[v].link == NULL) return; // @@ [Error: This line incorrectly skips DFS for vertex 0 when it has no edges, but the graph is connected so this is not the main issue. The real problem is that after deleting vertex vc, the DFS and BFS traversals should start from vertex 0 and skip the deleted vertex, but the code still traverses all vertices including the deleted one, and the DFS function returns early for the deleted vertex because its link is NULL, causing incorrect traversal order. The expected output after deletion is "0 2" for DFS and "0 2" for BFS, but the buggy output shows "0 2" for DFS and "0 2 1" for BFS, indicating that vertex 1 is still visited in BFS. This is because the BFS function does not check if the vertex is the deleted one before printing and enqueuing, and the deletion of edges from other vertices to vc is done, but the BFS still processes vertex 1 because it is not marked as visited and its adjacency list still contains vertex 2 (since vc=1, edges from 1 to 0 and 2 are removed, but vertex 1 itself is not properly skipped in the traversal loop). The main error is that the travelDFS and travelBFS functions do not exclude the deleted vertex vc from the traversal; they should start from vertex 0 and skip vc, but the current code iterates over all vertices and calls DFS/BFS on vc as well, which then returns early due to the NULL link check, causing the traversal to miss vertices that should be visited from vc. The correct approach is to mark vc as visited before traversal, as in the reference program.]
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
    free(g[vc].link);
    g[vc].link = NULL;
    travelDFS(nv); // @@ [Error: After deleting vertex vc, the traversal should mark vc as visited before starting, so that it is skipped. The current code does not set Dvisited[vc]=1 or Bvisited[vc]=1, so the traversal will attempt to visit vc, and since its link is NULL, DFS returns early without printing, but BFS will still print vc because it prints before checking the link. This causes the BFS output to include vertex 1 (vc) incorrectly. The expected output after deletion is "0 2" for both DFS and BFS, but the buggy output shows "0 2" for DFS and "0 2 1" for BFS, meaning vertex 1 is printed in BFS. The fix is to set Dvisited[vc]=1 and Bvisited[vc]=1 before calling travelDFS and travelBFS, or to modify the travel functions to skip vc.]
    printf("\n");
    travelBFS(nv); // @@ [Same error as above: Bvisited[vc] is not set, so BFS will visit and print vertex vc, causing the extra output.]
    printf("\n");
    return 0;
}