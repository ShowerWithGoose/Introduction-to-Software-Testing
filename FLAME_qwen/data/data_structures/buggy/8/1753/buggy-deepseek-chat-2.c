# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <malloc.h>
# define N 100
int graph[N][N] = {0};
int vertex,edge;
int vertex2;
int searched[N] = {0};
int queue[N] = {0};
int head,rear;
void empty(void);
void DFS(int *);
void BFS(int *);
void print(void);
void push(void);
int main(){
    searched[0] = 1;
    scanf("%d%d",&vertex,&edge);
    vertex2 = vertex;
    for(int i = 0;i < edge;i++){
        int temp1,temp2;
        scanf("%d%d",&temp1,&temp2);
        graph[temp1][temp2] = 1;
        graph[temp2][temp1] = 1;
    }
    // print();
    empty();
    printf("0 ");
    DFS(graph[0]);
    printf("\n");
    empty();
    BFS(graph[0]);
    push();
    int target = 0;
    scanf("%d",&target);
    for (int i = 0; i < vertex; i++)
    {
        graph[i][target] = 0;
        graph[target][i] = 0;
    }
    // print();
    empty();
    printf("0 ");
    DFS(graph[0]);
    printf("\n");
    empty();
    vertex2--;
    BFS(graph[0]);
    push();
    getchar();getchar();
    return 0;
}
void empty(void){
    for(int i = 1;i < vertex;i++)
        searched[i] = 0;
    head = 0;
    rear = 1;
}
void DFS(int *v){
    for(int i = 0;i < vertex;i++){
        if(v[i] == 1 && searched[i] != 1){
            searched[i] = 1;
            printf("%d ",i);
            DFS(graph[i]);
        }
    }
    return;
}
void BFS(int *v){
    for (int i = 0; i < vertex; i++)
    {
        if (v[i] == 1 && searched[i] == 0)
        {
            queue[rear] = i;
            rear++;
            searched[i] = 1;
        }
    }
    head++;
    if(rear == vertex2)return;
    BFS(graph[queue[head]]);
    return;
}
void push(){
    for (int i = 0; i < vertex2; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
void print(void){
    printf(" ");
    for (int i = 0; i < vertex; i++)
    {
        printf(" %d",i);
    }
    printf("\n");
    for(int i = 0;i < vertex;i++){
        printf("%d ",i);
        for (int j = 0; j < vertex; j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}