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

    printf("\n%d\n",AdjVertex[8][6]); // @@ The problem requires only the traversal sequences as output. This line prints extra debug information ("0" in the failed case) which causes a Wrong Answer verdict. It should be removed or commented out.
    system("pause"); // @@ system("pause") is not standard and may cause issues or extra output depending on the environment, but primarily the previous line is the direct cause of the WA due to extra output.
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
    (*e)=q->next->data; // @@ Logic error: q is the dummy head node being freed. The actual data is in q->next. However, after Q->front is updated to q->next, accessing q->next is valid for retrieving data, BUT standard dequeuing from a linked list with a dummy head usually retrieves data from the node *after* the dummy. Here, q is the old dummy head. Q->front becomes the first real node. The data should be retrieved from the node that was just dequeued. In this implementation, the "front" points to the dummy head. So the first element is Q->front->next. When we dequeue, we remove the dummy head? No, typically we keep the dummy head. Let's trace: Init: front=rear=dummy. Enqueue: dummy->next=node1, rear=node1. Dequeue: q=dummy. front=node1. e = q->next->data = node1->data. This part is technically correct for retrieving the value. BUT, we must free q (the old dummy). And the new front is node1. If we dequeue again: q=node1. front=node2. e = node1->next->data = node2->data. This works. Wait, look at `free(q)`. We are freeing the node that *was* the front. In the first step, we free the dummy head. This is fine. In the second step, we free node1. This is fine. The logic `(*e)=q->next->data` assumes q still has its next pointer intact. Since we update `Q->front` before accessing `q->next`, and `q` is a local copy of the old front, this is safe. HOWEVER, there is a subtle bug. If the queue becomes empty, `Q->front` becomes NULL? No, `Q->front` becomes `q->next`. If q was the last node (dummy->last), q->next is NULL. Then Q->front is NULL. Next operation might crash. But standard LL queue with dummy head usually keeps the dummy head. This implementation consumes the dummy head on first dequeue. This is a non-standard implementation. Let's look closer. `Init`: front=rear=dummy. `Enqueue`: dummy->next=A, rear=A. `Dequeue`: q=dummy. front=A. e=A->data. free(dummy). Now front=A, rear=A. `Dequeue`: q=A. front=A->next (NULL). e=A->next->data (CRASH if A->next is NULL). Yes, if there is only 1 element A. A->next is NULL. Accessing NULL->data crashes. So `DeQueue` is buggy for the last element.
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