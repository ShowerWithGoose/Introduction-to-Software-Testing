#include <stdio.h>
#define MAXVEX 120
int A[MAXVEX][MAXVEX];
int visited[MAXVEX];
int Queue[MAXVEX];
int head = -1, rear = 0;
void creatEdge(int v1, int v2)
{
    if(v1 < MAXVEX || v2 < MAXVEX)
        A[v1][v2] = A[v2][v1] = 1;
    return;
}
void deleteVex(int v)
{
    int i, j;
    for(i = 0; i < MAXVEX; i++)
        A[v][i] = 0;
    for(i = 0; i < MAXVEX; i++)
        A[i][v] = 0;
    return;
}
void visitVex(int v)
{
    printf("%d ", v);
    visited[v] = 1;
    return;
}
void DFSgraph(int v, int max)
{
    int i;
    visitVex(v);
    for(i = 0; i < max; i++)
    {
        if(!visited[i] && A[v][i] == 1 )
            DFSgraph(i, max);
    }
    return;
}
void BFSgraph(int v, int max)
{
    int i;
    if(head > rear)
        return;
    visitVex(v);
    head++;
    for(i = 0; i < max; i++)
    {
        if(A[v][i] == 1 && !visited[i])
        {
            Queue[++rear] = i;
            visited[i] = 1;
        }

    }
    BFSgraph(Queue[head], max);
    return;
}
void refresh(int array[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        array[i] = 0;
}
int main()
{
    int i, j, del;
    int vex, edge;
    scanf("%d%d", &vex, &edge);
    int vex1, vex2;
    for(i = 0; i < edge; i++)
    {
        scanf("%d%d", &vex1, &vex2);
        creatEdge(vex1, vex2);
    }
    scanf("%d", &del);
//    for(i = 0; i < vex; i++)
//    {
//        for(j = 0; j < vex; j++)
//            printf("%d ", A[i][j]);
//        printf("\n");
//    }
//    printf("\n");
    DFSgraph(0, vex);
    printf("\n");
    refresh(visited, vex);

    Queue[++head] = 0;
    BFSgraph(Queue[head], vex);
    printf("\n");
    refresh(visited, vex);
    refresh(Queue, MAXVEX);

    deleteVex(del);

    DFSgraph(0, vex);
    printf("\n");
    refresh(visited, vex);

    rear = 0, head = -1;
    Queue[++head] = 0;
    BFSgraph(Queue[head], vex);
    printf("\n");

    return 0;
}

