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
            visit[p->adj]=1; // @@ The visit mark is set prematurely here. In standard DFS, the recursive call should handle marking. By marking it here AND inside the recursive call (if it enters the !visit[i] block), it's redundant but logically okay for prevention. However, the bigger issue is that this manual print and mark breaks the standard DFS flow if not careful. But looking closely at the logic: if we enter the if, we mark and print, then recurse. Inside recurse, it checks visit again. This is actually a hybrid iterative/recursive approach that is flawed. Standard DFS: Mark when visiting. Here: Mark before recursing. This is acceptable for correctness of sequence IF the recursion doesn't double print. Let's look at the recursion: DFS(G, p->adj). Inside DFS, it checks if(!visit[i]). Since we just set it to 1, the recursive call will NOT print or do anything except iterate its neighbors. This means the neighbor is printed HERE, but its children are explored in the recursive call. This is actually a valid DFS implementation style (pre-order). Wait, if visit is set to 1 here, the recursive call DFS(G, p->adj) will hit if(!visit[i]) which is false, so it returns immediately? No, it still iterates its neighbors. So it works as a traversal. 
            // However, there is a subtle bug. If node A connects to B and C. We visit A. We see B. Mark B, Print B. Recurse B. B explores neighbors. Returns. Back to A. We see C. Mark C, Print C. Recurse C.
            // This seems correct for DFS order.
            // Let's re-read the error. The buggy output for BFS is "0 1 2 0 2". This suggests BFS is running twice or incorrectly.
            // Let's look at BFS.
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
        DFS(G,i);
    }
}

void enQueue(int a){
    Queue[rear++]=a;
}
int deQueue(){
    return Queue[front++];
}
int isEmpty(){
    return front>rear;
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
    for(int i=0;i<105;i++){ // @@ The loop condition should be i < vn, not i < 105. Although visit is reset, iterating up to 105 might access uninitialized graph nodes if vn < 105, but G is global so it's NULL. The real issue is likely that `front` and `rear` are not reset properly or the queue logic is flawed across multiple calls if not careful. But they are reset below.
        Queue[i]=0;
    }
    front=0;
    rear=0;

    for(int i=0;i<vn;i++){
        if(i!=delver&&visit[i]==0)
        BFS(G,i);
    }
}