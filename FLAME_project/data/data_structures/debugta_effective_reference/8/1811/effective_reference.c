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

VLink edge[MAXV];
int vertex,point;
int DFSVisited[MAXV];
void Insert(int e1,int e2);
void travelDFS(VLink edge[]);  //深度优先遍历（前序版）
void DFS(VLink edge[],int v);
void travelBFS(VLink edge[]);
void BFS(VLink edge[],int v);
void enQueue(struct Queue* Q,int item);
int deQueue(struct Queue* Q);
int emptyQ(struct Queue* Q);
void Delete_v(int v);  //从图G中删除结点v

int main(){
    int i,deletePoint,v2;
    scanf("%d %d",&vertex,&point);
    for(i=0;i<point;i++){
        scanf("%d %d",&deletePoint,&v2);
        Insert(deletePoint,v2);
        Insert(v2,deletePoint);
    }
    scanf("%d",&deletePoint);

    travelDFS(edge);
    printf("\n");
    travelBFS(edge);
    printf("\n");

    Delete_v(deletePoint);
    travelDFS(edge);
    printf("\n");
    travelBFS(edge);
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
    if(edge[e1].link==NULL||e2<edge[e1].link->vertex){
        p->next=edge[e1].link;
        edge[e1].link=p;
    }
    else{
        pre=edge[e1].link;
        tmp=pre->next;
        while(tmp!=NULL&&tmp->vertex<e2){
            pre=pre->next;
            tmp=tmp->next;
        }
        p->next=tmp;
        pre->next=p;
    }
}
void travelDFS(VLink edge[]){
    int i;
    for(i=0;i<vertex;i++) DFSVisited[i]=0;
    //for(i=0;i<num_v;i++)
        //if(!Visited[i]) 
    DFS(edge,0);   //这样写是遍历0所在的连通分量，不会遍历孤立的点，原来的写法可以遍历所有的点
}
void DFS(VLink edge[],int v){
    ELink *p;
    DFSVisited[v]=1;
    printf("%d ",v);
    for(p=edge[v].link;p!=NULL;p=p->next){
        if(!DFSVisited[p->vertex]) DFS(edge,p->vertex);
    }
}
void travelBFS(VLink edge[]){
    int i;
    Q=(struct Queue*)malloc(sizeof(struct Queue));
    Q->rear=-1;
    Q->front=0;
    for(i=0;i<vertex;i++) DFSVisited[i]=0;
    //for(i=0;i<num_v;i++)
        //if(!Visited[i]) 
    BFS(edge,0);    //这样写是遍历0所在的连通分量，不会遍历孤立的点，原来的写法可以遍历所有的点
}
void BFS(VLink edge[],int v){
    ELink *p;
    DFSVisited[v]=1;
    enQueue(Q,v);
    while(!emptyQ(Q)){
        v=deQueue(Q);
        printf("%d ",v);
        for(p=edge[v].link;p!=NULL;p=p->next){
            if(!DFSVisited[p->vertex]){
                DFSVisited[p->vertex]=1;
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
    edge[v].link=NULL;
    for(i=0;i<vertex;i++){
        p=edge[i].link;
        if(p==NULL) continue;
        else if(p->vertex==v) edge[i].link=p->next;
        else{
            for(pre=edge[i].link,p=pre->next;p!=NULL;p=p->next,pre=pre->next){
                if(p->vertex==v){
                    pre->next=p->next;
                    free(p);
                    break;
                }
            }
        }
    }
}
