#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 105

int quantity_of_vertex, quantity_of_edge;
int graph[MAX_V][MAX_V] = {0};
int visit[MAX_V];

void DFS(int vertex){
    printf("%d ", vertex);
    visit[vertex] = 1;
    for(int i = 0; i < quantity_of_vertex; i++){
        if(graph[vertex][i] && !visit[i]){
            DFS(i);
        }
    }
}

void DFSGraph(void){
    memset(visit, 0, sizeof(int) * MAX_V);
    DFS(0);
    printf("\n");
}

void BFS(int vertex){
    int queue[MAX_V];
    int front = 0, rear = -1;
    queue[++rear] = vertex;
    visit[0] = 1;
    while(rear - front >= 0){
        printf("%d ", queue[front]);
        for(int i = 0; i < quantity_of_vertex; i++){
            if(graph[queue[front]][i] && !visit[i]){
                queue[++rear] = i;
                visit[i] = 1;
            }
        }
        front++;
    }
}

void BFSGraph(void){
    memset(visit, 0, sizeof(int) * MAX_V);
    BFS(0);
    printf("\n");
}

int main(){
    scanf("%d%d", &quantity_of_vertex, &quantity_of_edge);

    int v1, v2;
    for(int i = 0; i < quantity_of_edge; i++){
        scanf("%d%d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    DFSGraph();
    BFSGraph();

    scanf("%d", &v1);
    for(int i = 0; i < quantity_of_edge; i++){
        graph[v1][i] = 0;
        graph[i][v1] = 0;
    }

    DFSGraph();
    BFSGraph();

    return 0;
}
