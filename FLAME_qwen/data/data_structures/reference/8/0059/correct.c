#include <stdio.h>
#include <stdlib.h>

int adj[100][100];
int visit[100]={};
int Q[100]={};
int front = 0;
int rear = -1;

typedef struct node{
    int num;
    struct node *link;
}Graph, *pGraph;

void DFS(pGraph head[100], int i)
{
    pGraph p;
    visit[i] = 1;
    printf("%d ",head[i]->num);
    for(p=head[i]->link;p!=NULL;p=p->link)
    {
        if(!visit[p->num])
        DFS(head,p->num);
    }
}

int emptyQ()
{
    if(front>rear) return 1;
    else return 0;
}
void enQ(int i)
{
    rear++;
    Q[rear] = i;
}
int deQ(void)
{
    int ans;
    ans = Q[front];
    front++;
    return ans;
}
void BFS(pGraph head[100], int i)
{
    pGraph p;
    visit[i] = 1;
    enQ(i);
    while(!emptyQ()){
        i = deQ();
        printf("%d ",head[i]->num);
        for(p=head[i]->link;p!=NULL;p=p->link)
        if(!visit[p->num]){
            visit[p->num] = 1;
            enQ(p->num);
        }
    }}


int main(void)
{
    int i,j;
    int m,n;
    int a,b;
    int delete;
    pGraph table[100];
    pGraph head[100];
    pGraph p = NULL;
    scanf("%d%d",&m,&n);

    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
            adj[i][j] = 0;
    
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        adj[a][b] = adj[b][a] = 1;
    }

    scanf("%d",&delete);
    for(i=0;i<m;i++)
    {
        p = (pGraph)malloc(sizeof(Graph));
        p->num = i;
        p->link = NULL;
        table[i] = p;
    }

    for(i=0;i<m;i++)
    head[i] = table[i];
    for(i=0;i<m;i++)
        {for(j=0;j<m;j++)
        {
            if(adj[i][j]==1)
            {
                p = (pGraph)malloc(sizeof(Graph));
                p->num = j;
                p->link = NULL;
                table[i]->link = p;
                table[i] = p;

        }}}
   
   for(i=0;i<m;i++)
   {
       if(!visit[i]) DFS(head,i);
   }
   printf("\n");
   for(i=0;i<m;i++)
   visit[i] = 0;
   for(i=0;i<m;i++)
   {
       if(!visit[i]) BFS(head,i);
   }
   printf("\n");
   for(i=0;i<m;i++)
   visit[i] = 0;

   for(i=0;i<m;i++)
   {adj[delete][i] = 0;
    adj[i][delete] = 0;}

for(i=0;i<m;i++)
    {
        p = (pGraph)malloc(sizeof(Graph));
        p->num = i;
        p->link = NULL;
        table[i] = p;
    }

    for(i=0;i<m;i++)
    head[i] = table[i];
    for(i=0;i<m;i++)
        {for(j=0;j<m;j++)
        {
            if(adj[i][j]==1)
            {
                p = (pGraph)malloc(sizeof(Graph));
                p->num = j;
                p->link = NULL;
                table[i]->link = p;
                table[i] = p;

        }}}
   
    for(i=0;i<m;i++)
   {
       if(i==delete) continue;
       if(!visit[i]) DFS(head,i);
   }
   printf("\n");
   for(i=0;i<m;i++)
   visit[i] = 0;
   for(i=0;i<m;i++)
   {
       if(i==delete) continue;
       if(!visit[i]) BFS(head,i);
   }
   

}



