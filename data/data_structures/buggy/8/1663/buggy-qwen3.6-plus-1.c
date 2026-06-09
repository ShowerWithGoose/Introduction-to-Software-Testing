#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int graph[110][110];
int visited[110];

void dfs(int arr[][110], int ind) {
    printf("%d ", ind); // @@ Should mark visited[ind] = 1 here to prevent revisiting the starting node in cyclic graphs.
    int i = 0;
    for(i = 1; i < 110; i ++) { // @@ Loop starts from 1, skipping vertex 0. Vertices are labeled 0 to n-1.
        if(arr[ind][i] != 0 && visited[i] == 0){
            visited[i] = 1;
            dfs(arr, i);
        }
    }
    return ;
}

void bfs(int arr[][110], int ind, int *queue) {
    int i = 1; // @@ Should be initialized to 0 to match the 0-indexed vertex labels.
    int tail = 0, head = 0;
    queue[tail] = ind;
    tail++;
    while(head < tail){
        printf("%d ", queue[head]);
        ind = queue[head];
        head++;
        for(i = 1; i < 110; i++) { // @@ Loop starts from 1, skipping vertex 0.
            if(arr[ind][i] != 0 && visited[i] == 0){
                queue[tail] = i;
                tail++;
                visited[i] = 1;
            }
        }
    }
    return ;
}

int main()
{
    int a;
    int times = 1;
    int temp;
    while(scanf("%d ", &a) != EOF){ // @@ Trailing space causes input blocking; logic fails to correctly parse n, m, edges, and the delete vertex.
        if(times == 2) {
            graph[a][temp] = 1;
            graph[temp][a] = 1;
            times = 1;
            continue;
        }
        temp = a;
        times++;
    }
    int i = 1;
    dfs(graph, 0);
    printf("\n");
    
    int *queue = (int *) malloc(sizeof(int) * 1000);
    for(i = 1; i < 110; i ++) visited[i] = 0; // @@ Fails to reset visited[0], leading to incorrect traversal results.
    bfs(graph, 0, queue);
    printf("\n");
    free(queue);
    i = 0;
    for(i = 0; i < 110; i ++) {
        graph[a][i] = 0; // @@ 'a' holds the last edge vertex, not the delete vertex, due to flawed input parsing.
        graph[i][a] = 0;
    }
    for(i = 1; i < 110; i ++) visited[i] = 0; // @@ Fails to reset visited[0].
    dfs(graph, 0);
    printf("\n");
    queue = (int *) malloc(sizeof(int) * 1000);
    for(i = 1; i < 110; i ++) visited[i] = 0; // @@ Fails to reset visited[0].
    bfs(graph, 0, queue);
    free(queue);
    return 0;
}