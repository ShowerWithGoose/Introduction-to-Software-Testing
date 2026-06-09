#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int weight[200][200], visited[200], que[200];
int v_n, e_n;

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < v_n; i++) {
        if (weight[v][i] == 1 && visited[i] != 0) { // @@ The condition should be visited[i] == 0 to traverse unvisited vertices; != 0 incorrectly checks for already visited nodes, preventing traversal.
            DFS(i);
        }
    }
}
void BFS(int v) {
    int head = 0, tail = 1, tmp;
    que[head] = v;
    while (head <= tail) {
        tmp = que[head];
        head++;
        if (visited[tmp])    continue;
        else {
            printf("%d ", tmp);
            visited[tmp] = 1;
            for (int i = 0; i < v_n; i++)
                if (weight[tmp][i] == 1 && visited[i] != 0) // @@ The condition should be visited[i] == 0 to enqueue unvisited vertices; != 0 incorrectly checks for already visited nodes, preventing traversal.
                    que[tail++] = i;
        }
    }
}
int main() {
    int u, v, del;
    scanf("%d%d", &v_n, &e_n);
    for (int i = 0; i < e_n; i++) {
        scanf("%d %d", &u, &v);
        weight[u][v] = 1;
        weight[v][u] = 1;
    }
    DFS(0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    BFS(0);
    printf("\n");
    scanf("%d", &del);
    memset(visited, 0, sizeof(visited));
    visited[del] = 1;
    DFS(0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    memset(que, 0, sizeof(que));
    visited[del] = 1;
    BFS(0);
    printf("\n");
}