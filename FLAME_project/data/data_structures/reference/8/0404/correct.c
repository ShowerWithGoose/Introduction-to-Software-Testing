#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAXVERTEXNUM 100
#define MaxSize 10

typedef struct {
    int edges[MAXVERTEXNUM][MAXVERTEXNUM];
    int vexNum, edgeNum;
}MGraph;

void creategraph(MGraph *g);

bool visited[MAXVERTEXNUM];
void bfs_caller(MGraph g);
void bfs(MGraph g, int v);
void dfs_caller(MGraph g);
void dfs(MGraph g, int v);

int que[100];

int main(){
    MGraph g;
    creategraph(&g);

    int del_node;
    scanf("%d", &del_node);

    dfs_caller(g), puts("");

    memset(visited, 0, sizeof(visited));
    bfs_caller(g), puts("");

    memset(visited, 0, sizeof(visited));
    visited[del_node] = true;
    dfs_caller(g), puts("");

    memset(visited, 0, sizeof(visited));
    memset(que, 0, sizeof(que));
	visited[del_node] = true;
	bfs_caller(g);
}

void creategraph(MGraph *g){
    scanf("%d %d", &(g->vexNum), &(g->edgeNum));

    int s, e, i;
    for(i = 0; i < g->edgeNum; i++){
        scanf("%d %d", &s, &e);
        g->edges[s][e] = 1;
        g->edges[e][s] = 1;
    }
}

void dfs_caller(MGraph g){
    int i;
	for(i = 0; i < g.vexNum; ++i)
        if(!visited[i])
            dfs(g, i);

    printf("\n");
}

void dfs(MGraph g, int v){
    visited[v] = true;
    printf("%d ", v);

    int i;
    for(i = 0; i < g.vexNum; ++i){
        if(!visited[i] && g.edges[v][i])
            dfs(g, i);
    }
}

void bfs_caller(MGraph g){
    int i;
    for(i = 0; i < g.vexNum; i++){
        if(!visited[i])
            bfs(g, i);
    }

    printf("\n");
}

void bfs(MGraph g, int v){
    int head = 0, tail = 1;
    que[head] = v;
    visited[v] = true;

    while (head < tail) {
        int de_node = que[head];
        head++;
        printf("%d ", de_node);

		int i;
        for (i = 0; i < g.vexNum; ++i) {
            if (!visited[i] && g.edges[de_node][i]) {
                que[tail++] = i;
                visited[i] = true;
            }
        }
    }
}
