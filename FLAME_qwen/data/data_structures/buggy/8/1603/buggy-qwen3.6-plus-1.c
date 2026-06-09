#include<stdio.h>
#include<stdlib.h>
int visited[105] = {0};
int deletever;

int Q[105] = {-1}; // @@ Array initialization with {-1} only sets the first element; may cause warnings in strict compilers. Use {0} or initialize manually.
int top = 0;
int end = 0;

void enQueue(int Q[], int b)
{
    Q[end++] = b;
}
int deQueue(int Q[])
{
    int a;
    a = Q[top++];
    Q[top - 1] = -1;
    return a;
}

typedef struct _edge
{
    int flag;
    int adjver;
    struct _edge *next;
} edge,*Pedge;


typedef struct _ver
{
    int flag;
    edge *link;
} ver,*Pver;

ver G[105];

void visit(ver G[], int v)
{
    printf("%d ",v);
}

void DFS(ver G[], int v)
{
    Pedge p;
    visited[v] = 1; //标识某顶点被访问过
    visit(G,v);
    for (p = G[v].link; p != NULL; p = p->next)
    {
        if (!visited[p->adjver])
        {
            DFS(G, p->adjver);
        }
    }

}

void DFS1(ver G[], int v,int deletever) // @@ Parameter 'deletever' shadows the global variable; also modifies the graph structure during traversal which is unsafe and logically incorrect for proper vertex deletion.
{
    Pedge p;
    Pedge k;
    visited[v] = 1; //标识某顶点被访问过
    p = G[v].link;
    if(p != NULL && p->adjver == deletever)
    {
        k = p->next;
        G[v].link = k;
    }
    //visit(G,v);
    for (p = G[v].link; p != NULL; p = p->next)
    {
        if(p->next != NULL && p->next->adjver == deletever)
        {
            k = p->next->next;
            p->next = k;
        }

        if (!visited[p->adjver])
        {
            DFS1(G, p->adjver,deletever);
        }

    }

}


void BFS(ver G[], int v)
{
    Pedge p;

    visit(G, v); //访问当前顶点
    visited[v] = 1; //标识某顶点被访问过
    enQueue(Q, v);
    while (top < end)
    {
        v = deQueue(Q); //取出队头元素
        p = G[v].link; //获取该顶点第一个邻接顶点

        for (; p != NULL; p = p->next)
        {
            if (!visited[p->adjver])
            {
                visit(G,p->adjver);//访问当前顶点
                visited[p->adjver] = 1; //标识某顶点被访问过
                enQueue(Q, p->adjver);
            }
        }
    }
}


Pedge create(int a)
{
    Pedge p;
    p = (Pedge)malloc(sizeof(edge));
    p->flag = 1;
    p->adjver = a;
    p->next = NULL;
    return p;
}

void insert(ver G[], Pedge p, int a)
{

    Pedge k, q ;
    if(G[a].link == NULL)
    {
        G[a].link = p;
    }
    else
    {
        k = G[a].link;
        while(k != NULL)
        {
            if(k->adjver > p->adjver) // @@ Fails to update G[a].link when the new node should become the head, breaking the sorted adjacency list requirement.
            {
                q = k;
                k = q->next;
                break;
            }
            if(k->next != NULL && k->next->adjver > p->adjver)
            {
                q = k;
                k = q->next;
                break;
            }
            q = k;
            k = q->next;
        }
        p->next = k;
        q->next = p; // @@ Logical error: G[a].link is not updated to p when p is inserted at the beginning of the list.
    }

    /*int i;
    for(i = 0 ; i < 9 ;i++)//
    {
        printf("%d ",i);
        q = G[i].link;
        while(q != NULL)
        {
            printf("%d ",q->adjver);
            p = q;
            q = p->next;
        }
        printf("\n");
    }*/
}

int main ()
{
    int i;
    int a, b;
    int vetn,edgen;

    Pedge p,  k;
    scanf("%d %d",&vetn,&edgen);

    for(i = 0 ; i < vetn ; i++)
    {
        G[i].flag = 1;
    }
    for(i = 0 ; i < edgen ; i++)
    {
        scanf("%d %d",&a, &b);

        p = create(b);
        //printf("aaaaaaaaaaaaaaaa%d",p->adjver);
        insert(G, p, a);


        k = create(a);
        //printf("aaaaaaaaaaaaaaaa%d",k->adjver);
        insert(G, k, b);

    }

    /*for(i = 0 ; i < vetn ;i++)
    {
        printf("%d ",i);
        q = G[i].link;
        while(q != NULL)
        {
            printf("%d ",q->adjver);
            p = q;
            q = p->next;
        }
        printf("\n");
    }*/

    scanf("%d",&deletever);

    DFS(G,0);
    printf("\n");
    for(i = 0 ; i < 105 ; i++)
    {
        visited[i] = 0;
    }
    BFS(G,0);
    printf("\n");
    for(i = 0 ; i < 105 ; i++)
    {
        visited[i] = 0;
    }

    DFS1(G,0,deletever); // @@ DFS1 incorrectly attempts to delete the vertex by modifying edges during traversal; should follow the reference program's approach of shifting array indices and adjusting adjacency values.
    //Pedge q;
    for(i = 0 ; i < 105 ; i++)
    {
        visited[i] = 0;
    }
    /*for(i = 0 ; i < 9 ;i++)//
    {
        printf("%d ",i);
        q = G[i].link;
        while(q != NULL)
        {
            printf("%d ",q->adjver);
            p = q;
            q = p->next;
        }
        printf("\n");
    }*/



    DFS(G,0);
    printf("\n");
    for(i = 0 ; i < 105 ; i++)
    {
        visited[i] = 0;
    }

    BFS(G,0);
    printf("\n");
    for(i = 0 ; i < 105 ; i++)
    {
        visited[i] = 0;
    }


    return 0;
}