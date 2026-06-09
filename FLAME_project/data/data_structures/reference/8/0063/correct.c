#include <stdio.h>

int  q[2999],qian,f,num;
void  initQueue()
{
    qian = 0;
    f = 2998;
    num = 0;
}
int  isEmpty()
{
    return num == 0;
}
int  isFull()
{
    return num == 2999;
}
void enQueue(int queue[ ], int item)
{
    if(isFull())
        printf("Full queue!");
    else
	{
        f = (f+1) % 2999;
        queue[f]=item;
        num++;
    }
}
int  deQueue(int queue[ ])
{
    int e;
    if(isEmpty())   
        printf("Empty queue!");
    else{                   
        e=queue[qian];
        num--;
        qian = (qian+1) % 2999;
        return e;
    }
    return 0;
}
typedef struct e
{
    int  adj;
    int  wei;
    struct e  *next;
} elink;
typedef struct a
{
    elink  *link;
} vl;
vl  g[1000];
int vert, gdg,Visited[3000];
void DFS(vl  G[ ], int v)
{
    elink  *p;
    Visited[v] = 1; 
    printf("%d ", v);
    for(p = G[v].link; p !=NULL;  p=p->next)
        if( !Visited[p->adj] )
            DFS(G, p->adj);
}
void  travelDFS(vl  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV >= 0)  
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
    printf("\n");
}
void BFS(vl  G[ ], int v)
{
    elink  *p;
    initQueue(); 
    Visited[v] = 1;
    enQueue(q, v);
    while( !isEmpty()){
        v = deQueue(q);
        printf("%d ",v);
        for(p=G[v].link; p!=NULL; p=p->next ) 
            if( !Visited[p->adj] ) {
                Visited[p->adj] = 1;
                enQueue(q, p->adj);
            }
    }
}
void  travelBFS(vl  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV >= 0)  
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] )
            BFS(G, i);
    printf("\n");
}

elink  *insertEdge(elink *head, int avex)
{
    elink *e,*p,*q = NULL;
    e =(elink *)malloc(sizeof(elink)); 
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL) 
        return e;
    for(p=head; p != NULL && avex > p->adj;  q = p, p = p->next);
    if( p == head)
	{ 
        e->next = p;
        return e;
    }
    else 
	{     
        q->next = e;
        e->next = p;
        return head;
    }
}
void createGraph(vl  *graph)
{
	int i;
    for(i=0;i<gdg;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link, v2);
        graph[v2].link=insertEdge(graph[v2].link, v1);
    }
}
int main()       //////////////////////////////////////////////
{
    int i,k;
    scanf("%d %d",&vert,&gdg); 
    for(i=0;i<gdg;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        g[v1].link=insertEdge(g[v1].link, v2);
        g[v2].link=insertEdge(g[v2].link, v1);
    }
    travelDFS(g,vert,-1);
    travelBFS(g,vert,-1);
    scanf("%d",&k);
    travelDFS(g,vert,k);
    travelBFS(g,vert,k);
    return 0;
}



