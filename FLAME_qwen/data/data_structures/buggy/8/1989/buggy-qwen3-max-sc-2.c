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
int delete=-1;  //编号为1__n-1,-1不影响 @@ [Using 'delete' as a variable name is invalid in C++ but allowed in C; however, it's a reserved keyword in C++ and may cause issues with some compilers or tools. More critically, the real error is that the BFS queue implementation uses global variables inconsistently and incorrectly handles circular buffer indexing, leading to logical errors. But the immediate compilation error reported ("gcc: not found") is environmental, not code-related. However, based on the problem context and expected behavior, the actual bug causing wrong output is in traversal logic: traversals should always start from vertex 0, but current code loops over all vertices.]
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
    for (i=0; i<n; i++){ @@ [Error: The problem requires traversal to always start from vertex 0, but this loop starts DFS from every unvisited vertex (including those !=0). This violates requirement #3. It should only call DFS(G, 0) once.]
        if( Visited[i]==0 && i!=delete) DFS(G,i);
    }
}
//BFS
#define MAXSIZE  1000
ElemType QUENE[MAXV]; @@ [Error: Queue array size is MAXV (200), but MAXSIZE is defined as 1000. This mismatch can cause buffer overflow in enQuene/deQuene which use MAXSIZE for modulo, but QUENE only has MAXV elements. Also, QUENE is global but functions pass it as argument unnecessarily.]
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
    Rear = (Rear+1)%MAXSIZE; @@ [Error: Using MAXSIZE (1000) for modulo but QUENE array is only size MAXV (200). This can write beyond array bounds. Should use MAXV or consistent size.]
    quene[Rear]=item;
    Count++;
}
//出队，保证队不空再进来
ElemType deQuene( ElemType quene[]){
    ElemType e;
    e=quene[Front+1]; @@ [Error: Front starts at 0, so first element is at index 1? This skips index 0 and causes incorrect dequeue. Standard circular queue uses Front = (Front+1)%size and accesses quene[Front]. Also, inconsistent with enQuene which writes to Rear after increment.]
    Count--;
    Front=(Front+1)%MAXSIZE; @@ [Same size mismatch issue with MAXSIZE vs array size.]
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
    for (i=0; i<n; i++){ @@ [Error: Same as DFS - should only start BFS from vertex 0, not loop over all vertices. Violates requirement #3.]
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