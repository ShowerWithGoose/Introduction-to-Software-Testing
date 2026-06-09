#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <tgmath.h>
#include <complex.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>

struct node1{
    int to_id;          //边指向的节点标号
    struct node1* next_arc;
};

struct node2{
    int ver_id;         //节点标号
    struct node1* first_arc;//相邻的节点集合
};

struct node3{
    int vernum;
    int arcnum;
    struct node2 ver_list[105];
};

struct node3 Graph;
int Visited[105];
int deleteID=-1;

struct node1* Insert(struct node1* head,struct node1* p)
{
    if(head==NULL)
        head=p;
    else
    {
        if(head->to_id > p->to_id)
        {
            p->next_arc=head;
            head=p;
        }
        else
        {
            struct node1* tmp=head;
            struct node1* prev=head;
            while(tmp!=NULL && tmp->to_id < p->to_id)
            {
                prev=tmp;
                tmp=tmp->next_arc;
            }
            p->next_arc=tmp;
            prev->next_arc=p;
        }
    }
    return head;
}

void DFS(int id)
{
    if(id!=deleteID)
    {
        printf("%d ",id);
        Visited[id]=1;
        struct node1* p=Graph.ver_list[id].first_arc;
        for(p;p!=NULL;p=p->next_arc)
            if(!Visited[p->to_id] && (p->to_id)!=deleteID)
                DFS(p->to_id);
    }
    return;
}

void BFS(int id)
{
    if(id!=deleteID)
    {
        Visited[id]=1;

        int Queue[1000];
        int front=-1;
        int rear=0;
        struct node1* p;
        Queue[rear]=id;

        while(front<rear)
        {
            id=Queue[++front];
            printf("%d ",id);
            for(p=Graph.ver_list[id].first_arc;p!=NULL;p=p->next_arc)
            {
                if(!Visited[p->to_id] && p->to_id!=deleteID)
                {
                    Visited[p->to_id]=1;
                    Queue[++rear]=p->to_id;
                }
            }
        }
    }
    return;
}

int main()
{
    scanf("%d%d",&Graph.vernum,&Graph.arcnum);
    int i;
    for(i=0;i<Graph.vernum;i++)
    {
        Graph.ver_list[i].ver_id=i;
        Graph.ver_list[i].first_arc=NULL;
    }

    for(i=0;i<Graph.arcnum;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        struct node1* p=malloc(sizeof(struct node1));
        p->next_arc=NULL;
        p->to_id=b;
        Graph.ver_list[a].first_arc=Insert(Graph.ver_list[a].first_arc,p);
        struct node1* q=malloc(sizeof(struct node1));
        q->next_arc=NULL;
        q->to_id=a;
        Graph.ver_list[b].first_arc=Insert(Graph.ver_list[b].first_arc,q);
    }
    
    
    int a; 
    scanf("%d",&a);

    memset(Visited,0,sizeof(Visited));
    for(i=0;i<Graph.vernum;i++)
        if(!Visited[i])
            DFS(i);
    printf("\n");
    
    memset(Visited,0,sizeof(Visited));
    for(i=0;i<Graph.vernum;i++)
        if(!Visited[i])
            BFS(i);
    printf("\n");
    
    deleteID=a;

    memset(Visited,0,sizeof(Visited));
    for(i=0;i<Graph.vernum;i++)
        if(!Visited[i])
            DFS(i);
    printf("\n");
    
    memset(Visited,0,sizeof(Visited));
    for(i=0;i<Graph.vernum;i++)
        if(!Visited[i])
            BFS(i);
    printf("\n");


    return 0;
}

