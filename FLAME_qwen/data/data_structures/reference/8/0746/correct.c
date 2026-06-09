#include <stdio.h>
#include <stdlib.h>
#define VER_MAX 100

int A[VER_MAX][VER_MAX];
int Visited[VER_MAX];
int ver_num, side_num;
void TravelDFS(int A[][VER_MAX], int n);
void DFS(int A[][VER_MAX], int i);
void TravelBFS(int A[][VER_MAX], int n);
void BFS(int A[][VER_MAX], int i);
int de_ver = -1;
int main()
{
    //读入,建立邻接矩阵
    scanf("%d%d", &ver_num, &side_num);
    int a, b;
    for (int i = 0; i < side_num; i++){
        scanf("%d%d", &a, &b);
        A[a][b] = A[b][a] = 1;
    }

    TravelDFS(A, ver_num);
    TravelBFS(A, ver_num);
    scanf("%d", &de_ver);
    TravelDFS(A, ver_num);
    TravelBFS(A, ver_num);
    return 0;
}

void TravelDFS(int A[][VER_MAX], int n)
{
    for (int i = 0; i < n; i++)
        Visited[i] = 0;
    for (int i = 0; i < n; i++){
        if (i == de_ver)
            continue;
        if (!Visited[i])
            DFS(A, i);
    }
    printf("\n");
}
void DFS(int A[][VER_MAX], int i)
{
    Visited[i] = 1;
    printf("%d ", i);
    for (int j = 0; j < ver_num; j++){
        if (j == de_ver)
            continue;
        if (A[i][j] && !Visited[j])
            DFS(A, j);
    }
}



void TravelBFS(int A[][VER_MAX], int n)
{
    for (int i = 0; i < n; i++)
        Visited[i] = 0;
    for (int i = 0; i < n; i++){
        if (i == de_ver)
            continue;
        if (!Visited[i])
            BFS(A, i);
    }
    printf("\n");
}
int Q[VER_MAX];
int Q_head = 0, Q_end = -1;
void enQueue(int Q[], int num)
{
    Q[++Q_end] = num;
}
void deQueue(int Q[])
{
    Q_head++;
}
int empty(int Q[])
{
    return Q_end - Q_head == -1;
}
void BFS(int A[][VER_MAX], int i)
{
    Visited[i] = 1;
    enQueue(Q, i);
    while (!empty(Q)){
        printf("%d ", Q[Q_head]);
        i = Q[Q_head];
        deQueue(Q);
        for (int j = 0; j < ver_num; j++){
            if (j == de_ver)
                continue;
            if (A[i][j] && !Visited[j]){
                Visited[j] = 1;
                enQueue(Q, j);
            }
        }
    }
}



