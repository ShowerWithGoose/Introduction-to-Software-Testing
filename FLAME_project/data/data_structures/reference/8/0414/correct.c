#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int a;
    struct Node *next;
};
typedef struct Node VLink, *nodeptr;
nodeptr pic;
int Visited[110] = {0}; //标识顶点是否被访问
int mode=0;
int del;
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void travelBFS(VLink G[], int n);
void BFS(VLink G[], int v);
void travelDFS(VLink G[], int n);
void DFS(VLink G[], int v);

int main()
{
    int i;
    int m, n, ip, iq;
    nodeptr np, nq, ntmp;
    scanf("%d%d", &m, &n);
    pic = (nodeptr)malloc(sizeof(struct Node) * m);
    for (i = 0; i < m; i++)
    {
        pic[i].a = i;
        pic[i].next = NULL;
    }
    //输入节点
    while (n--)
    {
        scanf("%d%d", &ip, &iq);
        for (i = 0; i < 2; i++)
        {
            swap(&ip, &iq);
            ntmp = (nodeptr)malloc(sizeof(struct Node));
            ntmp->a = iq;
            np = pic + ip;
            nq = pic[ip].next;
            while (nq != NULL)
            {
                if (nq->a >= ntmp->a)
                    break;
                np = nq;
                nq = nq->next;
            }
            if (nq != NULL)
                if (nq->a == ntmp->a)
                    continue;
            np->next = ntmp;
            ntmp->next = nq;
        }
    }
    scanf("%d",&del);
    /*//输出节点检查
    for (i = 0; i < m; i++)
    {
        printf("%d ", pic[i].a);
        np = pic[i].next;
        while (np != NULL)
        {
            printf("-> %d ", np->a);
            np = np->next;
        }
        printf("\n");
    }*/
    travelDFS(pic,m);
    putchar('\n');
    travelBFS(pic,m);
    putchar('\n');
    mode=1;
    travelDFS(pic,m);
    putchar('\n');
    travelBFS(pic,m);
    return 0;
}

//广度优先遍历(Breadth First Search,BFS)
void travelBFS(VLink G[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    if(mode)
        Visited[del]=1;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            BFS(G, i);
}
void BFS(VLink G[], int v)
{
    int line[210] = {0};
    int front = 0, roar = 0;
    VLink *p;
    printf("%d ", G[v].a);
    Visited[v] = 1; //标识某顶点被访问过
    // enQueue(Q, v);
    line[roar++] = v;
    while (front < roar)
    {
        // v = deQueue(Q); 取出队头元素
        v = line[front++];
        p = G[v].next; //获取该顶点第一个邻接顶点
        /*访问该顶点的每个邻接顶点*/
        for (; p != NULL; p = p->next)
            if (!Visited[p->a])
            {
                printf("%d ", G[p->a].a);
                Visited[p->a] = 1;
                line[roar++] = p->a;
                //enQueue(G, p->a);
            }
    }
}

//深度优先遍历(Depth First Search,DFS)
void travelDFS(VLink G[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    if(mode)
        Visited[del]=1;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            DFS(G, i);
}
/*遍历一个连通子图*/
void DFS(VLink G[], int v)
{
    VLink *p;
    printf("%d ", G[v].a);
    //访问某顶点
    Visited[v] = 1; //标识某顶点被访问过
    for (p = G[v].next; p != NULL; p = p->next)
        if (!Visited[p->a])
            DFS(G, p->a);
}

