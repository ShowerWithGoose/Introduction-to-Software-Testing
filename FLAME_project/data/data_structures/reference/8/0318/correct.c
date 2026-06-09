#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int visited[105];
int queue[105];//队
int front=0,rear=-1;//记录队头和队尾
typedef struct Anode
{
    int adjvex;
    //int weight;//权值
    struct Anode *next;//指向下一条边
}Anode;//边结点
typedef struct vnode
{
    int vertax;//数据信息
    Anode *link;//指向链表中第一个节点
}Vnode;//顶点
Vnode adjlist[105];//邻接表
void DFS(Vnode G[],int v);
void BFS(Vnode G[],int v);
int main()
{
    //建立邻接表
    int i,d;
    int v1,v2;
    Anode *p1,*p2,*p;
    int vnum,anum;//顶点数与边数
    scanf("%d %d",&vnum,&anum);
    for(i=0;i<vnum;i++)
    {
        adjlist[i].vertax=i;
        adjlist[i].link=NULL;
    }
    for(i=0;i<anum;i++)
    {
        scanf("%d %d",&v1,&v2);
        p1=(Anode*)malloc(sizeof(Anode));
        p1->adjvex=v2;
        p1->next=NULL;
        if(adjlist[v1].link==NULL) 
            adjlist[v1].link=p1;
        else
        {
            p=adjlist[v1].link;
            if(p->adjvex>p1->adjvex)
            {
                p1->next=p;
                adjlist[v1].link=p1;
            }
            else
            {
                while(p->next!=NULL)
                {
                    if(p->next->adjvex>p1->adjvex)
                        break;
                    p=p->next;
                }
                if(p->next==NULL) p->next=p1;
                else
                {
                    p1->next=p->next;
                    p->next=p1;
                }
            }
            
        }
        p2=(Anode*)malloc(sizeof(Anode));
        p2->adjvex=v1;
        p2->next=NULL;
        if(adjlist[v2].link==NULL) 
            adjlist[v2].link=p2;
        else
        {
            p=adjlist[v2].link;
            if(p->adjvex>p2->adjvex)
            {
                p2->next=p;
                adjlist[v2].link=p2;
            }
            else
            {
                while(p->next!=NULL)
                {
                    if(p->next->adjvex>p2->adjvex)
                        break;
                    p=p->next;
                }
                if(p->next==NULL) p->next=p2;
                else
                {
                    p2->next=p->next;
                    p->next=p2;
                }
            }
        }
    }
    //深度优先遍历
    for(i=0;i<vnum;i++)
    {
        if(visited[i]==0)
            DFS(adjlist,i);
    }
    printf("\n");
    memset(visited,0,sizeof(visited));
    //广度优先遍历
    for(i=0;i<vnum;i++)
    {
        if(visited[i]==0)
            BFS(adjlist,i);
    }
    printf("\n");
    memset(visited,0,sizeof(visited));
    front=0,rear=-1;

    scanf("%d",&d);
    visited[d]=1;
    for(i=0;i<vnum;i++)
    {
        if(visited[i]==0)
            DFS(adjlist,i);
    }
    printf("\n");
    memset(visited,0,sizeof(visited));
    visited[d]=1;
    for(i=0;i<vnum;i++)
    {
        if(visited[i]==0)
            BFS(adjlist,i);
    }
    return 0;
}
void DFS(Vnode G[],int v)
{
    Anode *p;
    visited[v]=1;
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next)
    {
        if(visited[p->adjvex]==0)
            DFS(G,p->adjvex);
    }
}
void BFS(Vnode G[],int v)
{
    Anode *p;
    visited[v]=1;
    queue[++rear]=v;
    while(front<=rear)
    {
        v=queue[front++];
        printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next)
        {
            if(visited[p->adjvex]==0)
            {
                visited[p->adjvex]=1;
                queue[++rear]=p->adjvex;
            }
        }
    }
}
