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

void AddEdge(int a,int b); // @@ Missing parameter types in function declaration, though C allows implicit int, it's bad practice and might cause warnings/errors in strict compilers. However, the definition below is the real issue.
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

void AddEdge(a,b) { // @@ Function definition uses old-style K&R syntax without specifying types for parameters 'a' and 'b'. In modern C standards (C99+), this is invalid or defaults to int, but combined with the logic errors inside, it's problematic. More importantly, the logic below has flaws.
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
        while ( p->next!=NULL && p->num < b ) { // @@ This loop condition stops if p->next is NULL OR p->num >= b. If it stops because p->next is NULL but p->num < b, we append. If it stops because p->num >= b, we insert before p. However, if the list has only one element and it's greater than b, p->next is NULL and p->num > b. The loop doesn't run. Then we go to the else block below? No, we check the if below.
            prep = p;
            p = p->next;
        }
        
        if ( p->next == NULL && p->num < b ) { // @@ If the list is sorted, and we are at the last node (p->next == NULL), and p->num < b, we append. This is correct for appending at the end.
            q = (struct node*)malloc(sizeof(struct node));
            q->num = b;
            q->next = NULL;
            p->next = q;
        }
        else { // @@ This handles insertion in the middle or at the beginning (if the first node was >= b). But wait, if the first node was >= b, the while loop wouldn't execute (p->next might not be null, but p->num < b would be false immediately if p->num >= b). If p->num >= b, we insert before p. prep is &A[a]. So prep->next becomes q, q->next becomes p. This seems logically okay for insertion sort style, BUT there is a subtle bug: if p->next == NULL and p->num >= b, we fall into this else block. We insert before p. This is correct. 
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
    A[v].num = 0; // @@ This line is suspicious. It changes the vertex number of the deleted node to 0. This might confuse traversal if not handled correctly, but primarily the issue is how neighbors are cleaned up.
    p = A[v].next;
    while (p->next != NULL) { // @@ This loop structure is flawed for deleting all nodes in the linked list. It processes nodes until the second to last.
        Fr(p->num,v); // Remove v from the adjacency list of p->num
        prep = p;
        p = p->next;
        free(prep); // Free the previous node
    }
    Fr(p->num,v); // Process the last node
    free(p); // Free the last node
    A[v].next = NULL; // @@ After freeing all nodes in the adjacency list of v, we must set A[v].next to NULL. Otherwise, it points to freed memory (dangling pointer). This is a critical error causing undefined behavior in subsequent traversals.
}

void Fr (int u,int v) {
    struct node* q,*preq;
    preq = &A[u];
    q = A[u].next;
    while ( q->next != NULL ) { // @@ This loop fails if the node to be deleted is the LAST node in the adjacency list of u. If q->next is NULL, the loop doesn't run.
        if ( q->num == v ){
            preq->next = q->next;
            q->next = NULL;
            free(q);
            return;
        }
        q = q->next;
    }
    // If we exit the loop, either q->next is NULL.
    // If q->num == v, we need to delete q (the last node).
    // If q->num != v, then v is not in the list (should not happen if graph is consistent).
    if (q->num == v) { // @@ Missing check for the last node. The original code just does preq->next = NULL and frees q regardless of whether q->num == v. If q->num != v, it incorrectly deletes the last node which is NOT v.
        preq->next = NULL;
        free(q);
    }
}