#include <stdio.h>
#include <stdlib.h>
typedef struct Graph
{
    int Nv;
    int Ne;
    int G[105][105];
}GRA;
typedef struct queue
{
    int data;
    struct queue *next;
}QUE;
int visited[105]={0};
void DFS(GRA *,int);
void BFS(GRA *,int);
int main()
{
    GRA graph,*p_g=&graph;
    for(int i=0;i<105;i++)
        for(int j=0;j<105;j++)
            p_g->G[i][j]=0;
    scanf("%d",&(p_g->Nv));
    scanf("%d",&(p_g->Ne));
    for(int i=0;i<p_g->Ne;i++){
        int v,w;
        scanf("%d%d",&v,&w);
        p_g->G[v][w]=1;
        p_g->G[w][v]=1;
    }
    int delV;
    scanf("%d",&delV);
    DFS(p_g,0);
    putc('\n',stdout);
    for(int i=0;i<105;i++)visited[i]=0;
    BFS(p_g,0);
    for(int i=0;i<105;i++)visited[i]=0;
    for(int i=0;i<p_g->Nv;i++){
        p_g->G[delV][i]=0;
        p_g->G[i][delV]=0;
    }
    putc('\n',stdout);
    DFS(p_g,0);
    for(int i=0;i<105;i++)visited[i]=0;
    putc('\n',stdout);
    BFS(p_g,0);
}
void DFS(GRA *p,int searchV)
{
    visited[searchV]=1;
    printf("%d ",searchV);
    for(int i=1;i<p->Nv;i++){
        if(p->G[searchV][i]&&!visited[i]){
            DFS(p,i);
        }
    }
}
void BFS(GRA *p,int searchV)
{
    QUE *head=NULL,*tail=NULL,*pos=NULL;
    head=malloc(sizeof(QUE));
    head->data=searchV;
    tail=pos=head;
    head->next=NULL;
    while(head!=NULL){
        int V=head->data;
        printf("%d ",V);
        for(int i=1;i<p->Nv;i++){
            if(p->G[V][i]&&!visited[i]){
                visited[i]=1;
                QUE *q=(QUE *)malloc(sizeof(QUE));
                tail->next=q;
                tail=q;
                q->data=i;
                q->next=NULL;
            }
        }
        pos=head;
        head=head->next;
        if(head==NULL)tail=NULL;
        free(pos);
    }
}
