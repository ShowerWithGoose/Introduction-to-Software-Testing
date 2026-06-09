#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 512
int V, E; // vertex, edge
typedef struct EDGE{
    int adjvex; // 邻接顶点
    int weight; // 边的权重（可以为时间、距离等），此题均为1
    struct EDGE *next;
} edge;
typedef struct VERTEX{
    edge *link;
} ver;
ver Graph[MAXSIZE]; // 由邻接表构成的图
int Visited[MAXSIZE] = {0}; // 标识相应顶点是否被访问
edge *insert_edge(edge *head, int avex){
    edge *e, *p, *q = NULL;
    e = (edge*)malloc(sizeof(edge));
    e->adjvex = avex; e->weight = 1; e->next = NULL;
    if(head == NULL){
        head = e;
    }
    else{
        for(p=head; p!=NULL && p->adjvex<avex; q=p,p=p->next);
        if(p == head){ // 头结点前插入
            e->next = p;
            head = e;
        }
        else{
            q->next = e;
            e->next = p;
        }
    }
    return head;
}
void dfs(ver g[], int v){
    edge *p;
    Visited[v] = 1; // 先标记！
    printf("%d ", v); // VISIT(g, v);
    for(p=g[v].link; p!=NULL; p=p->next){
        if(!Visited[p->adjvex])
            dfs(g, p->adjvex);
    }
    return;
}
void trav_dfs(ver g[], int v, int dnum){
    memset(Visited, 0, sizeof(Visited));
    int i;
    if(dnum != -1)
        Visited[dnum] = 1; // 标记为已访问，以充当删除
    
    for(i=0; i<v; ++i){
        if(Visited[i] == 0)
            dfs(g, i);
    }
    printf("\n");
    return;
}
int Q[MAXSIZE];
int front = 0, rear = MAXSIZE - 1, count = 0;
void init_queue(){
    front = 0;
    rear = MAXSIZE - 1;
    count = 0;
    return;
}
void enqueue(int q[], int item){
    if(count == MAXSIZE){
        printf("queue full!\n");
        return;
    }
    rear = (rear + 1) % MAXSIZE;
    q[rear] = item;
    count += 1;
    return;
}
int dequeue(int q[]){
    int e;
    if(count == 0){
        printf("empty!\n");
        return -1;
    }
    e = q[front];
    count -= 1;
    front = (front + 1) % MAXSIZE;
    return e;
}
void bfs(ver g[], int v){
    edge *p;
    init_queue();
    Visited[v] = 1;
    enqueue(Q, v);
    while(count != 0){
        v = dequeue(Q);
        printf("%d ", v);
        for(p=Graph[v].link; p!=NULL; p=p->next){
            if(Visited[p->adjvex] == 0){
                Visited[p->adjvex] = 1;
                enqueue(Q, p->adjvex);
            }
        }
    }
    return;
}
void trav_bfs(ver g[], int v, int dnum){
    memset(Visited, 0, sizeof(Visited));
    int i;
    if(dnum != -1)
        Visited[dnum] = 1; // 标记为已访问，以充当删除
    
    for(i=0; i<v; ++i){
        if(Visited[i] == 0)
            bfs(g, i);
    }
    printf("\n");
    return;
}
int main()
{
    // 初始化
    int i, delete_num, v1, v2;
    scanf("%d %d", &V, &E);
    for(i=0; i<E; ++i){
        scanf("%d %d", &v1, &v2);
        Graph[v1].link = insert_edge(Graph[v1].link, v2);
        Graph[v2].link = insert_edge(Graph[v2].link, v1);
    }
    // 先无删除、遍历
    trav_dfs(Graph, V, -1);
    trav_bfs(Graph, V, -1);
    // 再删除某节点、遍历
    scanf("%d", &delete_num);
    trav_dfs(Graph, V, delete_num);
    trav_bfs(Graph, V, delete_num);
    system("pause");
    return 0;
}
