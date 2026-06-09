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

    DFS(109); // @@ [Error: The parameter 109 is used as a sentinel value to indicate no deletion, but it is not a valid vertex number. The function should be called with a value that is not a vertex (e.g., -1 or n) to indicate no deletion, but here it uses 109 which may cause out-of-bounds access or incorrect behavior if n is small. The intended logic is to pass a vertex that is not in the graph to skip marking it as visited, but 109 is arbitrary and could be misinterpreted.]
    BFS(109); // @@ [Same error as above: The parameter 109 is used incorrectly. The function should be called with a value that is not a vertex to indicate no deletion, but 109 is not guaranteed to be out of range and may cause issues.]
    DFS(del);
    BFS(del);

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
    visited[point] = 1; // @@ [Error: This marks the deleted vertex as visited, which is correct for the "after deletion" case, but for the "before deletion" case (when point=109), it marks vertex 109 as visited, which is out of range and may cause undefined behavior. The function should handle the case where point is not a valid vertex (e.g., -1) by not marking any vertex as visited initially.]

    printf("0 ");
    visited[0] = 1;
    DFS_search(0);

    printf("\n");
}
void DFS_search(int p) {
    for (int i = 0; i < n; i++) {
        if (i == p)
            continue;
        if (visited[i] == 0 && G[i][p] == 1) {
            printf("%d ", i);
            visited[i] = 1;
            DFS_search(i);

        }
    }
}
void BFS(int point) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[point] = 1; // @@ [Same error as in DFS: For the "before deletion" case, marking vertex 109 as visited is incorrect and may cause undefined behavior.]

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

    } while (k != rear);

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