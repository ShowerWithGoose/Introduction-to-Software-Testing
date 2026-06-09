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
        if( !Visited[p->adj] && p->adj!=delete ) // @@ [Error: The condition `p->adj!=delete` should not be here. The deletion check should be done in `travelDFS` by marking the deleted vertex as visited, not in the DFS recursion. This causes incorrect traversal when the deleted vertex is encountered as a neighbor.]
            DFS( G, p->adj);
    }
}
void travelDFS( VLink G[], int n){
    int i;
    for (i=0; i<n; i++) Visited[i]=0;   //先初始化！！！
    if (delete >= 0) Visited[delete] = 1; // @@ [Missing: The deleted vertex should be marked as visited before traversal to prevent visiting it. The original code does not do this, so the DFS may still attempt to visit the deleted vertex.]
    for (i=0; i<n; i++){
        if( Visited[i]==0 && i!=delete) DFS(G,i); // @@ [Redundant: The condition `i!=delete` is unnecessary if the deleted vertex is already marked visited. However, it does not cause an error, just redundancy.]
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
    e=quene[Front+1]; // @@ [Error: The queue implementation is incorrect. `Front` should be updated before accessing the element, and the index should be `Front` not `Front+1`. This causes incorrect dequeue behavior, potentially returning wrong elements or causing out-of-bounds access.]
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
        for (p=G[v].link; p!=NULL; p=p->next){
            if( !Visited[p->adj] && p->adj!=delete){ // @@ [Error: Same issue as in DFS - the deletion check should not be here. The deleted vertex should be marked visited in `travelBFS` instead.]
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
    if (delete >= 0) Visited[delete] = 1; // @@ [Missing: The deleted vertex should be marked as visited before BFS traversal.]
    for (i=0; i<n; i++){
        if(!Visited[i] && i!=delete) // @@ [Redundant: Same as in DFS, the condition `i!=delete` is unnecessary if the deleted vertex is already marked visited.]
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