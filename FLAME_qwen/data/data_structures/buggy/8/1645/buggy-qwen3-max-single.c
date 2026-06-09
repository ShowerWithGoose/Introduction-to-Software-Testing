#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int visit[100];
struct link{
    int vertex;
    struct link *next;
}*Vertex[100];
struct{
    int rear;
    int front;
    struct link *queue[100];
}que;
void DFS(struct link* p)
{
    if(p!=NULL)
    {
    if(visit[p->vertex]==0)
    {
    printf("%d ",p->vertex);
    visit[p->vertex]=1;
    struct link* t;
        t=p->next;
        while(t!=NULL)
        {
            DFS(Vertex[t->vertex]); // @@ [DFS is called on Vertex[t->vertex], but the adjacency list for each vertex is stored starting from the head node that contains the vertex itself. This causes traversal to start from a node containing the neighbor's ID as its own vertex field, leading to incorrect traversal order and possible infinite recursion or missed nodes. Also, neighbors are not visited in ascending order because the insertion does not guarantee full sorting and DFS does not select the smallest unvisited neighbor first.]
            t=t->next;
        }
    }
    }
}
void BFS(struct link* p)
{
    if(p!=NULL)
    {
    if(que.rear==0)
    {
        que.queue[que.rear]=p;
        que.rear++;
        BFS(que.queue[que.front]);
    }
    else
    {
        if(visit[que.queue[que.front]->vertex]==0)
        {
        visit[que.queue[que.front]->vertex]=1;
        printf("%d ",que.queue[que.front]->vertex);
        struct link* t;
        t=que.queue[que.front]->next;
        while(t!=NULL)
        {
            if(visit[t->vertex]==0)
            {
            que.queue[que.rear]=Vertex[t->vertex]; // @@ [Similar to DFS, BFS enqueues Vertex[t->vertex] which is a head node containing t->vertex as its own ID, but the actual adjacency list starts at Vertex[t->vertex]->next. This leads to incorrect graph representation during traversal. Additionally, neighbors are not processed in ascending order due to lack of proper ordering during enqueue.]
            que.rear++;
            }
            t=t->next;
        }
            que.front++;
            BFS(que.queue[que.front]);
        }
        else
        {
            que.front++;
            BFS(que.queue[que.front]);    
        }
    }
    }
}
void deletVertex(int goal,int n)
{
    for(int i=0;i<n;i++)
    {
        if(i==goal)
        {
            Vertex[i]=NULL;
        }
        else
        {
        struct link* t=Vertex[i];
        while(t->next!=NULL) // @@ [If Vertex[i] is NULL (e.g., after deletion or initially), this will cause a segmentation fault. Also, the loop condition should check t != NULL before accessing t->next. Moreover, this deletion logic only removes the first occurrence of the goal vertex in the adjacency list and assumes edges are stored only once, but it may miss cases where the list has multiple links or isn't properly terminated.]
        {
            if(t->next->vertex==goal)
            {
                t->next=t->next->next;
                break;
            }
            t=t->next;
        }
        }
    }
}
int main()
{
    que.rear=0;
    que.front=0;
    struct link *p,*q,*temp;
    int numOfvertex;//顶点
    int numOfside;
    int vertex1,vertex2;
    int goal;
    scanf("%d%d",&numOfvertex,&numOfside);
    for(int i=0;i<numOfside;i++)
    {
        scanf("%d%d",&vertex1,&vertex2);
        if(Vertex[vertex1]==NULL)
        {
            p=(struct link*)malloc(sizeof(struct link));
            q=(struct link*)malloc(sizeof(struct link));
            q->vertex=vertex2;
            q->next=NULL;
            p->vertex=vertex1;
            p->next=q;
            Vertex[vertex1]=p;
        }
        else
        {
            temp=Vertex[vertex1];
            while(temp->next!=NULL)
            {
                if(temp->next->vertex>vertex2)
                {
                    p=(struct link*)malloc(sizeof(struct link));
                    p->vertex=vertex2;
                    p->next=temp->next;
                    temp->next=p;
                    break;
                }
                temp=temp->next;
            }
            if(temp->next==NULL)
            {
                p=(struct link*)malloc(sizeof(struct link));
                p->vertex=vertex2;
                p->next=NULL;
                temp->next=p;
            }
        }
        if(Vertex[vertex2]==NULL)
        {
            p=(struct link*)malloc(sizeof(struct link));
            q=(struct link*)malloc(sizeof(struct link));
            q->vertex=vertex1;
            q->next=NULL;
            p->vertex=vertex2;
            p->next=q;
            Vertex[vertex2]=p;
        }
        else
        {
            temp=Vertex[vertex2];
            while(temp->next!=NULL)
            {
                if(temp->next->vertex>vertex1)
                {
                    p=(struct link*)malloc(sizeof(struct link));
                    p->vertex=vertex1;
                    p->next=temp->next;
                    temp->next=p;
                    break;
                }
                temp=temp->next;
            }
            if(temp->next==NULL)
            {
                p=(struct link*)malloc(sizeof(struct link));
                p->vertex=vertex1;
                p->next=NULL;
                temp->next=p;
            }
        }
    }
    scanf("%d",&goal);
    DFS(Vertex[0]);
    printf("\n");
    for(int i=0;i<numOfvertex;i++)
    {
        visit[i]=0;
    }
    BFS(Vertex[0]);
    printf("\n");
    deletVertex(goal,numOfvertex);
    for(int i=0;i<numOfvertex;i++)
    {
        visit[i]=0;
    }
    DFS(Vertex[0]);
    printf("\n");
    for(int i=0;i<numOfvertex;i++)
    {
        visit[i]=0;
        que.queue[i]=NULL;
    }
    que.front=0;
    que.rear=0;
    BFS(Vertex[0]);
    return 0;
}