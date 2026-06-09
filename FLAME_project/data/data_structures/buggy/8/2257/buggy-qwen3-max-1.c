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
        printf("%d ",v); // @@ [The vertex 'v' is printed after being dequeued, but it may have been marked as visited already in the enqueue step. However, the real issue is that the BFS marks nodes as visited only when dequeued, which can cause duplicates in the queue. But the main error causing WA is the extra output at the end.]
        visited[v] = 1;
        for (int i = 0; i < n; i++){
            if(AdjVertex[v][i] == 1&&visited[i] == 0){
                EnQueue(&Q,i);
                visited[i] = 1; // @@ [This is correct: mark visited when enqueued to avoid duplicate enqueues. So this line is actually fine. The real problem is elsewhere.]
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

    printf("\n%d\n",AdjVertex[8][6]); // @@ [This line prints an extra value (AdjVertex[8][6]) which is not part of the required output. Since n is at most 100, but in the test case n=3, AdjVertex[8][6] is accessing out-of-bound memory (though zero-initialized), and more importantly, it adds an extra line with "0" at the end, causing Wrong Answer. This line must be removed.]
    system("pause"); // @@ [This line is non-standard and unnecessary, and may cause issues in automated judging environments. However, the primary error is the extra printf above.]
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
    (*e)=q->next->data; // @@ [This line has a bug: it accesses q->next->data, but after Q->front is updated, q is the old dummy head. However, q->next is the actual first element. But if the queue has only one element, q->next is valid. However, the real issue is that the dummy head design means the first real node is front->next. But the bigger problem is the extra output in main, not this. However, this dequeue implementation is correct for a queue with a dummy head node. So this is likely not the cause of WA. The main error is the extra printf.]
    free(q);
    Q->length--;
    return OK;
}


QueueElem GetFront(Queue *Q){
    if(Q->length)
        return Q->front->next->data;
    return NULL;
}

QueueElem GetRear(Queue *Q){
    if(Q->length)
        return Q->rear->data;
    return NULL;
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