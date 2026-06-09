#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int graph[110][110];
int visited[110];

void dfs(int arr[][110], int ind) {
    printf("%d ", ind); // @@ Missing visited[ind] = 1; here, which can lead to revisiting nodes in cyclic graphs.
    int i = 0;
    for(i = 1; i < 110; i ++) { // @@ Loop should start from 0 to correctly visit vertex 0 as a neighbor, since vertices are labeled 0 to n-1.
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
        for(i = 1; i < 110; i++) { // @@ Loop should start from 0 to correctly visit vertex 0 as a neighbor, since vertices are labeled 0 to n-1.
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
    while(scanf("%d ", &a) != EOF){ // @@ Incorrect input parsing: fails to read n and m separately, treating them as edge vertices. Should read n, m, then loop m times for edges, then read the vertex to delete.
        if(times == 2) {
            graph[a][temp] = 1; // @@ Incorrectly treats n and m as edge endpoints due to flawed input parsing logic.
            graph[temp][a] = 1; // @@ Incorrectly treats n and m as edge endpoints due to flawed input parsing logic.
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
    for(i = 1; i < 110; i ++) visited[i] = 0; // @@ visited[0] is not reset to 0, which may cause incorrect traversal results. Should reset from i = 0.
    bfs(graph, 0, queue);
    printf("\n");
    free(queue);
    i = 0;
    for(i = 0; i < 110; i ++) {
        graph[a][i] = 0;
        graph[i][a] = 0;
    }
    for(i = 1; i < 110; i ++) visited[i] = 0; // @@ visited[0] is not reset to 0, which may cause incorrect traversal results. Should reset from i = 0.
    dfs(graph, 0);
    printf("\n");
    queue = (int *) malloc(sizeof(int) * 1000);
    for(i = 1; i < 110; i ++) visited[i] = 0; // @@ visited[0] is not reset to 0, which may cause incorrect traversal results. Should reset from i = 0.
    bfs(graph, 0, queue);
    free(queue);
    return 0;
}