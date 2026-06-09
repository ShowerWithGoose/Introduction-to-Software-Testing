#include<stdio.h>
#define max 110

int G[max] = { 0 };
int V[max][max] = { 0 };
int isus[max] = { 0 };

void dfs(int p,int n) {
    printf("%d ", G[p]);
    isus[p] = 1;
    for (int i = 0; i < n; i++) {
        if (V[p][i] == 1 && isus[i] == 0) {
            dfs(i, n);
        }
    }
}

void bfs(int p, int n) { // @@ BFS function is incomplete; lacks queue initialization and traversal loop to visit adjacent vertices
    printf("%d", G[p]); // @@ Missing space separator and BFS traversal logic is entirely absent

} // @@ Function ends prematurely without implementing BFS algorithm
int main() {
    int n,e;
    scanf("%d%d", &n, &e);
    for (int i = 0; i < e; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        V[a][b] = 1;
        V[b][a] = 1;
    }
    int q;
    scanf("%d", &q);

    for (int i = 0; i < n; i++)G[i] = i;
    dfs(0, n);
    for (int i = 0; i < n; i++)isus[i] = 0;
    printf("\n");//1

    for (int i = 0; i < n; i++)if (V[q][i] == 1) { V[q][i] = 0; V[i][q] = 0; } // @@ Only removes incident edges; should also mark isus[q] = 1 to properly simulate vertex deletion
    dfs(0, n);
    for (int i = 0; i < n; i++)isus[i] = 0;
    printf("\n");//3 // @@ Missing calls to bfs(0, n) before and after deletion; program only outputs DFS sequences instead of both DFS and BFS
}