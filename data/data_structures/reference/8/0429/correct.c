#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define GraphMax 110
#define MAXqueue 110

void traDFS(int graph[][GraphMax], int n);
void DFS(int graph[][GraphMax], int i, int visit[], int n);
void traBFS(int graph[][GraphMax], int n);
void BFS(int graph[][GraphMax], int i, int visit[], int n);
int main() {
    int graph[GraphMax][GraphMax] = {0};
    int n, e, n1, n2, del;
    scanf("%d%d", &n, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &n1, &n2);
        graph[n2][n1] = 1;
        graph[n1][n2] = 1;
    }
    traDFS(graph, n);
    puts("");
    traBFS(graph, n);
    scanf("%d", &del);
    puts("");
    for (int i = 0; i < n; i++) {
        graph[i][del] = 0;
    }
    for (int i = 0; i < n; i++) {
        graph[del][i] = 0;
    }
    traDFS(graph, n);
    puts("");
    traBFS(graph, n);
    scanf("%d", &del);
    puts("");
    system("pause");
    return 0;
}
void traDFS(int graph[][GraphMax], int n) {
    int visit[GraphMax] = {0};int i = 0;
    //for (int i = 0; i < n; i++) {
    //    if (!visit[i]) {
            DFS(graph, i, visit, n);
    //    }
    //}
}
void DFS(int graph[][GraphMax], int i, int visit[], int n) {
    visit[i] = 1;
    printf("%d ", i);
    for (int j = 0; j < n; j++) {
        if (!visit[j] && graph[i][j] == 1) {
            DFS(graph, j, visit, n);
        }
    }
}

void traBFS(int graph[][GraphMax], int n) {
    int visit[GraphMax] = {0};int i = 0;
    //for (int i = 0; i < n; i++) {
    //    if (!visit[i]) {
            BFS(graph, i, visit, n);
    //    }
    //}
}
void BFS(int graph[][GraphMax], int i, int visit[], int n){
    int Queue[MAXqueue];
    int rear = -1, front = 0;
    int nownum = i;
    Queue[(++rear) % MAXqueue] = i;
    while (front <= rear) {
        nownum = Queue[(front++) % MAXqueue];
        if (!visit[nownum])
            printf("%d ", nownum);
        visit[nownum] = 1;
        for (int j = 0; j < n; j++) {
            if (graph[j][nownum] == 1 && visit[j] == 0) {
                Queue[(++rear) % MAXqueue] = j;
            }
        }
    }
}

