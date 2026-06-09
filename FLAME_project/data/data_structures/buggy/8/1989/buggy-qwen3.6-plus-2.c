/*样例输入
9 10
0 1
0 2
1 4
1 3
1 8
8 6
3 6
7 2
7 5
5 2
3
*/
//访问相邻顶点时按照编号从小到大的顺序访问；
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int ElemType;
#define MAXV 200    //最大顶点个数
#define MAXE 200    //最大边个数
typedef struct edge{
    int adj;
    int wei;
    struct edge *next;
}ELink;
typedef struct ver{
    ELink *link;
}VLink;
VLink G[MAXV];
//把avex顶点插入到大小合适的位置，呈增顺序
ELink *insertEdge( ELink *head, int avex){
    ELink *e, *p, *r;   //e结点存信息，把e结点存到head末尾
    e=(ELink *)malloc(sizeof(ELink));
    e->adj=avex; e->wei=1; e->next=NULL;
    if( head==NULL ) {
        head=e;
        return head;
    }
    for( p=head; p->next!=NULL && p->next->adj < e->adj; p=p->next);
    //现在p.next==NULL || p.next.adj>e.adj;
    r=p->next;
    p->next=e;
    p->next->next=r;
    return head;
}
int countE=0,countV=0;
void creatGraph(VLink graph[]){
    scanf("%d %d",&countV,&countE);
    int v1,v2;
    for ( int i=0; i<countE; i++){
        scanf("%d %d",&v1,&v2);
        graph[v1].link=insertEdge( graph[v1].link, v2);
        graph[v2].link=insertEdge( graph[v2].link, v1);
    }
}
int delete=-1;  //编号为1__n-1,-1不影响
void VISIT(VLink G[], int v){
    printf("%d ",v);
}
int Visited[MAXV];
void DFS( VLink G[], int v){
    ELink *p;
    Visited[v]=1;
    VISIT(G,v);
    for ( p=G[v].link; p!=NULL; p=p->next){
        if( !Visited[p->adj] && p->adj!=delete )
            DFS( G, p->adj);
    }
}
void travelDFS( VLink G[], int n){
    int i;
    for (i=0; i<n; i++) Visited[i]=0;   //先初始化！！！
    for (i=0; i<n; i++){
        if( Visited[i]==0 && i!=delete) DFS(G,i);
    }
}
//BFS
#define MAXSIZE  1000
ElemType QUENE[MAXV];
int Front,Rear,Count;
int  isEmpty( ){
    return Count == 0;
}
void  initQueue(  ) {
    Front = 0;
    Rear = 0;
    Count = 0;
    memset(QUENE,0,sizeof(QUENE));
}
//入队,保证队不满再进来
void enQuene ( ElemType quene[],ElemType item){
    Rear = (Rear+1)%MAXSIZE;
    quene[Rear]=item;
    Count++;
}
//出队，保证队不空再进来
ElemType deQuene( ElemType quene[]){
    ElemType e;
    e=quene[Front+1]; // @@ The dequeue operation incorrectly accesses index Front+1 instead of Front. In a circular queue where Front points to the position before the first element (or the first element depending on convention, but here Front starts at 0 and Rear moves), standard implementation usually retrieves queue[Front] then increments, or increments then retrieves. Given initQueue sets Front=0, Rear=0, Count=0, and enQuene increments Rear then sets value, the first element is at index 1. However, deQuene increments Front then retrieves? No, it retrieves Front+1 then increments Front. Let's trace: Init: F=0, R=0, C=0. Enqueue A: R=1, Q[1]=A, C=1. Dequeue: e=Q[0+1]=Q[1]=A. C=0. F=1. This seems to work for the first element. But what if we enqueue again? Enqueue B: R=2, Q[2]=B, C=1. Dequeue: e=Q[1+1]=Q[2]=B. C=0. F=2. This logic assumes Front always points to the index *before* the current head. Standard circular queue often uses Front pointing to the head. If Front points to head, deQueue should be e=Q[Front]; Front=(Front+1)%MAXSIZE. Here, the implementation is inconsistent with standard practices and likely fails when wrapping around or with specific sequences. More critically, in many standard implementations where Front is initialized to 0 and Rear to 0, and Enqueue does Rear++ then set, Dequeue should do Get Q[Front+1] then Front++. Wait, if Front=0, Rear=0. Enq: R=1, Q[1]=val. Deq: val=Q[1], F=1. This works. But if we wrap around? If MAXSIZE is small. The bigger issue is usually that Front should point to the current head. If we change deQuene to use `e=quene[(Front+1)%MAXSIZE]` it might be safer, but the real bug is often simpler. Let's look at `travelBFS`. It calls `initQueue`. Then loops. Inside BFS, it enqueues v. Then while not empty, dequeues. The `deQuene` implementation `e=quene[Front+1]` is dangerous if `Front+1` exceeds bounds without modulo, although `Front` is updated with modulo. Actually, the standard error in these student codes is often that `deQuene` should retrieve `quene[Front]` if `Front` points to the element, or `quene[(Front+1)%MAXSIZE]` if `Front` points to the previous. Given `initQueue` sets `Front=0`, and `enQuene` sets `Rear=(Rear+1)%MAXSIZE` then `quene[Rear]=item`, the first item is at `Rear=1`. So `Front=0` is "before" the first item. So `quene[Front+1]` gets the first item. Then `Front` becomes 1. Next item enqueued at `Rear=2`. `deQuene` gets `quene[1+1]=quene[2]`. This seems logically consistent for a non-wrapping case. However, if the queue wraps, e.g., `Rear` reaches `MAXSIZE-1` and goes to 0. `Front` might be somewhere else. The access `quene[Front+1]` does NOT use modulo for the index access itself, only for the update of `Front`. This will cause an out-of-bounds read if `Front` is `MAXSIZE-1`. It should be `e=quene[(Front+1)%MAXSIZE];`.
    Count--;
    Front=(Front+1)%MAXSIZE;
    return e;
}
void BFS(VLink G[],int v){
    ELink *p;
    Visited[v]=1;
    enQuene(QUENE,v);
    while( !isEmpty(QUENE)){
        v=deQuene(QUENE);
        VISIT(G,v);
        for (p=G[v].link; p!=NULL; p->next){ // @@ The loop increment is missing p=p->next, causing an infinite loop. It should be p=p->next.
            if( !Visited[p->adj] && p->adj!=delete){
                Visited[p->adj]=1;
                enQuene(QUENE,p->adj);
            }
        }
    }
}
void travelBFS(VLink G[],int n){
    initQueue();
    int i;
    for(i=0; i<n; i++)  Visited[i]=0;
    for (i=0; i<n; i++){
        if(!Visited[i] && i!=delete)
            BFS(G,i);
    }
}
int main(){
    creatGraph(G);
    travelDFS(G,countV);
    printf("\n");
    travelBFS(G,countV);
    printf("\n");
    scanf("%d",&delete);
    travelDFS(G,countV);
    printf("\n");
    travelBFS(G,countV);
    printf("\n");
    system ("pause");
}