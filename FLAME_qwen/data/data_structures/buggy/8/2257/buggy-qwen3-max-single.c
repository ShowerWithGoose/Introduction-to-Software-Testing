#include <stdio.h>
#include<stdlib.h>
#define OK 1
typedef int QueueElem;
typedef int Bool;
typedef int Status;
typedef struct QNode{
    QueueElem data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
    int length;
}Queue;

Status InitQueue(Queue *Q);
Status DestroyQueue(Queue *Q);
Status ClearQueue(Queue *Q);
Bool QueueEmpty(Queue Q);
int QueueLength(Queue Q);
Status EnQueue(Queue *Q,QueueElem e);
Status DeQueue(Queue *Q,QueueElem *e);
QueueElem GetFront(Queue *Q);
QueueElem GetRear(Queue *Q);


void PrintQueue(Queue Q);

int AdjVertex[101][101];
int n,m;
int *visited;
void addEdge(int v1, int v2)
{
    AdjVertex[v1][v2] = 1;
    AdjVertex[v2][v1] = 1;
}

void removeEdge(int v1, int v2)
{
    AdjVertex[v1][v2] = 0;
    AdjVertex[v2][v1] = 0;
}

void removeNode(int v){
    for (int i = 0; i < n; i++)
    {
        AdjVertex[v][i] = 0;
        AdjVertex[i][v] = 0;
    }
}

void dfs(int v){
    visited[v] = 1;
    printf("%d ",v);
    for (int i = 0; i < n; i++)
    {
        if(AdjVertex[v][i] == 1&&visited[i] == 0){
            dfs(i);
        }
    }
}

void bfs(int v){
    Queue Q;
    InitQueue(&Q);
    EnQueue(&Q,v);
    while(!QueueEmpty(Q)){
        DeQueue(&Q,&v); 
        printf("%d ",v);
        visited[v] = 1;
        for (int i = 0; i < n; i++){
            if(AdjVertex[v][i] == 1&&visited[i] == 0){
                EnQueue(&Q,i);
                visited[i] = 1;
            }
        }
    }
}

void reset(){
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
}

int main(int argc, char const *argv[])
{
    int v1,v2;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; i++){
        scanf("%d %d",&v1,&v2);
        addEdge(v1,v2);
    }
    visited = (int*)calloc(n,sizeof(int));
    reset();
    dfs(0);
    reset();
    printf("\n");
    bfs(0);
    printf("\n");
    scanf("%d",&v1);
    removeNode(v1);
    reset();
    dfs(0);
    printf("\n");
    reset();
    bfs(0);

    printf("\n%d\n",AdjVertex[8][6]);
    system("pause"); // @@ [The function 'system' is declared in <stdlib.h>, but some compilers or environments may not support it or require additional linking. However, the actual compilation error reported is "gcc: not found", which indicates a missing compiler, not a code error. But since the problem states there's a Compilation Error and asks to locate errors in the program, the real issue is likely in the BFS queue implementation. Specifically, in DeQueue(), when the queue has only one element, accessing q->next->data after freeing leads to undefined behavior. Also, GetFront() returns NULL (which is typically ((void*)0)) as an int, causing type mismatch. However, the immediate cause of compilation failure in strict environments could be the use of 'NULL' as an integer return value in GetFront() and GetRear().]
    return 0;
}

/*
kong ->  1 ->  2 ->  3->  4
|                         |
队头                      队尾  入队
    <-------------- 队列方向
*/

Status InitQueue(Queue *Q){
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
    Q->length=0;
    return OK;
}

Status DestroyQueue(Queue *Q){
    QueuePtr p=Q->front;
    while(p){
        QueuePtr q=p;
        p=p->next;
        free(q);
    }
    Q->front=Q->rear=NULL;
    Q->length=0;
    return OK;
}

Status ClearQueue(Queue *Q){
    QueuePtr p=Q->front;
    while(p->next){
        QueuePtr q=p;
        p=p->next;
        free(q);
    }
    p->data=0;
    p->next=NULL;
    Q->front=Q->rear=p;
    Q->length=0;
    return OK;
}

Bool QueueEmpty(Queue Q){
    return Q.length==0;
}

int QueueLength(Queue Q){
    return Q.length;
}




Status EnQueue(Queue *Q,QueueElem e){
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    p->data=e;
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;
    Q->length++;
    return OK;
}

Status DeQueue(Queue *Q,QueueElem *e){
    QueuePtr q=Q->front;
    Q->front=Q->front->next;
    (*e)=q->next->data; // @@ [When the queue has only one element, q->next is the node to be dequeued. However, after Q->front is updated to Q->front->next (which is q->next), then q->next might be invalid after free. But more critically, if the queue is empty, this causes undefined behavior. However, the function assumes non-empty queue due to prior QueueEmpty check. The real bug is that q points to the dummy head, so q->next is the first real node. But after freeing q, accessing q->next is invalid. Actually, the assignment (*e)=q->next->data happens before free, so it's safe. However, the bigger issue is in GetFront and GetRear returning NULL as int.]
    free(q);
    Q->length--;
    return OK;
}


QueueElem GetFront(Queue *Q){
    if(Q->length)
        return Q->front->next->data;
    return NULL; // @@ [Returning NULL (a pointer constant) from a function returning int (QueueElem is typedef'd as int) is invalid in C and causes a compilation error in strict compilers. Should return a sentinel integer value (like -1) or handle differently.]
}

QueueElem GetRear(Queue *Q){
    if(Q->length)
        return Q->rear->data;
    return NULL; // @@ [Same issue as GetFront: returning NULL from an int-returning function causes compilation error.]
}

void PrintQueue(Queue Q){
    QueuePtr p=Q.front->next;
    int n=Q.length;
    printf("队头: ");
    while(n){
        printf("%d ",p->data);
        n--;
        p=p->next;  
    }
    printf("队尾\n");
}