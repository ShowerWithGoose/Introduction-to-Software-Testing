#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int graph[110][110];
int visited[110];

void dfs(int arr[][110], int ind) {
    printf("%d ", ind); // @@ Missing visited[ind] = 1; here, which causes the starting node to be revisited in cyclic graphs.
    int i = 0;
    for(i = 1; i < 110; i ++) { // @@ Loop should start from 0 to correctly check adjacency with vertex 0.
        if(arr[ind][i] != 0 && visited[i] == 0){
            visited[i] = 1;
            dfs(arr, i);
        }
    }
    return ;
}

void bfs(int arr[][110], int ind, int *queue) {
    int i = 1; // @@ Should be initialized to 0 for the subsequent loop.
    int tail = 0, head = 0;
    queue[tail] = ind;
    tail++;
    while(head < tail){
        printf("%d ", queue[head]);
        ind = queue[head];
        head++;
        for(i = 1; i < 110; i++) { // @@ Loop should start from 0 to correctly check adjacency with vertex 0.
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
    while(scanf("%d ", &a) != EOF){ // @@ Input parsing is incorrect; it should explicitly read n, m, then m edges, and finally the deletion vertex. The trailing space may also cause input blocking.
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
    for(i = 1; i < 110; i ++) visited[i] = 0; // @@ Should start from 0 to reset visited[0], otherwise vertex 0 remains marked and will be skipped in BFS.
    bfs(graph, 0, queue);
    printf("\n");
    free(queue);
    i = 0;
    for(i = 0; i < 110; i ++) {
        graph[a][i] = 0; // @@ 'a' does not reliably store the deletion vertex due to incorrect input parsing; the deletion vertex should be read separately.
        graph[i][a] = 0;
    }
    for(i = 1; i < 110; i ++) visited[i] = 0; // @@ Should start from 0 to reset visited[0] before the second DFS traversal.
    dfs(graph, 0);
    printf("\n");
    queue = (int *) malloc(sizeof(int) * 1000);
    for(i = 1; i < 110; i ++) visited[i] = 0; // @@ Should start from 0 to reset visited[0] before the second BFS traversal.
    bfs(graph, 0, queue);
    free(queue);
    return 0;
}