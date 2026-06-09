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
        if(isend()==1)
        break;
        x=queue[front++];
        printf("%d ",x); @@ [Vertex x is printed without checking if it has already been visited, which may cause duplicate output in BFS. Also, v[x] is not marked as visited before enqueueing neighbors, leading to potential re-enqueueing of the same node.]
        for(i=0;i<m;i++)
        {
            if(A[x][i]==1&&v[i]==0)
            {
                queue[++rear]=i;
                v[i]=1; @@ [Marking v[i]=1 here prevents re-enqueue, but x itself was never marked as visited before printing, causing inconsistency with DFS and possible logic errors.]
            }
        }
    }
}
int main()
{
    int a,b,i,j;
    scanf("%d%d",&m,&n); @@ [Variables m and n are swapped: m should be number of vertices, n number of edges, but problem states first input is n (vertices) then m (edges). This causes all subsequent logic to use wrong graph size.]
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