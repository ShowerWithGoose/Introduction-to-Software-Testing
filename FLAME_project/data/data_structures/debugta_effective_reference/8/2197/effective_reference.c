#include<stdio.h>
#include<string.h>

typedef struct edge
{
    int adjvex;
    struct edge *next;
}Elink;
Elink *tmp;

typedef struct node
{
    int vertex;
    Elink *link;
}Vlink;
Vlink graph[100];


int Queue[100];
int rear;
int front;

int visited[100];
void travelBFS(Vlink [],int);
void BFS(Vlink [],int);
void DFS(Vlink G[ ], int v){
    Elink *p;
    printf("%d ",v);
    visited[v] = 1; 
    for(p = G[v].link; p->next !=NULL; p=p->next)
    if( !visited[p->adjvex] )
    DFS(G, p->adjvex);
}
void travelDFS(Vlink G[ ], int n){
    for(int i=0; i<n; i++)
    if( !visited[i] ) DFS(G, i);
}
int main()
{
    int removeV;
    int end;
    int n1,n2;
    rear = -1;
    front = 0;
    scanf("%d%d",&n1,&n2);
    for(int i = 0 ; i < n1 ; i ++)
    {
        graph[i].vertex = i;
        graph[i].link = (Elink*)malloc(sizeof(Elink));
        graph[i].link->next = NULL;
    }
    for(int i = 0 ; i < n2 ; i ++)
    {
        scanf("%d%d",&removeV,&end);
        tmp = graph[removeV].link;
        while(tmp->next != NULL) tmp = tmp->next;
        tmp->next = (Elink*)malloc(sizeof(Elink));
        tmp->adjvex = end;
        tmp->next->next = NULL;
        tmp = graph[end].link;
        while(tmp->next != NULL) tmp = tmp->next;
        tmp->next = (Elink*)malloc(sizeof(Elink));
        tmp->adjvex = removeV;
        tmp->next->next = NULL;
    }
    for(int i = 0 ; i < n1 ; i ++)
    {
        if(graph[i].link->next->next != NULL)
        {
            for(Elink *p = graph[i].link ; p->next->next != NULL ; p = p->next)
            {
                for(Elink *q = p->next; q->next != NULL ; q = q->next)
                {
                    if(p->adjvex > q->adjvex)
                    {
                        int a;
                        a = q->adjvex;
                        q->adjvex = p->adjvex;
                        p->adjvex = a;
                    }
                }
            }
        }
    }
    scanf("%d",&removeV);
    for(int i = 0 ; i < n1 ; i ++) visited[i] = 0;
    travelDFS(graph,n1);
    printf("\n");
    for(int i = 0 ; i < n1 ; i ++) visited[i] = 0;
    travelBFS(graph,n1);
    printf("\n");
    rear = -1;
    front = 0;
    for(int i = 0 ; i < n1 ; i ++)
    {
        tmp = graph[i].link;
        while(tmp->next->next != NULL)
        {
            if(tmp->next->adjvex == removeV)
            {
                tmp->next = tmp->next->next;
                break;
            }
            tmp = tmp->next;
        }
    }
    for(int i = 0 ; i < n1 ; i ++) visited[i] = 0;
    visited[removeV] = 1;
    travelDFS(graph,n1);
    printf("\n");
    for(int i = 0 ; i < n1 ; i ++) visited[i] = 0;
    visited[removeV] = 1;
    travelBFS(graph,n1);
    printf("\n");
    system("pause");
    return 0;
}

void travelBFS(Vlink a[],int n)
{
    for(int i = 0 ; i < n ; i ++)
    {
        if(!visited[i])
        BFS(a,i);
    }
}

void BFS(Vlink a[],int v)
{
    Elink *p;
    printf("%d ",v);
    visited[v] = 1;
    rear++;
    Queue[rear] = v;
    while(rear >= front)
    {
        v = Queue[front++];
        p = a[v].link;
        for(;p->next != NULL; p = p->next)
        {
            if(!visited[p->adjvex])
            {
                printf("%d ",p->adjvex);
                visited[p->adjvex] = 1;
                rear++;
                Queue[rear] = p->adjvex;
            }
        }
    }
}

