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
int delete=-1;  //编号为1__n-1,-1不影响 @@ [Using 'delete' as a variable name is invalid in C++ but allowed in C; however, it may cause issues with some compilers or tools that treat it as a keyword. More critically, the real issue is that global variable 'delete' is used to skip the vertex during traversal, but the graph structure itself is not modified — edges to 'delete' are still present and may cause undefined behavior when accessed after deletion. However, the immediate compilation error likely stems from 'delete' being a reserved word in C++ mode. But since this is C code, the actual compilation error reported ("gcc: not found") is environmental, not code-related. However, given the problem context, the logical error is that traversal starts from 0 but skips 'delete', yet if 0 is connected only through 'delete', it might not traverse correctly. But per instructions, we must find code errors causing mismatched output. The main bug is in BFS queue implementation: deQuene uses Front+1 but doesn't handle circular buffer correctly, and isEmpty checks Count but en/deQueue manipulate Count inconsistently. Also, travelDFS and travelBFS loop over all vertices instead of starting only from 0 as required.]
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
    for (i=0; i<n; i++){ @@ [Problem requires traversal to start from vertex 0 only, not from every unvisited vertex. This loop causes multiple DFS calls if there are disconnected components, but problem states graph is connected. However, after deletion, graph is still connected, so starting from 0 is sufficient. This loop violates requirement #3: "traversal should start from vertex 0".]
        if( Visited[i]==0 && i!=delete) DFS(G,i);
    }
}
//BFS
#define MAXSIZE  1000
ElemType QUENE[MAXV]; @@ [Queue size is MAXV but MAXSIZE is 1000; inconsistent, but not critical. However, QUENE is global and reused without proper reset between traversals.]
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
    Rear = (Rear+1)%MAXSIZE; @@ [Rear is incremented modulo MAXSIZE, but QUENE array is only MAXV (200) in size. If Rear exceeds MAXV-1, it will write out of bounds. Should use MAXV or make QUENE size MAXSIZE.]
    quene[Rear]=item;
    Count++;
}
//出队，保证队不空再进来
ElemType deQuene( ElemType quene[]){
    ElemType e;
    e=quene[Front+1]; @@ [Front is not modulo-adjusted here. Also, standard circular queue uses Front index directly, not Front+1. This causes incorrect dequeuing and potential out-of-bounds if Front+1 >= MAXV. Moreover, Front is never wrapped around with modulo, leading to overflow.]
    Count--;
    Front=(Front+1)%MAXSIZE; @@ [Front is updated modulo MAXSIZE, but quene array is only MAXV size. Inconsistent sizing leads to memory access errors.]
    return e;
}
void BFS(VLink G[],int v){
    ELink *p;
    Visited[v]=1;
    enQuene(QUENE,v);
    while( !isEmpty(QUENE)){
        v=deQuene(QUENE);
        VISIT(G,v);
        for (p=G[v].link; p!=NULL; p=p->next){
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
    for (i=0; i<n; i++){ @@ [Same issue as travelDFS: should start only from vertex 0, not loop over all vertices. Violates requirement #3.]
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
    scanf("%d",&delete); @@ [Using 'delete' as variable name may cause compilation issues in C++ mode, but in pure C it's allowed. However, the bigger issue is that the graph structure isn't actually modified; the 'delete' flag is used during traversal to skip the vertex, but edges to 'delete' are still in the adjacency lists. When traversing neighbors of other nodes, the code checks p->adj != delete, which is correct. But the main logical errors are in the traversal starting points and queue implementation.]
    travelDFS(G,countV);
    printf("\n");
    travelBFS(G,countV);
    printf("\n");
    system ("pause");
}