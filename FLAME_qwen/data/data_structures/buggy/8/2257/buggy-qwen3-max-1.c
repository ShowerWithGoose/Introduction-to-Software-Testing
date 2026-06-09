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
    system("pause"); // @@ [The function 'system' is declared in <stdlib.h>, but some environments may not support it or require linking with additional libraries. However, the primary compilation error likely stems from missing function definitions or incorrect queue implementation.]
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
    (*e)=q->next->data; // @@ [This line causes undefined behavior when the queue has only one element because q->next may be NULL after dequeueing the last element. Also, freeing 'q' which points to the dummy head node is correct, but accessing q->next->data assumes at least one real node exists, which may not be true if DeQueue is called on an empty queue. However, QueueEmpty should prevent that. The real issue is that the dummy head design makes DeQueue access q->next->data, but if the queue is empty (though guarded), or during edge cases, this can crash. More critically, the DeQueue function does not check if the queue is empty before dequeuing, even though the caller checks QueueEmpty — but if QueueEmpty returns false incorrectly, this crashes. However, the main compilation error reported is "gcc: not found", which is environment-related, but assuming the intent is to find logical/semantic errors causing runtime issues or incorrect output, this line is problematic.]
    free(q);
    Q->length--;
    return OK;
}


QueueElem GetFront(Queue *Q){
    if(Q->length)
        return Q->front->next->data;
    return NULL; // @@ [Returning NULL for an int return type is invalid. NULL is typically ((void*)0), which is a pointer, not an integer. This causes a type mismatch warning or error depending on compiler settings. Should return a sentinel integer value like -1 instead.]
}

QueueElem GetRear(Queue *Q){
    if(Q->length)
        return Q->rear->data;
    return NULL; // @@ [Same issue as GetFront: returning NULL (pointer) from a function returning int (QueueElem is typedef'd to int). This is a type error.]
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