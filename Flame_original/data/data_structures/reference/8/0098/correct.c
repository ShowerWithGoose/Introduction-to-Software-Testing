#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXV 120

typedef struct edge{   //定义边结点类型
    int vertex;
    int weight;
    struct edge *next;
}ELink;
typedef struct ver{   //定义顶点结点类型
    int vertex;  //似乎可以不用这样，直接用指针数组
    ELink *link;
}VLink;
struct Queue{      //定义队列（BFS用）
    int Data[MAXV];
    int rear;
    int front;
};
struct Queue *Q;

VLink G[MAXV];
int num_v,num_e;
int Visited[MAXV];
void Insert(int e1,int e2);
void travelDFS(VLink G[]);  //深度优先遍历（前序版）
void DFS(VLink G[],int v);
void travelBFS(VLink G[]);
void BFS(VLink G[],int v);
void enQueue(struct Queue* Q,int item);
int deQueue(struct Queue* Q);
int emptyQ(struct Queue* Q);
void Delete_v(int v);  //从图G中删除结点v

int main(){
    int i,v1,v2;
    scanf("%d %d",&num_v,&num_e);
    for(i=0;i<num_e;i++){
        scanf("%d %d",&v1,&v2);
        Insert(v1,v2);
        Insert(v2,v1);
    }
    scanf("%d",&v1);

    travelDFS(G);
    printf("\n");
    travelBFS(G);
    printf("\n");

    Delete_v(v1);
    travelDFS(G);
    printf("\n");
    travelBFS(G);
    system("pause");
    return 0;
}
void Insert(int e1,int e2){  //将e2插入到e1所指的链表中，按从小到大顺序插入
    ELink *p;
    ELink *pre;
    ELink *tmp;
    p=(ELink*)malloc(sizeof(ELink));
    p->vertex=e2;
    p->next=NULL;
    if(G[e1].link==NULL||e2<G[e1].link->vertex){
        p->next=G[e1].link;
        G[e1].link=p;
    }
    else{
        pre=G[e1].link;
        tmp=pre->next;
        while(tmp!=NULL&&tmp->vertex<e2){
            pre=pre->next;
            tmp=tmp->next;
        }
        p->next=tmp;
        pre->next=p;
    }
}
void travelDFS(VLink G[]){
    int i;
    for(i=0;i<num_v;i++) Visited[i]=0;
    //for(i=0;i<num_v;i++)
        //if(!Visited[i]) 
    DFS(G,0);   //这样写是遍历0所在的连通分量，不会遍历孤立的点，原来的写法可以遍历所有的点
}
void DFS(VLink G[],int v){
    ELink *p;
    Visited[v]=1;
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next){
        if(!Visited[p->vertex]) DFS(G,p->vertex);
    }
}
void travelBFS(VLink G[]){
    int i;
    Q=(struct Queue*)malloc(sizeof(struct Queue));
    Q->rear=-1;
    Q->front=0;
    for(i=0;i<num_v;i++) Visited[i]=0;
    //for(i=0;i<num_v;i++)
        //if(!Visited[i]) 
    BFS(G,0);    //这样写是遍历0所在的连通分量，不会遍历孤立的点，原来的写法可以遍历所有的点
}
void BFS(VLink G[],int v){
    ELink *p;
    Visited[v]=1;
    enQueue(Q,v);
    while(!emptyQ(Q)){
        v=deQueue(Q);
        printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next){
            if(!Visited[p->vertex]){
                Visited[p->vertex]=1;
                enQueue(Q,p->vertex);
            }
        }
    }
}
void enQueue(struct Queue* Q,int item){
    Q->rear++;
    Q->Data[Q->rear]=item;
}
int deQueue(struct Queue* Q){
    int a=Q->Data[Q->front];
    Q->front++;
    return a;
}
int emptyQ(struct Queue* Q){
    if(Q->front>Q->rear) return 1;
    else return 0;
}
void Delete_v(int v){  //把v变成一个孤立的结点
    int i;
    ELink *p,*pre;
    G[v].link=NULL;
    for(i=0;i<num_v;i++){
        p=G[i].link;
        if(p==NULL) continue;
        else if(p->vertex==v) G[i].link=p->next;
        else{
            for(pre=G[i].link,p=pre->next;p!=NULL;p=p->next,pre=pre->next){
                if(p->vertex==v){
                    pre->next=p->next;
                    free(p);
                    break;
                }
            }
        }
    }
}
