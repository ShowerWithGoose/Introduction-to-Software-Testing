#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int graph[110][110];
int visited[110];

void dfs(int arr[][110], int ind) {
    printf("%d ", ind);
    int i = 0;
    for(i = 1; i < 110; i ++) { // @@ Error: Loop starts from i=1, but vertices are labeled from 0 to n-1, so vertex 0 is skipped in adjacency traversal
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
        for(i = 1; i < 110; i++) { // @@ Error: Loop starts from i=1, but vertices are labeled from 0 to n-1, so vertex 0 is skipped in adjacency traversal
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
    while(scanf("%d ", &a) != EOF){ // @@ Error: Input reading logic is incorrect; it does not properly read n, m, edges, and the vertex to delete as specified in the problem
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
    for(i = 1; i < 110; i ++) visited[i] = 0; // @@ Error: visited[0] is not initialized to 0, but it should be
    bfs(graph, 0, queue);
    printf("\n");
    free(queue);
    i = 0;
    for(i = 0; i < 110; i ++) {
        graph[a][i] = 0;
        graph[i][a] = 0;
    }
    for(i = 1; i < 110; i ++) visited[i] = 0; // @@ Error: visited[0] is not initialized to 0, but it should be
    dfs(graph, 0);
    printf("\n");
    queue = (int *) malloc(sizeof(int) * 1000);
    for(i = 1; i < 110; i ++) visited[i] = 0; // @@ Error: visited[0] is not initialized to 0, but it should be
    bfs(graph, 0, queue);
    free(queue);
    return 0;
}