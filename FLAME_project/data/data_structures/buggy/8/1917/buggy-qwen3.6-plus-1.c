#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
#define ElmeType int
int  Visited[MAXSIZE]={0}; //标识顶点是否被访问，N为顶点数
ElmeType Q[MAXSIZE];
struct ver{
    int vertex;
    struct edge *link;
};
struct edge{
    int adjvex;
    int weight;
    struct edge *link;
};
int front,rear,count;
void  initQueue() 
{
    front=0;
    rear=MAXSIZE-1;
    count=0;
}
int isEmpty()
{
    return count==0;
}
int isFull()
{
    return count==MAXSIZE;
}
void enQueue(ElmeType queue[],ElmeType item) //元素入队 
{
    if(isFull())                       /* 队满，插入失败 */  
        printf("Full queue!");
    else
    {
        rear=(rear+1)%MAXSIZE; 
        queue[rear]=item;
        count++;                      /* 队未满，插入成功 */ 
    }
}
ElmeType deQueue(ElmeType queue[]) //元素出队 
{ 
    int e;
    if(isEmpty())
        printf("Empty queue!");     /* 队空，删除失败 */
    else
    {
        e=queue[front];
        count--;                             /* 队非空，删除成功 */
        front=(front+1)%MAXSIZE;
        return e;
    }
}
void  travelDFS(struct ver G[], int n);
void DFS(struct ver G[],int v); 
void BFS(struct ver G[ ], int v);
void travelBFS(struct ver G[], int n);
int main()
{
    struct ver Vertex[100]={0,NULL};
    struct edge *p=NULL,*q=NULL,*r=NULL;
    int v_num,e_num;
    scanf("%d %d",&v_num,&e_num);
    int del;
    int i,j,k;
    for(i=0;i<e_num;i++)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        p=(struct edge*)malloc(sizeof(struct edge));
        p->adjvex=n;
        p->link=NULL;
        q=(struct edge*)malloc(sizeof(struct edge));
        q->adjvex=m;
        q->link=NULL;
        if(Vertex[m].link==NULL)
        {
            Vertex[m].link=p;
            Vertex[m].vertex=m;
        }
        else
        {
            if(Vertex[m].link->adjvex>n)
            {
                p->link=Vertex[i].link; // @@ Error: Uses index 'i' (loop counter for edges) instead of 'm' (current vertex), leading to incorrect linked list insertion or crash. Should be Vertex[m].link.
                Vertex[m].link=p;
            }
            else
            {
                for(r=Vertex[m].link;r->link!=NULL&&r->link->adjvex<=n;r=r->link);
                p->link=r->link;
                r->link=p;
            }
        }
        if(Vertex[n].link==NULL)
        {
            Vertex[n].link=q;
            Vertex[n].vertex=n;
        }
        else
        {
            if(Vertex[n].link->adjvex>m)
            {
                q->link=Vertex[i].link; // @@ Error: Uses index 'i' (loop counter for edges) instead of 'n' (current vertex), leading to incorrect linked list insertion or crash. Should be Vertex[n].link.
                Vertex[n].link=q;
            }
            else
            {
                   for(r=Vertex[n].link;r->link!=NULL&&r->link->adjvex<=m;r=r->link);
                q->link=r->link;
                r->link=q;
            }
        }
    }
/*    for(i=0;i<v_num;i++)
    {
        printf("%d",Vertex[i].vertex);
        if(Vertex[i].link!=NULL)
        {
            for(p=Vertex[i].link;p!=NULL;p=p->link)
            {
                printf("->%d",p->adjvex);
            }
        }
        printf("\n");
    }*/ 
    scanf("%d",&del);
    travelDFS(Vertex,v_num);
    printf("\n");
    travelBFS(Vertex,v_num);
    printf("\n");
    for(i=0;i<v_num;i++)
    {
        if(i==del)
        {
            if(Vertex[i].link==NULL)
            {
                Vertex[i].vertex=-1;
                Vertex[i].link=NULL;
            }
            else
            {
                p=Vertex[i].link;
                while(p->link!=NULL)
                {
                    Vertex[i].link=p->link;
                    free(p);
                    p=Vertex[i].link;
                }
                free(Vertex[i].link);
                Vertex[i].vertex=-1;
                Vertex[i].link=NULL;
            }
        }
        else
        {
            if(Vertex[i].link!=NULL)
            {
                for(p=Vertex[i].link;p!=NULL;p=p->link)
                {
                    if(p->adjvex==del)
                    {
                        if(p!=Vertex[i].link)
                        {
                            for(r=Vertex[i].link;r->link!=NULL&&r->link!=p;r=r->link);
                            if(p->link==NULL)
                            {
                                r->link=NULL;
                                free(p);
                            }
                            else
                            {
                                r->link=p->link;
                                free(p);
                            }
                            p=r;    
                        }
                        else
                        {
                            if(p->link==NULL)
                            {
                                Vertex[i].link=NULL;
                                free(p);
                            }
                            else
                            {
                                Vertex[i].link=p->link;
                                free(p);
                            }
                            p=Vertex[i].link;    
                        }
                    }
                }
            }
        }
    }
    travelDFS(Vertex,v_num);
    printf("\n");
    travelBFS(Vertex,v_num);
    printf("\n");
    return 0;
}
void travelDFS(struct ver G[],int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i]=0;
    for(i=0; i<n; i++)
    {
        if(G[i].vertex==-1)
        continue;
        if(!Visited[i] ) 
            DFS(G,i);
    }
}
void DFS(struct ver G[],int v)
{
    struct edge *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",G[v].vertex); 
    //访问某顶点
    for(p=G[v].link;p!=NULL;p=p->link)
         if(!Visited[p->adjvex])
             DFS(G,p->adjvex);
}
void travelBFS(struct ver G[], int n)
{
    initQueue();
    int i;
    for(i=0;i<n;i++) Visited[i] = 0 ;
    for(i=0;i<n;i++)
    {
        if(G[i].vertex==-1)
        continue;
        if(!Visited[i]) 
            BFS(G,i);
    }
    
}
void BFS(struct ver G[ ], int v)
{
    struct edge *p;
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q,v);
    while(!isEmpty())
    {
        v=deQueue(Q);  //取出队头元素
        printf("%d ",G[v].vertex); 
        for(p=G[v].link;p!=NULL;p=p->link) //访问该顶点的每个邻接顶点
        {
            if(!Visited[p->adjvex]) 
            {
                Visited[p->adjvex] = 1; 
                enQueue(Q, p->adjvex); //标识某顶点入队
            }
        }
    }
}