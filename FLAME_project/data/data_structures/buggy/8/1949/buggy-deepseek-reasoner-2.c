#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
    int adjvex;
    struct node*next;
}EdgeNode;
typedef struct vnode
{
    int vertex;
    EdgeNode* FirstEdge;
}VertexNode;
typedef struct graph
{
    VertexNode s[100];
    int side,dot;
}LinkGraph;
int visit[100];
void dfs(LinkGraph *g,int i)
{
    printf("%d",g->s[i].vertex); // @@ [输出缺少空格，应改为printf("%d ",...)]
    visit[i]=1;
    EdgeNode *p=g->s[i].FirstEdge;
    while(p!=NULL)
    {
        if(!visit[p->adjvex])
        {
            dfs(g,p->adjvex);
        }
        p=p->next;
    }
}
void traveldfs(LinkGraph *g)
{
    // for(int i=0;i<g->dot;i++)
    // {
    //     visit[i]=0;
    // }
    for(int i=0;i<g->dot;i++)
    {
        if(!visit[g->s[i].vertex])
        dfs(g,i);
    }
    printf("\n");

}
void bfs(LinkGraph *g,int i)
{
    printf("%d",g->s[i].vertex); // @@ [输出缺少空格，应改为printf("%d ",...)]
    visit[i]=1;
    int queue[100];
    int front=0,rear=0;
    queue[rear++]=i;
    while(rear>front)
    {
    int j=queue[front++];
    EdgeNode*p=g->s[j].FirstEdge;
    while(p!=NULL)
    {
        if(visit[p->adjvex]==0)
        {
            printf("%d",p->adjvex); // @@ [输出缺少空格，应改为printf("%d ",...)]
            visit[p->adjvex]=1;
            queue[rear++]=p->adjvex;
        }
        p=p->next;
    }
}
}
void travelbfs(LinkGraph *g)
{
    //  for(int i=0;i<g->dot;i++)
    // {
    //     visit[i]=0;
    // }
    for(int i=0;i<g->dot;i++)
    {
        if(!visit[g->s[i].vertex])
        bfs(g,i);
    }
    printf("\n");
}
int main()
{
    LinkGraph g;
    int mark=0;
    scanf("%d%d",&g.dot,&g.side);
    int i=0;
    int a,b;
    for(i=0;i<g.dot;i++)
    {
       g.s[i].vertex=i;
       g.s[i].FirstEdge=NULL;
    }
    for(i=0;i<g.side;i++)
    {
        scanf("%d%d",&a,&b);
        // if(a>b)
        // {
        //     int tmp=a;
        //     a=b;
        //     b=tmp;
        // }
        //让一条边的两个点都有对方。
        EdgeNode *p,*h;
        p=(EdgeNode*)malloc(sizeof(EdgeNode));
        h=(EdgeNode*)malloc(sizeof(EdgeNode));
        p->adjvex=b;
        h->adjvex=a;
        if(g.s[a].FirstEdge==NULL)
        {
            g.s[a].FirstEdge=p;
            p->next=NULL;
        }
        else
        {
            EdgeNode *temp;
            if(b<g.s[a].FirstEdge->adjvex)
            {
                p->next=g.s[a].FirstEdge;
                g.s[a].FirstEdge=p;
            }
            else
            {
                EdgeNode*r;
                temp=g.s[a].FirstEdge;
                r=temp;
                temp=temp->next;
                while(temp!=NULL)
                {
                    if(temp->adjvex>b)
                    {
                        r->next=p;
                        p->next=temp;
                        break;
                    }
                    r=temp;
                    temp=temp->next;
                }
                if(temp==NULL)
                {
                    r->next=p;
                    p->next=NULL;
                }
            }
        
        }
        if(g.s[b].FirstEdge==NULL)
        {
            g.s[b].FirstEdge=h;
            h->next=NULL;
        }
         else
        {
            EdgeNode *temp;
            if(a<g.s[b].FirstEdge->adjvex)
            {
                h->next=g.s[b].FirstEdge;
                g.s[b].FirstEdge=h;
            }
            else
            {
                EdgeNode*r;
                temp=g.s[b].FirstEdge;
                r=temp;
                temp=temp->next;
                while(temp!=NULL)
                {
                    if(temp->adjvex>a)
                    {
                        r->next=h;
                        h->next=temp;
                        break;
                    }
                    r=temp;
                    temp=temp->next;
                }
                if(temp==NULL)
                {
                    r->next=h;
                    h->next=NULL;
                }
            }
        
        }
    }
    scanf("%d",&mark);
     for(int i=0;i<g.dot;i++)
    {
        visit[i]=0;
    }
    traveldfs(&g);
     for(int i=0;i<g.dot;i++)
    {
        visit[i]=0;
    }
    travelbfs(&g);
     for(int i=0;i<g.dot;i++)
    {
        visit[i]=0;
    }
    visit[mark]=1;
    traveldfs(&g);
     for(int i=0;i<g.dot;i++)
    {
        visit[i]=0;
    }
    visit[mark]=1;
    travelbfs(&g);
    // g.dot--;
    // for(i=mark;i<g.dot;i++)
    // {
    //     g.s[i+1]=g.s[i];
    // }
    // for(i=0;i<g.dot;i++)
    // {
    //     EdgeNode *p=g.s[i].FirstEdge;
    //     EdgeNode *r=p;

    //     while(p!=NULL)
    //     {
    //         if(p->adjvex==mark)
    //     }
    // }
    return 0;
}