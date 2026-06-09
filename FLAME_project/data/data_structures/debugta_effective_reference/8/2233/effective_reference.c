#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXVEX 110
typedef struct MGraph{
//    int vertex[MAXVEX];//节点信息即下标，可忽略
    int arc[MAXVEX][MAXVEX];
    int nvex, nedge;
} MGraph, *MGp;
int vis[MAXVEX];
void createMGraph(MGp g);
void DFS(MGraph g, int i);
void DFSTraverse(MGraph g);
void BFSTraverse(MGraph g);
void delVex(MGp g, int dvex);
int main() {
    int dvex;
    MGraph G;
    createMGraph(&G);
    scanf("%d",&dvex);
    DFSTraverse(G);
    BFSTraverse(G);
    delVex(&G, dvex);
    DFSTraverse(G);
    delVex(&G, dvex);
    BFSTraverse(G);
    return 0;
}

void createMGraph(MGp g){
    int i, v1, v2;
    scanf("%d%d", &g->nvex, &g->nedge);
    memset(g->arc, 0, sizeof(g->arc));
    for (i = 0; i < g->nedge; i++) {
        scanf("%d%d", &v1, &v2);
        g->arc[v1][v2] = g->arc[v2][v1] = 1;
    }
}
void DFS(MGraph g, int i){
    int j;
    vis[i] = 1;
    printf("%d ", i);
    for (j = 0; j < g.nvex; j++) {
        if (g.arc[i][j] == 1 && !vis[j]) {
            DFS(g, j);
        }
    }
}
void DFSTraverse(MGraph g){
    int i;
    for (i = 0; i < g.nvex; i++) {
        if (!vis[i]) {
            DFS(g, i);
        }
    }
    printf("\n");
    memset(vis, 0, sizeof(vis));
}
void BFSTraverse(MGraph g){
    int i, j;
    int queue[MAXVEX], f = 0, r = 0;
    for (i = 0; i < g.nvex; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            printf("%d ", i);
            queue[r++] = i;
            while (f < r) {
                i = queue[f++];
                for (j = 0; j < g.nvex; j++) {
                    if (g.arc[i][j] == 1 && !vis[j]) {
                        vis[j] = 1;
                        printf("%d ", j);
                        queue[r++] = j;
                    }
                }
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    printf("\n");
}

void delVex(MGp g, int dvex){
    int i;
    vis[dvex] = 1;
    memset(g->arc[dvex], 0, sizeof(g->arc[dvex]));
    for (i = 0; i < g->nvex; i++) {
        g->arc[i][dvex] = 0;
    }
}
/*
9 10
0 1
0 2
1 4
1 3
1 8
8 6
3 6
7 2
7 5
5 2
3
 */



