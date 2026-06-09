#include<stdio.h>
int v[150]={0},A[150][150]={0},m,n,del=140,queue[150]={0};
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
    queue[0]=0;
    rear=front=0;
    while(front<=rear)
    {
        if(isend()==1) // @@ This break condition causes premature termination when all vertices have been marked visited but some may still be in the queue, resulting in missing vertices in the BFS output.
        break;
        x=queue[front++];
        printf("%d ",x); // @@ The visited flag for vertex x is not set here, which can lead to the vertex being enqueued and printed again later, causing duplicates.
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
    scanf("%d%d",&m,&n);
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