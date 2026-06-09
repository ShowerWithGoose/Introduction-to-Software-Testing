#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

struct node {
    int num;
    struct node* next;
};
struct node A[101];

int Visited[101] = {0};
int Queue[201] = {0};

void AddEdge(int a,int b);
void DFS(struct node A[ ], int v);
void BFS(struct node A[ ], int v);
void DelVer(struct node A[ ],int delver);
void Fr (int u,int v);

int main() {
    int i=0,j=0,n,vercount,edgecount,v1,v2,delver;
    scanf("%d%d",&vercount,&edgecount);
    
    for (i=0;i<vercount;i++) {
        A[i].num = i;
        A[i].next = NULL;
    }
    
    for (i=0;i<edgecount;i++) {
        scanf("%d%d",&v1,&v2);
        AddEdge(v1,v2);
        AddEdge(v2,v1);
    }
    
    scanf("%d",&delver);
    
    DFS(A,0);
    printf("\n");
    memset(Visited,0,sizeof(int)*101);
    
    BFS(A,0);
    printf("\n");
    memset(Visited,0,sizeof(int)*101);
    memset(Queue,0,sizeof(int)*201);
    
    DelVer(A,delver);
    
    DFS(A,0);
    printf("\n");
    memset(Visited,0,sizeof(int)*101);
    
    BFS(A,0);
    printf("\n");
    
    return 0;
}

void AddEdge(a,b) { // @@ Missing type specifiers for parameters 'a' and 'b'. In C, function definitions must explicitly declare parameter types (e.g., 'void AddEdge(int a, int b)'), otherwise it causes a compilation error.
    struct node* p,*prep,*q;
    if ( A[a].next == NULL ) {
        q = (struct node*)malloc(sizeof(struct node));
        q->num = b;
        q->next = NULL;
        A[a].next = q;
    }
    else {
        prep = &A[a];
        p = A[a].next;
        while ( p->next!=NULL && p->num < b ) {
            prep = p;
            p = p->next;
        }
        
        if ( p->next == NULL && p->num < b ) {
            q = (struct node*)malloc(sizeof(struct node));
            q->num = b;
            q->next = NULL;
            p->next = q;
        }
        else {
            q = (struct node*)malloc(sizeof(struct node));
            q->num = b;
            q->next = p;
            prep->next = q;
        }
    }
}

void DFS(struct node A[ ], int v) {
    struct node* p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v);
    for (p = A[v].next; p!=NULL;  p = p->next) {
        if ( Visited[p->num]==0 )
            DFS(A, p->num);
    }
}

void BFS(struct node A[ ], int v) {
    struct node* p;
    int front=0,rear=1;
    Visited[v] = 1;
    Queue[0] = v;
    while ( front!=rear ) {
        v = Queue[front]; //取出队头元素
        front++;
        printf("%d ",v); //访问当前顶点
        for ( p = A[v].next; p!=NULL; p = p->next ) //访问该顶点的每个邻接顶点
            if ( Visited[p->num] == 0 ) {
                Queue[rear] = p->num;
                rear++;
                Visited[p->num] = 1; //标识某顶点入队
            }
    }
}

void DelVer(struct node A[ ],int v) {
    struct node* p,*prep;
    A[v].num = 0;
    p = A[v].next;
    while (p->next != NULL) {
        Fr(p->num,v);
        prep = p;
        p = p->next;
        free(prep);
    }
    Fr(p->num,v);
    free(p);
}

void Fr (int u,int v) {
    struct node* q,*preq;
    preq = &A[u];
    q = A[u].next;
    while ( q->next != NULL ) {
        if ( q->num == v ){
            preq->next = q->next;
            q->next = NULL;
            free(q);
            return;
        }
        q = q->next;
    }
    preq->next = NULL;
    free(q);
}