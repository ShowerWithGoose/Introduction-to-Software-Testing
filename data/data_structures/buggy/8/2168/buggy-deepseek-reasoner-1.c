#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int graph[110][110];
int visited[110];

void dfs(int arr[][110], int ind) {
    printf("%d ", ind);
    int i = 0;
    for(i = 1; i < 110; i ++) { // @@ Error: loop should start from 0 to include vertex 0. Also, visited[0] is not set to 1 before the first call, which can cause infinite recursion when a neighbor has an edge back to 0.
        if(arr[ind][i] != 0 && visited[i] == 0){
            visited[i] = 1;
            dfs(arr, i);
        }
    }
    return ;
}

void bfs(int arr[][110], int ind, int *queue) {
    int i = 1;
    int tail = 0, head = 0;
    queue[tail] = ind;
    tail++;
    while(head < tail){
        printf("%d ", queue[head]);
        ind = queue[head];
        head++;
        for(i = 1; i < 110; i++) { // @@ Error: loop should start from 0; also visited[0] is not set to 1 initially, causing potential issues.
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
    while(scanf("%d ", &a) != EOF){ // @@ Error: Input parsing is incorrect. Should first read n and m, then m edges, then the delete vertex. This loop treats all numbers as pairs, misinterpreting n and m as an edge.
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
    dfs(graph, 0); // @@ Error: visited[0] is not set to 1 before the call, causing potential infinite recursion or incorrect traversal.
    printf("\n");
    
    int *queue = (int *) malloc(sizeof(int) * 1000);
    for(i = 1; i < 110; i ++) visited[i] = 0; // @@ Error: visited[0] is not reset, though it may be 0 initially. Should reset visited[0] to 0 as well.
    bfs(graph, 0, queue); // @@ Error: visited[0] is not set to 1 before the call.
    printf("\n");
    free(queue);
    i = 0;
    for(i = 0; i < 110; i ++) {
        graph[a][i] = 0;
        graph[i][a] = 0;
    }
    for(i = 1; i < 110; i ++) visited[i] = 0; // @@ Error: again missing visited[0].
    dfs(graph, 0); // @@ Error: visited[0] not set.
    printf("\n");
    queue = (int *) malloc(sizeof(int) * 1000);
    for(i = 1; i < 110; i ++) visited[i] = 0; // @@ Error: missing visited[0].
    bfs(graph, 0, queue); // @@ Error: visited[0] not set.
    free(queue);
    return 0;
}