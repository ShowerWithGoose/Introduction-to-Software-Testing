#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 110

int n, e;
int del;

int G[MAXSIZE][MAXSIZE] = {{0}};
int visited[MAXSIZE] = {0};
int queue[MAXSIZE] = {-1};

void clear();
void DFS(int point);
void DFS_search(int p);
void BFS(int point);

int main() {
    clear();

    scanf("%d%d", &n, &e);

    for (int i = 0; i < e; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a][b] = 1;
        G[b][a] = 1;
    }

    scanf("%d", &del);

    DFS(109); // @@ [Calling DFS with an invalid vertex index (109) instead of printing traversal before deletion. Should call DFS with normal setup, not using dummy value.]
    BFS(109); // @@ [Same issue: BFS called with invalid vertex 109 instead of performing traversal on original graph.]
    DFS(del); // @@ [This attempts to run DFS after marking 'del' as visited, but doesn't actually remove the vertex from the graph structure. Also, it prints again starting from 0 but skips 'del' only by marking it visited, which may not correctly simulate deletion if 'del' is adjacent to others.]
    BFS(del); // @@ [Same issue as above: BFS uses 'del' as a visited node but doesn't remove edges connected to 'del', leading to incorrect traversal behavior.]

    return 0;
}
void clear() {
    for (int i = 0; i < MAXSIZE; i++) {
        for (int j = 0; j < MAXSIZE; j++) {
            G[i][j] = 0;
        }
    }
}
void DFS(int point) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[point] = 1; // @@ [If 'point' is 109 or 'del', this sets visited[109] or visited[del]=1, but visited array is only meaningful for indices 0..n-1. For point=109, this writes out-of-bounds if n <= 100.]

    printf("0 ");
    visited[0] = 1;
    DFS_search(0);

    printf("\n");
}
void DFS_search(int p) {
    for (int i = 0; i < n; i++) {
        if (i == p)
            continue;
        if (visited[i] == 0 && G[i][p] == 1) { // @@ [The adjacency check should be G[p][i], not G[i][p]; though symmetric in undirected graph, logic is reversed and may confuse. However, since graph is undirected and matrix is symmetric, this isn't logically wrong—but combined with other issues, contributes to confusion. Main error is elsewhere.]
            printf("%d ", i);
            visited[i] = 1;
            DFS_search(i);

        }
    }
}
void BFS(int point) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[point] = 1; // @@ [Same out-of-bound risk if point >= n (e.g., 109). Also, marking 'del' as visited doesn't delete its edges, so neighbors might still try to traverse through it incorrectly.]

    visited[0] = 1;
    printf("0 ");
    queue[0] = 0;
    int rear = 0, i = 0, k = 0;
    do {
        i = queue[k];
        for (int j = 0; j < n; j++) {
            if (G[i][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                queue[++rear] = j;
            }
        }
        k++;

    } while (k != rear); // @@ [Loop condition is flawed: when queue has one element, k=0, rear=0, loop doesn't run. But more critically, after processing first node, if multiple nodes are added, k increments but rear may be larger; however, condition k != rear will break too early. Should be while(k <= rear).]

    /*for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (visited[j] == 0 && G[i][j] == 1) {
                printf("%d ", j);
                visited[j] = 1;
            }
        }
        visited[i] = 1;
    }*/


    printf("\n");
}