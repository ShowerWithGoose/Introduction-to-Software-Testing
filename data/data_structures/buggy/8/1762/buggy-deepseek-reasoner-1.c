#include<stdio.h>
int v[150]={0},A[150][150]={0},m,n,del=140,queue[150]={0}; // @@ del=140 is incorrect: initial deletion vertex should not be set arbitrarily; it will be read later. This causes rejust() to treat a non-existent vertex as deleted.
void rejust()
{
    int i;
    for(i=0;i<m;i++)
    {
        if(i==del)
        v[i]=2;
        else
        v[i]=0;
    }
    printf("\n");
}
int isend()
{
    int i,flag=0;
    for(i=0;i<m;i++)
    if(v[i]==0)
    flag=1;
    if(flag==1)
    return -1;
    else
    return 1;
}
void DFS(int x)
{
    int i,j;
    if(v[x]==0)
    {
        v[x]=1;
        printf("%d ",x);
    }
    if(isend()==1)
    return ;
    for(i=0;i<m;i++)
    {
        if(A[x][i]==1&&v[i]==0)
        {
            DFS(i);
        }
    }
}
void BFS()
{
    int rear,front,x,i;
    queue[0]=0; // @@ The starting vertex 0 is enqueued but not marked as visited. This will cause vertex 0 to be visited again later when it appears as a neighbor, leading to duplicate prints and potential infinite loop.
    rear=front=0;
    while(front<=rear)
    {
        if(isend()==1)
        break;
        x=queue[front++];
        printf("%d ",x);
        for(i=0;i<m;i++)
        {
            if(A[x][i]==1&&v[i]==0)
            {
                queue[++rear]=i;
                v[i]=1;
            }
        }
    }
}
int main()
{
    int a,b,i,j;
    scanf("%d%d",&m,&n); // @@ The variable order is swapped: problem expects first integer as number of vertices (n) and second as number of edges (m). Here m receives the vertex count and n receives the edge count. While it may work numerically, it violates the problem specification and may cause confusion.
    for(i=0,j=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        A[a][b]=A[b][a]=1;
    }
    DFS(0);
    rejust();
    BFS();
    rejust();
    scanf("%d",&del);
    for(i=0;i<m;i++)
    {
        A[del][i]=0;
        A[i][del]=0;
    }
    DFS(0);
    rejust();
    BFS();
    return 0;
}