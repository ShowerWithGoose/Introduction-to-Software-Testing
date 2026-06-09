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
int delete=-1;  //编号为1__n-1,-1不影响 @@ [Using 'delete' as a variable name is invalid in C++ but allowed in C; however, it may cause compilation issues if compiled with a C++ compiler or certain strict C compilers that treat it as a reserved word. More critically, the real issue is that the global variable 'delete' is used to skip the deleted vertex during traversal, but the graph structure itself is never modified — edges to the deleted vertex remain, which violates the problem's requirement to actually delete the vertex from the graph. However, the immediate compilation error likely stems from 'delete' being a keyword in C++. But since the error message says "gcc: not found", this might be a red herring. However, looking deeper: the actual bug causing logical errors (not compilation) is elsewhere. But the prompt says "Compilation Error", and the test output shows "/bin/sh: 1: gcc: not found", which is NOT a code error—it's an environment issue. However, the instruction says to find errors in the program below based on failed test cases. Given that, perhaps the real issue is logical, but the prompt misleadingly says "Compilation Error". Re-examining: the variable name 'delete' is legal in C, so not a compilation error. The true logical errors are:]
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
        if( Visited[i]==0 && i!=delete) DFS(G,i); @@ [The problem requires traversal to always start from vertex 0, but this loop starts from the smallest unvisited vertex (which could be non-zero after deletion). Also, after deletion, the graph is still connected and must start from 0, but if 0 is not deleted (as per problem), we should only start from 0, not loop over all vertices. This causes incorrect traversal order when the graph is connected (which it always is).]
    }
}
//BFS
#define MAXSIZE  1000
ElemType QUENE[MAXV]; @@ [Queue size is MAXV but MAXSIZE is 1000; inconsistency may cause buffer overflow if MAXV > MAXSIZE, but here MAXV=200 < 1000, so safe. However, the queue implementation uses global array QUENE and global indices Front/Rear/Count, which is acceptable but not the main error.]
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
    e=quene[Front+1]; @@ [Incorrect indexing: should be quene[Front] then increment Front. Current code uses 1-based indexing for a 0-based array. When Front=0, it accesses quene[1], skipping quene[0]. This causes wrong BFS order and potential out-of-bounds if queue is full.]
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
            BFS(G,i); @@ [Same error as in travelDFS: should only start from vertex 0, not loop through all vertices. Problem states: "In any traversal, the traversal should start from vertex 0."]
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