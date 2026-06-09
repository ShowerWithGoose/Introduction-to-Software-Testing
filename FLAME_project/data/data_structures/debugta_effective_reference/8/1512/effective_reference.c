#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 105
typedef struct _pic
{
    int weight;
    int adjvex;
    struct _pic *next;
} pic;
pic list[MAX];
int flag[MAX], queue[MAX], front = 0, rear = MAX - 1, count = 0, del;
void enqueue(int k)
{
    rear = (rear + 1) % (MAX - 1);
    queue[rear] = k;
    count++;
    return;
}
int dequeue()
{
    int output = queue[front];
    front = (front + 1) % (MAX - 1);
    count--;
    return output;
}
void org(int numOfNode)
{
    int i;
    for (i = 0; i < numOfNode; i++)
    {
        flag[i] = 0;
    }
    return;
}
void insertNode(int n1, int n2)
{
    pic *p = NULL, *q = NULL, *r = NULL;
    q = (pic *)malloc(sizeof(pic));
    q->adjvex = n2;
    q->weight = 1;
    q->next = NULL;
    p = &list[n1];
    while (p != NULL && p->adjvex < n2)
    {
        r = p;
        p = p->next;
    }
    r->next = q;
    q->next = p;
    return;
}
void DFS(int k)
{
    pic *p;
    if (flag[k])
    {
        return;
    }
    printf("%d ", k); // visit
    flag[k] = 1;
    p = list[k].next;
    while (p != NULL)
    {
        if (!flag[p->adjvex])
        {
            DFS(p->adjvex);
        }
        p = p->next;
    }
    return;
}
void tDFS(int numOfNode)
{
    int i;
    org(numOfNode);
    for (i = 0; i < numOfNode; i++)
    {
        if (flag[i])
        {
            continue;
        }
        DFS(i);
    }
    return;
}
void BFS(int k)
{
    int res;
    pic *p;
    printf("%d ", k); // visit
    enqueue(k);
    flag[k] = 1;
    while (count != 0)
    {
        res = dequeue();
        p = list[res].next;
        while (p != NULL)
        {
            if (flag[p->adjvex])
            {
                p = p->next;
                continue;
            }
            printf("%d ", p->adjvex); // visit
            flag[p->adjvex] = 1;
            enqueue(p->adjvex);
            p = p->next;
        }
    }
    return;
}
void tBFS(int numOfNode)
{
    int i;
    org(numOfNode);
    front = 0, rear = -1, count = 0;
    for (i = 0; i < numOfNode; i++)
    {
        if (flag[i])
        {
            continue;
        }
        BFS(i);
    }
    return;
}
void dDFS(int numOfNode)
{
    int i;
    org(numOfNode);
    flag[del] = 1;
    for (i = 0; i < numOfNode; i++)
    {
        if (flag[i])
        {
            continue;
        }
        DFS(i);
    }
    return;
}
void dBFS(int numOfNode)
{
    int i;
    org(numOfNode);
    flag[del] = 1;
    front = 0, rear = -1, count = 0;
    for (i = 0; i < numOfNode; i++)
    {
        if (flag[i])
        {
            continue;
        }
        BFS(i);
    }
    return;
}
int main()
{
    int numOfEdge, numOfNode, i, n1, n2;
    // pic *p;
    scanf("%d%d", &numOfNode, &numOfEdge);
    for (i = 0; i < numOfNode; i++)
    {
        list[i].adjvex = -1;
        list[i].next = NULL;
    }
    for (i = 0; i < numOfEdge; i++)
    {
        scanf("%d%d", &n1, &n2);
        insertNode(n1, n2);
        insertNode(n2, n1);
    }
    scanf("%d", &del);
    tDFS(numOfNode);
    printf("\n");
    tBFS(numOfNode);
    printf("\n");
    dDFS(numOfNode);
    printf("\n");
    dBFS(numOfNode);
    printf("\n");
    return 0;
}
