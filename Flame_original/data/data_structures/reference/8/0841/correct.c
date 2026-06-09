#include <stdio.h>
#include <string.h>

#define max_size 100 + 10
int graph[max_size][max_size];
int visit[max_size];
int queue[max_size];

void DFS(int start);

void BFS(int start);

int number_of_vertex = 0, number_of_edge = 0;

int main(void) {

    scanf("%d %d", &number_of_vertex, &number_of_edge);
    for (int i = 0; i < number_of_edge; i++) {
        int vertex_first = 0, vertex_two = 0;
        scanf("%d %d", &vertex_first, &vertex_two);
        graph[vertex_two][vertex_first] = 1;
        graph[vertex_first][vertex_two] = 1;
    }
    DFS(0);
    putchar('\n');
    memset(visit, 0, max_size);
    BFS(0);
    putchar('\n');
    memset(visit, 0, max_size);
    int delete_vertex = 0;
    scanf("%d", &delete_vertex);
    visit[delete_vertex] = 1;
    DFS(0);
    memset(visit, 0, max_size);
    visit[delete_vertex] = 1;
    putchar('\n');
    BFS(0);

    return 0;
}

void DFS(int start) {

    printf("%d ", start);
    visit[start] = 1;
    for (int i = 0; i < number_of_vertex; i++)
        if (graph[start][i] != 0 && visit[i] == 0)
            DFS(i);
}

void BFS(int start) {

    int front = 0, rear = 0;
    queue[rear++] = start;
    while (front <= rear) {
        if (visit[queue[front]] == 0) {
            printf("%d ", queue[front]);
            visit[queue[front]] = 1;
            for(int i = 0; i < number_of_vertex; i++)
                if(graph[queue[front]][i] != 0 && visit[i] == 0)
                    queue[rear++] = i;
        }
        front++;
    }
}


