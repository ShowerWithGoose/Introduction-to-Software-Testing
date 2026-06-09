/*#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define maxgraph 200
typedef struct node{
    int  adj,wei;
    struct node  *next;
} enode, *elink;

elink g[maxgraph];//图
int ver, edge; //顶点数，边数
elink insert_graph(elink head, int ele){
    elink e, a, b = NULL;
    e = (elink)malloc(sizeof(enode));
    e->adj = ele;   e->wei=1;   e->next = NULL;
    if(head == NULL)    return e;
    for(a=head; a != NULL && ele > a->adj;  b = a, b = b->next);//找插入位置
    if(a == head){//头结点
        e->next = a;
        return e;
    }
    else {//结点p
        b->next = e;
        e->next = a;
        return head;
    }
}
void create_graph(elink graph[]){
    for(int i = 0 ; i < edge ; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a]=insert_graph(graph[a], b);
        graph[b]=insert_graph(graph[b], a);
    }
}
int flag[maxgraph]={0}; //标记
void dfs(elink  graph[], int ver){//深度优先遍历
    elink a;
    flag[ver] = 1;
    printf("%d ", ver);//访问
    for(a = graph[ver]; a !=NULL;  a = a->next)
        if(flag[a->adj] != 0)
            dfs(g, a->adj);
}
void  delete_dfs(elink graph[], int n, int d){//深度优先删除
    int i;
    for(i=0; i<n; i++)  flag[i] = 0 ;
    if(d >= 0)  flag[d] = 1;//删除
    for(i=0; i<n; i++)  if(flag[i] != 0)    dfs(g, i);
    printf("\n");
}
#define maxsize 500
int queue[maxsize];//循环队列
int front, rear, n;
void  init_queue(void){
    front = n = 0;
    rear = maxsize-1;
}
void insert_queue(int queue[], int ele){//入队
    if(n == maxsize)    printf("满了");
    else{
        rear = (rear+1) % maxsize;
        queue[rear]=ele;
        n++;
    }
}
int  delete_queue(int queue[]){//出队
    int e;
    if(n == 0)  printf("空的");
    else{
        e=queue[front];
        front = (front+1) % maxsize;
        n--;
        return e;
    }
    return 0;
}
void bfs(elink graph[], int ver){//广度优先遍历
    elink a;
    init_queue();
    flag[ver] = 1;//标记已经入队
    insert_queue(queue, ver);
    while(n != 0){
        ver = delete_queue(queue);//出队
        printf("%d ", ver);//访问
        for(a = graph[ver]; a != NULL ; a = a->next )//访问每个邻接顶点
            if(flag[a->adj] != 0){
                flag[a->adj] = 1;
                insert_queue(queue, a->adj);
            }
    }
}
void  delete_bfs(elink g[ ], int n, int d){//广度优先删除
    int i;
    for(i=0; i<n; i++)  flag[i] = 0 ;
    if(d >= 0)  flag[d] = 1;//删除
    for(i=0; i<n; i++)  if(flag[i] != 0)    bfs(g, i);
    printf("\n");
}

int main(){
    scanf("%d %d",&ver,&edge);
    create_graph(g);
    delete_dfs(g,ver,-1);//-1不删除顶点
    delete_bfs(g,ver,-1);
    int k;//删除顶点编号
    scanf("%d",&k);
    delete_dfs(g,ver,k);//懒惰删除
    delete_bfs(g,ver,k);
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#define MaxV 200
typedef struct edge{
    int  adj;
    int  wei;
    struct edge  *next;
} ELink;
typedef struct ver{
    ELink  *link;
} VLink;
VLink  G[MaxV];
int V, E;
void createGraph(VLink graph[]);
void  travelDFS(VLink  G[ ], int n, int delV);
void  travelBFS(VLink  G[ ], int n, int delV);
int main(int argc, const char * argv[]) {
    scanf("%d %d",&V,&E);
    createGraph(G);
    travelDFS(G,V,-1);
    travelBFS(G,V,-1);
    int k;
    scanf("%d",&k);
    travelDFS(G,V,k);
    travelBFS(G,V,k);
    return 0;
}
ELink  *insertEdge(ELink *head, int avex){
    ELink *e,*p,*q = NULL;
    e =(ELink *)malloc(sizeof(ELink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)
        return e;
    for(p=head; p != NULL && avex > p->adj;  q = p, p = p->next);
    if( p == head){
        e->next = p;
        return e;
    }
    else{
        q->next = e;
        e->next = p;
        return head;
    }
}

void createGraph(VLink graph[]){
    for(int i=0;i<E;i++){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link, v2);
        graph[v2].link=insertEdge(graph[v2].link, v1);
    }
}


int Visited[MaxV]={0};
void DFS(VLink  G[ ], int v){
    ELink  *p;
    Visited[v] = 1;
    printf("%d ", v);
    for(p = G[v].link; p !=NULL;  p=p->next)
        if( !Visited[p->adj] )
            DFS(G, p->adj);
}

void  travelDFS(VLink  G[ ], int n, int delV){
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV >= 0)
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
    printf("\n");
}

#define MAXSIZE 500
int  Q[MAXSIZE];
int  Front, Rear,Count;
void  initQueue(void){
    Front = 0;
    Rear = MAXSIZE-1;
    Count = 0;
}
int  isEmpty(){
    return Count == 0;
}
int  isFull(){
    return Count == MAXSIZE;
}
void enQueue(int queue[ ], int item){
    if(isFull())
        printf("Full queue!");
    else{
        Rear = (Rear+1) % MAXSIZE;
        queue[Rear]=item;
        Count++;
    }
}
int  deQueue(int queue[ ]){
    int e;
    if(isEmpty())
        printf("Empty queue!");
    else{
        e=queue[Front];
        Count--;
        Front = (Front+1) % MAXSIZE;
        return e;
    }
    return 0;
}


void BFS(VLink  G[ ], int v){
    ELink  *p;
    initQueue();
    Visited[v] = 1;
    enQueue(Q, v);
    while( !isEmpty()){
        v = deQueue(Q);
        printf("%d ",v);
        for(p=G[v].link; p!=NULL; p=p->next )
            if( !Visited[p->adj] ) {
                Visited[p->adj] = 1;
                enQueue(Q, p->adj);
            }
    }
}

void  travelBFS(VLink  G[ ], int n, int delV){
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV >= 0) 
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] )
            BFS(G, i);
    printf("\n");
}


