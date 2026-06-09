#include <stdio.h>
#include <stdlib.h>

typedef struct st {
    int adjvex;
    struct st *next;
} Elink;
Elink Graph[100];

void CreateGraph(int, int);
Elink InsertEdge(int, int);
void traDFS(int);
void DFS(int);
void traBFS(int);
void BFS(int);
void delete(int);

int Queue[100];
int Flag[100];
int front = 0, rear = 0;

int main()
{
    int nvex, nedge, del;
    
    scanf("%d%d", &nvex, &nedge);
    CreateGraph(nvex, nedge);
    scanf("%d", &del);
    
    traDFS( nvex );
    traBFS( nvex );

    delete( del );
    traDFS( nvex );
    traBFS( nvex );

    return 0;
}

void CreateGraph(int v, int e)
{
    int v1, v2;
    for( int i=0; i<v; i++ ) {
        Graph[i].next = NULL;
        Graph[i].adjvex = i;
    }
    for( int i=0; i<e; i++ ) {
        scanf("%d%d", &v1, &v2);
        Graph[v1] = InsertEdge(v1, v2);
        Graph[v2] = InsertEdge(v2, v1);
    }
    return ;
}
Elink InsertEdge(int v1, int v2)
{
    Elink *p = NULL, *q = NULL, *r = NULL;
    p = (Elink *)malloc( sizeof( Elink ) );
    p->adjvex = v2;
    p->next = NULL;
    if( Graph[v1].next == NULL ) {
        Graph[v1].next = p;
    } 
    else {
        for( q=Graph[v1].next, r=&Graph[v1]; q!=NULL && q->adjvex<v2; r=q, q=q->next )
            ;
        r->next = p;
        p->next = q;
    }
    return Graph[v1];
}

void traDFS(int n)
{
    int i;
    for( i=0; i<n; i++ )
        Flag[i] = 0;
    for( i=0; i<n; i++ )
        if( !Flag[i] && Graph[i].next != NULL )
            DFS( i );
    printf("\b\n");
}
void DFS(int v)
{
    Elink *p;
    Flag[v] = 1;
    printf("%d ", v);
    for( p=Graph[v].next; p!=NULL; p=p->next )
        if( !Flag[p->adjvex] )
            DFS( p->adjvex );
}

void traBFS(int n)
{
    int i;
    for( i=0; i<n; i++ )
        Flag[i] = 0;
    for( i=0; i<n; i++ )
        if( !Flag[i] && Graph[i].next != NULL )
            BFS( i );
    printf("\b\n");
}
void BFS(int v)
{
    Elink *p;
    int val;
    Queue[rear ++] = v;
    Flag[v] = 1;
    while( front < rear ) {
        val = Queue[front ++];
        printf("%d ", val);
        for( p=Graph[val].next; p!=NULL; p=p->next ) {
            if( !Flag[p->adjvex] ) {
                Queue[rear ++] = p->adjvex;
                Flag[p->adjvex] = 1;
            }
        }
    } 
}

void delete(int v)
{
    Elink *p, *q, *r, *t;
    p = q = r = t = NULL;
    for( p=Graph[v].next; p!=NULL; t=p, p=p->next ) {
        for( q=Graph[p->adjvex].next, r=&Graph[p->adjvex]; q->adjvex!=v; r=q, q=q->next )
            ;
        r->next = q->next;
        free( q );
        free( t );
    }
    Graph[v].next = NULL;
}
