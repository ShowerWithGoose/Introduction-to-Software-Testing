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

void bfs(int p, int n) { // @@ BFS function is completely unimplemented; it lacks queue initialization, traversal loop, and proper vertex visiting logic.
    printf("%d", G[p]); // @@ Output format misses a space separator, and the function body does not perform BFS traversal.

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
    dfs(0, n); // @@ Missing call to bfs(0, n) to output BFS sequence before deletion.
    for (int i = 0; i < n; i++)isus[i] = 0;
    printf("\n");//1 // @@ Should be preceded by BFS output for the 'before deletion' case.

    for (int i = 0; i < n; i++)if (V[q][i] == 1) { V[q][i] = 0; V[i][q] = 0; } // @@ Only removes edges connected to q but fails to mark q as visited (isus[q]=1), which is necessary to correctly exclude the deleted vertex from traversal.
    dfs(0, n); // @@ Missing call to bfs(0, n) to output BFS sequence after deletion.
    for (int i = 0; i < n; i++)isus[i] = 0;
    printf("\n");//3 // @@ Should be preceded by BFS output for the 'after deletion' case.
}