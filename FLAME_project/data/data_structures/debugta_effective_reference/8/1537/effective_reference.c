#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>

#define maxV 100

typedef struct edge{
    int adj;
    struct edge *next;
}ELink;

typedef struct ver{
    int vertex;
    ELink *link;
}VLink;

struct node{
    VLink data;
    struct node *s;
};

VLink G[maxV];
VLink Q[3*maxV];
int front=-1,rear=-1;
int visited[maxV]={0};


void createGragh(VLink graph[],int eg);
ELink *insertEdge(ELink *head,int avex);
void travelBFS(VLink G[],int pt);
void visit(VLink G[],int v);
void BFS(VLink G[],int v);
void initQ();
int emptyQ();
void enQueue(VLink G[],int v);
int deQueue();
void adjustQ(ELink *head);
void DFS(VLink G[],int v);
void travelDFS(VLink G[],int pt);
void deleteVex(int del,int pt);
ELink * deleteEdge(ELink *head,int del);


int main()
{
    int pt,eg,del;
    int i;
    scanf("%d%d",&pt,&eg);
    createGragh(G,eg);
    for(i=0;i<pt;i++)
    {
        G[i].vertex=i;
        adjustQ(G[i].link);
    }
    scanf("%d",&del);


    travelDFS(G,pt);
    printf("\n");
    travelBFS(G,pt);

    //deleteVex(cut,n);
    G[del].vertex=-1;
    G[del].link=NULL;

    for(i=0;i<pt-1;i++)
    {
        if(G[i].link!=NULL)
        {
            G[i].link=deleteEdge(G[i].link,del);
        }
        else continue;
    }

    printf("\n");
    travelDFS(G,pt);
    printf("\n");
    initQ();
    travelBFS(G,pt);
    printf("\n");


    /*
    for(i=0;i<n-1;i++)
    {
        p=G[i].link;
        if(p!=NULL)
        {
            for(;p!=NULL;p=p->next)
            {
                printf("%d ",p->adj);
            }
            printf("\n");
        }
        else{
            printf("-1\n");
        }

    }
    */




    return 0;
}

void createGragh(VLink graph[],int eg)
{
    int i,v1,v2;
    for(i=0;i<eg;i++)
    {
        scanf("%d%d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link,v2);
        graph[v2].link=insertEdge(graph[v2].link,v1);
    }

}


ELink *insertEdge(ELink *head,int avex)
{
    ELink *e,*p;
    e=(ELink*)malloc(sizeof(ELink));
    e->adj=avex;
    e->next=NULL;

    if(head==NULL)
    {
        head=e;
        return head;
    }

    for(p=head;p->next!=NULL;p=p->next);
    p->next=e;
    return head;

}

void travelBFS(VLink G[],int pt)
{
    int i;
    for(i=0;i<pt;i++)
    {
        visited[i]=0;
    }
    for(i=0;i<pt;i++)
    {
        if(!visited[i])
            BFS(G,i);
    }
}

void visit(VLink G[],int v)
{
    if(G[v].vertex!=-1)
    printf("%d ",G[v].vertex);
}



void BFS(VLink G[],int v)
{
    ELink *p;
    visit(G,v);
    visited[v]=1;
    enQueue(G,v);
    while(!emptyQ())
    {
        //adjustQ();
        v=deQueue();
        p=G[v].link;
        for(;p!=NULL;p=p->next)
        {
            if(!visited[p->adj])
            {
                visit(G,p->adj);
                visited[p->adj]=1;
                enQueue(G,p->adj);
            }
        }
    }
}

void initQ()
{
    front=rear=-1;
    memset(Q,0,3*maxV*sizeof(int));
}

int emptyQ()
{
    return front==rear;
}

void enQueue(VLink G[],int v)
{
    Q[++rear]=G[v];
}

int deQueue()
{
    int item;
    item=Q[front++].vertex;
    return item;
}

void DFS(VLink G[],int v)
{
    ELink *p;
    visit(G,v);
    visited[v]=1;
    for(p=G[v].link;p!=NULL;p=p->next)
    {
        if(!visited[p->adj])
        {
            DFS(G,p->adj);
        }
    }
}

void travelDFS(VLink G[],int pt)
{
    int i;
    for(i=0;i<pt;i++)
    {
        visited[i]=0;
    }
    for(i=0;i<pt;i++)
    {
        if(!visited[i])
            DFS(G,i);
    }
}


void adjustQ(ELink *head)
{
  int hold;
  ELink *p,*q;
  for(p=head;p->next!=NULL;p=p->next)
  {
      for(q=head;q->next!=NULL;q=q->next)
      {
          if(q->adj>(q->next)->adj)
          {
              hold=q->adj;
              q->adj=(q->next)->adj;
              (q->next)->adj=hold;
          }
      }
  }


}

ELink * deleteEdge(ELink *head,int del)
{
    ELink *p,*q;
    p=q=head;
    if(head->adj==del)
    {
        head=p->next;
    }
    else{
        for(;p!=NULL;q=p,p=p->next)
        {
            if(p->adj==del)
            {
                q->next=p->next;
                free(p);
                break;
            }
        }
    }
    return head;
}


