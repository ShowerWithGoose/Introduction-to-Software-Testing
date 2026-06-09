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
    if (g[v].link == NULL) return;
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
    travelDFS(nv); // @@ Missing marking of deleted vertex as visited; requires setting Dvisited[vc]=1 to avoid calling DFS(vc) (though DFS skips it due to early return, but BFS will print it)
    printf("\n");
    travelBFS(nv); // @@ Deleted vertex not marked visited; BFS will output it incorrectly because it prints the vertex before checking for edges
    printf("\n");
    return 0;
}