#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include<stdbool.h>
#include<assert.h>
#define MaxV 100
/*
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
*/
typedef int Datatype;
struct QueueNode  //队列
{
    Datatype data;
    struct QueueNode* next;
};
struct Queue        //存头尾指针
{
    struct QueueNode* head;
    struct QueueNode* tail;
};
void QueueInit(struct Queue* pq);//初始化
void QueueDestory(struct Queue* pq);//销毁
void QueuePush(struct Queue* pq,Datatype x);  //在队尾插入
void QueuePop(struct Queue* pq);//在队头出
Datatype QueueFront(struct Queue* pq);  //取队头数据
Datatype QueueBack(struct Queue* pq);   //取队尾数据
int QueueSize(struct Queue* pq);    //取数据个数
bool QueueEmpty(struct Queue* pq);  //判断是否为空
typedef struct edge
{
    int data;
    int weight;
    struct edge* next;
} ELink;
typedef struct ver
{
    int vertex;
    ELink* link;
} VLink;
VLink G[MaxV];
int createGraph(VLink* graph)
{
    int i,n,v;
    scanf("%d%d",&n,&v);
    for(i=0; i<n; i++)
    {
        graph[i].vertex=i;
        graph[i].link=NULL;
    }
    for(i=0; i<v; i++)   //每一条边都记录
    {
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        ELink* e1=(ELink*)malloc(sizeof(ELink));
        ELink* e2=(ELink*)malloc(sizeof(ELink));
        e1->data=v2;
        e1->next=NULL;
        e2->data=v1;
        e2->next=NULL;


        if(graph[v1].link==NULL)
        {
            graph[v1].link=e1;
            //printf("1\n");
        }
        else
        {
            ELink* s1=graph[v1].link;
            if(s1->data>v2)
            {
                graph[v1].link=e1;
                e1->next=s1;
            }
            else
            {
                while(s1->next!=NULL&&s1->next->data<v2)
                {
                    s1=s1->next;
                }
                if(s1->next==NULL)
                {
                    s1->next=e1;
                }
                else
                {
                    e1->next=s1->next;
                    s1->next=e1;
                }
            }

        }
        if(graph[v2].link==NULL)
        {
            graph[v2].link=e2;
            //printf("1\n");
        }
        else
        {
            ELink* s2=graph[v2].link;
            if(s2->data>v1)
            {
                graph[v2].link=e2;
                e2->next=s2;
            }
            else
            {
                while(s2->next!=NULL &&s2->next->data<v1)
                {

                    if(s2->next==NULL)
                        break;
                    s2=s2->next;
                }
                if(s2->next==NULL)
                {
                    s2->next=e2;
                }
                else
                {
                    e2->next=s2->next;
                    s2->next=e2;
                }
            }
        }
    }
    return n;
}
int Visited[MaxV];
void BFS(VLink* G,int del)   //广度优先遍历
{
    struct Queue q;
    QueueInit(&q);
    ELink *p;
    printf("0 ");
    Visited[0] = 1; //标识某顶点被访问过
    QueuePush(&q,0);
    while( !QueueEmpty(&q))
    {
        int v = QueueFront(&q); //取出队头元素
        //printf("%d ",v);
        QueuePop(&q);
        p = G[v].link; //获取该顶点第一个邻接顶点
        /*访问该顶点的每个邻接顶点*/
        for(; p != NULL ; p = p->next )
            if( !Visited[p->data] &&p->data!=del)
            {
                printf("%d ",p->data);
                Visited[p->data] = 1;
                QueuePush(&q, p->data);
            }
    }
    printf("\n");
}
void DFS(VLink* G, int v,int del) //深度优先遍历
{
    ELink *p;
    printf("%d ",v);
    Visited[v] = 1; //标识某顶点被访问过
    for(p = G[v].link; p !=NULL; p=p->next)
        if( Visited[p->data]==0 &&p->data!=del)
        {
            DFS(G, p->data,del);
        }

}
void deleteGraph(VLink* G,int del,int n)
{
    int i;
    for(i=del;i<n-1;i++)
    {
        G[i]=G[i+1];
    }
    for(i=0;i<n-1;i++)
    {
        if(G[i].link->data==del)
        {
            G[i].link=G[i].link->next;
        }
        else
        {
            ELink* p=G[i].link;
            while(p->next!=NULL)
            {
                if(p->next->data==del)
                {
                    p->next=p->next->next;
                    break;
                }
                else
                {
                    p=p->next;
                }

            }
        }
    }

}
int main()
{
    int n=createGraph(G);
    int i;

    int del;
    scanf("%d",&del);
    DFS(G,0,MaxV+1);
    printf("\n");
    for(int i=0;i<MaxV;i++)
    {
        Visited[i]=0;
    }
    BFS(G,MaxV+1);
    for(int i=0;i<MaxV;i++)
    {
        Visited[i]=0;
    }
    //deleteGraph(G,del,n);
    /*for(i=0;i<8;i++)
    {
        ELink* p=G[i].link;
        printf("%d->",G[i].vertex);
        while(p!=NULL)
        {
            printf("%d->",p->data);
            p=p->next;
        }
        printf("\n");
    }*/
    DFS(G,0,del);
    printf("\n");
    for(int i=0;i<MaxV;i++)
    {
        Visited[i]=0;
    }
    BFS(G,del);

    return 0;
}
void QueueInit(struct Queue* pq)
{
    assert(pq);
    pq->head=pq->tail=NULL;
}
void QueueDestory(struct Queue* pq)
{
    assert(pq);
    struct QueueNode* cur=pq->head;
    while(cur)
    {
        struct QueueNode* next=cur->next;
        free(cur);
        cur=next;
    }
    pq->head=pq->tail=NULL;
}
void QueuePush(struct Queue* pq,Datatype x)
{
    assert(pq);
    struct QueueNode* newnode=(struct QueueNode*)malloc(sizeof(struct QueueNode));

    if(newnode==NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    newnode->data=x;
    newnode->next=NULL;
    if(pq->tail==NULL)  //还没有节点
    {
        pq->head=pq->tail=newnode;
    }
    else        //已经有了节点
    {
        pq->tail->next=newnode;
        pq->tail=newnode;
    }

}
void QueuePop(struct Queue* pq)
{
    assert(pq);
    assert(pq->head);  //保证队列不为空
    if(pq->head->next==NULL)
    {
        free(pq->head);
        pq->head=pq->tail=NULL;
    }
    else
    {
        struct QueueNode* next=pq->head->next;
        free(pq->head);
        pq->head=next;
    }
}
Datatype QueueFront(struct Queue* pq)
{
    assert(pq);
    assert(pq->head);
    return pq->head->data;
}
Datatype QueueBack(struct Queue* pq)
{
    assert(pq);
    assert(pq->head);
    return pq->tail->data;
}
int QueueSize(struct Queue* pq)
{
    assert(pq);
    int size=0;
    struct QueueNode* cur=pq->head;
    while(cur)
    {
        ++size;
        cur=cur->next;
    }
    return size;
}
bool QueueEmpty(struct Queue* pq)
{
    assert(pq);
    return pq->head==NULL;
}

