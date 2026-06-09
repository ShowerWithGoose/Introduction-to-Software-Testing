#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct edge{
    int adj;
    struct edge *next;
}Elink;
typedef struct vertex{
    Elink *link;
}Vlink;
Vlink G[105];

int visit[105]={0};
int vn,en,delver=-1;
int Queue[105]={0};
int front,rear;

void insert(Vlink *p,int a);
void del(Vlink *p);
void DFS(Vlink G[],int i);
void travelDFS(Vlink G[]);
void BFS(Vlink G[],int i);
void travelBFS(Vlink G[]);

int main(){
    scanf("%d%d",&vn,&en);

    //创建无向图
    for(int i=0;i<en;i++){
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        insert(&G[v1],v2);
        insert(&G[v2],v1);
    }
    travelDFS(G);
    printf("\n");
    travelBFS(G);

    //删除顶点
    scanf("%d",&delver);
    del(&G[delver]);

    //DFS,BFS输出
    travelDFS(G);
    printf("\n");
    travelBFS(G);

    return 0;
}

void insert(Vlink *p,int a){
    if(p->link==NULL){
        Elink *t=(Elink*)malloc(sizeof(Elink));
        t->adj=a;
        t->next=NULL;
        p->link=t;
        return;
    }
    if(p->link->adj>a){
        Elink *t=(Elink*)malloc(sizeof(Elink));
        t->adj=a;
        t->next=p->link;
        p->link=t;
        return;
    }
    Elink *e=p->link->next,*pre=p->link;
    while(e!=NULL){
        if(a>e->adj){
            pre=pre->next;
            e=e->next;
        }else{
            Elink *t=(Elink*)malloc(sizeof(Elink));
            t->adj=a;
            t->next=e;
            pre->next=t;
            return;
        }
    }
    Elink *t=(Elink*)malloc(sizeof(Elink));
    t->adj=a;
    t->next=NULL;
    pre->next=t;
    return;
}

void del(Vlink *p){
    p->link=NULL;
}

void DFS(Vlink G[],int i){
    if(!visit[i]){
        visit[i]=1;
        printf("%d ",i);
    }
    Elink*p=G[i].link;
    while(p!=NULL){
        if(p->adj!=delver&&visit[p->adj]==0){
            visit[p->adj]=1;
            printf("%d ",p->adj);
            DFS(G,p->adj);
        }
        p=p->next;
    }
}
void travelDFS(Vlink G[]){
    for(int i=0;i<105;i++){
        visit[i]=0;
    }
    for(int i=0;i<vn;i++){
        if(i!=delver&&visit[i]==0)
        DFS(G,i); // @@ [The DFS traversal must start from vertex 0 only, but this loop starts from i=0 and may skip 0 if delver==0 (though problem says delver != 0), but more critically, it does multiple DFS calls which is wrong for a connected graph. Also, after deletion, the graph is still connected, so only one DFS starting at 0 is needed. This causes incorrect traversal order and possibly missing or extra outputs.]
    }
}

void enQueue(int a){
    Queue[rear++]=a;
}
int deQueue(){
    return Queue[front++];
}
int isEmpty(){
    return front>rear; // @@ [This condition is incorrect. The queue is empty when front == rear, not when front > rear. This can cause infinite loops or premature termination in BFS.]
}
void BFS(Vlink G[],int i){
    visit[i]=1;
    printf("%d ",i);
    enQueue(i);
    Elink*p;
    while(!isEmpty()){
        int v=deQueue();
        p=G[v].link;
        while(p!=NULL){
            if(p->adj!=delver&&visit[p->adj]==0){
                visit[p->adj]=1;
                printf("%d ",p->adj);
                enQueue(p->adj);
            }
            p=p->next;
        }
    }
}
void travelBFS(Vlink G[]){
    //初始化
    for(int i=0;i<105;i++){
        visit[i]=0;
    }
    for(int i=0;i<105;i++){
        Queue[i]=0;
    }
    front=0;
    rear=0;

    for(int i=0;i<vn;i++){
        if(i!=delver&&visit[i]==0)
        BFS(G,i); // @@ [Same issue as in travelDFS: BFS should start only from vertex 0, not iterate over all vertices. The problem states the graph is connected before and after deletion, so only one BFS starting at 0 is required. This leads to incorrect output sequences.]
    }
}