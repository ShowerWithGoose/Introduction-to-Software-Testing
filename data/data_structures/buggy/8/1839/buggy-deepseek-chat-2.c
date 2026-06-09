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

void bfs(int p, int n) {
    printf("%d", G[p]); // @@ [BFS function is incomplete; it only prints the starting vertex without implementing the full BFS algorithm using a queue]

}
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

    for (int i = 0; i < n; i++)if (V[q][i] == 1) { V[q][i] = 0; V[i][q] = 0; }
    dfs(0, n);
    for (int i = 0; i < n; i++)isus[i] = 0;
    printf("\n");//3
}