#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int total_vertex, total_edge, weight[10000][10000], queue[10000], visited[10000];

void DFS(int vertex);
void BFS(int vertex);


int main() {
    int vertex_start, vertex_end, vertex_delete;

    scanf("%d %d", &total_vertex, &total_edge);

    for (int i = 0; i < total_edge; i++) {
        scanf("%d %d", &vertex_start, &vertex_end);
        weight[vertex_start][vertex_end] = 1;
        weight[vertex_end][vertex_start] = 1;
    }
    scanf("%d", &vertex_delete);
    DFS(0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    BFS(0);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    visited[vertex_delete] = 1;
    DFS(0);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    visited[vertex_delete] = 1;
    memset(queue, 0, sizeof(queue));
    BFS(0);
    printf("\n");

    system("pause");
    return 0;
}

void DFS(int vertex) {
    int i;
    printf("%d ", vertex);
    visited[vertex] = 1;
    for (i = 0; i < total_vertex; i++) {
        if (weight[vertex][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

void BFS(int vertex) {
    int i, head = 0, tail = 1, tmp;
    queue[head] = vertex;
    while (head <= tail) {
        tmp = queue[head];
        head++;
        if (visited[tmp]) {
            continue;
        } else {
            printf("%d ", tmp);
            visited[tmp] = 1;
            for (i = 0; i < total_vertex; i++) {
                if (weight[tmp][i] == 1 && visited[i] == 0) {
                    queue[tail] = i;
                    tail++;
                }
            }
        }
    }
}
