#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int graph[110][110];
int visited[110];

void dfs(int arr[][110], int ind) {
    printf("%d ", ind); // @@ Missing visited[ind] = 1; leads to infinite recursion if graph contains cycle back to ind.
    int i = 0;
    for(i = 1; i < 110; i ++) {
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
    // @@ Missing visited[ind] = 1; causes vertex 0 to never be marked visited, leading to possible revisit.
    while(head < tail){
        printf("%d ", queue[head]);
        ind = queue[head];
        head++;
        for(i = 1; i < 110; i++) {
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
    while(scanf("%d ", &a) != EOF){
        if(times == 2) {
            graph[a][temp] = 1; // @@ Incorrect: treats the second integer (m) as a vertex, creating an extraneous edge between n and m.
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
    for(i = 1; i < 110; i ++) visited[i] = 0;
    bfs(graph, 0, queue);
    printf("\n");
    free(queue);
    i = 0;
    for(i = 0; i < 110; i ++) {
        graph[a][i] = 0;
        graph[i][a] = 0;
    }
    for(i = 1; i < 110; i ++) visited[i] = 0;
    dfs(graph, 0);
    printf("\n");
    queue = (int *) malloc(sizeof(int) * 1000);
    for(i = 1; i < 110; i ++) visited[i] = 0;
    bfs(graph, 0, queue);
    free(queue);
    return 0;
}