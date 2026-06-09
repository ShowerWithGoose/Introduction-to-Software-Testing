#include <stdio.h>
#include <stdlib.h>
int A[100][100],visit[100],queue[100];
int front=0,rear=1;
void tdfs(int[][100],int,int);
void dfs(int[][100],int,int);
void tbfs(int[][100],int,int);
//void bfs(int[][100],int,int);
int main()
{
    int v,e,i,a,b,d;
    scanf("%d%d",&v,&e);
    for(i=0;i<e;i++)
    {
        scanf("%d%d",&a,&b);
        A[a][b]=1;
        A[b][a]=1;
    }
    scanf("%d",&d);
    tdfs(A,0,v);
    tbfs(A,0,v);
    tdfs(A,d,v);
    tbfs(A,d,v);
    return 0;
}
void tdfs(int A[][100],int d,int v)
{
    int i;
    for(i=0;i<v;i++)
        visit[i]=0;
    visit[0]=1;
    visit[d]=1;
    printf("0 ");
    for(i=0;i<v;i++)
        if(A[0][i]==1&&visit[i]!=1)
            dfs(A,i,v);
    printf("\n");
}
void dfs(int A[][100],int i,int v)
{
    int j;
    printf("%d ",i);
    visit[i]=1;
    for(j=0;j<v;j++)
        if(A[i][j]==1&&visit[j]!=1)
            dfs(A,j,v);
}
void tbfs(int A[][100],int d,int v)
{
    int i,t;
    front=0;
    rear=1;
    for(i=0;i<v;i++)
        visit[i]=0;
    for(i=0;i<100;i++)
        queue[i]=0;
    if(d!=0)
        visit[d]=1;
    queue[front]=0;
    /*for(i=0;i<v;i++)
        if(A[0][i]==1&&visit[i]!=1)
            queue[rear++]=i;
    printf("0 ");
    visit[0]=1;*/
    while(front<=rear){
    t=queue[front];
    front++;
    if(visit[t]==1)
        continue;
    else{
            printf("%d ",t);
            visit[t]=1;
            for(i=0;i<v;i++)
                if(A[t][i]==1&&visit[i]!=1)
                    queue[rear++]=i;
           }
    }
    /*for(i=0;i<v;i++)
        if(visit[i]==0)
            bfs(A,i,v);*/
    printf("\n");
}
/*void bfs(int A[][100],int i,int v)
{
    int j,t;
    printf("%d ",i);
    visit[i]=1;
    for(j=0;j<v;j++)
        if(A[i][j]==1&&visit[j]!=1)
            queue[rear++]=j;
    while(front<=rear){
    t=queue[front];
    front++;
    if(visit[t]==1)
        continue;
    else{
            printf("%d ",t);
            visit[t]=1;
            for(j=0;j<v;j++)
                if(A[t][j]==1&&visit[j]!=1)
                    queue[rear++]=j;
           }
    }
}*/

