#include<stdio.h>
#include<stdlib.h>
#define MaxV 100
//data type
typedef struct edge{
    int adj;
    struct edge* next;
}Elink;
typedef struct ver{
    Elink* link;
}Vlink;
Vlink g[MaxV];
int Visit[MaxV];
int queue[MaxV];
int front = 0,rear = MaxV - 1,count = 0;
//function statements
void creatGraph(int e);
void setzero(int n);
Elink* insertGraph(int v1,int v2);
void travelDFS(int n,int x);
void travelBFS(int n,int x);
void DFS(int v);
void BFS(int v);
void check(int n);
void enQueue(int v);
int deQueue();
int isFull();
int isEmpty();
//main function
int main(){
    int n = 0,e = 0,x = 0;
    scanf("%d%d",&n,&e);
    creatGraph(e);
    scanf("%d",&x);
    //check(n);
    travelDFS(n,0);//1
    travelBFS(n,0);//2
    travelDFS(n,x);//3
    travelBFS(n,x);//4
    return 0;
}
//functions
void creatGraph(int e){
    int i = 0,v1 = 0,v2 = 0;
    for(i=0;i<e;i++){
        scanf("%d%d",&v1,&v2);
        g[v1].link = insertGraph(v1,v2);
        g[v2].link = insertGraph(v2,v1);
    }
}

Elink* insertGraph(int v1,int v2){
    Elink *p,*head = g[v1].link;
    int i = 0;
    p = (Elink*)malloc(sizeof(Elink));
    p->adj = v2;
    p->next = NULL;
    if(head == NULL){
        g[v1].link = p;
        return g[v1].link;
    }
    Elink *r,*t;
    r = t = head;
    while(t!=NULL){
        if(p->adj < t->adj){
            if(t == head){
                p->next = t;
                head = p;
                break;
            }else{
                p->next = t;
                r->next = p;
                break;
            }
        }
        r = t;
        t = t->next;
    }

    if(t==NULL)
        r->next = p;
    return head;
}

void setzero(int n){
    int i = 0;
    for(i=0;i<n;i++)
        Visit[i] = 0;
}

void travelDFS(int n,int x){
    if(x!=0)
        Visit[x] = 1;
    int i = 0;
    for(i=0;i<n;i++){
        if(Visit[i]!=1) DFS(i);
    }
    printf("\n");
    setzero(n);
}

void travelBFS(int n,int x){
    if(x!=0)
        Visit[x] = 1;
    int i = 0;
    for(i=0;i<n;i++){
        if(Visit[i]!=1) BFS(i);
    }
    printf("\n");
    setzero(n);
}

void DFS(int v){
    Elink* p;
    p = g[v].link;
    printf("%d ",v);
    Visit[v] = 1;
    for(p;p!=NULL;p=p->next)
        if(Visit[p->adj]!=1)
            DFS(p->adj);
}

void BFS(int v){
    Elink *p;
    Visit[v] = 1;
    enQueue(v);
    while(!isEmpty()){
        v = deQueue();
        printf("%d ",v);
        for(p=g[v].link;p!=NULL;p=p->next){
            if(!Visit[p->adj]){
                Visit[p->adj]=1;
                enQueue(p->adj);
            }
        }
    }
}

void check(int n){
    Elink* r;
    int i = 0;
    for(i=0;i<n;i++){
        r = g[i].link;
        printf("%d->",i);
        while(r!=NULL){
            printf("%d ",r->adj);
            r = r->next;
        }
        printf("\n");
    }
}

void enQueue(int v){
    if(!isFull()){
        rear=(rear+1)%MaxV;
        queue[rear] = v;
        count = (rear - front + 1)%MaxV;
    }else printf("queue is full\n");
}

int deQueue(){
    int x = 0;
    if(!isEmpty()){
        x = queue[front];
        front=(front+1)%MaxV;
        count = (rear - front + 1)%MaxV;
        return x;
    }else printf("queue is empty\n");
}
int isFull(){
    if(count==MaxV)
        return 1;
    else return 0;
}
int isEmpty(){
    if(count==0)
        return 1;
    else return 0;
}

